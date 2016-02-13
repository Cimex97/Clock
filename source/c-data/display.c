#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "../h-data/display.h"


int multiplex(uint8_t m_one, uint8_t m_ten, uint8_t h_one, uint8_t h_ten){
  //minute
  PORTB = 0x00;    //all turn of
  PORTA = m_one;
  PORTB |= (1<<PB7);

  //minute
  PORTB = 0x00;
  PORTA = m_ten;
  PORTB |= (1<<PB6);

  //hour
  PORTB = 0x00;
  PORTA = h_one; 
  PORTB |= (1<<PB5);

  //hour
  PORTB = 0x00;
  PORTA = h_ten;
  PORTB |= (1<<PB4);
  
  return 0;
  
}

