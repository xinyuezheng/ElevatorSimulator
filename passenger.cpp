#include "passenger.h"

#include "building.h"
passenger::passenger(Building& building) : m_building(building)
{

}

void passenger::RequestElevator(Direction direction)
{
    if (direction == up) {
        m_building.floors.at(m_currentFloor).requestUp = true;
    }

    if (direction == down) {
        m_building.floors.at(m_currentFloor).requestDown = true;
    }
}

void passenger::RequestFloor(int floorNum)
{
//    elevator.buttons[floorNum] = true;
}
