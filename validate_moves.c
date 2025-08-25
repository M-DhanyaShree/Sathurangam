#include "chess.h"

int validate_moves_sepoy(int i, int j, int fi, int fj, int turn) {
    int dir = (turn == 0) ? -1 : 1;
    
    if (fj == j - 1 || fj == j + 1) {
        if (fi == i + dir && brd[fi][fj] != ' ') {
            if (turn == 0 && brd[fi][fj] >= 'a' && brd[fi][fj] <= 'z') return 1;
            if (turn == 1 && brd[fi][fj] >= 'A' && brd[fi][fj] <= 'Z') return 1;
        }
        return 0;
    }
    
    if (fj == j) {
        if (brd[fi][fj] != ' ') return 0;
        if (fi == i + dir) return 1;
        if ((turn == 0 && i == 6 && fi == i + 2 * dir && brd[i + dir][j] == ' ') || 
            (turn == 1 && i == 1 && fi == i + 2 * dir && brd[i + dir][j] == ' ')) return 1;
    }
    return 0;
}

int validate_moves_rook(int i, int j, int fi, int fj, int turn) {
    int p, q;
    if (i != fi && j != fj) return 0;
    
    if (j == fj) {
        p = (i < fi) ? 1 : -1;
        for (q = i + p; q != fi; q += p) {
            if (brd[q][j] != ' ') return 0;
        }
    }
    
    if (i == fi) {
        p = (j < fj) ? 1 : -1;
        for (q = j + p; q != fj; q += p) {
            if (brd[i][q] != ' ') return 0;
        }
    }
    
    if (brd[fi][fj] == ' ') return 1;
    if (turn == 0 && brd[fi][fj] >= 'a' && brd[fi][fj] <= 'z') return 1;
    if (turn == 1 && brd[fi][fj] >= 'A' && brd[fi][fj] <= 'Z') return 1;
    return 0;
}

int validate_moves_bishop(int i, int j, int fi, int fj, int turn) {
    int p, q, x, y;
    if (abs(i - fi) != abs(j - fj)) return 0;
    
    p = (i < fi) ? 1 : -1;
    q = (j < fj) ? 1 : -1;
    
    for (x = i + p, y = j + q; x != fi && y != fj; x += p, y += q) {
        if (brd[x][y] != ' ') return 0;
    }
    
    if (brd[fi][fj] == ' ') return 1;
    if (turn == 0 && brd[fi][fj] >= 'a' && brd[fi][fj] <= 'z') return 1;
    if (turn == 1 && brd[fi][fj] >= 'A' && brd[fi][fj] <= 'Z') return 1;
    return 0;
}

int validate_moves_knight(int i, int j, int fi, int fj, int turn) {
    if ((abs(i - fi) == 2 && abs(j - fj) == 1) || (abs(i - fi) == 1 && abs(j - fj) == 2)) {
        if (brd[fi][fj] == ' ') return 1;
        if (turn == 0 && brd[fi][fj] >= 'a' && brd[fi][fj] <= 'z') return 1;
        if (turn == 1 && brd[fi][fj] >= 'A' && brd[fi][fj] <= 'Z') return 1;
        return 0;
    }
    return 0;
}

int validate_moves_queen(int i, int j, int fi, int fj, int turn) {
    return validate_moves_rook(i, j, fi, fj, turn) || validate_moves_bishop(i, j, fi, fj, turn);
}

int validate_moves_king(int i, int j, int fi, int fj, int turn) {
    if (abs(i - fi) <= 1 && abs(j - fj) <= 1) {
        if (brd[fi][fj] == ' ') return 1;
        if (turn == 0 && brd[fi][fj] >= 'a' && brd[fi][fj] <= 'z') return 1;
        if (turn == 1 && brd[fi][fj] >= 'A' && brd[fi][fj] <= 'Z') return 1;
    }
    return 0;
}

int validate_position(int i, int j, int fi, int fj, int turn) {
    char piece = brd[i][j];
    if (piece == ' ') return 0;
    if ((turn == 0 && islower(piece)) || (turn == 1 && isupper(piece))) return 0;
    if (fi < 0 || fi >= SIZE || fj < 0 || fj >= SIZE) return 0;

    switch (tolower(piece)) {
        case 'p': return validate_moves_sepoy(i, j, fi, fj, turn);
        case 'r': return validate_moves_rook(i, j, fi, fj, turn);
        case 'b': return validate_moves_bishop(i, j, fi, fj, turn);
        case 'n': return validate_moves_knight(i, j, fi, fj, turn);
        case 'q': return validate_moves_queen(i, j, fi, fj, turn);
        case 'k': return validate_moves_king(i, j, fi, fj, turn);
        default: return 0;
    }
}