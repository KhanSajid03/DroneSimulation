#ifndef CREEPER_FACTORY_H_
#define CREEPER_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Creeper.h"  

#include <vector>

/**
 * @brief This class serves as a factory for the Creeper class
 */
class CreeperFactory : public IEntityFactory {
  public:
    /**
     * Creates and returns a new Creeper object
     * 
     * @param entity Json Object containing details for the creeper 
     * @return creeper object configured as per entity Json Object
     */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif