#ifndef BUILDING_H
#define BUILDING_H

#include <elevator.h>
#include <floor.h>
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

class Building
{
public:
    int m_numElevators;
    int m_numFloors;
    vector<unique_ptr<Elevator>> m_elevators;
    vector<Floor> m_floors;
    Building(int numElevators, int numFloors);
    ~Building();
private:
};

#endif // BUILDING_H
