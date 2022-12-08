#ifndef CAR_FACTORY_H_
#define CAR_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Car.h"

#include <vector>

/**
 * @brief This class serves as a factory for the Car class
 */
class CarFactory : public IEntityFactory {
  public:
    /**
    * 
    * virtual destructor
    * 
    */
    virtual ~CarFactory() {}
    /**
     * Creates and returns a new car object
     * 
     * @param entity Json Object containing details for the car 
     * @return car object configured as per entity Json Object
     */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif
