#ifndef LIBS_TRANSIT_INCLUDE_BATTERYDRONEDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_BATTERYDRONEDECORATOR_H_

#include <vector>

#include "BeelineStrategy.h"
#include "BaseDroneDecorator.h"

/**
 * @brief Decorator for drone objects that handles drone's battery capabilities.
 */
class BatteryDroneDecorator : public BaseDroneDecorator {
 public:
  /**
   * @brief Constructor for BatteryDroneDecorator.
   */
  BatteryDroneDecorator(Drone* drone) : BaseDroneDecorator(drone) {}
  /**
   * @brief Destructor for BatteryDroneDecorator.
   */
  ~BatteryDroneDecorator();
  /**
   * @brief Wrapper for drone update function; accepts new requests, moves drone, etc.
   * @param dt Time delta from last update.
   * @param scheduler Vector of all robot objects.
   * @param stations Vector of all recharge station objects.
   */
  void Update(double dt, std::vector<IEntity*> scheduler,
  std::vector<IEntity*> stations);
  /**
   * @brief Wrapper for drone GetNearestEntity function. Finds nearest robot entity.
   * @param scheduler Vector of all robots.
   * @param stations Vector of stations.
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler,
  std::vector<IEntity*> stations);
  /**
   * @brief Finds nearest recharge station.
   * @param stations Vector of all recharge station objects.
   */
  void GetNearestRechargeStation(std::vector<IEntity*> stations);
  /**
   * @brief Determines whether drone has enough battery to complete a trip of a certain distance.
   * @param dist Trip distance.
   * @return true if drone has enough battery for the trip; false otherwise
   */
  bool hasEnoughBatteryForDist(float dist);
  /**
   * @brief Determines whether object from which function is called is a battery drone.
   * @return true
   */
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

#endif  // LIBS_TRANSIT_INCLUDE_BATTERYDRONEDECORATOR_H_
