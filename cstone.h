//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_CSTONE

#include <TXLib.h>
#include <stdio.h>
#include "coceanobject.h"
#include "windowsize.h"
#ifndef _cstone_
#define _cstone_

//Class
class CStone:public COceanObject{
private:
    HDC stone;
public:
    const double NUMBER_OF_STONES;
    CStone(int x0,int y0,int r0,const double NUMBER_OF_STONES0,HDC stone0):
        COceanObject(x0,y0,r0),NUMBER_OF_STONES(NUMBER_OF_STONES0),stone(stone0) {}
    virtual void change() override{}
    virtual void show() const override
    {
        Win32::TransparentBlt(txDC(),x,y,r,r, stone,0,0,1024,846,TX_WHITE);
    }
    void deleteDC();
    HDC getHDCstone = stone;
    CStone(const CStone &cstone);
    CStone& operator = (CStone);
    virtual ~CStone() = default;
};

void CStone::deleteDC()
{
    txDeleteDC(stone);
}

#endif
