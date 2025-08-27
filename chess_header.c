#ifndef CHESS_H
#define CHESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#define SIZE 8

// Player structure
struct Player {
    char name[30];
    int color;         // 0 = Black, 1 = White
    char lp[32];       // Lost pieces
    int lc;            // Lost piece count
};

// Global variables
extern struct Player player1, player2;
extern char brd[SIZE][SIZE];

// Function declarations

// UI functions (ui.c)
void center_text(const char *text, int width);
void intro_screen(void);
void instructions(void);
void initialize(void);
void display_board(char board[SIZE][SIZE]);

// Game logic functions (game.c)
void chess(char (*board)[SIZE]);
int is_valid(int x, int y);
double get_move_time(clock_t start, clock_t end);

// Move validation functions (moves.c)
int validate_moves_sepoy(int i, int j, int fi, int fj, int turn);
int validate_moves_rook(int i, int j, int fi, int fj, int turn);
int validate_moves_bishop(int i, int j, int fi, int fj, int turn);
int validate_moves_knight(int i, int j, int fi, int fj, int turn);
int validate_moves_queen(int i, int j, int fi, int fj, int turn);
int validate_moves_king(int i, int j, int fi, int fj, int turn);
int validate_position(int i, int j, int fi, int fj, int turn);

// Game state functions (gamestate.c)
int is_check(int turn);
int is_checkmate(int turn);
int is_stalemate(int turn);

// Input functions (input.c)
int timed_input(int *row, int *col, const char *prompt);

#endif // CHESS_H