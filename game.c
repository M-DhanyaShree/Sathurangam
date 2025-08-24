#include "chess.h"

void chess(char (*board)[SIZE]) {
    char *p = &board[0][0];
    for (int i = 0; i < SIZE * SIZE; i++) *(p + i) = ' ';
    
    char black[SIZE] = {'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r'};
    for (int j = 0; j < SIZE; j++) {
        *(p + j) = black[j];
        *(p + SIZE + j) = 'p';
    }
    
    for (int j = 0; j < SIZE; j++) *(p + 6 * SIZE + j) = 'P';
    
    char white[SIZE] = {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'};
    for (int j = 0; j < SIZE; j++) *(p + 7 * SIZE + j) = white[j];
}

int is_valid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

double get_move_time(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}