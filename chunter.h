//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_CHUNTER

#include <TXLib.h>
#include "cmovingobject.h"

#ifndef _chunter_
#define _chunter_

//Class
typedef class CHunter chunter_t;
class CHunter:public CMovingObject{
private:
    HDC hunter;
    int dv = 1;
    int xpic = 0;
    int ypic = 0;
    int old;
    int win = 0;
public:
    CHunter(int x0,int y0,int r0,double vx0,double vy0,HDC hunter0):
        CMovingObject(x0,y0,r0,vx0,vy0),hunter(hunter0) {}
    virtual void change() override
    {
        old++;
        if( old % 100 == 0)
        {
            r-=10;
        }
        if(dv == 1)
        {
            double distance = hypot(txMouseX()-150 - x, y=txMouseY()-70 - y );
            if(distance != 0 && txMouseButtons() == 1)
            {
                if(x - txMouseX()-150 > 0 && txMouseY()-70 - y > 0)
                {
                    for(int i=x;i>txMouseX()-150;i--)
                    {
                        x--;
                    }
                    for(int i=y;i<txMouseX()-150;i++)
                    {
                        y++;
                    }
                }
                if(txMouseX()-150 - x > 0 && y - txMouseY()-70 > 0)
                {
                    for(int i=x;i<txMouseX()-150;i++)
                    {
                        x++;
                    }
                    for(int i=y;i>txMouseX()-150;i--)
                    {
                        y--;
                    }
                }
                if(txMouseX()-150 - x > 0 && txMouseY()-70 - y > 0)
                {
                    for(int i=x;i<txMouseX()-150;i++)
                    {
                        x++;
                    }
                    for(int i=y;i<txMouseX()-150;i++)
                    {
                        y++;
                    }
                }
                if(x - txMouseX()-150 > 0 && y - txMouseY()-70 > 0)
                {
                    for(int i=x;i>txMouseX()-150;i--)
                    {
                        x--;
                    }
                    for(int i=y;i>txMouseX()-150;i--)
                    {
                        y--;
                    }
                }
            }
            x=txMouseX()-r/2;
            y=txMouseY()-70;
            if( txMouseButtons() & 2)
            {
                xpic=1200;
            }
            if( txMouseButtons() & 1)
            {
                xpic=0;
            }
            if(r==700)
            {
                win = 1;
            }
        }
        if(win == 1)
        {
            xpic=2700;
            ypic=500;
            dv = 0;
        }
    }
    virtual void show() const override
    {
        Win32::TransparentBlt(txDC(),x,y,r,r/2, hunter,xpic,ypic,1200,600,TX_WHITE);
    }
    void deleteDC();
    HDC getHDChunter = hunter;
    CHunter(const CHunter &chunter);
    CHunter& operator = (CHunter);
    virtual void collideWith( COceanObject* pOther ) override;
};



void CHunter::deleteDC()
{
    txDeleteDC(hunter);
}

#endif
