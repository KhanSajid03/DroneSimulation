#include "DroneFactory.h"
#include "BatteryDecorator.h"

IEntity* DroneFactory::CreateEntity(JsonObject& entity){
  std::string type = entity["type"];
  if(type.compare("drone") == 0){
    std::cout << "Drone Created" << std::endl;

    Drone* droneTemp = new Drone(entity);
    BatteryDecorator* BatteryDrone = new BatteryDecorator(droneTemp);
    // return new Drone(entity);
    return BatteryDrone;
  }
  return nullptr;
}