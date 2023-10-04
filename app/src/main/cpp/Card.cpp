/*
 * Card.cpp
 *
 *  Created on: Sep 22, 2023
 *      Author: ahmed
 */

#include "Card.h"

Card::Card(Rectangle rec,Texture2D backText,Texture2D frontText) {
	// TODO Auto-generated constructor stub
//	 position=pos;
	 texture=backText;
	 frontTexture=frontText;

	 destRect =rec;
	 position.x=destRect.x;
	 position.y=destRect.y;

		frontTexture.width=texture.width;
		frontTexture.height=texture.height;

		size.x=destRect.width;
		size.y=destRect.height;

	 sourceRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
	 isClicked=false;

//	 origin = { position.x+texture.width / 2,position.y+ texture.height / 2 };



}



void Card::draw(){
	   // Draw the textured rectangle
	if(!matched){
	if(!isClicked){

        DrawTexturePro(texture, sourceRect, destRect, Vector2{0, 0}, 0.0f, WHITE);
	}
	else if(isClicked){


//
//	if(!animateTime.TimerDone()){
//			setScaleWidth(0.9);
//			 DrawTexturePro(texture, sourceRect, destRect, Vector2{0, 0}, 0.0f, WHITE);
//	}
//		transition=false;
//
//
//
//
////normal view after animation
//		if(animateTime.TimerDone()){
//		destRect.width=size.x;
//
//		}
	 DrawTexturePro(frontTexture, sourceRect, destRect, Vector2{0, 0}, 0.0f, WHITE);
//		destRect.width=size.x;

	}

	}
}



void Card::update(){

	if(!matched){


//detect mouse input
if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
Vector2 mousePosition= GetMousePosition();

if(CheckCollisionPointRec(mousePosition,destRect)){
	isClicked=true;
	transition=true;
}
//detect android input
if (IsGestureDetected(GESTURE_TAP)) {
      Vector2 touchPosition = GetTouchPosition(0); // Get the position of the first touch (assuming single touch)

      if (CheckCollisionPointRec(touchPosition, destRect)) {
          isClicked = true;
          transition=true;
          animateTime.StartTimer(0.5f);
      }
  }
   }

animateTime.UpdateTimer();//borrowing




}



//	position=GetMousePosition();
//
//	destRect.x=position.x;
//	destRect.y=position.y;
}


Card::~Card() {
	// TODO Auto-generated destructor stub

	  UnloadTexture(texture);
	  UnloadTexture(frontTexture);

}

