#include "controller.h"
#include <building.h>

using std::vector;

Controller::Controller(Building& building) : m_building(building)
{

}

unsigned Controller::FindElev(Req request){
    unsigned index = 0;
    int min_distance = 2* m_building.m_numElevators;

    for (size_t i = 0; i < m_building.m_elevators.size(); i++)
    {
//        unique_ptr<Elevator> elev = m_building.m_elevators.at(i);
        int distance = request.floorNum - m_building.m_elevators.at(i)->m_currentFloor;

        //Same direction as request
        if (m_building.m_elevators.at(i)->m_currentDirection == request.direction){
            if (request.direction == up) {
                if (distance < 0)
                    distance  = 2*m_building.m_numFloors + distance;
            }
            if(request.direction == down) {
                if (distance < 0) {
                    distance = 0 - distance;
                } else {
                    distance = 2*m_building.m_numFloors - distance;
                }
            }

        } else {
            distance = (m_building.m_numFloors - m_building.m_elevators.at(i)->m_currentFloor) + (m_building.m_numFloors - request.floorNum);
        }

        if (distance < min_distance) {
            min_distance = distance;
            index = i;
        }
    }

    return index;
}

int Controller::RequestElev(Req request){
    int elev_index = FindElev(request);
    m_building.m_elevators.at(elev_index)->m_tasklist.push(request);

    return elev_index;
}
