#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "../h-data/display.h"


int multiplex(uint8_t m_one, uint8_t m_ten, uint8_t h_one, uint8_t h_ten){
  //minute
  PORTB = 0x00;    //all turn of
  _delay_ms(3);
  PORTA = m_one;
  PORTB |= (1<<PB7);
  _delay_ms(3);
  
  //minute
  PORTB = 0x00;
  _delay_ms(30);
  PORTA = m_ten;
  PORTB |= (1<<PB6);
  _delay_ms(3);
  
  //hour
  PORTB = 0x00;
  _delay_ms(3);
  PORTA = h_one; 
  PORTB |= (1<<PB5);
  _delay_ms(3);
  
  //hour
  PORTB = 0x00;
  _delay_ms(3);
  PORTA = h_ten;
  PORTB |= (1<<PB4);
  _delay_ms(3);
  
  return 0;
  
}

