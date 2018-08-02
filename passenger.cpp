#include "passenger.h"

#include "building.h"
passenger::passenger(Building& building) : m_building(building)
{

}

void passenger::GoToFloor(int elev_index, int floorNum)
{
    Req request;
    request.floorNum = floorNum;
    if (m_currentFloor < floorNum){
        request.direction = up;
    }
    else {
        request.direction = down;
    }

    if(elev_index >= 0) {
        m_building.m_elevators.at(elev_index)->m_tasklist.push(request);
    }
}

int passenger::RequestElev(Direction direction)
{
    int elev_index;
    elev_index = m_building.m_floors.at(m_currentFloor).Request(direction);

    return elev_index;
}
