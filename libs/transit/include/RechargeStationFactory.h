#ifndef LIBS_TRANSIT_INCLUDE_RECHARGESTATIONFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_RECHARGESTATIONFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RechargeStation.h"

#include <vector>

/**
 * @brief This class serves as a factory for the Car class
 */
class RechargeStationFactory : public IEntityFactory {
 public:
    /**
    * @brief virtual destructor
    */
    virtual ~RechargeStationFactory() {}
    /**
     * Creates and returns a new RechargeStation object
     * @param entity Json Object containing details for the RechargeStation.
     * @return RechargeStation object configured as per entity Json Object
     */
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_RECHARGESTATIONFACTORY_H_
