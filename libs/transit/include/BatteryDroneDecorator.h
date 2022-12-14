#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include <vector>

#include "BeelineStrategy.h"
#include "BaseDroneDecorator.h"

class BatteryDroneDecorator : public BaseDroneDecorator {
 public:
  BatteryDroneDecorator(Drone* drone) : BaseDroneDecorator(drone) {}
  // TODO: destructor??

  ~BatteryDroneDecorator();

  void CalculateBatteryLevel(); // calculating the battery level based on the distance required to complete the trip

  void Update(double dt, std::vector<IEntity*> scheduler, std::vector<IEntity*> stations);
  void GetNearestEntity(std::vector<IEntity*> scheduler, std::vector<IEntity*> stations);
  void GetNearestRechargeStation(std::vector<IEntity*> stations);
  bool hasEnoughBatteryForDist(float dist);

  bool IsBatteryDrone() override { return true; }

 protected:
  float batteryLevel = 50.0;
  float BATTERY_RATE = 0.25;
  IEntity* nearestRechargeStation;
  bool onRechargeMission = false;

  Vector3 targetPos;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};  

#endif  // BATTERY_DECORATOR_H_