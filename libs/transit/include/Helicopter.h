#ifndef HELICOPTER_H_
#define HELICOPTER_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
class Helicopter : public IEntity {
 public:
  /**
   * Constructor, creates Drone object
   * 
   * @param obj Json Object containing configuration details for Car
   */
  Helicopter(JsonObject& obj);

  /**
   * Destructor for Helicopter
   */
  ~Helicopter();

  /**
   * Getter for helicopter speed
   * 
   * @return float representing car speed
   */
  float GetSpeed() const { return speed; }

  /**
   * Getter for Helicopter position
   * 
   * @return Vector3 representing Helicopter position
   */
  Vector3 GetPosition() const { return position; }

  /**
   * Getter for Helicopter Direction
   * 
   * @return Vector3 representing Helicopter Direction.
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * Getter for Helcopter Destination
   * 
   * @return Vector3 representing Helcopter Destination.
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * Getter for helicopter details Json object
   * 
   * @return JsonObject representing helicopter details
   */
  JsonObject GetDetails() const { return details; }

  /**
   * Getter for helicopter availability attribute
   * 
   * @return JsonObject representing helicopter availability
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
   * Setter for helicopter position
   * 
   * @param pos__ vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * Setter for helicopter direction
   * 
   * @param dir__ vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * Setter for helicopter direction
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
   * Helicopter object initialization
   * 
   * @param Helicopter& helicopter object
   */
  Helicopter(const Helicopter& helicopter) = delete;

  /**
   * Helicopter object equals operator
   * 
   * @param const Helicopter& helicopter object
   */
  Helicopter& operator=(const Helicopter& helicopter) = delete;

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
