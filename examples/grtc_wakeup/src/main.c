#include <zephyr/kernel.h>
#include <zephyr/drivers/timer/nrf_grtc_timer.h>        // z_nrf_grtc_wakeup_prepare()
#include <zephyr/logging/log_ctrl.h>                    // log_panic()
#include <zephyr/sys/poweroff.h>                        // sys_poweroff()
#include <zephyr/drivers/led.h>                         // led_off()

#define WAIT_TIME_SECS 10

int main(void)
{
        // Turn off the power / charge LED
        const struct device *leds = DEVICE_DT_GET(DT_NODELABEL(pmic_leds));
        led_off(leds, 1);

        printk("Awake\n");
        // Wait 10 secs
        k_msleep(WAIT_TIME_SECS * MSEC_PER_SEC);

        // Prepare to wake up in 10 secs
        int err = z_nrf_grtc_wakeup_prepare(WAIT_TIME_SECS * USEC_PER_SEC);
        if (err < 0) {
		printk("Error: GRTC wakeup prepare failed: %d\n", err);
		return 0;
	} else {
		printk("Success: GRTC wakeup prepared. Powering off...\n");
	}

        // Force logging to flush to allow GRTC / Poweroff
        // Credit to https://github.com/kemegard/generic_grtc
        log_panic();

        // Power off
        sys_poweroff();

        // Should never get here
        return 0;
}
