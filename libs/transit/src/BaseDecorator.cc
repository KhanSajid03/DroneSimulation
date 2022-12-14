#include "BaseDecorator.h"

void BaseDecorator::Update(double dt, IEntity* entity) {
  entity->Update(dt, entity);
}