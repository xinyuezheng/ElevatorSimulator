#ifndef BUILDING_H
#define BUILDING_H

#include <elevator.h>
#include <floor.h>
#include <vector>

using std::vector;

class Building
{
public:
    int m_numElevators;
    int m_numFloors;
    vector<Elevator> elevators;
    vector<Floor> floors;
    Building(int numElevators, int numFloors);
    ~Building();
private:
};

#endif // BUILDING_H
