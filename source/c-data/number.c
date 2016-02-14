#include <avr/io.h>
#include "../h-data/number.h"
#include <avr/interrupt.h>

int setting(struct value* numbers){
  //direction of the pins
  DDRA = 0xFF;
  DDRB = 0x0F;
  DDRC = 0x3F;

  //all off;
  PORTB &= ~(1<<PB7);
  PORTB &= ~(1<<PB6);
  PORTB &= ~(1<<PB5);
  PORTB &= ~(1<<PB4);
  
  //init the number
  numbers->zero = 0x41;
  numbers->one = 0xDB;
  numbers->two = 0x23;
  numbers->three = 0x0B;
  numbers->four = 0x99;
  numbers->five = 0x0D;
  numbers->six = 0x05;
  numbers->seven = 0x5B;
  numbers->eight = 0x01;
  numbers->nine = 0x09;
  
  //init timer
  TIMSK |= (1<<TOIE0);
  TCCR0 |= (1<<CS00);
  TCCR0 &= ~(1<<CS01);
  TCCR0 &= ~(1<<CS02);
  
  return 0;
}
