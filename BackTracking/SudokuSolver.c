#include <stdio.h>
#include <stdbool.h>

#define N 9

bool solveSudoku(char board[N][N], bool row[N][N], bool col[N][N], bool box[N][N], int i, int j);

int getBoxIndex(int i, int j) {
    return (i / 3) * 3 + (j / 3);
}

void solveSudokuWrapper(char board[N][N]) {
    bool row[N][N] = { false };
    bool col[N][N] = { false };
    bool box[N][N] = { false };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1';
                row[i][num] = true;
                col[j][num] = true;
                int boxIndex = getBoxIndex(i, j);
                box[boxIndex][num] = true;
            }
        }
    }

    solveSudoku(board, row, col, box, 0, 0);
}

bool solveSudoku(char board[N][N], bool row[N][N], bool col[N][N], bool box[N][N], int i, int j) {
    if (j == N) {
        j = 0;
        i++;
    }
    if (i == N) return true;

    if (board[i][j] != '.') {
        return solveSudoku(board, row, col, box, i, j + 1);
    }

    for (int num = 0; num < 9; num++) {
        int boxIndex = getBoxIndex(i, j);
        if (!row[i][num] && !col[j][num] && !box[boxIndex][num]) {
            row[i][num] = col[j][num] = box[boxIndex][num] = true;
            board[i][j] = num + '1';

            if (solveSudoku(board, row, col, box, i, j + 1)) return true;

            board[i][j] = '.';
            row[i][num] = col[j][num] = box[boxIndex][num] = false;
        }
    }
    return false;
}

void printBoard(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[N][N] = {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}
    };

    solveSudokuWrapper(board);
    printBoard(board);
    return 0;
}
