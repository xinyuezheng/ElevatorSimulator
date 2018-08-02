#ifndef PASSENGER_H
#define PASSENGER_H

#include <direction.h>
class Building;
class Elevator;
class passenger
{
public:
    int m_favorateFloor;
    int m_currentFloor;
    Building& m_building;
    passenger(Building& building);
    int RequestElev(Direction direction);
    void GoToFloor(int elev_index, int floorNum);
};

#endif // PASSENGER_H
