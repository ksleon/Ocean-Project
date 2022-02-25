//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_BUBBLES

#include <TXLib.h>
#include "coceanobject.h"
#include "windowsize.h"
#ifndef _cbubbles_
#define _cbubbles_

//Class
typedef class CBubbles cbubbles_t;
class CBubbles:public COceanObject{
private:
    HDC bubble;
public:
    const double NUMBER_OF_BUBBLES;
    CBubbles(int x0,int y0,int r0,const double NUMBER_OF_BUBBLES0,HDC bubble0):
        COceanObject(x0,y0,r0),NUMBER_OF_BUBBLES(NUMBER_OF_BUBBLES0),bubble(bubble0) {}
    virtual void change() override{

        y--;
        if(y-r<0)
        {
            y = SCREEN_HEIGHT;
            x = random(SCREEN_WIDTH+1);
            y = random(SCREEN_HEIGHT+1);
        }
    }
    virtual void show() const override
    {
        Win32::TransparentBlt(txDC(),x,y,r,r, bubble,0,0,1024,846,TX_WHITE);
    }
    void deleteDC();
    HDC getHDCbubble = bubble;
    CBubbles(const CBubbles &cbubbles);
    CBubbles& operator = (CBubbles);
    virtual void collideWith( COceanObject* pOther) override;
};
void CBubbles::deleteDC()
{
    txDeleteDC(bubble);
}

#endif
