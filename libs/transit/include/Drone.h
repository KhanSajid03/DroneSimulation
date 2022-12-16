#ifndef LIBS_TRANSIT_INCLUDE_DRONE_H_
#define LIBS_TRANSIT_INCLUDE_DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
/**
 * @brief this class inhertis from the IEntity class and is responsible for creating functionality for the drone entity.
 */
class Drone : public IEntity {
 public:
  /**
   * @brief Constructor, creates Drone object
   * @param obj Json Object containing configuration details for Drone
   */
  Drone(JsonObject& obj);
  /**
   * @brief Destructor
   */
  ~Drone();
  /**
   * @brief Getter for Drone speed
   * 
   * @return float representing Drone speed
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Getter for Drone position
   * 
   * @return Vector3 representing Drone position
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Getter for Drone direction
   * 
   * @return Vector3 representing Drone direction
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Getter for Drone destination
   * 
   * @return Vector3 representing Drone destination
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Getter for Drone details Json object
   * 
   * @return JsonObject representing Drone details
   */
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Getter for Drone availability attribute
   * 
   * @return bool representing Drone availability
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Get the nearest entity from list of entity objects
   * 
   * @param scheduler list of entity objects
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the entity
   * @param dt time variable
   * @param entities list of entity objects
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Setter for Drone position
   * 
   * @param pos__ vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Setter for Drone direction
   * 
   * @param dir__ vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Setter for Drone destination
   * 
   * @param des__ vector3 representing new destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Strategy to get to target position
   * 
   * @return return the strategy
   */
  IStrategy* GetToTargetPosStrategy() { return toTargetPosStrategy; }
  /**
   * @brief Strategy to get to destination
   * 
   * @return return the strategy
   */
  IStrategy* GetToTargetDestStrategy() { return toTargetDestStrategy; }
  /**
   * @brief Set strategy to get to positon
   * 
   * @param strategy
   */
  void SetToTargetPosStrategy(IStrategy* strategy) {
    this->toTargetPosStrategy = strategy; }
  /**
   * @brief Set strategy to get to target destination
   * 
   * @param strategy
   */
  void SetToTargetDestStrategy(IStrategy* strategy) {
    this->toTargetDestStrategy = strategy; }
  /**
   * @brief Rotate method for drone
   * 
   * @param angle
   */
  void Rotate(double angle);
  /**
   * @brief Jump method for drone
   * 
   * @param height
   */
  void Jump(double height);
  /**
   * @brief Copy constructor for drone
   * 
   * @param drone
   */
  Drone(const Drone& drone) = delete;
  /**
   * @brief assignment operator for drone
   * 
   * @param drone
   */
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONE_H_
