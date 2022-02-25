//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_CFISH

#include <TXLib.h>
#include "cmovingobject.h"
#ifndef _cfish_
#define _cfish_

//Class
typedef class CFish ccfish_t;
class CFish:public CMovingObject{
private:
    HDC fish;
    int xpic = 0;
    int old;
public:
    const double NUMBER_OF_FISH;
    CFish(int x0,int y0,int r0,double vx0,double vy0,double course0,const double NUMBER_OF_FISH0,HDC fish0):
        CMovingObject(x0,y0,r0,vx0,vy0,course0),NUMBER_OF_FISH(NUMBER_OF_FISH0),fish(fish0) {}
    virtual void change() override
    {
        move();
        old++;
        if( old % 100 == 0)
        {
            r--;
        }
        if(vx<0)
        {
            xpic=450;
        }
    }
    virtual void show() const override
    {
        Win32::TransparentBlt(txDC(),x,y,r,r, fish,xpic,0,450,450,TX_WHITE);
    }
    void deleteDC();
    HDC getHDCfish = fish;
    int regenerate = 0;
    CFish(const CFish &cfish);
    CFish& operator = (CFish);
    virtual void collideWith( COceanObject* pOther) override;
    virtual void distanceWith( COceanObject* pOther) override;
};

void CFish::deleteDC()
{
    txDeleteDC(fish);
}

#endif
