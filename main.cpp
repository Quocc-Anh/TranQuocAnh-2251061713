#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "player.cpp"
#include "board.cpp"
#include "gameactive.cpp"

using namespace std;

int main(){
	Player a, b;
	Board brd;
	GameActive game;
	
	cout << "Nhap ten nguoi choi thu 1: "; 
	a.enterName();
	
	cout << "Nhap ten nguoi choi thu 2: "; 
	b.enterName();
	
	brd.printBoard(a, b);
	
	cout << "Tien hanh lua chon nguoi di truoc!\n";
	
	srand(time(NULL));
    int res = rand() % 2 + 1;
    
    cout << "Nguoi choi " << res << " duoc di truoc!\n";
    
    while(brd.getBoard()[0] != 0 or brd.getBoard()[6] != 0){
		game.gameStart(res, brd,a,b);
		system("cls");
		brd.printBoard(a, b);
		res = res % 2 + 1;
	}
	
	if(brd.getBoard()[0] == 0 and brd.getBoard()[6] == 0){
		for(int i = 1; i < 6; i++){
			a.setScore(brd.getBoard()[i]);
		}
		for(int i = 7; i < 12; i++){
			b.setScore(brd.getBoard()[i]);
		}
	}
	
	game.gameEnd(a,b);
	return 0;
}