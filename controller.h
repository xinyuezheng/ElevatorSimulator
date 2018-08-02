#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <direction.h>
#include <memory>

using std::unique_ptr;
using std::vector;

class Building;
class Elevator;

class Controller
{
public:
    Building& m_building;
    vector<Req> m_floorRequests;
    Controller(Building& building);
    int RequestElev(Req request);
private:
    unsigned FindElev(Req request);
};

#endif // CONTROLLER_H
