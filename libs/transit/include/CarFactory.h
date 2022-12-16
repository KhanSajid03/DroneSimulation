#ifndef LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_CARFACTORY_H_

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
     * @brief virtual destructor
     * 
     */
    virtual ~CarFactory() {}
    /**
     * @brief Creates and returns a new car object
     * 
     * @param entity Json Object containing details for the car 
     * @return car object configured as per entity Json Object
     */
    IEntity* CreateEntity(const JsonObject& entity);
};
#endif  // LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
