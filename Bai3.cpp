#include <bits/stdc++.h>

using namespace std;

class TruyVan{
	private:
    	int u, v;
	public:
    	TruyVan(int uu, int vv) : u(uu), v(vv){}
    	int layU() const{
        	return u;
    	}
    	int layV() const{
        	return v;
    	}
};

class CapNhat{
	private:
    	int u, v, k;
	public:
    	CapNhat(int uu, int vv, int kk) : u(uu), v(vv), k(kk){}
    	int layU() const{
        	return u;
    	}
    	int layV() const{
        	return v;
    	}
    	int layK() const{
       		return k;
    	}
};

class CapNhatMang{
	private:
    	vector<int> mang;
	public:
    	CapNhatMang(int n) : mang(n, 0){}
    	void apDungCapNhat(const CapNhat& capNhat){
        	mang[capNhat.layU() - 1] += capNhat.layK();
        	if (capNhat.layV() < mang.size()) {
            	mang[capNhat.layV()] -= capNhat.layK();
        	}
   		}
    	void tinhTongTienTo(){
        	for (int i = 1; i < mang.size(); ++i){
            	mang[i] += mang[i - 1];
        	}
    	}
    	int layGiaTriLonNhatTrongDoan(int u, int v) const{
        	int giaTriLonNhat = INT_MIN;
        	for (int i = u - 1; i < v; ++i){
            	giaTriLonNhat = max(giaTriLonNhat, mang[i]);
        	}
        	return giaTriLonNhat;
    	}	
};

int main(){
    int n, m;
    cin >> n >> m;

    CapNhatMang capNhatMang(n);

    for (int i = 0; i < m; ++i){
        int u, v, k;
        cin >> u >> v >> k;
        CapNhat capNhat(u, v, k);
        capNhatMang.apDungCapNhat(capNhat);
    }

    capNhatMang.tinhTongTienTo();

    int p;
    cin >> p;

    for (int i = 0; i < p; ++i){
        int u, v;
        cin >> u >> v;
        TruyVan truyVan(u, v);
        cout << capNhatMang.layGiaTriLonNhatTrongDoan(truyVan.layU(), truyVan.layV()) << endl;
    }

    return 0;
}

