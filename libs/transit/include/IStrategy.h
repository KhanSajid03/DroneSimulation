#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;

class IStrategy {
    public:
        virtual void Move(IEntity* entity, double dt) = 0;
        virtual bool IsCompleted() = 0;
        std::vector<std::vector<float>> getPath() { return path; }
    protected:
        // IGraph object to be used in the simulation.
        std::vector<std::vector<float>> path;
        const IGraph* graph;
}; //close class 

#endif // ISTRATEGY_H_