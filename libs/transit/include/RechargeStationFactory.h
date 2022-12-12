#ifndef RECHARGE_STATION_FACTORY_H_
#define RECHARGE_STATION_FACTORY_H_

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
    * 
    * virtual destructor
    * 
    */
    virtual ~RechargeStationFactory() {}

    /**
     * Creates and returns a new RechargeStation object
     * 
     * @param entity Json Object containing details for the RechargeStation.
     * @return RechargeStation object configured as per entity Json Object
     */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif
