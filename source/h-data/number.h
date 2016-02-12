#ifndef __NUMBER_H__
#define __NUMBER_H_



#include <stdint.h>

//struct for numbers
struct value {
  uint8_t zero;
  uint8_t one;
  uint8_t two;
  uint8_t three;
  uint8_t four;
  uint8_t five;
  uint8_t six;
  uint8_t seven;
  uint8_t eight;
  uint8_t nine;
  
};

int setting(struct value* number);

#endif
