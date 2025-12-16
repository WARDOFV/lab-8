#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <climits>
#include <iomanip>

using namespace std;

int get_from_interval(int a, int b) {
    return rand() % (b - a + 1) + a;
}

void echo_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int** fill_matrix(int n, int a, int b) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = get_from_interval(a, b);
        }
    }
    return matrix;
}

void clear_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool is_green_area(int i, int j, int n) {
    // Левая верхняя часть: выше главной диагонали и выше побочной диагонали
    // Правая нижняя часть: ниже главной диагонали и ниже побочной диагонали
    return (j < i && i < n - j - 1) || (j > i && i > n - j - 1);
}

bool is_red_area(int i, int j, int n) {
    // Левая нижняя часть: ниже главной диагонали и выше побочной диагонали
    // Правая верхняя часть: выше главной диагонали и ниже побочной диагонали
    return (j > i && i < n - j - 1) || (j < i && i > n - j - 1);
}

void swap_elements(int** matrix, int n) {
    setlocale(LC_ALL, "RU");
    int max_neg_green = INT_MIN;
    int min_pos_red = INT_MAX;
    pair<int, int> green_pos = { -1, -1 };
    pair<int, int> red_pos = { -1, -1 };

    // Поиск максимального отрицательного в зеленой области
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_green_area(i, j, n) && matrix[i][j] < 0) {
                if (matrix[i][j] > max_neg_green) {
                    max_neg_green = matrix[i][j];
                    green_pos = { i, j };
                }
            }
        }
    }

    // Поиск минимального положительного в красной области
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_red_area(i, j, n) && matrix[i][j] > 0) {
                if (matrix[i][j] < min_pos_red) {
                    min_pos_red = matrix[i][j];
                    red_pos = { i, j };
                }
            }
        }
    }

    // Проверка, что оба элемента найдены
    if (green_pos.first != -1 && red_pos.first != -1) {
        // Перестановка элементов
        int temp = matrix[green_pos.first][green_pos.second];
        matrix[green_pos.first][green_pos.second] = matrix[red_pos.first][red_pos.second];
        matrix[red_pos.first][red_pos.second] = temp;

        cout << "\nПерестановка выполнена успешно!" << endl;
        cout << "Макс. отрицательный в зеленой зоне: " << max_neg_green
            << " на позиции (" << green_pos.first << "," << green_pos.second << ")" << endl;
        cout << "Мин. положительный в красной зоне: " << min_pos_red
            << " на позиции (" << red_pos.first << "," << red_pos.second << ")" << endl;
    }
    else {
        cout << "\nПерестановка не выполнена!" << endl;
        if (green_pos.first == -1) {
            cout << "Не найден подходящий элемент в зеленой области" << endl;
        }
        if (red_pos.first == -1) {
            cout << "Не найден подходящий элемент в красной области" << endl;
        }
    }
}

int main() {
    srand(time(nullptr));
    setlocale(LC_ALL, "RU");
    int n, a, b;
    cout << "Введите размер матрицы: ";
    cin >> n;
    cout << "Введите интервал для генерации значений (a b): ";
    cin >> a >> b;

    int** matrix = fill_matrix(n, a, b);

    cout << "\nИсходная матрица:" << endl;
    echo_matrix(matrix, n);

    swap_elements(matrix, n);

    cout << "\nМатрица после перестановки:" << endl;
    echo_matrix(matrix, n);

    clear_matrix(matrix, n);

    return 0;
}
