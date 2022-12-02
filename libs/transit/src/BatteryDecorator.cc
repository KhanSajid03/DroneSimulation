#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include <vector>

#include "IStrategy.h"

class BatteryDecorator : public IEntity {
 public:
  BatteryDecorator(IEntity *entity) {
    strategy = strategy_;
    time = 0;
  }
  // all entity functions
  // void Update()
  // calculate battery required to calculate distance
  // 

 protected:
  IStrategy *strategy;
  float time;
  // BL float
};  // close class

#endif  // Battery_DECORATOR_H_