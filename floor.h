#ifndef FLOOR_H
#define FLOOR_H

class Controller;
class Floor
{
public:
    Floor(int floorNum, Controller& m_controller);
    int m_floorNum;
    Controller& m_controller;
    void RequestUp();
    void RequestDown();
};

#endif // FLOOR_H
