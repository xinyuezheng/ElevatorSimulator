#ifndef DIRECTION_H
#define DIRECTION_H

typedef enum Direction{up, down} Direction;

typedef struct Req {
    int floorNum;
    Direction direction;
}Req;

#endif // DIRECTION_H
