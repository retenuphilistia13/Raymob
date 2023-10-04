/*
 * Ballon.h
 *
 *  Created on: Sep 28, 2023
 *      Author: ahmed
 */

#ifndef BALLON_H_
#define BALLON_H_
#include"GameObject.h"
#include<iostream>
using std::cout;
class Ballon: public GameObject{
	float speed;
public:

	 const char* color[2]{"blue_ballon.png","red_ballon.png"};

	Ballon(Rectangle rec);

	~Ballon();
void updateRatio();
void setSpeed(float speed1);
	void update();

	void draw();

	Ballon* creatBallon();
};
#endif /* BALLON_H_ */
