#ifndef LIBS_TRANSIT_INCLUDE_IENTITY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
/**
 * @brief Abstract controller class used in Transit Service
 */
class IEntity {
 public:
  /**
   * @brief Constructor
   */
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  /**
   * @brief Virtual Destructor
   */
  virtual ~IEntity() {}
  /**
   * @brief Retrieves the ID
   * @return the int value of the ID
   */
  virtual int GetId() const { return id; }
  /**
   * @brief Getter for entity's position
   * 
   * @return Vector3 representing entity's position
   */
  virtual Vector3 GetPosition() const = 0;
  /**
   * @brief Getter for entity's direction
   * 
   * @return Vector3 representing entity's direction
   */
  virtual Vector3 GetDirection() const = 0;
  /**
   * @brief Getter for entity's destination
   * 
   * @return Vector3 representing entity's destination
   */
  virtual Vector3 GetDestination() const = 0;
  /**
   * @brief Getter for entity's details Json object
   * 
   * @return JsonObject representing entity's details
   */
  virtual JsonObject GetDetails() const = 0;
  /**
   * @brief Getter for entity's speed
   * @return the float speed value
   */
  virtual float GetSpeed() const = 0;
  /**
   * @brief Getter for entity availability attribute
   * 
   * @return bool representing Entity availability
   */
  virtual bool GetAvailability() const {}
  /**
   * @brief Getter for strategy name
   * 
   * @return string with strategy name
   */
  virtual std::string GetStrategyName() {}
  /**
   * @brief Setter for strategy availability
   * 
   * @param choice bool representing drone's availability
   */
  virtual void SetAvailability(bool choice) {}
  /**
   * @brief Update function
   * @param dt time variable
   * @param scheduler list of entity objects
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}
  /**
   * @brief Update function
   * @param dt time variable
   * @param scheduler list of entity objects
   * @param stations list of recharge stations
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler,
  std::vector<IEntity*> stations) {}
  /**
   * @brief function to set the graph
   * @param graph variable
   */
  virtual void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Setter for Entity position
   * 
   * @param pos__ vector3 representing new position
   */
  virtual void SetPosition(Vector3 pos_) {}
  /**
   * @brief Setter for Entity direction
   * 
   * @param dir__ vector3 representing new direction
   */
  virtual void SetDirection(Vector3 dir_) {}
  /**
   * @brief Setter for Entity destination
   * 
   * @param des__ vector3 representing new destination
   */
  virtual void SetDestination(Vector3 des_) {}
  /**
   * @brief Setter for strategy name
   * 
   * @param strategyName_ new string for the name
   */
  virtual void SetStrategyName(std::string strategyName_) {}
  /**
   * @brief Rotate function
   * @param angle
   */
  virtual void Rotate(double angle) {}
  /**
   * @brief Jump function
   * @param height
   */
  virtual void Jump(double height) {}

  /**
   * @brief Check if entity is a creeper
   * 
   * @return true if entity is a creeper, false otherwise
   */
  virtual bool IsCreeper() { return false; }

  /**
   * @brief Check if entity is a battery drone
   * 
   * @return true if entity is a battery drone, false otherwise
   */
  virtual bool IsBatteryDrone() { return false; }

  /**
   * @brief Check if entity is a RechargeStation
   * 
   * @return true if entity is a RechargeStation, false otherwise
   */
  virtual bool isRechargeStation() { return false; }


 protected:
  int id;
  const IGraph* graph;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITY_H_
