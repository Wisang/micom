#include <stdint.h>
#include "lm4f120h5qr.h"
#include "delay.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)

uint8_t u8a, u8b;
uint16_t u16c, u16d;
uint32_t u32e, u32f;

int8_t s8;
int16_t s16;
int32_t s32;

 int main() {
   
   u8a = sizeof(u8a);
   u16c = sizeof(uint16_t);
   u32e = sizeof(uint32_t);
   
   u16c = 40000U;
   u16d = 30000U;
   u32e = (uint32_t)u16c + u16d; //portable to 16bit machine
   
   u16c = 100U;
   s32 = 10 - (int16_t)u16c; //portable to 16bit machine
   
   u8a = 0xffU;
   if((uint8_t)~u8a == 0x00U) {
     u8b = 1U;
   }
   
   if((int32_t)u32e > -1) {
     u8a = 1U;
   }
   else {
     u8a = 0U;
   }
   
  SYSCTL_RCGCGPIO_R |= (1U << 5); //0x20U;   // enable clock for GPIO_F
  
  SYSCTL_GPIOHBCTL_R |= (1U << 5); //enable AHB for GPIO
  GPIO_PORTF_AHB_DIR_R |= (LED_BLUE | LED_RED | LED_GREEN); //0x0EU;  // set pins 1,2, and 3 as outputs
  GPIO_PORTF_AHB_DEN_R |= (LED_BLUE | LED_RED | LED_GREEN); //0x0EU;
  
  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
  
  while(1) {
  
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
   
    delay(500000);
  
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
    delay(1000000);
  }
  
  //return 0;
}
