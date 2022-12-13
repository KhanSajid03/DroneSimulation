#include "BatteryDecorator.h"
#include "AstarStrategy.h" // need to implement for all strategies
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "SpinDecorator.h"
#include "JumpDecorator.h"

void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler, std::vector<IEntity*> stations) {
  if (drone->GetAvailability() && batteryLevel > 1) {
    batteryLevel -= 0.01;
  }
  timeSinceLastBatteryLevelPrint += dt;
  std::cout << "timeSinceLastBatteryLevelPrint: " <<  timeSinceLastBatteryLevelPrint << std::endl;
  if (timeSinceLastBatteryLevelPrint > 1.0) {
    std::cout << "Battery Level: " << batteryLevel << std::endl;
    timeSinceLastBatteryLevelPrint = 0.0;
  }
  std::cout << "UPdating Battery drone."

  if (batteryLevel > 250) { // within threshold
    drone->Update(dt, scheduler);
  }
  else {
    GetNearestRechargeStation(stations);
    if(nearestRechargeEntity) { // checking that recharge station exists
      nearestRechargeEntity->SetAvailability(false);
      destination = nearestRechargeEntity->GetPosition(); // getting position of recharge station
      toTargetPosStrategy = new BeelineStrategy(this->GetPosition(), destination);
    }
    else {
      std::cout << "couldn't fetch nearest recharge station. Line 28. \n";
    }
  }
}

void BatteryDecorator::GetNearestRechargeStation(std::vector<IEntity*> stations) {
  float minDis = std::numeric_limits<float>::max();
  for (auto entity : stations) {
    if (entity->GetAvailability()) {
      float disToEntity = this->position.Distance(entity->GetPosition());
      if (disToEntity <= minDis) {
        minDis = disToEntity;
        nearestRechargeEntity = entity;
      }
    }
  }
  return; 
}

  

