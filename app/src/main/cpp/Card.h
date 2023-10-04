/*
 * Card.h
 *
 *  Created on: Sep 22, 2023
 *      Author: ahmed
 */

#ifndef CARD_H_
#define CARD_H_
#include<raylib.h>
#include"Timer.h"
#include"GameObject.h"
class Card:public GameObject{

	private:

	int ID;
	bool matched=false;
public:


Timer animateTime;



static bool isAbleToFlip;
bool transition=false;;


Vector2 origin ;


Texture2D frontTexture;

	Card(Rectangle rec,Texture2D backText,Texture2D frontText);
	virtual ~Card();


	void draw();
	void update();
//	~Card();


void updateSize(){
	destRect.width=size.x;

	destRect.height=size.y;
}
void updatePos(){
	destRect.x=position.x;

	destRect.y=position.y;
}
	static bool isIsAbleToFlip() {
		return isAbleToFlip;
	}


	bool isIsClicked() const {
		return isClicked;
	}

	void setIsClicked(bool isClicked) {
		this->isClicked = isClicked;
	}

	int getId() const {
		return ID;
	}

	void setId(int id) {
		ID = id;
	}

	bool isMatched() const {
		return matched;
	}

	void setMatched(bool matched = false) {
		this->matched = matched;
	}
};

#endif /* CARD_H_ */
