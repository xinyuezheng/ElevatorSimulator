#include <floor.h>
#include <controller.h>
#include <algorithm>

Floor::Floor(int floorNum, Controller& controller)
    : m_floorNum(floorNum), m_controller(controller)
{

}

void Floor::RequestUp(){
    vector<int>::iterator it;
    it = find (m_controller.upRequest.begin(), m_controller.upRequest.end(), m_floorNum);
    //no previous request found
    if (it == m_controller.upRequest.end()) {
        m_controller.upRequest.push_back(m_floorNum);
    }
}

void Floor::RequestDown(){
    vector<int>::iterator it;
    it = find (m_controller.downRequest.begin(), m_controller.downRequest.end(), m_floorNum);
    //no previous request found
    if (it == m_controller.downRequest.end()) {
        m_controller.downRequest.push_back(m_floorNum);
    }
}
