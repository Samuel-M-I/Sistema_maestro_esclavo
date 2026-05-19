/*
 * File:   UART.c
 * Author: Samuel Marroquín Isaza
 *
 * Created on May 17, 2026, 9:21 PM
 */


#include <xc.h>

void UART_Init() {
    TRISC6 = 0; //Establece el pin TX como salida
    TRISC7 = 1; //Establece el pin RX como entrada

    SPBRG = 129;

    TXSTA = 0b00100100;
    RCSTA = 0b10010000;
}

void UART_Write(char data) {
    while(!TXIF);
    TXREG = data;
}

char UART_Read() {
    if (OERR) {          // Error de overrun
        CREN = 0;
        CREN = 1;        // Reset del receptor
    }
    while(!RCIF);
    return RCREG;
}
