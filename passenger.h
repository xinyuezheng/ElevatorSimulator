#ifndef PASSENGER_H
#define PASSENGER_H
#include "elevator.h"


class passenger
{
public:
    int favorateFloor;
    int currentFloor;
    passenger();
    void RequestElevator(Direction direction);
    void RequestFloor(int floorNum);
};

#endif // PASSENGER_H
