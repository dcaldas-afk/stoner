#include "../lib/modes.h"

struct termios original_value;

// redefine o estado do terminal como os valores originais, retirando as mudanças feitas pelo modo raw
void disableRawMode(void) {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_value) == -1)
      die("tcsetattr");
}

/*grava os atributos do terminal em original_value (para poder reverter para esse estado posteriormente)
registra a função para rodar o disable quando ela encerrar, depois grava os valores originais numa variável raw que será modificada
as constantes ECHO, ICANON e ISIG são desabilitadas para que a saída seja instantânea e grava o novo estado do terminal em raw*/
void enableRawMode(void) {
  if (tcgetattr(STDIN_FILENO, &original_value) == -1)
    die("tcgetattr");
  atexit(disableRawMode);
  struct termios raw = original_value;
  raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
  raw.c_cflag |= (CS8);
  raw.c_oflag &= ~(OPOST);
  raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
    die("tcsetattr");
}