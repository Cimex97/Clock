#ifndef F_CPU
#define F_CPU 8000000
#endif



#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//myself header
#include "../h-data/number.h"
#include "../h-data/display.h"
#include "../h-data/time.h"

int main(){

  struct value numbers;
  struct value* zeiger = &numbers;
  uint8_t m_one = numbers.four; //display
  uint8_t m_ten = numbers.three;
  uint8_t h_one = numbers.two;
  uint8_t h_ten = numbers.one;

  setting(zeiger);

  while(1){
    multiplex(m_one, m_ten, h_one, h_ten);  //display numbers multiplex

    // clock(&m_one, &m_ten, &h_one, &h_ten, zeiger);
  }
  return 0;
    
}
