#include <iostream>
#include <math.h>
#include <string.h>
#include "player.cpp"
#include "board.cpp"
#ifndef GAMEACTIVE_H
#define GAMEACTIVE_H

using namespace std;

class GameActive{
	private:
		Player player;
		Board board;
	public:
		bool checkRow1(Board brd);
		bool checkRow2(Board brd);
		void fillRow1(Board &brd, Player &plr1);
		void fillRow2(Board &brd, Player &plr2);
		void gameStart(int x, Board &brd, Player &plr1, Player &plr2);
		void gameEnd(Player &plr1, Player &plr2);
};

bool GameActive::checkRow1(Board brd){
	int num = 0;
	for(int i = 1; i < 6; i++){
		if(brd.getBoard()[i] == 0) num++;
	}
	
	if(num == 5) return true;
	
	return false;
}

bool GameActive::checkRow2(Board brd){
	int num = 0;
	for(int i = 6; i < 12; i++){
		if(brd.getBoard()[i] == 0) num++;
	}
	
	if(num == 5) return true;
	
	return false;
}

void GameActive::fillRow1(Board &brd, Player &plr1){
	if(checkRow1(brd)){
		cout << "Hang cua ban da trong, tien hanh rai hat!\nBan bi tru 5 diem!";
		for(int i = 1; i < 6; i ++){
			brd.getBoard()[i] += 1;
			plr1.setScore(-1);
		}
	}
}

void GameActive::fillRow2(Board &brd, Player &plr2){
	if(checkRow2(brd)){
		cout << "Hang cua ban da trong, tien hanh rai hat!\nBan bi tru 5 diem!";
		for(int i = 6; i < 12; i ++){
			brd.getBoard()[i] += 1;
			plr2.setScore(-1);
		}
	}
}


void GameActive::gameStart(int x, Board &brd, Player &plr1, Player &plr2){
    int st, dir, i, nowScore = 0,seed;

    if (x == 1){
    	fillRow1(brd, plr1);
    	
    	cout << "\nLuot choi cua nguoi choi 1!\n";
        do{
            cout << "\nChon o bat dau(1-5): ";
            cin >> st;
            if (st < 1 or st > 5) cout << "\nO ban chon khong hop le! Vui long chon lai\n";
            if(brd.getBoard()[st] == 0) cout << "\nO ban chon hien tai khong con hat! Vui long chon lai\n";
        }while (st < 1 or st > 5 or brd.getBoard()[st] == 0);

        do{
            cout << "\nChon huong di cua ban(1: sang phai; -1: sang trai): ";
            cin >> dir;
            if (dir != 1 and dir != -1) cout << "\nHuong di ban chon khong hop le! Vui long chon lai\n";
        }while (dir != 1 and dir != -1);
		
		
        switch (dir){
        	case 1:
        		seed = brd.getBoard()[st];
				brd.getBoard()[st] = 0;

				while (seed > 0){
    				st = (st + dir + 12) % 12;
    				brd.getBoard()[st] += 1;
    				seed--;
    				
    				if (seed == 0){
    					
    					if(brd.getBoard()[(st + dir + 12) % 12] != 0){
    						if(brd.getBoard()[(st + dir + 12) % 12]==brd.getBoard()[0] or brd.getBoard()[(st + dir + 12) % 12]==brd.getBoard()[6]){
    							brd.getBoard()[(st + dir + 12) % 12]--;
    							brd.getBoard()[(st + dir + 12 + 1) % 12] +=1;
    							seed = brd.getBoard()[(st + dir + 12 + 2) % 12];
    							brd.getBoard()[(st + dir + 12 + 2) % 12] = 0;
    							st = (st + dir + 12 + 2) % 12;
							}
							else{
								seed = brd.getBoard()[(st + dir + 12) % 12];
        						brd.getBoard()[(st + dir + 12) % 12] = 0;
        						st = (st + dir + 12) % 12;
							}
						}
						
						while(brd.getBoard()[(st + dir + 12) % 12] == 0 and brd.getBoard()[(st + dir + 12 + 1) % 12] != 0){
							nowScore += brd.getBoard()[(st + dir + 12 + 1) % 12];
        					brd.getBoard()[(st + dir + 12 + 1) % 12] = 0;
        					plr1.setScore(nowScore);
        					st = (st + dir + 12 + 1) % 12;
						}
					}
				}
				break;
				
			case -1:
				seed = brd.getBoard()[st];
				brd.getBoard()[st] = 0;

				while (seed > 0) {
    				st = (st + dir + 12) % 12;
    				brd.getBoard()[st] += 1;
    				seed--;

    				if (seed == 0){
    					if(brd.getBoard()[(st + dir + 12) % 12] != 0){
	    					if(brd.getBoard()[(st + dir + 12) % 12]==brd.getBoard()[0] or brd.getBoard()[(st + dir + 12) % 12]==brd.getBoard()[6]){
    							brd.getBoard()[(st + dir + 12) % 12]--;
    							brd.getBoard()[(st + dir + 12 - 1) % 12] +=1;
    							seed = brd.getBoard()[(st + dir + 12 - 2) % 12];
    							brd.getBoard()[(st + dir + 12 - 2) % 12] = 0;
    							st = (st + dir + 12 - 2) % 12;
							}
							else{
								seed = brd.getBoard()[(st + dir + 12) % 12];
        						brd.getBoard()[(st + dir + 12) % 12] = 0;
        						st = (st + dir + 12) % 12;
							}
						}
							
						while(brd.getBoard()[(st + dir + 12) % 12] == 0 and brd.getBoard()[(st + dir + 12 - 1) % 12] != 0){
							nowScore += brd.getBoard()[(st + dir + 12 - 1) % 12];
        					brd.getBoard()[(st + dir + 12 - 1) % 12] = 0;
        					plr1.setScore(nowScore);
        					st = (st + dir + 12 - 1) % 12;
						}							    						
    				}
				}
				break;	
		
			default:
				break;	            
	}
}
	if (x == 2){
		fillRow2(brd, plr2);
		
    	cout << "\nLuot choi cua nguoi choi 2!\n";
        do{
            cout << "\nChon o bat dau(7-11): ";
            cin >> st;
            if (st < 7 or st > 11) cout << "\nO ban chon khong hop le! Vui long chon lai\n";
            if(brd.getBoard()[st] == 0) cout << "\nO ban chon hien tai khong con hat! Vui long chon lai\n";
        }while (st < 7 or st > 11 or brd.getBoard()[st] == 0);

        do{
            cout << "\nChon huong di cua ban(1: sang phai; -1: sang trai): ";
            cin >> dir;
            if (dir != 1 and dir != -1) cout << "\nHuong di ban chon khong hop le! Vui long chon lai\n";
        }while (dir != 1 and dir != -1);

        switch (dir){
        	case 1:
        		seed = brd.getBoard()[st];
				brd.getBoard()[st] = 0;

				while (seed > 0) {
    				st = (st - dir + 12) % 12;
    				brd.getBoard()[st] += 1;
    				seed--;
    				if (seed == 0){
    					if(brd.getBoard()[(st - dir + 12) % 12] != 0){
    						if(brd.getBoard()[(st - dir + 12) % 12] == brd.getBoard()[0] or brd.getBoard()[(st - dir + 12) % 12] == brd.getBoard()[6]){
    							brd.getBoard()[(st - dir + 12) % 12]--;
    							brd.getBoard()[(st - dir + 12 - 1) % 12] +=1;
    							seed = brd.getBoard()[(st - dir + 12 - 2) % 12];
    							brd.getBoard()[(st - dir + 12 - 2) % 12] = 0;
    							st = (st - dir + 12 - 2) % 12;
							}
							else{
								seed = brd.getBoard()[(st - dir + 12) % 12];
        						brd.getBoard()[(st - dir + 12) % 12] = 0;
        						st = (st - dir + 12) % 12;
							}
						}
						
						while(brd.getBoard()[(st - dir + 12) % 12] == 0 and brd.getBoard()[(st - dir + 12 - 1) % 12] != 0){
        					nowScore += brd.getBoard()[(st - dir + 12 - 1) % 12];
        					brd.getBoard()[(st - dir + 12 - 1) % 12] = 0;
        					plr2.setScore(nowScore);
							st = (st - dir + 12 - 1) % 12;							
						}
    				}
				}
				break;
				
			case -1:
				seed = brd.getBoard()[st];
				brd.getBoard()[st] = 0;

				while (seed > 0) {
    				st = (st - dir + 12) % 12;
    				brd.getBoard()[st] += 1;
    				seed--;

    				if (seed == 0 && brd.getBoard()[(st - dir + 12) % 12] != 0) {
    					if(brd.getBoard()[(st - dir + 12) % 12] != 0){
    						if(brd.getBoard()[(st - dir + 12) % 12] == brd.getBoard()[0] or brd.getBoard()[(st - dir + 12) % 12] == brd.getBoard()[6]){
    							brd.getBoard()[(st - dir + 12) % 12]--;
    							brd.getBoard()[(st - dir + 12 + 1) % 12] +=1;
    							seed = brd.getBoard()[(st - dir + 12 + 2) % 12];
    							brd.getBoard()[(st - dir + 12 + 2) % 12] = 0;
    							st = (st - dir + 12 + 2) % 12;
							}
							else{
								seed = brd.getBoard()[(st - dir + 12) % 12];
        						brd.getBoard()[(st - dir + 12) % 12] = 0;
        						st = (st - dir + 12) % 12;
							}
						}
						
						while(brd.getBoard()[(st - dir + 12) % 12] == 0 and brd.getBoard()[(st - dir + 12 + 1) % 12] != 0){
							nowScore += brd.getBoard()[(st - dir + 12 + 1) % 12];
        					brd.getBoard()[(st - dir + 12 + 1) % 12] = 0;
        					plr2.setScore(nowScore);
        					st = (st - dir + 12 + 1) % 12;
						}
    				}
				}
				break;
			default:
				break;	            
		}
	}
}

void GameActive::gameEnd(Player &plr1, Player &plr2){
	cout << "Tro choi ket thuc!\n";
	cout << "Diem cua 2 nguoi choi la:\n";
	cout << left << setw(20) << plr1.getName() << left << setw(20) << plr2.getName() << endl;
	cout << left << setw(20) << plr1.getScore() << left << setw(20) << plr2.getScore();
	if(plr1.getScore() > plr2.getScore()){
		cout << "\n NGUOI CHIEN THANG LA ";
		for(int i = 0; i < plr1.getName().size(); i++){
			plr1.getName()[i] = toupper(plr1.getName()[i]);
			cout << plr1.getName()[i];
		}
	}
	else{
		cout << "\n NGUOI CHIEN THANG LA ";
		for(int i = 0; i < plr2.getName().size(); i++){
			plr2.getName()[i] = toupper(plr2.getName()[i]);
			cout << plr2.getName()[i];
		}
	}
}
#endif //GAMEACTIVE_H