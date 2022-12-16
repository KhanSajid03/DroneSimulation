#ifndef LIBS_TRANSIT_INCLUDE_CAR_H_
#define LIBS_TRANSIT_INCLUDE_CAR_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inhertis from the IEntity class and is responsible for creating functionality for the car entity.
 */
class Car : public IEntity {
 public:
  /**
   * @brief Constructor, creates Car object
   * @param obj Json Object containing configuration details for Car
   */
  Car(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Car();

  /**
   * @brief Getter for car speed
   * 
   * @return float representing car speed
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Getter for car position
   * 
   * @return Vector3 representing car position
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Getter for car direction
   * 
   * @return Vector3 representing car direction
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Getter for car destination
   * 
   * @return Vector3 representing car destination
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Getter for car details Json object
   * 
   * @return JsonObject representing car details
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Getter for car availability attribute
   * 
   * @return JsonObject representing car availability
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Get the nearest entity from list of entity objects
   * 
   * @param entities list of entity objects
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the entity
   * 
   * @param entities list of entity objects
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Setter for car position
   * 
   * @param pos__ vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Setter for car direction
   * 
   * @param dir__ vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Setter for car destination
   * 
   * @param des__ vector3 representing new destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Rotate function
   * 
   * @param angle double representing new angle
   */
  void Rotate(double angle);

  /**
   * @brief Car object initialization
   * 
   * @param Car& car object
   */
  Car(const Car& car) = delete;

  /**
   * @brief Car object equals operator
   * 
   * @param const Car& car object
   */
  Car& operator=(const Car& car) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName = "astar";
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
};
#endif  // LIBS_TRANSIT_INCLUDE_CAR_H_
