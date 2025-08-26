#include "chess.h"

int is_check(int turn) {
    char king = (turn == 0) ? 'K' : 'k';
    int kx = -1, ky = -1;
    
    for (int i = 0; i < SIZE && kx == -1; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (brd[i][j] == king) {
                kx = i; ky = j; break;
            }
        }
    }
    
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    for (int d = 0; d < 8; d++) {
        int x = kx + dx[d], y = ky + dy[d];
        while (is_valid(x, y)) {
            char c = brd[x][y];
            if (c != ' ') {
                if ((turn == 0 && islower(c)) || (turn == 1 && isupper(c))) {
                    char pc = tolower(c);
                    if ((d < 4 && (pc == 'r' || pc == 'q')) || (d >= 4 && (pc == 'b' || pc == 'q')))
                        return 1;
                }
                break;
            }
            x += dx[d]; y += dy[d];
        }
    }
    
    int kdx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int kdy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    for (int i = 0; i < 8; i++) {
        int x = kx + kdx[i], y = ky + kdy[i];
        if (is_valid(x, y)) {
            char c = brd[x][y];
            if ((turn == 0 && c == 'n') || (turn == 1 && c == 'N'))
                return 1;
        }
    }
    
    int px = (turn == 0) ? -1 : 1;
    for (int dy = -1; dy <= 1; dy += 2) {
        int x = kx + px, y = ky + dy;
        if (is_valid(x, y)) {
            char c = brd[x][y];
            if ((turn == 0 && c == 'p') || (turn == 1 && c == 'P'))
                return 1;
        }
    }
    
    return 0;
}

int is_checkmate(int turn) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char piece = brd[i][j];
            if ((turn == 0 && isupper(piece)) || (turn == 1 && islower(piece))) {
                for (int x = 0; x < SIZE; x++) {
                    for (int y = 0; y < SIZE; y++) {
                        if (i == x && j == y) continue;
                        if (validate_position(i, j, x, y, turn)) {
                            char captured = brd[x][y];
                            brd[x][y] = brd[i][j];
                            brd[i][j] = ' ';
                            
                            // Prevent move that would capture the opponent's king (illegal in chess)
                            int king_count = 0;
                            for (int a = 0; a < SIZE; a++) {
                                for (int b = 0; b < SIZE; b++) {
                                    if (brd[a][b] == 'K' || brd[a][b] == 'k') king_count++;
                                }
                            }
                            int chk = (king_count == 2) ? is_check(turn) : 1;
                            brd[i][j] = brd[x][y];
                            brd[x][y] = captured;
                            if (!chk) return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}

int is_stalemate(int turn) {
    if (is_check(turn)) return 0;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char piece = brd[i][j];
            if ((turn == 0 && isupper(piece)) || (turn == 1 && islower(piece))) {
                for (int x = 0; x < SIZE; x++) {
                    for (int y = 0; y < SIZE; y++) {
                        if (i == x && j == y) continue;
                        if (validate_position(i, j, x, y, turn)) {
                            char captured = brd[x][y];
                            brd[x][y] = brd[i][j];
                            brd[i][j] = ' ';
                            
                            int king_count = 0;
                            for (int a = 0; a < SIZE; a++) {
                                for (int b = 0; b < SIZE; b++) {
                                    if (brd[a][b] == 'K' || brd[a][b] == 'k') king_count++;
                                }
                            }
                            int chk = (king_count == 2) ? is_check(turn) : 1;
                            brd[i][j] = brd[x][y];
                            brd[x][y] = captured;
                            if (!chk) return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}