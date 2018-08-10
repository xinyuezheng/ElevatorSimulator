#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <direction.h>
#include <bugcodes.h>
#include <QTimer>
#include <queue>

using std::vector;
using std::queue;

typedef enum ElevState {Move, Open, Close} ElevState;


class Building;
class Elevator : public QObject
{
public:
    int m_currentFloor;
    bool m_stopped;
    Direction m_currentDirection;
    const int m_maxCapacity = 20; //20 people
    Building& m_building;
    vector<bool>m_buttons;
    queue<Req> m_tasklist;
    queue<Req> m_tasks;

    Elevator(Building& building);
private:
    void HandleStateMachine(ElevState state);
    ElevState m_state;
    int MoveTo(int destFloor);
    int DoorOpen();
    int DoorClosed(Req& request);
};

#endif // ELEVATOR_H
