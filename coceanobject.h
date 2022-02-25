//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_COCEANOBJECT

#include <TXLib.h>
#ifndef _coceanobject_
#define _coceanobject_

//Class

class COceanObject{
protected:
    int x,y,r;
    COceanObject(int x0,int y0,int r0):
        x(x0),y(y0),r(r0) {}
public:
    void update(){
    change();
    show();
    }
    virtual void change() = 0;
    virtual void show() const = 0;
    virtual ~COceanObject() = default;

    virtual bool isDead() { return (r==0);}
    bool hasCollisionWith( COceanObject* pOther ) const;
    bool hasDistanceWith( COceanObject* pOther ) const;
    virtual void collideWith( COceanObject* pOther ) {}
    virtual void distanceWith( COceanObject* pOther ) {}
};

bool COceanObject::hasCollisionWith( COceanObject* pOther ) const
{
    double distance = hypot(x - pOther->x, y - pOther->y );
    return (distance < r);
}
bool COceanObject::hasDistanceWith( COceanObject* pOther ) const
{
    double distance = hypot(x - pOther->x, y - pOther->y );
    return (distance < r+100);
}

#endif
