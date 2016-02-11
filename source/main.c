#ifndef F_CPU
#define F_CPU 8000000000
#endif

#include <avr/io.h>
#include <stdint.h>

int main(){
  DDRC |= (1<<PC7);
  
  
  PORTC |= (1<<PC7);

  while(1){
  }
  return 0;
    
}
