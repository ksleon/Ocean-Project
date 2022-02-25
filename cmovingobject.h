//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_CMOVINGOBJECT

#include <TXLib.h>
#include "windowsize.h"
#ifndef _cmovingobject_
#define _cmovingobject_

//Class
typedef class CMovingObject cmovingobject_t;
class CMovingObject: public COceanObject{
protected:
    double vx,vy,
              course;
public:
    CMovingObject(int x0,int y0,int r0,double vx0,double vy0,double course0 = 0):
        COceanObject(x0,y0,r0),vx(vx0),vy(vy0),course(course0) {}
    virtual void move()
    {
        double courseRadians = course*M_PI/180;
        x += round(vx*cos(courseRadians));
        y -= round(vy*sin(courseRadians));
        if(x-r<0)
            x+= SCREEN_WIDTH;
        if(x+r > SCREEN_WIDTH)
            x-= SCREEN_WIDTH;
        if(y-r<0)
            y+= SCREEN_HEIGHT;
        if(y+r > SCREEN_HEIGHT)
            y-= SCREEN_HEIGHT;
    }
};

#endif
