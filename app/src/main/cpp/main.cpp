#include <iostream>
#include"raylib.h"


#include<vector>
#include<string>

#include <random>

#include"CardManager.h"
#include"Ballon.h"

#include"WinScreen.h"
//#include"raymath.h"


// define a timer

using std::vector;
using std::string;

using std::cout;
using std::endl;

const int screenWidth = 720;
const int screenHeight = 1000;

bool win;

int main(int argc, char **argv) {
	  // Initialization

	    InitWindow(0, 0, "meomary card");
	    SetWindowSize(screenWidth, screenHeight);
int level=1;
	    CardManager* cardGame=new CardManager(level);

	    SetTargetFPS(60);

WinScreen* win_screen;

	    // Main game loop
	    while (!WindowShouldClose()) {
	        // Update
	    if(!win)
	    	cardGame->update();

	        // Draw

	        BeginDrawing();
	        DrawText("", 100, 100, 20, DARKGRAY);

	        ClearBackground(WHITE);
       if(!win){
	        cardGame->draw();

       }
       if(!win)
        	if(cardGame->playerPoint==cardGame->cardSize){
        		delete cardGame;

win_screen=new WinScreen();

        		win=true;

        		std::cout<<"you win";
        		  win_screen->setTimer((float)5.0f+level*1.1f);


        		win_screen->creatBallon();
win_screen->isActivate=true;
        	}

//display win screen till timer end
if(!win_screen->isWinDone()&&win){
win_screen->show();
// cout<<"update("<<endl;
}

//after win screen make new game;
if(win_screen->isWinDone()&&win){
	win=false;

win_screen->clearScreen();
delete win_screen;
int size=CardManager::max;
	if(level<size){//may be a proplem but now not
	level++;}else{
	level=3;
	}
	cardGame=new CardManager(level);


}


	        EndDrawing();
	    }



	    CloseWindow();

	    return 0;
}

