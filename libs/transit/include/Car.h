#ifndef CAR_H_
#define CAR_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

class Car : public IEntity {
 public:
  /**
   * Constructor, creates Car object
   * 
   * @param obj Json Object containing configuration details for Car
   */
  Car(JsonObject& obj);

  /**
   * Destructor
   */
  ~Car();

  /**
   * Getter for car speed
   * 
   * @return float representing car speed
   */
  float GetSpeed() const { return speed; }

  /**
   * Getter for car position
   * 
   * @return Vector3 representing car position
   */
  Vector3 GetPosition() const { return position; }

  /**
   * Getter for car direction
   * 
   * @return Vector3 representing car direction
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * Getter for car destination
   * 
   * @return Vector3 representing car destination
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * Getter for car details Json object
   * 
   * @return JsonObject representing car details
   */
  JsonObject GetDetails() const { return details; }

  /**
   * Getter for car availability attribute
   * 
   * @return JsonObject representing car availability
   */
  bool GetAvailability() const { return available; }
  /**
   * Get the nearest entity from list of entity objects
   * 
   * @param entities list of entity objects
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler) override {}

  /**
   * Updates the entity
   * 
   * @param entities list of entity objects
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * Setter for car position
   * 
   * @param pos__ vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * Setter for car direction
   * 
   * @param dir__ vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * Setter for car destination
   * 
   * @param des__ vector3 representing new destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * Rotate function
   * 
   * @param angle double representing new angle
   */
  void Rotate(double angle);

  /**
   * Car object initialization
   * 
   * @param Car& car object
   */
  Car(const Car& car) = delete;

  /**
   * Car object equals operator
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
#endif
