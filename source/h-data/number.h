#ifndef __NUMBER_H__
#define __NUMBER_H_



#include <stdint.h>

//struct for numbers
struct value {
  //numbers
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

  //segment numbers
  uint8_t m_one;
  uint8_t m_ten;
  uint8_t h_one;
  uint8_t h_ten;

  //clock time
  uint8_t first;
  uint8_t ten;
  uint8_t hundred;
  uint8_t thousand;

  //calculatot clock time
  uint8_t hour;
  uint8_t minute;

  uint8_t segment;
};

int setting(struct value* numbers);

#endif
