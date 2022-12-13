#include "DroneFactory.h"
#include "BatteryDecorator.h"

IEntity* DroneFactory::CreateEntity(JsonObject& entity){
  std::string type = entity["type"];
  if(type.compare("drone") == 0){
    std::cout << "Drone Created" << std::endl;

    IEntity* droneTemp = new Drone(entity);
    droneTemp = new BatteryDecorator(droneTemp);
    return droneTemp;
  }
  return nullptr;
}