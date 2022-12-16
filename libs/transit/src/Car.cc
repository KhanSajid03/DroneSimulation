#define _USE_MATH_DEFINES
#include "Car.h"
#include "AstarStrategy.h"
#include "SpinDecorator.h"
#include "JumpDecorator.h"

#include <cmath>
#include <limits>

Car::Car(const JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;
}

Car::~Car() {
}

void Car::Update(double dt, std::vector<IEntity*> scheduler) {
  if (toTargetPosStrategy == NULL) {
    toTargetPosStrategy = new AstarStrategy(this->GetPosition(),
                                            destination, graph);
  }
  if (!toTargetPosStrategy->IsCompleted()) {
    toTargetPosStrategy->Move(this, dt);
  } else {
    delete toTargetPosStrategy;
    destination = {rand() % 2900 - 1400, 500, rand() % 1600 - 800};
    toTargetPosStrategy = new AstarStrategy(this->GetPosition(),
                                            destination, graph);
    toTargetPosStrategy->Move(this, dt);
  }
}

void Car::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}
