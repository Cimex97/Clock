#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "../h-data/number.h"
#include "../h-data/display.h"

int multiplex(struct value* numbers){
  //minute
  PORTB = 0x00;    //all turn of
  _delay_ms(3);
  PORTA = numbers->m_one;
  PORTB |= (1<<PB7);
  _delay_ms(3);
  
  //minute
  PORTB = 0x00;
  _delay_ms(3);
  PORTA = numbers->m_ten;
  PORTB |= (1<<PB6);
  _delay_ms(3);
  
  //hour
  PORTB = 0x00;
  _delay_ms(3);
  PORTA = numbers->h_one; 
  PORTB |= (1<<PB5);
  _delay_ms(3);
  
  //hour
  PORTB = 0x00;
  _delay_ms(3);
  PORTA = numbers->h_ten;
  PORTB |= (1<<PB4);
  _delay_ms(3);
  PORTB = 0x00;
  
  return 0;
  
}

