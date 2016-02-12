#ifndef F_CPU
#define F_CPU 8000000000
#endif



#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>


//myself header
#include "../h-data/number.h"

int main(){

  struct value numbers;
  struct value* zeiger = &numbers;
  
  setting(zeiger);

  PORTB |= (1<<PB4);
  while(1){

    PORTA = numbers.zero;
    _delay_us(200);
    PORTA = numbers.one;
    _delay_us(200);
    PORTA = numbers.two;
    _delay_us(200);
    PORTA = numbers.three;
    _delay_us(200);
    PORTA = numbers.four;
    _delay_us(200);
    PORTA = numbers.five;
    _delay_us(200);
    PORTA = numbers.six;
    _delay_us(200);
    PORTA = numbers.seven;
    _delay_us(200);
    PORTA = numbers.eight;
    _delay_us(200);
    PORTA = numbers.nine;
    _delay_us(200);
    
  }
  return 0;
    
}
