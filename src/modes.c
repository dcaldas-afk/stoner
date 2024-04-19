#include "../lib/modes.h"

struct termios original_value;

void disableRawMode(void) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_value);
}

void enableRawMode(void) {
  tcgetattr(STDIN_FILENO, &original_value);
  atexit(disableRawMode);
  struct termios raw = original_value;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}