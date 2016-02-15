#include <avr/io.h>
#include <stdint.h>

#include "../h-data/number.h"
#include "../h-data/time.h"


int clock_calc(struct value* numbers)
{
  numbers->hour = second / 3600;
  numbers->minute = second / 60;
  
  //calc hour from 24 to 2   4
  numbers->thousand = numbers->hour / 10;
  numbers->hundred = numbers->hour - (10*numbers->thousand);
  
  //Calc minute from 60 to 6   0 
  numbers->ten = numbers->minute / 10;
  numbers->first = numbers->minute - (10*numbers->ten);

  return 0;
}


int clock(uint8_t* number, uint8_t* segment, struct value* numbers)
{

  uint8_t cnt = number;
 
  switch(cnt){
  case 0:
    numbers->m_one = numbers->zero;
    break;
    
  case 1:
    numbers->m_one = numbers->one;
    break;
    
  case 2:
    numbers->m_one = numbers->two;
    break;
    
  case 3:
    numbers->m_one = numbers->three;
      break;
    
  case 4:
    numbers->m_one = numbers->four;
      break;
    
  case 5:
    numbers->m_one = numbers->five;
      break;
    
  case 6:
    numbers->m_one = numbers->six;
      break;
    
  case 7:
    numbers->m_one = numbers->seven;
      break;
    
  case 8:
    numbers->m_one = numbers->eight;
      break;
    
  case 9:
    numbers->m_one = numbers->nine;
      break;
    
  default:
    break;
  }

  
}



