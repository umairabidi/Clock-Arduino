# ArduinoClock

This is a clock I made on an Arduino. It was meant as a learning experience so that I could practice my coding skills.
I designed it around December 2017.
I was very new to arduino at this point. I had bought my first Arduino less than a month prior.

Some of the features I wanted to become familiar with
- displaying digital numbers
- multiplexing 7-seg displays

Ultimately, I worked on this as practice for another clock I made. That one was in asm on a pic16f690 (see ASM_Clock).

If I wanted to improve this, there are a number of features I could revise
- Timing using non-blocking delays
  - Even better, use an RTC to get proper timing.
  - Implement this with interrupts
- DigitalWrite replace with asm or embedded_C
- General cleaning
