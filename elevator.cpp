#include "elevator.h"
#include <ctime>
#include <windows.h>
#include <building.h>
#include <vector>

using std::vector;

Elevator::Elevator(Building& building)
    : m_building(building)
{
    for(int i = 0; i < m_building.m_numFloors; i++){
        buttons.push_back(false);
    }
}

void Elevator::ExecuteTask() {
    //TODO: put to while(1) in seperate thread
    if(m_stopped && !m_tasklist.empty()) {
        Req task = m_tasklist.front();
        MoveTo(task.floorNum);
        m_tasklist.pop();
        //clear floor request;
        m_building.m_floors.at(task.floorNum).ClearTask(task.direction);
    }
}


void Elevator::MoveTo(int distFloor)
{
    int nrFloorToMove = distFloor - m_currentFloor;
    if (nrFloorToMove < 0) {
        m_currentDirection = down;
        nrFloorToMove = 0 - nrFloorToMove;
    } else {
        m_currentDirection = up;
    }

    m_stopped = false;

    for (int i = 0; i < nrFloorToMove; i++) {
        QTimer::singleShot(5000, this, SLOT(moveOneFloor(m_currentDirection))); //5s to move one floor
    }

    m_stopped = true;

    if (m_currentFloor == m_building.m_numFloors - 1 && m_currentDirection == up)
        m_currentDirection = down;
    if (m_currentFloor == 0 && m_currentDirection == down)
        m_currentDirection = up;
}

void Elevator::moveOneFloor(Direction direction)
{
    if (direction == up)
        m_currentFloor++ ;
    else
        m_currentFloor--;
}
