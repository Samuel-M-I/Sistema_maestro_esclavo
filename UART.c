/*
 * File:   UART.c
 * Author: Usuario
 *
 * Created on May 17, 2026, 9:21 PM
 */


#include <xc.h>

void USART_Init() {
    TRISC6 = 0;
    TRISC7 = 1;

    SPBRG = 129;

    TXSTA = 0b00100100;
    RCSTA = 0b10010000;
}

void USART_Write(char data) {
    while(!TXIF);
    TXREG = data;
}

char USART_Read() {
    while(!RCIF);
    return RCREG;
}
