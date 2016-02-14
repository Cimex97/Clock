#include <avr/io.h>
#include <stdint.h>

#include "../h-data/time.h"
#include "../h-data/number.h"

int clock(uint8_t* m_one, uint8_t* m_ten, uint8_t* h_one, uint8_t* h_ten, struct value* numbers)
{
  if(second <3600){
    int minute = second / 60;
    switch(minute){
    case 0:
      m_one = numbers->zero;
    case 1:
      m_one = numbers->one;
    case 2:
      m_one = numbers->two;
    default:
      return -1;
    }
  }
  else if(second >=3600){
    int hour = second / 24;
  }
  
  return 0;
}

