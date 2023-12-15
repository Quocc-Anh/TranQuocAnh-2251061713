#include <iostream>
#include <math.h>
#include <iomanip>
#include <string.h>
#include "player.cpp"
#ifndef BOARD_H
#define BOARD_H


const int NUM_BEADS_SMALL = 5;
const int NUM_BEADS_BIG = 1;

using namespace std;

class Board : private Player{
	private:
		int board[12];
	public:
		Board();
		int* getBoard();
		void printBoard(Player a, Player b);
};

Board::Board(){
	board[0] = NUM_BEADS_BIG; 
	board[6] = NUM_BEADS_BIG;
	for(int i = 1; i < 6; i++){
		board[i] = NUM_BEADS_SMALL;
	}
	for(int i = 7; i < 12; i++){
		board[i] = NUM_BEADS_SMALL;
	}
}

int* Board::getBoard(){
	return board;
}

void Board::printBoard(Player a, Player b){
	// Khung ten nguoi choi 1
	cout<<"      ";
	for(int i=0;i<31;i++){
			cout<<"_";
	}
	cout<<endl;
	cout<<"      |                             |\n";
	if(a.getName().size()%2!=0){
		cout<<"      |";
		for(int i=0;i<(29-a.getName().size())/2;i++){
			cout<<" ";
		}
		cout<<a.getName();
		for(int i=0;i<(28-a.getName().size())/2;i++){
			cout<<" ";
		}
		cout<<" |";
		cout<<endl;
	}else{
		cout<<"      |";
		for(int i=0;i<(29-a.getName().size())/2;i++){
			cout<<" ";
		}
		cout<<a.getName();
		for(int i=0;i<(29-a.getName().size())/2;i++){
			cout<<" ";
		}
		cout<<" |";
		cout<<endl;
	}
	//In ra ban co
	cout<<"______|__1_____2_____3_____4_____5__|______";
	cout<<"\n|     |     |     |     |     |     |     |\n";
	cout<<"|     ";
	for(int i=1;i<6;i++){
		cout<<"|  "<<setw(3)<<left<<board[i];
	}
	cout<<"|     |";
	cout<<"\n|     |_____|_____|_____|_____|_____|     |\n";
    cout <<"|     |                             |     |";
	cout<<endl;
	cout<<"|  "<<setw(3)<<left<<board[0]<<"|"
	<<"                             "<<"|  "<<setw(3)<<left<<board[6]<<"|";
	cout<<"\n|     |__11____10____9_____8_____7__|     |\n";
	cout<<"|     |     |     |     |     |     |     |\n";;
	cout<<"|     ";
	for(int i=11;i>=7;i--){
		cout<<"|  "<<setw(3)<<board[i];
	}
	cout<<"|"<<"     |"<<endl;
	cout<<"|_____|_____|_____|_____|_____|_____|_____|\n";
	//Khung ten nguoi choi 2
	cout<<"      |                             |\n";
	if(b.getName().size()%2!=0){
		cout<<"      |";
		for(int i=0;i<(29-b.getName().size())/2;i++){
			cout<<" ";
		}
		cout<<b.getName();
		for(int i=0;i<(28-b.getName().size())/2;i++){
			cout<<" ";
		}
		cout<<" |";
		cout<<endl;
	}else{
		cout<<"      |";
		for(int i=0;i<(29-b.getName().size())/2;i++){
			cout<<" ";
		}
		cout<<b.getName();
		for(int i=0;i<(29-b.getName().size())/2;i++){
			cout<<" ";
		}
		cout<<" |";
		cout<<endl;
	}
	cout<<"      |_____________________________|\n";
}


#endif //BOARD_H