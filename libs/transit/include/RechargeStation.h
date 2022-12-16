
#ifndef LIBS_TRANSIT_INCLUDE_RECHARGESTATION_H_
#define LIBS_TRANSIT_INCLUDE_RECHARGESTATION_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a RechargeStation in a physical system.
// RechargeStations move using euler integration based on a specified
// velocity and direction.
class RechargeStation : public IEntity {
 public:
  /**
   * @brief Constructor.
   * @param obj JsonObject containing specifications.
   */
  RechargeStation(const JsonObject& obj);
  /**
   * @brief Destructor.
   */
  ~RechargeStation();
  /**
   * @brief Getter for entity's speed.
   * @return float representing entity's speed.
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Getter for entity's position.
   * @return Vector3 representing entity's position.
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Getter for entity's direction.
   * @return Vector3 representing entity's direction.
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Getter for entity's destination.
   * @return Vector3 representing entity's destination.
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Getter for entity's details.
   * @return JsonObject representing entity's details.
   */
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Getter for recharge station's availability
   * @return true if recharge station is available, false otherwise
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Setter for Entity position
   * 
   * @param pos__ vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Setter for Entity direction
   * 
   * @param dir__ vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Setter for Entity destination
   * 
   * @param des__ vector3 representing new destination
   */
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

#endif  // LIBS_TRANSIT_INCLUDE_RECHARGESTATION_H_

