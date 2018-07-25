#ifndef PASSENGER_H
#define PASSENGER_H

#include <direction.h>
class Building;
class passenger
{
public:
    int m_favorateFloor;
    int m_currentFloor;
    Building& m_building;
    passenger(Building& building);
    void RequestElevator(Direction direction);
    void RequestFloor(int floorNum);
};

#endif // PASSENGER_H
