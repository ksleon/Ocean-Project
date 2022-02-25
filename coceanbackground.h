//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_OCEANBACKGROUND

#include <TXLib.h>
#ifndef _coceanbackground_
#define _coceanbackground_

//Class
typedef class COceanBackground coceanbackground_t;
class COceanBackground{
private:
    HDC ocean;
public:
    COceanBackground(HDC ocean0):
        ocean(ocean0) {}
    void draw();
    void deleteDC();
};

void COceanBackground::draw()
{
    Win32::TransparentBlt(txDC(),0,0,1280,720, ocean,0,0,1280,720,TX_WHITE);
}
void COceanBackground::deleteDC()
{
    txDeleteDC(ocean);
}

#endif
