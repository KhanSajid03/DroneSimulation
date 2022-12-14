#ifndef BASE_DRONE_DECORATOR_H_
#define BASE_DRONE_DECORATOR_H_

#include <vector>

#include "Drone.h"
#include "IStrategy.h"
#include "IEntity.h"
#include "math/vector3.h"

class BaseDroneDecorator : public IEntity {
 public:
  BaseDroneDecorator(Drone* drone);
  ~BaseDroneDecorator();
  
  // functions from IEntity
  virtual float GetSpeed() const { return drone->GetSpeed(); }
  virtual Vector3 GetPosition() const { return drone->GetPosition(); }
  virtual Vector3 GetDirection() const { return drone->GetDirection(); }
  virtual Vector3 GetDestination() const { return drone->GetDestination(); }
  virtual JsonObject GetDetails() const { return drone->GetDetails(); }
  virtual bool GetAvailability() const { return drone->GetAvailability(); }
  virtual void SetPosition(Vector3 pos_) { drone->SetPosition(pos_); }
  virtual void SetDirection(Vector3 dir_) { drone->SetDirection(dir_); }
  virtual void SetDestination(Vector3 des_) { drone->SetDestination(des_); }
  virtual std::string GetStrategyName() { return drone->GetStrategyName(); }
  virtual void SetAvailability(bool choice) { drone->SetAvailability(choice); }
  virtual void SetGraph(const IGraph* graph) override { this->graph = graph; drone->SetGraph(graph); }
  virtual void SetStrategyName(std::string strategyName_){ drone->SetStrategyName(strategyName_); }
  virtual void Rotate(double angle) { drone->Rotate(angle); }
  virtual void Jump(double height) { drone->Jump(height); }
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}

 protected:
    Drone* drone = NULL;

}; 

#endif  // BATTERY_DECORATOR_H_