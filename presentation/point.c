#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#include "Point.h"
 
struct _point {
    double x;
    double y;
};
 
//typedef struct _point * Point;
 
Point newPoint(double x, double y) {
    Point new = malloc(sizeof(struct _point));
    assert(new != NULL);
    new->x = x;
    new->y = y;
    return new;
}
 
void destroyPoint(Point p) {
    assert(p != NULL);
    free(p);
 
}
 
double getX(Point p) {
    assert(p != NULL);
    return p->x;
}
 
double getY(Point p) {
    assert(p != NULL);
    return p->y;
}
 
void setPoint(Point p, double x, double y) {
    assert(p != NULL);
    p->x = x;
    p->y = y;
 
}