#include "BatteryDecorator.h"
#include "AstarStrategy.h" // need to implement for all strategies
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "SpinDecorator.h"
#include "JumpDecorator.h"


BatteryDecorator::BatteryDecorator(Drone *drone, RechargeStation* stations) {
  this->drone = drone;
  this->stations = stations;
}

void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
  if (drone->GetAvailability() && batteryLevel > 1) {
    batteryLevel -= 0.01;
  }
  timeSinceLastBatteryLevelPrint += dt;
  std::cout << "timeSinceLastBatteryLevelPrint: " <<  timeSinceLastBatteryLevelPrint << std::endl;
  if (timeSinceLastBatteryLevelPrint > 1.0) {
    std::cout << "Battery Level: " << batteryLevel << std::endl;
    timeSinceLastBatteryLevelPrint = 0.0;
  }
  if (batteryLevel > 50) { // within threshold
    drone->Update(dt, scheduler);
  }
  else {
    if(nearestEntity) { // checking that recharge station exists
      nearestEntity->SetAvailability(false);
      destination = nearestEntity->GetPosition(); // getting position of recharge station

    }
  }
}

void BatteryDecorator::GetNearestRechargeStation(std::vector<RechargeStation*> stations) {
  float minDis = std::numeric_limits<float>::max();
  for (auto entity : stations) {
    if (entity->GetAvailability()) {
      float disToEntity = this->position.Distance(entity->GetPosition());
      if (disToEntity <= minDis) {
        minDis = disToEntity;
        nearestEntity = entity;
      }
    }
  }
  if(nearestEntity) { // if RechargeStation exists, Beeline to it
    nearestEntity->SetAvailability(false); // not available anymore
    destination = nearestEntity->GetPosition();
    toTargetPosStrategy = new BeelineStrategy(this->GetPosition(), destination);
  }
}

