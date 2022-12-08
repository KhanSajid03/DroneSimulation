#include "CreeperFactory.h"


IEntity* CreeperFactory::CreateEntity(JsonObject& entity){
    std::cout << " making creeper " << std::endl;
  std::string type = entity["type"];
  if(type.compare("creeper") == 0){
    std::cout << "Creeper Created" << std::endl;
    return new Creeper(entity);
  }
  return nullptr;
}
