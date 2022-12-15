#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include <vector>

#include "BeelineStrategy.h"
#include "BaseDroneDecorator.h"

class BatteryDroneDecorator : public BaseDroneDecorator {
 public:
  /**
   * Constructor for BatteryDroneDecorator
   * 
   */
  BatteryDroneDecorator(Drone* drone) : BaseDroneDecorator(drone) {}
  /**
   * Destructor for BatteryDroneDecorator
   * 
   */
  ~BatteryDroneDecorator();

  void Update(double dt, std::vector<IEntity*> scheduler, std::vector<IEntity*> stations);
  void GetNearestEntity(std::vector<IEntity*> scheduler, std::vector<IEntity*> stations);
  void GetNearestRechargeStation(std::vector<IEntity*> stations);
  bool hasEnoughBatteryForDist(float dist);
  bool IsBatteryDrone() override { return true; }

 protected:
  float batteryLevel = 50.0;
  const float BATTERY_RATE = 0.25;
  const float BATTERY_CHARGING_RATE = 10.0;
  const float BATTERY_BUFFER_ZONE = 25.0;
  IEntity* nearestRechargeStation;
  bool onRechargeMission = false;

  Vector3 targetPos;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};  

#endif  // BATTERY_DECORATOR_H_