#include <building.h>
#include <elevator.h>
#include <controller.h>

Building::Building(int numElevators , int numFloors)
    : m_numElevators(numElevators), m_numFloors(numFloors)
{
    Controller controller(*this);

    m_elevators.reserve(numElevators);
    for (int i = 0; i < numElevators; i++) {
        m_elevators.push_back(unique_ptr<Elevator>(new Elevator(*this)));
    }

    m_floors.reserve(numFloors);
    for (int i = 0; i < numFloors; i++) {
        m_floors.push_back(Floor(i, controller));
    }
}

Building::~Building()
{

}
