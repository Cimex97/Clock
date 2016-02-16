#ifndef F_CPU
#define F_CPU 8000000UL
#endif



#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//myself header
#include "../h-data/number.h"
#include "../h-data/time.h"
#include "../h-data/display.h"


int main(){
  
  struct value numbers;
  struct value* zeiger = &numbers;

  //init zero number after reboot
  numbers.m_one = numbers.zero;
  numbers.m_ten = numbers.zero;
  numbers.h_one = numbers.zero;
  numbers.h_ten = numbers.zero;
  
  //counter and seconds reset
  cnt_1 = 0;
  cnt_2 = 0;
  second = 0;
  
  //pin settings
  setting(zeiger);
  sei();

  while(1){
    multiplex(zeiger);  //display numbers multiplex

    clock_calc(zeiger);

    //load the correct time
    clock(numbers.first, &numbers.m_one, zeiger);
    clock(numbers.ten, &numbers.m_ten, zeiger);
    clock(numbers.hundred, &numbers.h_one, zeiger);
    clock(numbers.thousand, &numbers.h_ten, zeiger);
    
  }
  return 0;
    
}


ISR(TIMER0_OVF_vect){

    if(cnt_1<100){
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

