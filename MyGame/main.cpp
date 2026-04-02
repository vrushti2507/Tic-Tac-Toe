#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

bool checkWin(char player) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

int main() {
    int choice;
    char player = 'X';

    for(int turn = 0; turn < 9; turn++) {
        displayBoard();

        cout << "Player " << player << ", enter position: ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if(board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again.\n";
            turn--;
            continue;
        }

        board[row][col] = player;

        if(checkWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins! 🎉\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    displayBoard();
    cout << "It's a draw!\n";

    return 0;
}
