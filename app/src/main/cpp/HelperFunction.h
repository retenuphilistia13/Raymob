/*
 * HelperFunction.h
 *
 *  Created on: Sep 28, 2023
 *      Author: ahmed
 */

#ifndef HELPERFUNCTION_H_
#define HELPERFUNCTION_H_
#include<vector>
#include<random>
#include"GameObject.h"
#include"Card.h"
template <typename T>
void customSwap(T& ptr1, T& ptr2) {
    T temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

// Function to shuffle a vector
template <typename T>
void shuffleVector(std::vector<T>& vec) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Shuffle the pointers using the Fisher-Yates shuffle algorithm
    for (int i = vec.size()-1 ; i > 0; --i) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        customSwap(vec[i]->position, vec[j]->position);
//            vec[i]->updatePos();//            vec[j]->updatePos();
        vec[i]->GameObject::update();
        vec[j]->GameObject::update();

    }
}
#endif /* HELPERFUNCTION_H_ */
