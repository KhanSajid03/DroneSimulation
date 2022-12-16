#ifndef LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_

#include "util/json.h"

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"
/**
 * @brief This class serves as a factory for the IEntity class
 */
class IEntityFactory {
 public:
    /**
    * @brief virtual destructor
    */
    virtual ~IEntityFactory() {}
     /**
     * @brief Creates and returns a new entity object
     * @param entity Json Object containing details for the entity.
     * @return entity object configured as per entity Json Object
     */
    virtual IEntity* CreateEntity(const JsonObject& entity) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
