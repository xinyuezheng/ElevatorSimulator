#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <direction.h>
#include <bugcodes.h>
#include <QTimer>
#include <queue>

using std::vector;
using std::queue;

class Building;
class Elevator : public QObject
{
public:
//    const int floorHeight = 3; //meters
    int m_currentFloor;
    bool m_stopped;
    Direction m_currentDirection;
//    double currentSpeed;
    const int maxCapacity = 20; //20 people
    Building& m_building;
    vector<bool>buttons;
    queue<Req> m_tasklist;
    queue<Req> m_tasks;

    Elevator(Building& building);
private:
    void moveOneFloor(Direction direction);
    void ExecuteTask();
    void MoveTo(int distFloor);
};

#endif // ELEVATOR_H
