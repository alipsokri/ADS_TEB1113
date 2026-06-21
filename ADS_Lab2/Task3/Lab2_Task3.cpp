#include <iostream>
using namespace std;

//Check if player wins
bool win(char board[3][3], char p) {

    //rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p &&
            board[i][1] == p &&
            board[i][2] == p)
            return true;
    }

    //columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == p &&
            board[1][i] == p &&
            board[2][i] == p)
            return true;
    }

    //diagonals
    if (board[0][0] == p &&
        board[1][1] == p &&
        board[2][2] == p)
        return true;

    if (board[0][2] == p &&
        board[1][1] == p &&
        board[2][0] == p)
        return true;

    return false;
}

int main() {

    char board[3][3];

    cout << "Enter board:\n";

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];

    int x = 0, o = 0;

    //Count X and O
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X')
                x++;
            else if (board[i][j] == 'O')
                o++;
        }
    }

    bool xWin = win(board, 'X');
    bool oWin = win(board, 'O');

    bool valid = true;

    if (!(x == o || x == o + 1))
        valid = false;

    if (xWin && oWin)
        valid = false;

    if (xWin && x != o + 1)
        valid = false;

    if (oWin && x != o)
        valid = false;

    if (valid)
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}