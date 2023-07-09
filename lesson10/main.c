#include "lm4f120h5qr.h"
#include "delay.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)

int* swap(int* x, int* y);

int* swap(int* x, int* y) {
  static int temp[2];
  temp[0] = *x;
  temp[1] = *y;
  *x = temp[1];
  *y = temp[0];
  
  return temp;
}

 int main() {
   
  SYSCTL_RCGCGPIO_R |= (1U << 5); //0x20U;   // enable clock for GPIO_F
  
  SYSCTL_GPIOHBCTL_R |= (1U << 5); //enable AHB for GPIO
  GPIO_PORTF_AHB_DIR_R |= (LED_BLUE | LED_RED | LED_GREEN); //0x0EU;  // set pins 1,2, and 3 as outputs
  GPIO_PORTF_AHB_DEN_R |= (LED_BLUE | LED_RED | LED_GREEN); //0x0EU;
  
  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
  
  while(1) {
    int x = 1000000;
    int y = 1000000/2;
    int* p = swap(&x, &y);
  
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
   
    delay(p[0]);
  
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
    delay(p[1]);
  }
  
  //return 0;
}
