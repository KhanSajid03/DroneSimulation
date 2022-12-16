#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTER_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a Helicopter in a physical system.
// Helicopters move using euler integration based on a specified
// velocity and direction.
/**
 * @brief this class inhertis from the IEntity class and is responsible for creating functionality for the helicopter entity.
 */
class Helicopter : public IEntity {
 public:
  /**
   * @brief Constructor, creates Helicopter object
   * 
   * @param obj Json Object containing configuration details for Helicopter
   */
  Helicopter(const JsonObject& obj);

  /**
   * @brief Destructor for Helicopter
   */
  ~Helicopter();

  /**
   * @brief Getter for helicopter speed
   * 
   * @return float representing Helicopter speed
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Getter for Helicopter position
   * 
   * @return Vector3 representing Helicopter position
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Getter for Helicopter Direction
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
   * @brief Getter for helicopter details Json object
   * 
   * @return JsonObject representing helicopter details
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Getter for helicopter availability attribute
   * 
   * @return JsonObject representing helicopter availability
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
   * @param scheduler list of entity objects
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Setter for helicopter position
   * 
   * @param pos__ vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Setter for helicopter direction
   * 
   * @param dir__ vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Setter for helicopter direction
   * 
   * @param dir__ vector3 representing new direction
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Rotate function
   * 
   * @param angle double representing new angle
   */
  void Rotate(double angle);

  /**
   * @brief Helicopter object initialization
   * 
   * @param Helicopter& helicopter object
   */
  Helicopter(const Helicopter& helicopter) = delete;

  /**
   * @brief Helicopter object equals operator
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

#endif  // LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
