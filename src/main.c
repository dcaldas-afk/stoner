#include "../lib/editor.h"
#include "../lib/modes.h"

int main(int ac, char **av) {
    enableRawMode();
    while (1) {
        keyPress();
    }
    return 0;
}