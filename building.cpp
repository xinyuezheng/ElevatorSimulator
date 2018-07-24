#include "building.h"
#include "elevator.h"

Building::Building(int numElevators , int numFloors)
    : m_numElevators(numElevators), m_numFloors(numFloors)
{
    elevators.reserve(numElevators);
    for (int i = 0; i < numElevators; i++) {
        elevators.push_back(Elevator(*this));
    }

    floors.reserve(numFloors);
    for (int i = 0; i < numFloors; i++) {
        floors.push_back(Floor());
    }
}

Building::~Building()
{

}
