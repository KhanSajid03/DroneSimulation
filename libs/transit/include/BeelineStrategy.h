#ifndef LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for generating the beeline that the drone will take.
 */
class BeelineStrategy : public IStrategy {
 public:
     /**
     * @brief constructor
     * @param position of entity
     * @param destination of entity
     **/
    BeelineStrategy(Vector3 position, Vector3 destination);
    /**
     * @brief destructor
     **/
    ~BeelineStrategy();
    /**
     * @brief moves the inputted entity
     * @param entity is the entity that will be moved
     * @param dt is the distance that the entity will be moved
     * @return void
     **/
    void Move(IEntity* entity, double dt);
    /**
     * @brief returns a boolean on if the movement was completed or not
     * @return returns a boolean regarding whether the movement is completed.
     **/
    bool IsCompleted();

 private:
    Vector3 position;
    Vector3 destination;
};
#endif  // LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
