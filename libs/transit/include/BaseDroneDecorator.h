#ifndef BASE_DRONE_DECORATOR_H_
#define BASE_DRONE_DECORATOR_H_

#include <vector>

#include "Drone.h"
#include "IStrategy.h"
#include "IEntity.h"
#include "math/vector3.h"

/**
 * @brief Base Class for Decorator wrappers on drone objects.
 */
class BaseDroneDecorator : public IEntity {
 public:
  BaseDroneDecorator(Drone* drone);
  ~BaseDroneDecorator();
  /**
   * @brief Getter for drone's speed
   * @return the float speed value
   */
  virtual float GetSpeed() const { return drone->GetSpeed(); }
  /**
   * @brief Getter for drone's position
   * @return the Vector3 position value
   */
  virtual Vector3 GetPosition() const { return drone->GetPosition(); }
  /**
   * @brief Getter for drone's direction
   * @return the Vector3 direction value
   */
  virtual Vector3 GetDirection() const { return drone->GetDirection(); }
  /**
   * @brief Getter for drone's destination
   * @return the Vector3 destination value
   */
  virtual Vector3 GetDestination() const { return drone->GetDestination(); }
  /**
   * @brief Getter for drone's JsonObject
   * @return the details JsonObject 
   */
  virtual JsonObject GetDetails() const { return drone->GetDetails(); }
  /**
   * @brief Getter for drone's availability
   * @return true if drone is available, false otherwise
   */
  virtual bool GetAvailability() const { return drone->GetAvailability(); }
  /**
   * @brief Setter for drone's position
   * @param pos_ new position Vector3 value
   */
  virtual void SetPosition(Vector3 pos_) { drone->SetPosition(pos_); }
  /**
   * @brief Setter for drone's direction
   * @param dir_ new direction Vector3 value
   */
  virtual void SetDirection(Vector3 dir_) { drone->SetDirection(dir_); }
  /**
   * @brief Setter for drone's destination
   * @param des_ new destination Vector3 value
   */
  virtual void SetDestination(Vector3 des_) { drone->SetDestination(des_); }
  /**
   * @brief Setter for graph
   * @param graph IGraph* graph value
   */
  virtual void SetGraph(const IGraph* graph) override { this->graph = graph; drone->SetGraph(graph); }

 protected:
    Drone* drone = NULL;
}; 

#endif  // BATTERY_DECORATOR_H_
