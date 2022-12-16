#ifndef LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_

#include "IEntityFactory.h"
/**
 * @brief This class serves as a factory to create entities
 */
class CompositeFactory : public IEntityFactory {
 public:
    /**
    * @brief Functionality to create entity
    * @param entity Json Object containing configuration details
    * @return return an IEntity* object
    */
    IEntity* CreateEntity(JsonObject& entity);
    /**
    * @brief Functionality to add factory
    * @param factoryEntity IEntityFactory* Object containing configuration details
    */
    void AddFactory(IEntityFactory* factoryEntity);
    /**
    * @brief virtual destructor
    */
    virtual ~CompositeFactory();
 private:
    std::vector<IEntityFactory*> componentFactories;
};

#endif  // LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
