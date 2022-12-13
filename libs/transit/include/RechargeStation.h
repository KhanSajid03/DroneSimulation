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

  void GetNearestEntity(std::vector<IEntity*> scheduler);

  // Updates the RechargeStation's position
  void Update(double dt, std::vector<IEntity*> scheduler);

  void SetPosition(Vector3 pos_) { position = pos_; }

  // Sets the RechargeStation's direction
  void SetDirection(Vector3 dir_) { direction = dir_; }

  void SetDestination(Vector3 des_) { destination = des_; }

  // Rotates a RechargeStation
  void Rotate(double angle);

  void Jump(double height);

  // /**
  //  * Check if entity is RechargeStation, returns true in this case
  //  * 
  //  * @return true, since the object is a RechargeStation
  //  */
  bool isRechargeStation() override { return true; }

  // Removing the copy constructor and assignment operator
  // so that RechargeStations cannot be coppied.
  RechargeStation(const RechargeStation& rechargestation) = delete;
  RechargeStation& operator=(const RechargeStation& rechargestation) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true; // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif




// #ifndef RECHARGE_STATION_H_
// #define RECHARGE_STATION_H_

// #include <vector>

// #include "IEntity.h"
// #include "IStrategy.h"
// #include "math/vector3.h"

// // Represents a RechargeStation in a physical system.
// // RechargeStations move using euler integration based on a specified
// // velocity and direction.
// class RechargeStation : public IEntity {
//  public:
//   /**
//    * Constructor, creates RechargeStation object
//    * 
//    * @param obj Json Object containing configuration details for Car
//    */
//   RechargeStation(JsonObject& obj);

//   /**
//    * Destructor for RechargeStation
//    */
//   ~RechargeStation();

//   /**
//    * Getter for RechargeStation speed
//    * 
//    * @return float representing car speed
//    */
//   float GetSpeed() const { return speed; }

//   /**
//    * Getter for RechargeStation position
//    * 
//    * @return Vector3 representing RechargeStation position
//    */
//   Vector3 GetPosition() const { return position; }

//   /**
//    * Getter for RechargeStation Direction
//    * 
//    * @return Vector3 representing RechargeStation Direction.
//    */
//   Vector3 GetDirection() const { return direction; }

//   /**
//    * Getter for RechargeStation Destination
//    * 
//    * @return Vector3 representing RechargeStation Destination.
//    */
//   Vector3 GetDestination() const { return destination; }

//   /**
//    * Getter for RechargeStation details Json object
//    * 
//    * @return JsonObject representing RechargeStation details
//    */
//   JsonObject GetDetails() const { return details; }

//   /**
//    * Getter for RechargeStation availability attribute
//    * 
//    * @return JsonObject representing RechargeStation availability
//    */
//   bool GetAvailability() const { return available; }

//   /**
//    * Get the nearest entity from list of entity objects
//    * 
//    * @param entities list of entity objects
//    */
//   void GetNearestEntity(std::vector<IEntity*> scheduler);

//   /**
//    * Setter for RechargeStation position
//    * 
//    * @param pos__ vector3 representing new position
//    */
//   void SetPosition(Vector3 pos_) { position = pos_; }

//   /**
//    * Setter for RechargeStation direction
//    * 
//    * @param dir__ vector3 representing new direction
//    */
//   void SetDirection(Vector3 dir_) { direction = dir_; }

//   /**
//    * Setter for RechargeStation direction
//    * 
//    * @param dir__ vector3 representing new direction
//    */
//   void SetDestination(Vector3 des_) { destination = des_; }

//   /**
//    * RechargeStation object initialization
//    * 
//    * @param RechargeStation& RechargeStation object
//    */
//   RechargeStation(const RechargeStation& rechargestation) = delete;

//   /**
//    * RechargeStation object equals operator
//    * 
//    * @param const RechargeStation& RechargeStation object
//    */
//   RechargeStation& operator=(const RechargeStation& rechargestation) = delete;

//  private:
//   JsonObject details;
//   Vector3 position;
//   Vector3 direction;
//   Vector3 destination;
//   float speed;
//   bool available;
//   bool pickedUp;
//   std::string strategyName = "beeline";
//   IEntity* nearestEntity = NULL;
//   IStrategy* toTargetPosStrategy = NULL;
//   IStrategy* toTargetDestStrategy = NULL;
// };

// #endif
