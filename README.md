#include <iostream>
using namespace std;
const int SIZE = 3;
void doska(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout«board[i][j]«" ";
        }
        cout « endl;
    }   
    cout « "-------\n";
}
char winni(char board[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; ++i)
    {
        if (board[0][i] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
        if (board[0][0] == board[1][1] && board[1][1]==board[2][2] && board[0][0] != ' ')
            return board[0][0];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
            return board[0][2];
    }
    return ' ';
}
bool polnalidoska(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }   
        }
    }
    return true;
}
int main()
{
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    while (true){
        doska(board);
        int stroka, stolbik;
        cout«"Введите номер строки и столбца(цифра от 0 до 2):"«endl;
        cin » stroka » stolbik;
        if (stroka < 0 || stroka >= SIZE || stolbik < 0 || stolbik >= SIZE || board[stroka][stolbik] != ' ')
        {
            cout «"Такого хода быть не может. Начните ещё раз"«endl;
            continue;
        }
        board[stroka][stolbik] = player;
        char winner = winni(board);
        if (winner != ' ')
        {
            doska(board);
            cout«"ПОБЕДА!!!"«winner«"Он смог внатуре"«endl;
            break;
        }
        if (polnalidoska(board))
        {
            doska(board);
            cout«"Игра закончилась ничьей!"«endl;
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
