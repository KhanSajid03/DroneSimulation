#include "BeelineStrategy.h"
// document this DHRUV
BeelineStrategy::BeelineStrategy(Vector3 position, Vector3 destination) {
    this->position = position;
    this->destination = destination;

    path.push_back(position.toCppVector());
    path.push_back(destination.toCppVector());
}

bool BeelineStrategy::IsCompleted() {
    return (destination - position).Magnitude() < 1.0;
}

void BeelineStrategy::Move(IEntity* entity, double dt) {
    position = entity->GetPosition();
    Vector3 dir = (destination - position).Unit();
    float speed = entity->GetSpeed();
    position = position + dir * speed * dt;
    entity->SetPosition(position);
    entity->SetDirection(dir);
}
