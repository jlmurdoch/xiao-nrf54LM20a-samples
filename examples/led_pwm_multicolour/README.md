# blinky example

This example is ported from the example write up here: https://wiki.seeedstudio.com/xiao_nrf54lm20a_ncs/#write-the-blinky-program.

It has three changes:
- Edited: `src/main.c`
  - Pasted in code (source unknown)
- Edited: `prj.conf`
  - PWM enabled
  - Serial disabled
- Added: boards/xiao_nrf54lm20a_nrf54lm20a_cpuapp.overlay
  - PWM device overlay for the XIAO nRF54LM20A

Once run, it will flash the onboard LED 7 times colours and then go off.