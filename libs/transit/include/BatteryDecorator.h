#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"

class BatteryDecorator : public IEntity {
 public:
  BatteryDecorator(IEntity *entity) {}
  void Update(IEntity *entity, double dt);
  void CalculateBatteryLevel(float BatteryLevel); // calculating the battery level based on the distance required to complete the trip

 protected:
  float BatteryLevel;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
  Vector3 destination;

};  // close class

#endif  // BATTERY_DECORATOR_H_