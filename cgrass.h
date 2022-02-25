//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_CGRASS

#include <TXLib.h>
#include "coceanobject.h"
#ifndef _cgrass_
#define _cgrass_

//Class
typedef class CGrass cgrass_t;
class CGrass:public COceanObject{
private:
    HDC grass;
    int grow;
public:
    const double NUMBER_OF_GRASS;
    CGrass(int x0,int y0,int r0,const double NUMBER_OF_GRASS0,HDC grass0):
        COceanObject(x0,y0,r0),NUMBER_OF_GRASS(NUMBER_OF_GRASS0),grass(grass0) {}
    virtual void change() override {
        grow++;
        if( grow % 10 == 0)
        {
            y--;
            r++;
        }
    }
    virtual void show() const override
    {
        Win32::TransparentBlt(txDC(),x,y,r,r+35, grass,300,100,160,500,TX_WHITE);
    }
    void deleteDC();
    HDC getHDCgrass = grass;
    CGrass(const CGrass &cgrass);
    CGrass& operator = (CGrass);
    virtual void collideWith( COceanObject* pOther) override;
};
void CGrass::deleteDC()
{
    txDeleteDC(grass);
}

#endif
