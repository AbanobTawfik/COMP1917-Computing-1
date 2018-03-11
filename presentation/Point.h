typedef struct _point * Point;
Point newPoint(double x, double y);
void destroyPoint(Point p);
double getX(Point p);
double getY(Point p);
void setPoint(Point p, double x, double y);