#include "chess.h"

void center_text(const char *text, int width) {
    int len = strlen(text);
    int padding = (width - len) / 2;
    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s", text);
}

void initialize() {
    printf("\n\n");
    center_text("Enter the name of the commander of WHITE kingdom : ", 80);
    scanf("%s", player1.name);
    center_text("Enter the name of the commander of BLACK kingdom : ", 80);
    scanf("%s", player2.name);
    player1.color = 1;
    player2.color = 0;
    printf("\n\n");
    getchar();
    center_text("Loading...", 80);
    sleep(2);
}

void display_board(char board[SIZE][SIZE]) {
    center_text("CHESS GAME\n\n", 80);
    printf("     ");
    for (int col = 1; col <= SIZE; col++) printf(" %-5d", col);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("  +-----+-----+-----+-----+-----+-----+-----+-----+\n");
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) printf("|  %c  ", board[i][j]);
        printf("| %d\n", SIZE - i);
    }
    printf("  +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf("     ");
    for (int col = 1; col <= SIZE; col++) printf(" %-5d", col);
    printf("\n");
}

void instructions() {
    printf("\n\n");
    center_text("========== GAME INSTRUCTIONS ==========\n\n", 80);
    center_text("* All classical rules of chess are followed.\n", 80);
    center_text("* Lowercase letters represent WHITE pieces.\n", 80);
    center_text("* Uppercase letters represent BLACK pieces.\n", 80);
    center_text("* Inputs are CASE SENSITIVE.\n", 80);
    center_text("* Enter moves in standard chess notation (row_no col_no)\n", 80);
    center_text("* Only legal moves will be accepted.\n", 80);
    center_text("* Check and Checkmate detection included.\n", 80);
    center_text("* Game continues until one king is checkmated.\n\n", 80);
    center_text("========================================\n", 80);
    printf("\n");
    center_text("Press Enter to continue...", 80);
    getchar();
}

void intro_screen() {
    system("cls");
    printf("\n\n\n");
    printf("   _____      _______ _    _ _    _ _____            _   _  _____          __  __ \n");
    printf("  / ____|  /\\|__   __| |  | | |  | |  __ \\     /\\   | \\ | |/ ____|   /\\   |  \\/  |\n");
    printf(" | (___   /  \\  | |  | |__| | |  | | |__) |   /  \\  |  \\| | |  __   /  \\  | \\  / |\n");
    printf("  \\___ \\ / /\\ \\ | |  |  __  | |  | |  _  /   / /\\ \\ | . ` | | |_ | / /\\ \\ | |\\/| |\n");
    printf("  ____) / ____ \\| |  | |  | | |__| | | \\ \\  / ____ \\| |\\  | |__| |/ ____ \\| |  | |\n");
    printf(" |_____/_/    \\_\\_|  |_|  |_|\\____/|_|  \\_\\/_/    \\_\\_| \\_|\\_____/_/    \\_\\_|  |_|\n");
    printf("                                                                                 \n");
    printf("\n");
    center_text("Welcome to THE WAR OF KINGS !!\n", 80);
    center_text("This is two-player chess duel, played in the terminal,\n", 80);
    center_text("crafted in C, and bound by the rules of classical strategy.\n", 80);
    center_text("Command your army, defend your king, and lead your strategy\n", 80);
    center_text("to glory in this timeless war of wisdom.\n", 80);

    printf("\n\n");
    center_text("Press Enter to Start the Game...\n", 80);
    getchar();
    system("cls");
    instructions();
    initialize();
}