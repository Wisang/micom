#include <stdint.h>
#include "tm4c_cmsis.h"
#include "delay.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)

typedef struct {
  uint16_t x;
  uint8_t y;
} Point;

Point p1, p2;

int main() {
  
  p1.x = sizeof(Point);
  p1.y = 0xAAU;
  
  SYSCTL->RCGC2 |= (1U << 5); //0x20U;   // enable clock for GPIO_F
  SYSCTL->GPIOHSCTL |= (1U << 5); //enable AHB for GPIO
  
  GPIOF_HS->DIR |= (LED_BLUE | LED_RED | LED_GREEN); //0x0EU;  // set pins 1,2, and 3 as outputs
  GPIOF_HS->DEN |= (LED_BLUE | LED_RED | LED_GREEN); //0x0EU;
  GPIOF_HS->DATA_Bits[LED_BLUE] = LED_BLUE;
  
  while(1) {
  
    //GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
    GPIOF_HS->DATA_Bits[LED_RED] = LED_RED;
    delay(500000);
  
    //GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
    GPIOF_HS->DATA_Bits[LED_RED] = 0;
    delay(1000000);
  }
  
  //return 0;
}
