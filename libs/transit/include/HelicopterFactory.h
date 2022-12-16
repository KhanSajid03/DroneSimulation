#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Helicopter.h"

#include <vector>

/**
 * @brief This class serves as a factory for the Helicopter class
 */
class HelicopterFactory : public IEntityFactory {
 public:
    /**
    * 
    * @brief virtual destructor
    * 
    */
    virtual ~HelicopterFactory() {}

    /**
     * @brief Creates and returns a new helicopter object
     * 
     * @param entity Json Object containing details for the helicopter.
     * @return helicopter object configured as per entity Json Object
     */
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
