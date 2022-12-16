#ifndef LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"
#include "BatteryDroneDecorator.h"

#include <vector>
/**
 * @brief This class serves as a factory for the Drone class
 */
class DroneFactory : public IEntityFactory {
 public:
    /**
    * 
    * @brief virtual destructor
    * 
    */
    virtual ~DroneFactory() {}
    /**
     * @brief Creates and returns a new drone object
     * 
     * @param entity Json Object containing details for the drone 
     * @return drone object configured as per entity Json Object
     */
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
