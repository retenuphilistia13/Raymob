/*
 * GameObject.cpp
 *
 *  Created on: Sep 27, 2023
 *      Author: ahmed
 */

#include "GameObject.h"

GameObject::GameObject() {
	// TODO Auto-generated constructor stub
	deltaTime=GetFrameTime();//first assigning delta Time
	
}

GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
	UnloadTexture(texture);
}

