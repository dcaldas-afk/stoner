#ifndef EDITOR_H
# define EDITOR_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <stddef.h>
#include <ctype.h>

void parse(int ac, char *av);
void error_exit(void);

#endif