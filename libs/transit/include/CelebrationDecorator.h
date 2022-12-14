#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include <vector>

#include "IStrategy.h"

class CelebrationDecorator : public IStrategy {
 public:
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }
  void Move(IEntity *entity, double dt);
  std::vector<std::vector<float>> GetPath() override { return strategy->GetPath(); }
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};  // close class

#endif  // CELEBRATION_DECORATOR_H_


// TODO: do we need destructor?
