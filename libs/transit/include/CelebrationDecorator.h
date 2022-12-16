#ifndef LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_

#include <vector>

#include "IStrategy.h"
/**
 * @brief This class serves as a decorator for the varous celebrations
 */
class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief Construct a new Celebration Decorator object
   * 
   * @param strategy used
   */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }
  /**
   * @brief moves the entity
   * 
   * @param entity entity to be moved
   * @param dt distance moved
   */
  void Move(IEntity *entity, double dt);
  /**
   * @brief Gets the path of the strategy
   * @return a vector of floats
   */
  std::vector<std::vector<float>> GetPath()
  override { return strategy->GetPath(); }
  /**
   * @brief returns a boolean on if the movement was completed or not
   * @return a boolean confirming that the celebration has completed
   */
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
