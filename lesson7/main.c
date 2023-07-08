#include "lm4f120h5qr.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)



int main() {
  SYSCTL_RCGCGPIO_R |= (1U << 5); //0x20U;   // enable clock for GPIO_F
  
  SYSCTL_GPIOHBCTL_R |= (1U << 5); //enable AHB for GPIO
  GPIO_PORTF_AHB_DIR_R |= (LED_BLUE | LED_RED | LED_GREEN); //0x0EU;  // set pins 1,2, and 3 as outputs
  GPIO_PORTF_AHB_DEN_R |= (LED_BLUE | LED_RED | LED_GREEN); //0x0EU;
  
  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
  
  while(1) {
  
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
  
    int volatile counter = 0;
    while(counter < 1000000) {
      ++counter;
    }
  
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
  
    counter = 0;
    while(counter < 1000000) {
      ++counter;
    }
  }
  
  return 0;
}
