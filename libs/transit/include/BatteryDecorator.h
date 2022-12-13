#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include <vector>

#include "Drone.h"
#include "IStrategy.h"
#include "RechargeStation.h"

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
  void GetNearestEntity(std::vector<IEntity*> scheduler);
  void SetPosition(Vector3 pos_) { drone->SetPosition(pos_); }
  void SetDirection(Vector3 dir_) { drone->SetDirection(dir_); }
  void SetDestination(Vector3 des_) { drone->SetDestination(des_); }
  virtual std::string GetStrategyName(){ return drone->GetStrategyName(); }
  virtual void SetAvailability(bool choice) { drone->SetAvailability(choice); }
  void SetGraph(const IGraph* graph) override { this->graph = graph; drone->SetGraph(graph); }
  virtual void SetStrategyName(std::string strategyName_){ drone->SetStrategyName(strategyName_); }
  virtual void Rotate(double angle) { drone->Rotate(angle); }
  virtual void Jump(double height) { drone->Jump(height); }

  void GetNearestRechargeStation();
  bool hasEnoughBatteryForDist(float dist);

  /**
   * Check if entity is drone, returns true in this case
   * 
   * @return true, since the object is a drone
   */
  bool IsDrone() override { return drone->IsDrone(); }

 protected:
  float batteryLevel = 100;
  double timeSinceLastBatteryLevelPrint = 0;
  float BATTERY_RATE = 1.0;
  RechargeStation* nearestRechargeStation;
  Drone* drone = NULL;
  bool onRechargeMission = false;
};  // close class

#endif  // BATTERY_DECORATOR_H_