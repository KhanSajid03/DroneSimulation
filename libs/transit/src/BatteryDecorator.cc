
#include "BatteryDecorator.h"


BatteryDecorator::BatteryDecorator(Drone *drone) {
  this->drone = drone;
}


void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler) {

  if (drone->GetSpeed() > 0.5 && batteryLevel > 1) {
    batteryLevel -= 0.01;
  }

  timeSinceLastBatteryLevelPrint += dt;
  if (timeSinceLastBatteryLevelPrint > 1.0) {
    std::cout << "Battery Level: " << batteryLevel << std::endl;
    timeSinceLastBatteryLevelPrint = 0.0;
  }

  drone->Update(dt, scheduler);
  
  // float minDis = std::numeric_limits<float>::max();
  // if (entity->GetAvailability()) {
  //   // float disToEntity = this->GetPosition().Distance(entity->GetPosition()); // calculating the distance from current entity to robot
    
  // }

}

void BatteryDecorator::CalculateBatteryLevel() {
  
}


