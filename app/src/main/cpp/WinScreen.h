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


}
bool isActivate=false;
Timer winScreen;

int ballonNumber=130;
void creatBallon(){
	float x=10;


std::random_device rd;
std::mt19937 gen(rd());

int randomW= GetScreenWidth();
int randomH=GetScreenHeight()*4;
int randomC=1;//color
int maxSpeed=350;
int minSpeed=130;

// ballons.clear();//important to not cause
for(int i=0;i<ballonNumber;i++){

    std::uniform_int_distribution<int> distPosX(0, randomW);
    std::uniform_int_distribution<int> distPosY(GetScreenHeight()/2, randomH);
    std::uniform_int_distribution<int> distColor(0, randomC);
    std::uniform_int_distribution<int> distSpeed(minSpeed, maxSpeed);

    int w = distPosX(gen);
    int h = distPosY(gen);
    int c=distColor(gen);
    int speed=distSpeed(gen);

	Rectangle rec= {(float)w,(float)(h),100.0f,100.0f};

	ballons.push_back(new Ballon(rec));
	ballons[i]->setTexture(ballons[i]->color[c]);

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
}

winScreen.UpdateTimer();


}

void clearScreen(){

    for(int i=0;i<ballons.size();i++){
		delete ballons[i];
	}

	ballons.clear();

}


};




#endif
