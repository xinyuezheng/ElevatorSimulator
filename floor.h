#ifndef FLOOR_H
#define FLOOR_H
#include <direction.h>
#include <memory>

using std::unique_ptr;
class Controller;
class Elevator;
class Floor
{
public:
    Floor(int floorNum, Controller& m_controller);
    int m_floorNum;
    bool m_request_up;
    bool m_request_down;
    Controller& m_controller;
    int Request(Direction direction);
    void ClearTask(Direction direction);
};

#endif // FLOOR_H
