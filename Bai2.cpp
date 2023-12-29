#include <bits/stdc++.h>

using namespace std;

class cacBien{
    private:
        vector<int> numbers;
    public:
        void nhapChuoi(const string& str);
        int ketQua();
};

void cacBien::nhapChuoi(const string& str){
    stringstream ss(str);
    char ch;
    int num;
    while (ss >> ch){
        if (isdigit(ch) || (ch == '-' && isdigit(ss.peek()))){
            ss.unget();
            ss >> num;
            numbers.push_back(num);
        }
    }
}

int cacBien::ketQua(){
    if (numbers.size() < 4){
        return 0;
    }
    return numbers[0] + (numbers[1] - abs(numbers[2])) * numbers[3];
}

int main(){
    string str;
    getline(cin, str);
    cacBien A;
    A.nhapChuoi(str);
    cout << A.ketQua();
    return 0;
}

