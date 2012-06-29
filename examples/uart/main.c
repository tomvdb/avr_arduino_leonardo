// uart example on atmega32u4 (arduino leonardo)
// tom van den bon (2012/06/29)
// note: this is for the uart (rx/tx) pins. To connect them to your pc you will need a ttl->rs232 level converter 

#include <avr/io.h>
#include <util/delay.h>

#include <string.h>

# define USART_BAUDRATE 9600
# define BAUD_PRESCALE ((( F_CPU / ( USART_BAUDRATE * 16UL))) - 1)

// transmit a char to uart
void uart_transmit( unsigned char data )
{
    // wait for empty transmit buffer
    while ( ! ( UCSR1A & ( 1 << UDRE1 ) ) )
        ;
    
    // put data into buffer, sends data
    UDR1 = data;
}

// read a char from uart
unsigned char uart_receive(void)
{
    while (!( UCSR1A & ( 1 << RXC1) ))
        ;
    
    return UDR1;
}

// init uart
void uart_init(void)
{
    // set baud rate   
    unsigned int baud = BAUD_PRESCALE;
    
    UBRR1H = (unsigned char) (baud >> 8 );
    UBRR1L = (unsigned char)baud;
    
    // enable received and transmitter
    UCSR1B = ( 1 << RXEN1 ) | ( 1 << TXEN1 );
    
    // set frame format ( 8data, 2stop )
    UCSR1C = ( 1 << USBS1 ) | ( 3 << UCSZ10 );
}

// check if there are any chars to be read
int uart_dataAvailable(void)
{
    if ( UCSR1A & ( 1 << RXC1) )
        return 1;
    
    return 0;
}

// write a string to the uart
void uart_print( char data[] )
{
    int c = 0;
    
    for ( c = 0; c < strlen(data); c++ )
        uart_transmit(data[c]);
}

int main(void)
{
    // setup uart
    uart_init();
    
    unsigned char receivedChar = '0';
    
    uart_print( "\n\rWelcome :)\n\r" );
    
    while (1)
    {
        if ( uart_dataAvailable() )
        {
            // echo any received characters right back 
            receivedChar = uart_receive();
            uart_transmit(receivedChar);
        }
    }
    
    return 0;
}