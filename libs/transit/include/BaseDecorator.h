#ifndef BASE_DECORATOR_H_
#define BASE_DECORATOR_H_

#include <vector>

#include "IEntity.h"

class BaseDecorator : public IEntity {
 public:
  BaseDecorator(IEntity* drone_) {
    drone = drone_;
  }
  void Update(double dt, IEntity *entity);

 protected:
  IEntity *drone;
};  // close class

#endif  // BASE_DECORATOR_H_