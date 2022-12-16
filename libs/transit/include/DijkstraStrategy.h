#ifndef LIBS_TRANSIT_INCLUDE_DIJKSTRASTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_DIJKSTRASTRATEGY_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for generating the dijkstra that the drone will take.
 */
class DijkstraStrategy : public IStrategy {
 public:
    /**
     * @brief constructor
     * @param position of entity
     * @param destination of entity
     * @param graph object
     **/
    DijkstraStrategy(Vector3 position, Vector3 destination,
    const IGraph* graph);
    /**
     * @brief destructor
     **/
    ~DijkstraStrategy();
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
#endif  // LIBS_TRANSIT_INCLUDE_DIJKSTRASTRATEGY_H_
