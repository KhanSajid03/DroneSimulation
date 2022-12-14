
#include "BatteryDroneDecorator.h"


void BatteryDroneDecorator::Update(double dt, std::vector<IEntity*> scheduler, std::vector<IEntity*> stations) {

  if (drone->GetAvailability()) {
    GetNearestEntity(scheduler, stations); 
  }

  if (onRechargeMission) { 
    if (drone->GetPosition().Distance(nearestRechargeStation->GetPosition()) < 50.0) {
      batteryLevel += 10.0 * dt;
    }  // TODO: change this from literal float values to constants
    if (batteryLevel >= 95.0) {
      std::cout << "Battery charged to " << batteryLevel << std::endl;
      nearestRechargeStation = NULL;
      onRechargeMission = false;

      std::cout << "Rerouting drone to robot " << std::endl;
      
      drone->SetToTargetPosStrategy(new BeelineStrategy(drone->GetPosition(), targetPos));
      drone->SetToTargetDestStrategy(toTargetDestStrategy);

      return;
    }
  }

  if (!drone->GetAvailability() && batteryLevel > 1) {
    batteryLevel -= BATTERY_RATE * dt;
  }

  drone->Update(dt, scheduler);

}


bool BatteryDroneDecorator::hasEnoughBatteryForDist(float dist) {
  float batteryRequired = (BATTERY_RATE / drone->GetSpeed()) * dist;
  batteryRequired += 25.0; // buffer zone
  std::cout << "Current battery level: " << batteryLevel << std::endl;
  std::cout << "Battery level required: " << batteryRequired << std::endl;
  return (batteryLevel > batteryRequired);
}


void BatteryDroneDecorator::GetNearestEntity(std::vector<IEntity*> scheduler, std::vector<IEntity*> stations) {

  drone->GetNearestEntity(scheduler);

  toTargetPosStrategy = drone->GetToTargetPosStrategy();
  toTargetDestStrategy = drone->GetToTargetDestStrategy();

  if (!toTargetPosStrategy || !toTargetDestStrategy) { return; }

  std::vector<std::vector<float>> path1 = toTargetPosStrategy->GetPath();
  std::vector<std::vector<float>> path2 = toTargetDestStrategy->GetPath();

  float path1Distance = 0.0;

  for (int i = 1; i < path1.size(); i++) {
    Vector3 lastPos(path1[i-1]);
    Vector3 nowPos(path1[i]);

    path1Distance += nowPos.Distance(lastPos);
  }

  std::cout << "Distance from drone to robot: " << path1Distance << std::endl;

  float path2Distance = 0.0;

  for (int i = 1; i < path2.size(); i++) {
    Vector3 lastPos(path2[i-1]);
    Vector3 nowPos(path2[i]);

    path2Distance += nowPos.Distance(lastPos);
  }

  std::cout << "Distance from robot to destination: " << path2Distance << std::endl;

  float tripDistance = path1Distance + path2Distance;

  std::cout << "Trip Distance: " << tripDistance << std::endl;

  if (!hasEnoughBatteryForDist(tripDistance)) {
    std::cout << std::endl << "Not enough battery for trip!" << std::endl << std::endl;;
    std::cout << "Drone routing to nearest recharge station" << std::endl;
    onRechargeMission = true;
    drone->SetAvailability(false);
    GetNearestRechargeStation(stations);

    targetPos = drone->GetDestination();

    drone->SetToTargetPosStrategy(new BeelineStrategy(drone->GetPosition(), nearestRechargeStation->GetPosition()));
    drone->SetToTargetDestStrategy(NULL);
  }

}

void BatteryDroneDecorator::GetNearestRechargeStation(std::vector<IEntity*> stations) {

  float minDis = std::numeric_limits<float>::max();
  for (auto entity : stations) {
    if (entity->GetAvailability()) {
      float disToEntity = drone->GetPosition().Distance(entity->GetPosition());
      if (disToEntity <= minDis) {
        minDis = disToEntity;
        nearestRechargeStation = entity;
      }
    }
  }

  if (nearestRechargeStation) {
    std::cout << "Found recharge station " << minDis << " away" << std::endl;
  }

  return; 
}

