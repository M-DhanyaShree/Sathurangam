#include "chess.h"

// Global variables definition
struct Player player1, player2;
char brd[SIZE][SIZE];

int main() {
    intro_screen();
    int turn = 1;
    double total_white_time = 0, total_black_time = 0;
    chess(brd);

    while (1) {
        system("cls");
        display_board(brd);

        if (is_check(turn)) {
            printf("\nCHECK! %s is in danger.\n", (turn == 1 ? player1.name : player2.name));
            if (is_checkmate(turn)) {
                printf("\nCHECKMATE! %s wins the game!\n", (turn == 0 ? player1.name : player2.name));
                break;
            }
        } else if (is_stalemate(turn)) {
            printf("\nSTALEMATE! The game is a draw.\n");
            break;
        }

        printf("\n%s's Move (%s):\n", (turn == 1 ? player1.name : player2.name), (turn == 1 ? "White" : "Black"));

        int cr, cc, dr, dc;
        DWORD move_start = GetTickCount();

        // Time-limited input for source
        if (!timed_input(&cr, &cc, "Enter current position (row col): ")) {
            printf("%s loses their turn!\n", (turn == 1 ? player1.name : player2.name));
            Sleep(2000);
            turn = 1 - turn;
            continue;
        }

        // Time-limited input for destination
        if (!timed_input(&dr, &dc, "\nEnter destination position (row col): ")) {
            printf("%s loses their turn!\n", (turn == 1 ? player1.name : player2.name));
            Sleep(2000);
            turn = 1 - turn;
            continue;
        }

        DWORD move_end = GetTickCount();
        double move_time = (move_end - move_start) / 1000.0;
        printf("\nMove Time: %.2f seconds\n", move_time);

        if (turn == 1) total_white_time += move_time;
        else total_black_time += move_time;

        // Convert input to array indices
        cr = SIZE - cr; cc--;
        dr = SIZE - dr; dc--;

        if (validate_position(cr, cc, dr, dc, turn)) {
            char captured = brd[dr][dc];
            brd[dr][dc] = brd[cr][cc];
            brd[cr][cc] = ' ';
            int king_count = 0;
            for (int a = 0; a < SIZE; a++)
                for (int b = 0; b < SIZE; b++)
                    if (brd[a][b] == 'K' || brd[a][b] == 'k') king_count++;

            int still_in_check = (king_count == 2) ? is_check(turn) : 1;
            if (!still_in_check) {
                if (captured != ' ') {
                    struct Player *opponent = (turn == 1) ? &player2 : &player1;
                    opponent->lp[opponent->lc++] = captured;
                }
                turn = 1 - turn;
            } else {
                brd[cr][cc] = brd[dr][dc];
                brd[dr][dc] = captured;
                printf("Invalid move! You must get out of check. Press enter to continue.");
                getchar(); getchar();
            }
        } else {
            printf("Invalid move! Press enter to continue.");
            getchar(); getchar();
        }
    }
    return 0;
}