# XIAO nRF54LM20A + nRF Connect SDK

This is a series of examples for the XIAO nRF54LM20A, referenced from the [Seeed Studio wiki](https://wiki.seeedstudio.com/xiao_nrf54lm20a_ncs/). Most of the samples are Platform.io focused, but this one is nRF Connect SDK based.

## Building the examples

Need to add the boards definition to nRF Connect SDK from the [platform-seeedboards repo](https://github.com/Seeed-Studio/platform-seeedboards/tree/main/zephyr/nrf/boards/seeed/xiao_nrf54lm20a).

To add this to **nRF Connect** extension in VS Code:
- Open the "Cog" or "Gearwheel" > then select **Settings**
- In the search bar, type: `nrf-connect.boardRoots`
- Click **Add Item** 
- Paste in path. e.g. `~/Documents/github/platform-seeedboards/zephyr`
- Click **OK**

### Build Configuration
- NRF Connect > Applications / Build section > Add Build Configuration button
  - Board Target: `xiao_nrf54lm20a/nrf54lm20a/cpuapp`
  - Base configuration files: `prj.conf`
  - Extra Devicetree overlays: `boards/app.overlay`
  - Click **Generate and Build**

### Rebuilding
If the above doesn't work, or a code change has been made:
  - NRF Connect > Actions section > Build button

### Flashing
To flash, this is done manually:
- NRF Connect > Welcome section > Open terminal button:
  - `west flash`

### Serial Console
- Bottom status bar > Serial Monitor tab:
  - Port: `/dev/tty.usbmodem2EEDXXXX - Seeed Studio`
  - Click **Start Monitoring**

## Example List

XIAO nRF54LM20A common:
- PWM-driven RGB LED in the form of the (NationStar FC-B1010RGBT-HG)
- Timer wakeup using the [Global real-time counter AKA GRTC](https://docs.nordicsemi.com/r/bundle/ps_nrf54lm20a/page/grtc.html)
- Bluetooth Low Energy advertisements based on the [BTHome protocol](https://bthome.io)
- Battery management using the [nPM1300 PMIC](https://www.nordicsemi.com/Products/nPM1300)

XIAO nRF54LM20A Sense only:
- IMU reading using the [STMicroelectronics LSM6DS3TR-C](https://www.st.com/en/mems-and-sensors/lsm6ds3tr-c.html)
- TODO: Microphone (MEMS MSM261DGT006)