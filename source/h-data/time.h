#ifndef __TIME_H__
#define __TIME_H__

#include <stdint.h>

int time(uint8_t* m_one, uint8_t* m_ten, uint8_t* h_one, uint8_t* h_ten, struct value* numbers);

volatile int cnt_1;
volatile int cnt_2;
volatile int second;

#endif
