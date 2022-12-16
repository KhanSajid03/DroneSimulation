#ifndef LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"
/**
 * @brief class used to manage jump celebration
 */
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief JumpDecorator constructor
   * @param strategy_
   */
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
   * @brief Check if the celebration is complete
   * @return a bool value
   */
  bool IsCompleted();
  /**
   * @brief move function for the entity
   * @param entity for the entity that is moving
   * @param dt time variable
   */
  void Move(IEntity* entity, double dt);
};

#endif  // LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
