/*
 * Ballon.cpp
 *
 *  Created on: Sep 28, 2023
 *      Author: ahmed
 */

#include "Ballon.h"

Ballon::Ballon(Rectangle rec){

	 destRect =rec;

	 position.x=destRect.x;
	 position.y=destRect.y;

		size.x=destRect.width;
		size.y=destRect.height;

		 // setTexture(color[1]);

		speed=0;
		isClicked=false;
//texture=LoadTexture("assets/blue_ballon.png");
//
//	 sourceRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
}


void Ballon::updateRatio(){
//	Vector2 ratio;
//	ratio.x=texture.width/size.x;
//	ratio.y=texture.height/size.y;
//
//	destRect.width=size.x*ratio.x;
//	destRect.height=size.y*ratio.y;

}
void Ballon::setSpeed(float speed1){
	speed=speed1;
}
	void Ballon::update(){


		position.y-=speed*getDeltaTime();

		GameObject::update();

//updatePos();
//updateSize();
	}

	void Ballon::draw(){
if(isVisible)
		DrawTexturePro(texture, sourceRect, destRect, Vector2{0, 0}, 0.0f, WHITE);
		else if(!isVisible){

			cout<<"clicked";
		}
	}

	Ballon* Ballon::creatBallon(){

	}

Ballon::~Ballon(){
	  UnloadTexture(texture);
}

