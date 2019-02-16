#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum {white, black} color;

typedef struct {
    int x;
    int y;
    color c;
} Peice;

void print_board(Peice* board[][SIZE]) {
    int i,j;

    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            printf("%c ", board[i][j] ? (board[i][j]->c == white ? 'w' : 'b') : '-');
        }
        putchar('\n');
    }
}

void init_board(Peice* board[][SIZE]) {
    int i, j;

    for (i=0; i<3; i++) {
        for (j=0; j<SIZE; j++) {
            if ((i+j)%2 != 0) {
                board[i][j] = (Peice*) malloc (sizeof(Peice));
                board[i][j]->c = black;
                board[i][j]->x = j;
                board[i][j]->y = i;
            }
        }
    }
    for (i=5; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            if ((i+j)%2 != 0) {
                board[i][j] = (Peice*) malloc (sizeof(Peice));
                board[i][j]->c = white;
                board[i][j]->x = j;
                board[i][j]->y = i;
            }
        }
    }
}

int in_board(int i, int j) {
    return i>=0 && i<SIZE && j>=0 && j<SIZE;
}


int move_peice(Peice* board[][SIZE], Peice* to_move, int to_i, int to_j) {
    if (!in_board(to_i, to_j)) {
        return 0;
    }
    if (!in_board(to_move->x, to_move->y)) {
        return 0;
    }
    if (!(to_j+1 == to_move->x || to_j-1 == to_move->x)) {
        return 0;
    }
    if (to_move->c == white && to_i+1 != to_move->y) {
        return 0;
    }
    if (to_move->c == black && to_i-1 != to_move->y) {
        return 0;
    }
    board[to_move->y][to_move->x] = NULL;
    board[to_i][to_j] = to_move;
}

int main() {
    Peice* board[SIZE][SIZE] = {NULL};

    init_board(board);

    print_board(board);

    putchar('\n');
    putchar('\n');
    putchar('\n');

    move_peice(board, board[2][3], 3,2);

    print_board(board);

    return 0;
}
