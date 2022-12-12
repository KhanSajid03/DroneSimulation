
#include "BatteryDecorator.h"


BatteryDecorator::BatteryDecorator(Drone *drone) {
  this->drone = drone;
}


void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler) {

  if (batteryLevel > 0) {
    batteryLevel -= 0.1;
  }
  std::cout << "Battery Level: " << batteryLevel << std::endl;

  // float minDis = std::numeric_limits<float>::max();
  // if (entity->GetAvailability()) {
  //   // float disToEntity = this->GetPosition().Distance(entity->GetPosition()); // calculating the distance from current entity to robot
    
  // }

}

void BatteryDecorator::CalculateBatteryLevel() {
  
}


