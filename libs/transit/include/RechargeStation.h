#ifndef RECHARGE_STATION_H_
#define RECHARGE_STATION_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
class RechargeStation : public IEntity {
 public:
  /**
   * Constructor, creates Drone object
   * 
   * @param obj Json Object containing configuration details for Car
   */
  RechargeStation(JsonObject& obj);

  /**
   * Destructor for RechargeStation
   */
  ~RechargeStation();

  /**
   * Getter for RechargeStation speed
   * 
   * @return float representing car speed
   */
  float GetSpeed() const { return speed; }

  /**
   * Getter for RechargeStation position
   * 
   * @return Vector3 representing RechargeStation position
   */
  Vector3 GetPosition() const { return position; }

  /**
   * Getter for RechargeStation Direction
   * 
   * @return Vector3 representing RechargeStation Direction.
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * Getter for RechargeStation Destination
   * 
   * @return Vector3 representing RechargeStation Destination.
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * Getter for RechargeStation details Json object
   * 
   * @return JsonObject representing RechargeStation details
   */
  JsonObject GetDetails() const { return details; }

  /**
   * Getter for RechargeStation availability attribute
   * 
   * @return JsonObject representing RechargeStation availability
   */
  bool GetAvailability() const { return available; }

  /**
   * Get the nearest entity from list of entity objects
   * 
   * @param entities list of entity objects
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * Updates the entity
   * 
   * @param entities list of entity objects
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * Setter for RechargeStation position
   * 
   * @param pos__ vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * Setter for RechargeStation direction
   * 
   * @param dir__ vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * Setter for RechargeStation direction
   * 
   * @param dir__ vector3 representing new direction
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * Rotate function
   * 
   * @param angle double representing new angle
   */
  void Rotate(double angle);

  /**
   * RechargeStation object initialization
   * 
   * @param RechargeStation& RechargeStation object
   */
  RechargeStation(const RechargeStation& rechargestation) = delete;

  /**
   * RechargeStation object equals operator
   * 
   * @param const RechargeStation& RechargeStation object
   */
  RechargeStation& operator=(const RechargeStation& rechargestation) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName = "beeline";
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif
