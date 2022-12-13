#include "Creeper.h"
#include "BeelineStrategy.h"


Creeper::Creeper(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
}

JsonObject Creeper::GetDetails() const { return details; }

void Creeper::FindDrone(std::vector<IEntity*> entities) {

  for (auto entity : entities) {
    if (entity->IsDrone()) {
      drone = dynamic_cast<Drone*>(entity);
      followingDrone = true;
      return;
    }
  }

  std::cout << "CREEPER: could not find drone" << std::endl;

}


// TODO: scheduler only contains robots
void Creeper::Update(double dt, std::vector<IEntity*> entities) {
  
  // if(!followingDrone) {
  //   FindDrone(entities);
  // } else {

  //   if ((position-drone->GetPosition()).Magnitude() <= 5)  return;

  //   Vector3 yOffset(0, 100, 0);
  //   destination = drone->GetPosition() + yOffset;

  //   Vector3 direction = (destination-position).Unit();
  //   position = position + (direction * speed * dt);
  // }

  return;
}