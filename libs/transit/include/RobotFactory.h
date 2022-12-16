#ifndef LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>

/**
 * @brief This class serves as a factory for the Robot class
 */
class RobotFactory : public IEntityFactory {
 public:
    /**
     * @brief Creates and returns a new Robot object
     * 
     * @param entity Json Object containing details for the Robot.
     * @return Robot object configured as per entity Json Object
     */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
