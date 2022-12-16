#ifndef LIBS_TRANSIT_INCLUDE_ROBOT_H_
#define LIBS_TRANSIT_INCLUDE_ROBOT_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
/**
 * @brief class used to manage the Robot entity
 */
class Robot : public IEntity {
 public:
  /**
   * @brief Constructor
   * @param obj JsonObject
   */
  Robot(const JsonObject& obj);
  /**
   * @brief Virtual Destructor
   */
  ~Robot() override = default;
  /**
   * @brief Getter for Robot position
   * @return Vector3 representing Robot position
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Getter for Robot direction
   * @return Vector3 representing Robot direction
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Getter for Robot destination
   * @return Vector3 representing Robot destination
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Getter for Entity availability attribute
   * @return bool representing Entity availability
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Getter for Robot details Json object
   * @return JsonObject representing Robot details
   */
  JsonObject GetDetails() const override;
  /**
   * @brief Getter for Robot speed
   * @return the float speed value
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Getter for strategy name
   * @return string with strategy name
   */
  std::string GetStrategyName() {return strategyName;}
  /**
   * @brief Setter for strategy availability
   * @param bool
   */
  void SetAvailability(bool choice);
  /**
   * @brief Setter for Robot position
   * @param pos__ vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
   /**
   * @brief Setter for Robot direction
   * @param dir__ vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Setter for Robot destination
   * @param des__ vector3 representing new destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Setter for strategy name
   * @param strategyName_ new string for the name
   */
  void SetStrategyName(std::string strategyName_)
  { strategyName = strategyName_;}
  /**
   * @brief Rotate function
   * @param angle
   */
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOT_H_

