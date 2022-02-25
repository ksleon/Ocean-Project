//автор: Леонид Ксинопуло 9 "В"

//*_MAIN CODE_*

//LIBRARIES

#include "includeALL.h"

int main()
{
    txCreateWindow(SCREEN_WIDTH,SCREEN_HEIGHT);
    CStone stone(0,0,0,random(6)+5,txLoadImage("stone.bmp"));
    CGrass grass(0,0,0,random(60)+30,txLoadImage("grass.bmp"));
    CFish fish(0,0,0,0,0,0,random(7)+5,txLoadImage("fish.bmp"));
    CHunter hunter(0,0,0,4,4,txLoadImage("hunter.bmp"));
    COceanBackground oceanbackground(txLoadImage("ocean.bmp"));
    CBubbles bubble(random(SCREEN_WIDTH+1),random(SCREEN_HEIGHT+1),random(5)+10,random(5,10),txLoadImage("bubble.bmp"));

    COcean ocean;
    vector <COceanObject*> pObjects;

    for(int i=0;i < stone.NUMBER_OF_STONES;i++)
        ocean.addObject(STONE,random(SCREEN_WIDTH+1),random(101)+600,random(6)+40,0,0,0,stone.NUMBER_OF_STONES,0,0,0,stone.getHDCstone,0,0,0,0);
    for(int i=0;i < grass.NUMBER_OF_GRASS;i++)
        ocean.addObject(GRASS,random(SCREEN_WIDTH+1),random(101)+600,random(6)+40,0,0,0,0,grass.NUMBER_OF_GRASS,0,0,0,grass.getHDCgrass,0,0,0);
    for(int i=0;i < fish.NUMBER_OF_FISH;i++)
        ocean.addObject(FISH,random(SCREEN_WIDTH+1),random(701),random(51)+70,random(-10,10),random(100,300),random(-1,1),0,0,fish.NUMBER_OF_FISH,0,0,0,fish.getHDCfish,0,0);
    for(int i=0;i < 1;i++)
        ocean.addObject(HUNTER,0,500,300,4,4,0,0,0,0,0,0,0,0,hunter.getHDChunter,0);
    for(int i=0;i < bubble.NUMBER_OF_BUBBLES;i++)
        ocean.addObject(BUBBLES,random(SCREEN_WIDTH+1),random(SCREEN_HEIGHT+1),random(11)+10,0,0,0,0,0,0,bubble.NUMBER_OF_BUBBLES,0,0,0,0,bubble.getHDCbubble);

    txBegin();
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txClear();
        oceanbackground.draw();
        for(int i=0;i < pObjects.size();i++)
            pObjects[i]->update();
        ocean.update();
        txClearConsole();
        txSleep(1);
    }
    txEnd();
    grass.deleteDC();
    stone.deleteDC();
    for(int i=0;i < pObjects.size();i++)
        delete pObjects[i];
    fish.deleteDC();
    hunter.deleteDC();
    bubble.deleteDC();
    oceanbackground.deleteDC();
    return 0;
}
