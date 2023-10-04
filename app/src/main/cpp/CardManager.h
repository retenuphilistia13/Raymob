/*
 * CardManager.h
 *
 *  Created on: Sep 24, 2023
 *      Author: ahmed
 */

#ifndef CARDMANAGER_H_
#define CARDMANAGER_H_

#include"raylib.h"
#include<vector>
#include<iostream>

#include <random>

#include"Card.h"
#include"Timer.h"
#include"GameObject.h"
#include"HelperFunction.h"
using std::vector;
using std::cout;
using std::endl;

//todo make it in seperate class (helper function)
//extern const int screenWidth;
//extern const int screenHeight;
//

class CardManager {
public:
static constexpr int max=6;


	std::vector<Card*> cards;

	int cardIndex1=-1,cardIndex2=-1;

	bool nextCard=false;

	bool startTimer=false;

	bool isReset=false;
Timer intervalCard;

	CardManager(int card);
	 ~CardManager();


    // Load a texture
    Texture2D texture ;

int playerPoint=0;

    float scale=0.3;
    Vector2 pos;

Vector2 backSize;

    Rectangle sourceRect ;
    Rectangle destRect ;






//load front texture

vector<Texture2D>frontText;

int cardSize=1;
const char* path[6]={"sara.png","saeda.png","father.png","reema.png","ahmed.png","dema.png"};
//		,"banana_joe.png","darwin.png"};

	void update();
	void draw();
};

#endif /* CARDMANAGER_H_ */
