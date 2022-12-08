#ifndef HELICOPTER_FACTORY_H_
#define HELICOPTER_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Helicopter.h"

#include <vector>

/**
 * @brief This class serves as a factory for the Car class
 */
class HelicopterFactory : public IEntityFactory {
 public:
    /**
    * 
    * virtual destructor
    * 
    */
    virtual ~HelicopterFactory() {}

    /**
     * Creates and returns a new helicopter object
     * 
     * @param entity Json Object containing details for the helicopter.
     * @return helicopter object configured as per entity Json Object
     */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif
