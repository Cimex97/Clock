#include <avr/io.h>
#include "../h-data/number.h"

int setting(struct value* numbers){
  //direction of the pins
  DDRA = 0xFF;
  DDRB = 0x0F;

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
  
  
  return 0;
}
