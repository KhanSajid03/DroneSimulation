
#include "BaseDroneDecorator.h"

BaseDroneDecorator::BaseDroneDecorator(Drone* drone) {
    this->drone = drone;
}

BaseDroneDecorator::~BaseDroneDecorator() {
    delete drone;
}
