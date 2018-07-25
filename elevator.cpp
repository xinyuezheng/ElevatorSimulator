#include "elevator.h"
#include <ctime>
#include <windows.h>
#include <building.h>

Elevator::Elevator(Building& building)
    : m_building(building)
{
    for(int i = 0; i < m_building.m_numFloors; i++){
        buttons.push_back(false);
    }
}

void Elevator::MoveTo(int dstFloor){
    double distance = 0;

    if (dstFloor > currentFloor) {
        distance = (dstFloor - currentFloor) * floorHeight;
        currentDirection = up;
    } else {
        distance = (currentFloor - dstFloor) * floorHeight;
        currentDirection = down;
    }

    //TODO: accelerate available later
    currentSpeed = 1; //1m/s
    double movedDist = 0;
    time_t duration, now, begin = time(0);

    while (movedDist <= distance)
    {
        now = time(0);
        duration = now - begin;
        movedDist = duration * currentSpeed;
        Sleep(500); //500 ms
    }

    currentSpeed = 0;
    currentFloor = dstFloor;

    //change direction after arriving at top/bottom
    if (currentFloor == m_building.m_numFloors - 1 && currentDirection == up)
        currentDirection = down;
    if (currentFloor == 0 && currentDirection == down)
        currentDirection = up;
}

void Elevator::NextStop(){
//    if (currentDirection == up && m_building.floors.at(currentFloor).requestUp) {
//        //MoveTo();
//    }
}
