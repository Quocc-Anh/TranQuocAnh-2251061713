#include<bits/stdc++.h>
using namespace std;

class Solver {
    int n, s;
    int a[500];
    char op[500];
    bool found = false;

public:
    Solver(int n, int s) : n(n), s(s) {
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }
    }

    void solve() {
        solve(1, 1);
        if (!found) {
            cout << "Impossible" << endl;
        }
    }

private:
    void solve(int i, int sum) {
        if (found) return;
        if (i == n) {
            if (sum == s) {
                found = true;
                for (int j = 1; j < n; j++) {
                    cout << a[j] << op[j];
                }
                cout << a[n] << endl;
            }
            return;
        }
        op[i] = '+';
        solve(i + 1, sum + a[i + 1]);
        op[i] = '-';
        solve(i + 1, sum - a[i + 1]);
    }
};

int main() {
    int n, s;
    cin >> n >> s;
    Solver solver(n, s);
    solver.solve();
    return 0;
}

