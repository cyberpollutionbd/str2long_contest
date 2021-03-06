#include "str2long.h"

long str2long_gedare (const char *input)
{
  long rv;
  char t;

  if (input) {
    if (*input == 0) {
      error = 1;
    } else {
      rv = 0;
      if (*input == '-') {
        while (*++input) {
          t = *input - '0';
          if ( rv < LONG_MIN/10L || rv*10L < LONG_MIN + t ) {
            error = 1;
            break;
          }
          rv = rv * 10L - t;
        }
      } else {
        do {
          t = *input - '0';
          if ( rv > LONG_MAX/10L || rv*10L > LONG_MAX - t ) {
            error = 1;
            break;
          }
          rv = rv * 10L + t;
        } while (*++input);
      }
    }
  }
  return rv;
}
