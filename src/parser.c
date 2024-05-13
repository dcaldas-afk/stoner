#include "../lib/editor.h"

void error_exit(void) {
    printf("Erro\n");
    exit(1);
}

void die(const char *s) {
    perror(s);
    exit(1);
}

void parse(int ac, char *av) {
    if (ac == 2) {
        return ;
    }
    error_exit();
}