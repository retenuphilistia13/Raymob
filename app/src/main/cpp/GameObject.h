/*
 * GameObject.h
 *
 *  Created on: Sep 27, 2023
 *      Author: ahmed
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include"raylib.h"


class GameObject {
private:
	float deltaTime;
public:
		bool isClicked;
float getDeltaTime(){
	return deltaTime;
}
	Rectangle destRect;
	Rectangle sourceRect ;

	Vector2 position;
	Vector2 size;

	Texture2D texture;

	 void updateSize(){
		destRect.width=size.x;

		destRect.height=size.y;
	}
	 void updatePos(){
		destRect.x=position.x;

		destRect.y=position.y;
	}
	void setScaleWidth(float scaleX){
		destRect={position.x,position.y,destRect.width*scaleX,destRect.height};
	}

	void setTexture(const char* a){
			texture=LoadTexture(a);
			 sourceRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
	}
	void setScale(float scale){
		destRect={position.x,position.y,destRect.width*scale,destRect.height*scale};

	}
	void update(){
		deltaTime=GetFrameTime();
		this->updatePos();
		this->updateSize();
	}
	GameObject();
	virtual ~GameObject();
};

#endif /* GAMEOBJECT_H_ */
