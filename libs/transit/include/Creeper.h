#ifndef CREEPER_H
#define CREEPER_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "Drone.h"

/**
 * @brief This class implements IEntity and is responsible for handling the Creeper: an entity that continually seeks to hover over the drone, following around the drone from above, using the beeline algorithm
 */ 
class Creeper : public IEntity {
 public:

  /**
   * Constructor, creates Creeper object
   * 
   * @param obj Json Object containing configuration details for Creeper
   */
  Creeper(JsonObject& obj);

  /**
   * Destructor
   */
  ~Creeper() override = default;

  /**
   * Getter for creeper position
   * 
   * @return Vector3 representing creeper position
   */
  Vector3 GetPosition() const { return position; }

  /**
   * Getter for creeper direction
   * 
   * @return Vector3 representing creeper direction
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * Getter for creeper destination
   * 
   * @return Vector3 representing creeper destination
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * Getter for creeper details Json object
   * 
   * @return JsonObject representing creeper details
   */
  JsonObject GetDetails() const override;

  /**
   * Getter for creeper speed
   * 
   * @return float representing creeper speed
   */
  float GetSpeed() const { return speed; }

  /**
   * Setter for creeper position
   * 
   * @param pos__ vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * Setter for creeper direction
   * 
   * @param dir__ vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * Setter for creeper destination
   * 
   * @param des__ vector3 representing new destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * Finds the drone object, given a list of entity objects
   * 
   * @param entites list of entity objects
   */
  void FindDrone(std::vector<IEntity*> entites);

  /**
   * Updates creeper object such that it beelines toward the drone's position
   * 
   * @param dt time differential of update
   * @param entites list of entity objects
   */
  void Update(double dt, std::vector<IEntity*> entities);

  /**
   * Check if entity is creeper, returns true in this case
   * 
   * @return true, since the object is a creeper
   */
  bool IsCreeper() override { return true; }

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  Drone* drone = NULL;
  float speed;
  bool followingDrone = false;
};

#endif  
