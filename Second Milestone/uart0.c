#include "tm4c123gh6pm.h"
#include "string.h"
#include "stdint.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdio.h"
#include "uart0.h"
/////////////////////////////////
//uart0 porta intia
void UART0Init(void){
    SYSCTL_RCGCUART_R |= 0x01;
    SYSCTL_RCGCGPIO_R |= 0x01;

    UART0_CTL_R &= ~0x01; //disable uart
    UART0_IBRD_R = 104 ; //integer baud rate divisor
    UART0_FBRD_R = 11 ; //float baud rate divisor
    UART0_LCRH_R |= 0x70 ; //fifo enable and width  8 bits
    UART0_CTL_R = 0X0301 ; //uart enable , rx enable , tx enable
    GPIO_PORTA_AMSEL_R &= ~0x03; //clear analog mode
    GPIO_PORTA_AFSEL_R |= 0x03; //set alternate function
    GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R &= ~0xFF) | 0X00000011; //clear PA0 and PA1 then set them as uart
    GPIO_PORTA_DEN_R |= 0X03; //digital enable
}

void UART7Init(void){
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R7;
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;

    UART7_CTL_R &= ~0x01; //disable uart
    UART7_IBRD_R = 104 ; //integer baud rate divisor
    UART7_FBRD_R = 11 ; //float baud rate divisor
    UART7_LCRH_R |= 0x70 ; //fifo enable and width  8 bits
    UART7_CTL_R = 0X0301 ; //uart enable , rx enable , tx enable
    GPIO_PORTE_DEN_R |= 0X03; //digital enable
    GPIO_PORTE_AMSEL_R &= ~0x03; //clear analog mode
    GPIO_PORTE_AFSEL_R |= 0x03; //set alternate function
    GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R &= ~0xFF) | 0X00000011; //clear PE0 and PE1 then set them as uart

}
