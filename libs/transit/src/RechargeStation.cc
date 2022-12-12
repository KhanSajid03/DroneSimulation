#define _USE_MATH_DEFINES
#include "RechargeStation.h"
#include "BeelineStrategy.h"
#include "SpinDecorator.h"
#include "JumpDecorator.h"

#include <cmath>
#include <limits>

RechargeStation::RechargeStation(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray des(obj["destination"]);
  destination = {des[0], des[1], des[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;
}

RechargeStation::~RechargeStation() {
  // Delete dynamically allocated variables
}

void RechargeStation::Update(double dt, std::vector<IEntity*> scheduler) {
  toTargetPosStrategy = new BeelineStrategy(this->GetPosition(), destination);
  if (!toTargetPosStrategy->IsCompleted()) {
    toTargetPosStrategy->Move(this, dt);
  } else {
    destination = {rand() % 2900 - 1400, 500, rand() % 1600 - 800};
    toTargetPosStrategy->Move(this, dt);
  }
}

void RechargeStation::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

// RechargeStation can't jump, so commenting this out.
// void Drone::Jump(double height) {
//   if(goUp){
//     position.y += height;
//     jumpHeight += height;
//     if(jumpHeight > 5){
//       goUp = false;
//     }
//   } else {
//     position.y -= height;
//     jumpHeight -= height;
//     if(jumpHeight < 0){
//       goUp = true;
//     }
//   }
// }
