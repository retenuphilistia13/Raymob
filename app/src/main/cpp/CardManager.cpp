/*
 * CardManager.cpp
 *
 *  Created on: Sep 24, 2023
 *      Author: ahmed
 */

#include "CardManager.h"

//extern const int screenWidth;
//extern const int screenHeight;


CardManager::CardManager(int card) {
	// TODO Auto-generated constructor stub

cardSize=card;

	texture = LoadTexture("card.png");




	Vector2 backSize;
	backSize.x=texture.width;
	backSize.y=texture.height;

	sourceRect = { 0.0f, 0.0f, (float)backSize.x, (float)backSize.y };

	Vector2 size;

    float maxScale = static_cast<float>(GetScreenWidth()) / (static_cast<float>(cardSize) * texture.width);//if portrait
//  float maxScale = static_cast<float>(screenHeight) / (static_cast<float>(cardSize) * texture.width);//if landscape
float maxScaleY = static_cast<float>(screenHeight) / (static_cast<float>(cardSize) * texture.height*0.77f);

    float scale = std::min(maxScale, 0.6f); // Ensure scale is not greater than 1
    float scaleY = std::min(maxScaleY, 0.5f); // Ensure scale is not greater than 1

    size.x = static_cast<float>(texture.width) * scale;
    size.y = static_cast<float>(texture.height) * scaleY;

    		pos.x=0+size.x;
    	    pos.y=0;

    	  destRect = { pos.x, pos.y,size.x, size.y };

    		for(int i=0;i<cardSize;i++){
    			Texture2D front;

    			front=LoadTexture(path[i]);
    			frontText.push_back(front);

    		}
    Vector2 spacing;
    spacing.x=(size.x*0.2f);


    destRect.x=spacing.x;
      destRect.y+=(texture.height/2)/2;

    std::cout<<"texture width"<<texture.width<<std::endl;
    std::cout<<"scale width"<<scale<<std::endl;
    std::cout<<"space"<<spacing.x<<std::endl;

    float totalWidth=0;
    int count=0;
    	    for (int i = 0; i < cardSize * 2; i++) {
        Texture2D front = LoadTexture(path[i % cardSize]);
        frontText.push_back(front);

        Card* card = new Card(destRect, texture, frontText[i % cardSize]);
        card->setId(i % cardSize);
        cards.push_back(card);
    totalWidth+=destRect.x;
        // Update position for the next card
        destRect.x += size.x+spacing.x;
    		count++;


        // Check if the next card should be on a new row
        if (destRect.x + size.x +spacing.x > GetScreenWidth())

    	 {
            destRect.y += size.y * 1.2f; // Add some spacing between rows
            destRect.x =spacing.x;             // Start from the left of the screen

        }
    }

    std::cout<<"totalWidth"<<totalWidth<<std::endl;
    	        shuffleVector(cards);

	        shuffleVector(cards);


}


void CardManager::update(){

    for(int i=0;i<cards.size();i++){

     	cards[i]->update();



     if(cards[i]->isIsClicked()&&(cardIndex2!=i&&cardIndex1==-1)&&nextCard==false){

     		cardIndex1=i;
     		nextCard=true;
     		std::cout<<"cardIndex1 "<<cardIndex1<<" :"<<cards[i]->getId()<<std::endl;
     	}

   	 if(cards[i]->isIsClicked()&&(cardIndex1!=i&&cardIndex2==-1)&&nextCard==true){
   		cardIndex2=i;
   		std::cout<<"cardIndex2 "<<cardIndex2<<" :"<<cards[i]->getId()<<std::endl;
   	 }

   	 //reset after two
   	 if( (cardIndex1!=-1&&cardIndex2!=-1) &&cards[i]->isIsClicked()&&!isReset){
   		isReset=true;
   		intervalCard.StartTimer(1.4f);
       }


     	//end if reset


     }



		 if(isReset&&intervalCard.TimerDone()){

		cards[cardIndex1]->setIsClicked(false);
		cards[cardIndex2]->setIsClicked(false);

	    if(cardIndex1!=-1&&cardIndex2!=-1)//only if defined
	    if(cards[cardIndex1]->getId()==cards[cardIndex2]->getId()){

        cout<<"matched: "<<endl;

	    	    int id1 = cards[cardIndex1]->getId();
	    	    int id2 = cards[cardIndex2]->getId();

	    	    cards[cardIndex1]->setMatched(true);
	    	    cards[cardIndex2]->setMatched(true);
	    	    cout << "After erasing:" << std::endl;
	    	    std::cout << "cardIndex1 " << cardIndex1 << " : " << id1 << std::endl;
	    	    std::cout << "cardIndex2 " << cardIndex2 << " : " << id2 << std::endl;
	    	    playerPoint++;
	    }
		cardIndex1=-1;cardIndex2=-1;

		nextCard=false;
		startTimer=false;
        isReset=false;

	    }

		    if(isReset&&!intervalCard.TimerDone())
		    	intervalCard.UpdateTimer();

}



void CardManager::draw(){
    for(int i=0;i<cards.size();i++){

    	cards[i]->draw();
    }

}
CardManager::~CardManager() {
	// TODO Auto-generated destructor stub

    UnloadTexture(texture);
    for(int i=0;i<frontText.size();i++){
	    UnloadTexture(frontText[i]);
    }

    for (int i = 0; i < cards.size(); ++i) {
            delete cards[i];
    }
cards.clear();

}

