#include "passenger.h"
#include "building.h"

passenger::passenger()
{

}

void passenger::RequestElevator(Direction direction)
{
    if (direction == up) {
//        m_building.floors.at(floorNum).requestUp = true;
    }

    if (direction == down) {
//        m_building.floors.at(floorNum).requestDown = true;
    }
}

void passenger::RequestFloor(int floorNum)
{
//    elevator.buttons[floorNum] = true;
}
