#ifndef LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;
/**
 * @brief class used to manage the various strategies
 */
class IStrategy {
 public:
        /**
         * @brief move funtion for the strategies
         * @param entity to be moved
         * @param dt time variable
         */
        virtual void Move(IEntity* entity, double dt) = 0;
        /**
         * @brief check if the movement is completed or not
         * @return bool value
         */
        virtual bool IsCompleted() = 0;
        /**
         * @brief getting the paths of the points
         * @return a vector of floats containing the paths
         */
        virtual std::vector<std::vector<float>> GetPath() { return path; }
 protected:
        std::vector<std::vector<float>> path;
        const IGraph* graph;
};

#endif  // LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
