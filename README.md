INFORMATION
===========

The arduino boards are a nice introduction to microcontrollers as it simplifies the basics by doing the hardwork in various libraries. So whats the next step in the microcontroller education?

For me that would be to move to writing code which is compiled directly using avr-gcc without any arduino libraries. Essentially going a bit more low lever (but not too much).

Unfortunately each dev board out there has it's own atmel microcontroller with it's own pinouts, etc. Also most tutorials you will find on the internet is probably for a different devboard to the definitions don't match or those functions aren't available. This can be very frustrating for newbie.

So why not just use your arduino development board?

This repo contains various example programs that you can use for reference on doing avr-gcc programming on your arduino leonardo

Current Examples:

* examples/helloworld - Toggles some LED's
* example/uart - Configure and use the serial port


More coming soon!