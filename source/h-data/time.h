#ifndef __TIME_H__
#define __TIME_H__

#include <stdint.h>

int time(struct value* numbers);
int clock_calc(struct value* numbers);
int clock(int number, uint8_t* segment, struct value* numbers);

volatile int cnt_1;
volatile int cnt_2;
volatile unsigned long int second;

#endif
