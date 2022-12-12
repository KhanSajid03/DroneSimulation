#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include <vector>

#include "Drone.h"
#include "IStrategy.h"

class BatteryDecorator : public IEntity {
 public:
  BatteryDecorator(Drone* drone);
  void Update(double dt, std::vector<IEntity*> scheduler);
  void CalculateBatteryLevel(); // calculating the battery level based on the distance required to complete the trip

  // FUNCTIONS FROM IEntity
  float GetSpeed() const { return drone->GetSpeed(); }
  Vector3 GetPosition() const { return drone->GetPosition(); }
  Vector3 GetDirection() const { return drone->GetDirection(); }
  Vector3 GetDestination() const { return drone->GetDestination(); }
  JsonObject GetDetails() const { return drone->GetDetails(); }
  bool GetAvailability() const { return drone->GetAvailability(); }
  void GetNearestEntity(std::vector<IEntity*> scheduler) { return drone->GetNearestEntity(scheduler); }
  void SetPosition(Vector3 pos_) { drone->SetPosition(pos_); }
  void SetDirection(Vector3 dir_) { drone->SetDirection(dir_); }
  void SetDestination(Vector3 des_) { drone->SetDestination(des_); }

  /**
   * Check if entity is drone, returns true in this case
   * 
   * @return true, since the object is a drone
   */
  bool IsDrone() override { return drone->IsDrone(); }

 protected:
  float batteryLevel = 100;
  Drone* drone = NULL;
};  // close class

#endif  // BATTERY_DECORATOR_H_