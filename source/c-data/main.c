#ifndef F_CPU
#define F_CPU 8000000UL
#endif



#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//myself header
#include "../h-data/number.h"
#include "../h-data/display.h"
#include "../h-data/time.h"

volatile int cnt_1 = 0;
volatile int cnt_2 = 0;
volatile int second = 0;

int main(){

  struct value numbers;
  struct value* zeiger = &numbers;
  uint8_t m_one = numbers.four; //display
  uint8_t m_ten = numbers.three;
  uint8_t h_one = numbers.two;
  uint8_t h_ten = numbers.one;
  
  setting(zeiger);
  sei();

  while(1){
    multiplex(m_one, m_ten, h_one, h_ten);  //display numbers multiplex

    clock(&m_one, &m_ten, &h_one, &h_ten, zeiger);
  }
  return 0;
    
}


ISR(TIMER0_OVF_vect){
  if(second<86400){
    second++;
  }
  else{
    second = 0;
  }


  
  if(cnt_1<31372){
    cnt_1++;
  }
  else{
    if(cnt_2<140){
      cnt_2++;
    }
    else{
      PORTC ^= (1<<PC7);
      cnt_1 = 0;
      cnt_2 = 0;
    }
  }
}

