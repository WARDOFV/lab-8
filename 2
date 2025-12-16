#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "nety" << endl;
        return 1;
    }

    int m, n;
    inputFile >> m >> n;

    // создаем матрицы
    double** A = new double* [m];
    for (int i = 0; i < m; i++) {
        A[i] = new double[n];
    }

    double* B = new double[n];

    double** C = new double* [n];
    for (int i = 0; i < n; i++) {
        C[i] = new double[m];
    }

    double* D = new double[m];

    // засоываем данные в више созданние матрицы
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        inputFile >> B[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inputFile >> C[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        inputFile >> D[i];
    }

    inputFile.close();


    // создаем два массива
    double* AT_B = new double[m]();  
    double* C_D = new double[n]();  

    // считаем
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            AT_B[i] += A[i][j] * B[j];
        }
    }

    // ещё считаем
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C_D[i] += C[i][j] * D[j];
        }
        C_D[i] *= 10.0;
    }

    // проверяем по правилу что чтобы при сложении или вычитании стобчы дожны быть равны строкам в матрицах
    if (m != n) {
        cout << "no no no mister fish" << endl;
        return 1;
    }

    // Результат
    cout << "polychaem-" << endl;
    for (int i = 0; i < m; i++) {
        double result = AT_B[i] - C_D[i];
        cout << result << endl;
    }



    return 0;
}
