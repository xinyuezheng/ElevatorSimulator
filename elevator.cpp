#include "elevator.h"
#include <ctime>
#include <windows.h>
#include <building.h>
#include <vector>

using std::vector;

Elevator::Elevator(Building& building) : m_building(building), m_state(Close)
{    
    for(int i = 0; i < m_building.m_numFloors; i++){
        m_buttons.push_back(false);
    }    

}

void Elevator::HandleStateMachine(ElevState state) {
    int time = 0;
    Req request;
    request.floorNum = m_currentFloor;
    switch (state) {
    case Move:
        time = MoveTo(request.floorNum);
        break;
    case Close:
        time = DoorClosed(request);
        break;
    case Open:
        time = DoorOpen();
        break;
    default:
        break;
    }

    if(time) {
        QTimer::singleShot(5000, this, SLOT(HandleStateMachine));
    }

}

int Elevator::MoveTo(int destFloor)
{
    int time = 5000;
    int nrFloorToMove = destFloor - m_currentFloor;
    if (nrFloorToMove < 0) {
        m_currentDirection = down;
        nrFloorToMove = 0 - nrFloorToMove;
    } else if (nrFloorToMove > 0) {
        m_currentDirection = up;
    } else{
        m_state = Open;
        time = 0;
    }

    if (m_currentFloor == m_building.m_numFloors - 1 && m_currentDirection == up)
        m_currentDirection = down;
    if (m_currentFloor == 0 && m_currentDirection == down)
        m_currentDirection = up;

    return time;
}


int Elevator::DoorOpen(){
    //clear floor request;
    m_building.m_floors.at(m_currentFloor).ClearTask(m_currentDirection);
    m_state = Close;
    return 2000;
}

int Elevator::DoorClosed(Req& request){
    if(!m_tasklist.empty()) {
        request = m_tasklist.front();
        m_tasklist.pop();
        m_state = Move;
    }

    return 1000;
}

