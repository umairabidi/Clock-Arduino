# ArduinoClock

This is a clock I made on an Arduino. It was meant as a learning experience so that I could practice my coding skills.

I was very new to Arduino at this point, as I had bought my first Arduino less than a month prior. This was designed in December 2017.

Some of the features I wanted to become familiar with
- displaying digital numbers on 7-seg displays.
- multiplexing 7-seg displays.

Ultimately, I worked on this as practice for another clock I made. That one was in asm on a pic16f690 (see Clock-PICasm).

If I wanted to improve this, there are a number of features I could revise
- Timing using non-blocking delays
  - Even better, use an RTC to get proper timing.
  - Implement this with interrupts
- Replace DigitalWrite with asm or embedded-C (less overhead)
- General cleaning

---
todo
update with pinouts and schematic
