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

int main(){

  struct value numbers;
  struct value* zeiger = &numbers;
  numbers.m_one = numbers.zero;
  numbers.m_ten = numbers.zero;
  numbers.h_one = numbers.zero;
  numbers.h_ten = numbers.zero;
  
  cnt_1 = 0;
  cnt_2 = 0;
  second = 0;
  setting(zeiger);
  sei();

  while(1){
    multiplex(zeiger);  //display numbers multiplex

    clock(zeiger);
  }
  return 0;
    
}


ISR(TIMER0_OVF_vect){

    if(cnt_1<31372){
      cnt_1++;
    }
    else{
      if(cnt_2<140){
	cnt_2++;
      }
      else{
	cnt_1 = 0;
	cnt_2 = 0;
	PORTC ^= (1<<PC7);
	if(second<864000){
	  second++;
	}
	else {
	  second = 0;
	}
      }
    }

 }

