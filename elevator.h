#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <direction.h>
#include <bugcodes.h>

using std::vector;

class Building;
class Elevator
{
public:
    const int floorHeight = 3; //meters
    int currentFloor;
    Direction currentDirection;
    double currentSpeed;
    const int maxCapacity = 20; //20 people
    Building& m_building;
    vector<bool>buttons;

    Elevator(Building& building);
    void MoveTo(int distFloor);
    void NextStop();
};

#endif // ELEVATOR_H
