#include <floor.h>
#include <controller.h>
#include <algorithm>

Floor::Floor(int floorNum, Controller& controller)
    : m_floorNum(floorNum), m_controller(controller)
{

}

int Floor::Request(Direction direction){
    int elevator_index = -1;
    Req newRequest = Req();
    newRequest.floorNum = m_floorNum;
    newRequest.direction = direction;

    //no previous request
    if (direction == up && !m_request_up)
    {
        m_request_up = true;
        elevator_index = m_controller.RequestElev(newRequest);
    }

    if (direction == down && !m_request_down) {
        m_request_down = true;
        elevator_index = m_controller.RequestElev(newRequest);
    }

    return elevator_index;
}

void Floor::ClearTask(Direction direction){
    if (direction == up) {
        m_request_up = false;
    } else {
        m_request_down = false;
    }
}
