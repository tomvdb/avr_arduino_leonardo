// led example on atmega32u4 (arduino leonardo)
// tom van den bon (2012/06/29)

#include <avr/io.h>
#include <util/delay.h>

int main()
{
    // setup output
    DDRC |= 0x80;    // PC7 - LED on Leonardo
    DDRB |= 0x01;    // PB0 - RX LED on leonardo
    DDRD |= 0x32;    // PD5 - TX LED on leonardo
    
    PORTC |= 0x80;   // LED High
    PORTB |= 0x01;   // RX LED High (led is inverted)
    PORTD |= 0x32;   // RX LED High (led is inverted)
    
    while (1)
    {
        PORTC  ^= 1 << 7;
        PORTB  ^= 1 << 0;
        PORTD  ^= 1 << 5;
        
        _delay_ms(1000);
    }
}