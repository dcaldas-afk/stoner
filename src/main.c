#include "../lib/editor.h"
#include "../lib/modes.h"

int main(int ac, char **av) {
    enableRawMode();
    char c;
    while (read(STDIN_FILENO, &c, 1) && c != 'q') {
        if iscntrl(c)
            printf("%d\n", c);
        else
            printf("%d ('%c')\n", c, c);
    }
    return 0;
}