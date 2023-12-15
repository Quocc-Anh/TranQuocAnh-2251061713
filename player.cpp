#include <iostream>
#include <math.h>
#include <string.h>
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player{
	private:
		string name;
		int score = 0;
		bool turnStart = false;
	public:
		void enterName();
		string getName() const;
		int getScore();
		void setScore(int a);
		bool getTurnStart() const;
		void setTurnStart(bool value);
};

void Player::enterName(){
	getline(cin, name);
}

string Player::getName() const{
	return name;
}


int Player::getScore(){
	return score;
}

void Player::setScore(int a){
	score +=a;
}

bool Player::getTurnStart() const{
	return turnStart;
}

void Player::setTurnStart(bool value){
	turnStart = value;
}

#endif //PLAYER_H