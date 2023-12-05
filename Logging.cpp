#include <bits/stdc++.h>

using namespace std;

class Matrix {
public:
    vector<std::vector<int> > data;

    Matrix(int rows, int cols) : data(rows, vector<int>(cols, 0)) {}

    void input() {
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[0].size(); j++) {
                cin >> data[i][j];
            }
        }
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(data.size(), data[0].size());
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[0].size(); j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) {
        Matrix result(data.size(), data[0].size());
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[0].size(); j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) {
        Matrix result(data.size(), other.data[0].size());
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < other.data[0].size(); j++) {
                for (int k = 0; k < data[0].size(); k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    void display() {
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[0].size(); j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Logger {
public:
    ofstream logFile;

    Logger(const string& filename) {
        logFile.open(filename.c_str());
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void log(const string& operation, const Matrix& matrix) {
        logFile << operation << ":\n";
        for (int i = 0; i < matrix.data.size(); i++) {
            for (int j = 0; j < matrix.data[0].size(); j++) {
                logFile << matrix.data[i][j] << " ";
            }
            logFile << "\n";
        }
    }
};

int main() {
	
	int n, m;
	cout << "Nhap so cot: "; cin >> n;
	cout << "Nhap so hang: "; cin >> m;

    Matrix A(n, m);
    Matrix B(n, m);	
		
    Logger logger("log.txt");

    cout << "Nhap ma tran A:\n";
    A.input();
    cout << "Nhap ma tran B:\n";
    B.input();

    Matrix C = A + B;
    logger.log("A + B", C);

    Matrix D = A - B;
    logger.log("A - B", D);

    Matrix E = A * B;
    logger.log("A * B", E);

    return 0;
}

