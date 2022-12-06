#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include <vector>

#include "IEntity.h"

class BatteryDecorator : public IEntity {
 public:
  BatteryDecorator(IEntity *entitiy) : IEntity(entity_) {}
  void Update(IEntity *entity, double dt);
  void CalculateBatteryLevel(); // calculating the battery level based on the distance required to complete the trip

 protected:
  float BatteryLevel;
};  // close class

#endif  // BATTERY_DECORATOR_H_