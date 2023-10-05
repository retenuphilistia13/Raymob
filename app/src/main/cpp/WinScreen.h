//WinScreen.h


#ifndef WINSCREEN_H_
#define WINSCREEN_H_

#include<raylib.h>
#include<vector>
#include<random>

#include"Ballon.h"
#include"Timer.h"


class WinScreen{

float celebrationTime=1.0f;


std::vector<Ballon*> ballons;

public:
WinScreen(){
    InitAudioDevice();      // Initialize audio device

    popSound = LoadSound("pop_ballon.wav");         // Load WAV audio file
yeaySound=LoadSound("yeay.mp3");
PlaySound(yeaySound);
}
 Sound popSound ;
  Sound yeaySound ;
bool isActivate=false;
Timer winScreen;

int ballonNumber=150;
void creatBallon(){
	float x=10;

std::random_device rd;
std::mt19937 gen(rd());

int randomW= GetScreenWidth()-120;
int randomH=GetScreenHeight()*6;
int randomC=1;//color
int maxSpeed=220;
int minSpeed=130;

// ballons.clear();//important to not cause
for(int i=0;i<ballonNumber;i++){

    std::uniform_int_distribution<int> distPosX(0, randomW);
    std::uniform_int_distribution<int> distPosY(0, randomH);
    std::uniform_int_distribution<int> distColor(0, randomC);
    std::uniform_int_distribution<int> distSpeed(minSpeed, maxSpeed);

    int x = distPosX(gen);
    int y = distPosY(gen);
    int c=distColor(gen);
    int speed=distSpeed(gen);

	Rectangle rec= {(float)x,(float)(y),0,0};

	ballons.push_back(new Ballon(rec));
	ballons[i]->setTexture(ballons[i]->color[c]);

	ballons[i]->size.x=ballons[i]->texture.width;
	ballons[i]->size.y=ballons[i]->texture.height;

	ballons[i]->updateSize();

	ballons[i]->setSpeed(speed);

}
}


void update(){


}


void setTimer(){
winScreen.StartTimer(celebrationTime);
}
void setTimer(float time){
celebrationTime=time;
winScreen.StartTimer(celebrationTime);
}

bool isWinDone(){

//  bool isAllGone = true;  // Initialize to true, update to false if any element has position.y <= 0
//
//if(isActivate)
//    for (int i = 0; i < ballons.size(); i++) {
//        if (ballons[i] != nullptr) {
//            std::cout << "ballons[" << i << "]->position.y: " << ballons[i]->position.y << std::endl;
//
//            if (ballons[i]->position.y >=GetScreenHeight()) {
//                // If any balloon is not gone, set isAllGone to false
//                isAllGone = false;
//            }
//        }
//    }
//
//
//
   return (winScreen.TimerDone());
}

void show(){

for(int i=0;i<ballons.size();i++){
ballons[i]->update();
ballons[i]->draw();

if(ballons[i]->isClicked&&ballons[i]->isVisible){
PlaySound(popSound);
ballons[i]->isVisible=false;//make them unvisible after sound pop activate
}


}

winScreen.UpdateTimer();


}

void clearScreen(){
    UnloadSound(popSound);     // Unload sound data

 UnloadSound(yeaySound);
    CloseAudioDevice();     // Close audio device
    for(int i=0;i<ballons.size();i++){
		delete ballons[i];
	}

	ballons.clear();

}


};




#endif
