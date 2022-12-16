#ifndef LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for generating the astar that the drone will take.
 */
class AstarStrategy : public IStrategy {
 public:
    /**
     * @brief constructor
     * @param position of entity
     * @param destination of entity
     * @param graph object
     **/
    AstarStrategy(Vector3 position, Vector3 destination,
     const IGraph* graph);
    /**
     * @brief destructor
     **/
    ~AstarStrategy();
    /**
     * @brief moves the inputted entity
     * @param entity is the entity that will be moved
     * @param dt is the distance that the entity will be moved
     **/
    void Move(IEntity* entity, double dt);
    /**
     * @brief returns a boolean on if the movement was completed or not
     * @return returns a boolean regarding whether the movement is completed.
     **/
    bool IsCompleted();

 private:
    int currentIndex;
        int maxIndex;
};
#endif  // LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_
