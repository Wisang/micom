#include "lm4f120h5qr.h"

/*
#define RCGCGPIO (*((unsigned int*)0x400FE608U)) // clock gating control

#define GPIOF_BASE 0x40025000U
#define GPIOF_DIR (*((unsigned int*)(GPIOF_BASE + 0x400U)))
#define GPIOF_DEN (*((unsigned int*)(GPIOF_BASE + 0x51CU)))
#define GPIOF_DATA (*((unsigned int*)(GPIOF_BASE + 0x3FCU)))
*/

int main() {
  SYSCTL_RCGCGPIO_R = 0x20U;   // enable clock for GPIO_F
  GPIO_PORTF_DIR_R = 0x0EU;  // set pins 1,2, and 3 as outputs
  GPIO_PORTF_DEN_R= 0x0EU;
  
  while(1) {
    GPIO_PORTF_DATA_R = 0x02U;
  
    int volatile counter = 0;
    while(counter < 1000000) {
      ++counter;
    }
  
    GPIO_PORTF_DATA_R = 0x00U;
    counter = 0;
    while(counter < 1000000) {
      ++counter;
    }
  }
  
  return 0;
}
