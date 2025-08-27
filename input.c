#include "chess.h"

int timed_input(int *row, int *col, const char *prompt) {
    printf("%s", prompt);
    int r = 0, c = 0, entered = 0;
    DWORD start = GetTickCount();
    char buffer[10] = {0};
    int pos = 0;

    while ((GetTickCount() - start) < 30000) {  // 30 seconds
        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') { // Enter
                buffer[pos] = '\0';
                if (sscanf(buffer, "%d %d", &r, &c) == 2) {
                    *row = r;
                    *col = c;
                    return 1;
                } else {
                    printf("\nInvalid format! Enter as: row col -> ");
                    pos = 0;
                    buffer[0] = '\0';
                }
            } else if (ch == '\b' && pos > 0) {
                printf("\b \b");
                buffer[--pos] = '\0';
            } else if (pos < 9 && (isdigit(ch) || isspace(ch))) {
                buffer[pos++] = ch;
                putchar(ch);
            }
        }
        Sleep(100); // Lower CPU usage
    }

    printf("\nTime's up! You took too long.\n");
    return 0;
}