#include <bits/stdc++.h>

using namespace std;

class soNguyen{
	private:
		int a;
		int b;
	public:
		void nhap(int &X,int &Y);
		void congSo(int a, int b);
		void in();
};

void soNguyen::nhap(int &X, int &Y){
	this->a=X;
	this->b=Y;
}

void soNguyen::congSo(int a,int b){
	cout << a+b;
}

int main(){
	int X, Y;
	cin >> X >> Y;
	soNguyen A;
	A.nhap(X,Y);
	A.congSo(X,Y);
	return 0;
}
