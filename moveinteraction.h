//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_MOVEINTERACTION

#include <TXLib.h>
#include "cstone.h"
#include "chunter.h"
#include "cfish.h"
#include "cbubbles.h"
#include "cgrass.h"
#ifndef _moveinteraction_
#define _moveinteraction_

void CFish::collideWith( COceanObject* pOther )
{
    auto pHunter = dynamic_cast <CHunter*> (pOther);
    auto pGrass = dynamic_cast <CGrass*> (pOther);
    if( pHunter )
    {
        x=random(SCREEN_WIDTH+1);
        y=random(701);
        r=random(51)+70;
        vx=random(-10,10);
        vy=random(100,300);
        course=random(-1,1);
    }
    if( pGrass )
    {
        r+30;
    }
}

void CHunter::collideWith( COceanObject* pOther )
{
    auto pStone = dynamic_cast <CStone*> (pOther);
    auto pFish = dynamic_cast <CFish*> (pOther);
    auto pBubbles = dynamic_cast <CBubbles*> (pOther);
    if( pFish )
    {
        r+=10;
        ypic=600;
    }
    if( pStone )
    {
        dv = 0;
    }
    else
    {
        dv = 1;
    }
    if( pBubbles )
    {
        ypic=0;
    }
}

void CFish::distanceWith( COceanObject* pOther)
{
    auto pHunter = dynamic_cast <CHunter*> (pOther);
    if( pHunter )
    {
        course -= 0,5;
        vx=-10;
    }
    else
    {
        xpic=0;
        vx = random(3,10);
    }
}
void CBubbles::collideWith( COceanObject* pOther)
{
    auto pFish = dynamic_cast <CFish*> (pOther);
    if( pFish )
    {
        y-=10;
    }
}
void CGrass::collideWith( COceanObject* pOther )
{
    auto pFish = dynamic_cast <CFish*> (pOther);
    if( pFish )
    {
        r-=10;
        y+=10;
    }
}

#endif
