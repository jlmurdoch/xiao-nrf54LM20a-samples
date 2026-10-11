# XIAO nRF54LM20A + nRF Connect SDK

This is a series of examples for the XIAO nRF54LM20A, referenced from the [Seeed Studio wiki](https://wiki.seeedstudio.com/xiao_nrf54lm20a_ncs/) or other locations. This is fully nRF Connect SDK & Zephyr RTOS based. Examples have been cut down for clarity and not necessarily good practice (i.e. validation, logging).

## Building the examples

### Configuration
Add the board definition to nRF Connect SDK from the [Seeed Studio `platform-seeedboards` repo](https://github.com/Seeed-Studio/platform-seeedboards/). The board will be in `zeyphr/nrf`.

To add this to **nRF Connect** extension in VS Code:
- Open the "Cog" or "Gearwheel" > then select **Settings**
- In the search bar, type: `nrf-connect.boardRoots`
- Click **Add Item** 
- Paste in path where the directory `boards` is located. e.g. `~/Documents/github/platform-seeedboards/zephyr/nrf`
- Click **OK**

A copy of the XIAO nRF54LM20A board configuration has been put in this repo to correspond with any changes to the overlay needed in future.

### Build Configuration
- **NRF Connect** extension > **Applications** or **Build** section > **Add Build Configuration** button
  - Board Target: `xiao_nrf54lm20a/nrf54lm20a/cpuapp`
  - Base configuration files: `prj.conf`
  - Extra Devicetree overlays: `boards/app.overlay`
  - Click **Generate and Build** button

### Rebuilding
If the above doesn't work, or a code change has been made:
  - **NRF Connect** extension > **Actions** section > **Build** button

### Flashing
To flash, this is done manually via a terminal:
- **NRF Connect** extension > **Welcome** section > **Open terminal** button:
  - `west flash`

### Serial Console
- Bottom panel in VS Code > **Serial Monitor** tab:
  - Select the port from the **Port** dropdown: `/dev/tty.usbmodem2EEDXXXX - Seeed Studio`
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