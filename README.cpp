```
#include <iostream>
#include <limits> // Для std::numeric_limits
#include <string> // Для std::string

using namespace std;

// Размер игрового поля
const int SIZE = 3;

// Функция для отображения игрового поля
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) {
                cout << " | "; // Разделитель между клетками
            }
        }
        cout << endl;
        if (i < SIZE - 1) {
            cout << "---------"; // Разделитель между строками
            cout << endl;
        }
    }
    cout << endl; // Дополнительный отступ после отображения поля
}

// Функция для проверки победителя
char checkWinner(char board[SIZE][SIZE]) {
    // Проверка строк и столбцов
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Проверка диагоналей
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

// Функция для проверки, заполнено ли поле
bool isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Функция для проверки, является ли строка числом
bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "RU");
    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);

        string inputRow, inputCol;
        int row, col;
        cout << "Игрок " << currentPlayer << ", введите номер строки и столбца через пробел (1-3) : ";

        cin >> inputRow >> inputCol;

        // Проверка ввода на числовое значение
        if (!isNumber(inputRow)  !isNumber(inputCol)) {
            cout << "Некорректный ввод. Пожалуйста, введите только цифры." << endl;
            continue;
        }

        row = stoi(inputRow); // Преобразуем строку в число
        col = stoi(inputCol);

        // Проверка корректности ввода
        if (row < 1  row > SIZE  col < 1  col > SIZE || board[row - 1][col - 1] != ' ') {
            cout << "Некорректный ход. Учитывайте размерры доски." << endl;
            continue;
        }

        // Уменьшаем на 1, чтобы использовать в индексации массива
        board[row - 1][col - 1] = currentPlayer;

        // Проверка на победу
        char winner = checkWinner(board);
        if (winner != ' ') {
            printBoard(board);
            cout << "ПОБЕДА!!! " << winner << "он выйиграл внатуре)!" << endl;
            break;
        }

        // Проверка на ничью
        if (isBoardFull(board)) {
            printBoard(board);

            cout << "Ничья!" << endl;
            break;
        }

        // Смена игрока
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
```
