#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_
#include "BatteryDecorator.h"

#include <vector>

#include "IEntity.h"

class BatteryDecorator : public IEntity {
 public:
  BatteryDecorator(IEntity *entity) {
    BatteryLevel = 100.0;
  }

void Update(IEntity *entity, double dt) {}
void CalculateBatteryLevel() {}

 protected:
  float BatteryLevel;
};

#endif  // Battery_DECORATOR_H_