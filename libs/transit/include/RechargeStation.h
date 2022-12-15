
#ifndef RECHARGE_STATION_H_
#define RECHARGE_STATION_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a RechargeStation in a physical system.
// RechargeStations move using euler integration based on a specified
// velocity and direction.
class RechargeStation : public IEntity {
 public:
  // RechargeStations are created with a name
  RechargeStation(JsonObject& obj);
  // Destructor
  ~RechargeStation();

  float GetSpeed() const { return speed; }

  // Gets the RechargeStation position
  Vector3 GetPosition() const { return position; }

  Vector3 GetDirection() const { return direction; }

  Vector3 GetDestination() const { return destination; }

  JsonObject GetDetails() const { return details; }

  bool GetAvailability() const { return available; }

  void SetPosition(Vector3 pos_) { position = pos_; }

  void SetDirection(Vector3 dir_) { direction = dir_; }

  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * Check if entity is RechargeStation, returns true in this case
   * 
   * @return true, since the object is a RechargeStation
   */
  bool isRechargeStation() override { return true; }


 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
};

#endif

