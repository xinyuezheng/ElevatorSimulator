#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
using std::vector;

class Building;

class Controller
{
public:
    Building& m_building;
    vector<int> upRequest;
    vector<int> downRequest;
    Controller(Building& building);
private:
    void GetRequest();
};

#endif // CONTROLLER_H
