//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_COCEAN

#include <TXLib.h>
#include <vector>
using namespace std;
#ifndef _cocean_
#define _cocean_

//Class
typedef class COcean cocean_t;
class COcean{
private:
    vector <COceanObject*> pObjects;
public:
    void addObject(objectType type,int x0,int y0,int r0,double vx0,double vy0,double course0,const double NUMBER_OF_STONES0,const double NUMBER_OF_GRASS0,const double NUMBER_OF_FISH0,const double NUMBER_OF_BUBBLES0,HDC stone0,HDC grass0,HDC fish0,HDC hunter0,HDC bubble0);
    void update();
    ~COcean();
    void checkCollisions() const;
    void removeDead();
};

void COcean::addObject(objectType type,int x0,int y0,int r0,double vx0,double vy0,double course0,const double NUMBER_OF_STONES0,const double NUMBER_OF_GRASS0,const double NUMBER_OF_FISH0,const double NUMBER_OF_BUBBLES0,HDC stone0,HDC grass0,HDC fish0,HDC hunter0,HDC bubble0)
{
    COceanObject* pNewObj = nullptr;
    if(type == STONE)
        pNewObj = new CStone(x0,y0,r0,NUMBER_OF_STONES0,stone0);
    else if(type == GRASS)
        pNewObj = new CGrass(x0,y0,r0,NUMBER_OF_GRASS0,grass0);
    else if(type == FISH)
        pNewObj = new CFish(x0,y0,r0,vx0,vy0,course0,NUMBER_OF_FISH0,fish0);
    else if(type == HUNTER)
        pNewObj = new CHunter(x0,y0,r0,vx0,vy0,hunter0);
    else if(type == BUBBLES)
        pNewObj = new CBubbles(x0,y0,r0,NUMBER_OF_BUBBLES0,bubble0);
    if( pNewObj )
    {
        pObjects.push_back( pNewObj );
    }
}

void COcean::checkCollisions() const
{
    for( unsigned int i=0;i<pObjects.size();i++)
        for( unsigned int j=i+1;j<pObjects.size();j++)
        {
            if(pObjects[i]->hasCollisionWith(pObjects[j]))
            {
                pObjects[i]->collideWith(pObjects[j]);
                pObjects[j]->collideWith(pObjects[i]);
            }
            if(pObjects[i]->hasDistanceWith(pObjects[j]))
            {
                pObjects[i]->distanceWith(pObjects[j]);
                pObjects[j]->distanceWith(pObjects[i]);
            }
        }
}

void COcean::removeDead()
{
    for(int i=pObjects.size()-1;i>=0;i--)
        if(pObjects[i]->isDead())
        {
            delete pObjects[i];
            pObjects.erase(pObjects.begin() + i);
        }
}

void COcean::update()
{
    for( auto pObj: pObjects )
        pObj->update();
    checkCollisions();
    removeDead();
}

COcean::~COcean()
{
    for( auto pObj: pObjects )
        delete pObj;
}

#endif
