/*
 * File:   timer0.c
 * Author: swticher
 *
 * Created on 29 de junio de 2019, 07:14 PM
 */

#include <pic18f4550.h>
#include"config.h"

void Timer0_Init(void){

    INTCONbits.GIE = 0;
    T0CONbits.T0CS = 0; // Temporizador
    T0CONbits.PSA = 0; // Habilitamos Pre escaler
    T0CONbits.T0PS = 0b010; //256 Pre escaler PSA en 0 para poder descomentar esta seccion
    T0CONbits.T08BIT = 0; // 16 bits de cuenta 
    TMR0 = 0xEC77;     //10mS
    //TMR0L = 0x77;     //
    T0CONbits.TMR0ON = 1; // Tmr0 empieza
    INTCONbits.TMR0IE = 1; // Permitir el desbordamiento del Timer0
    INTCONbits.TMR0IF = 0; //Flag del Timer 0 apagado
    INTCONbits.PEIE = 1; // Interrupciones de perifericos
    INTCONbits.GIE = 1;
       
    
}


/*calculus for a win timer
 * NOTE for define prescaler the registers T0CONbits.PSA =0 and TOPS = 0bxxx
 * and for prescaler en 1 PSA=1; TOPS=nothing(commen line)
 * FOSC
 * Time
 * Prescaler =x
 * T0CONbits.T08BIT = 0; // configuration timer 8(1) or 16(0) bits
 * Ftimer= Fosc/4 --> time for instruccion
 * Period= x/Ftimer   --> x= prescaler
 * time= DesiredDelay/Period
 
 * Example
 * FOSC=16Mhz
 * Time= 10mS
 * Prescaler = 8 ---> T0CONbits.PSA=0; TOPS=0b010(0x3);
 * * T0CONbits.T08BIT = 0;  16bits
 * Ftimer=16Mhz/4 = 4Mhz -->time for instruccion
 * Period = 8/4Mhz = 2us  period result for instruccion.
 * time = 10mS/2uS = 5000;
 * 65535-5000 = 60535 TMR0 __>> this value is for a overflow every 10mS
 * 
 */