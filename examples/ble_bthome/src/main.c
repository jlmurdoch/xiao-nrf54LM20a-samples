#include <zephyr/kernel.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/uuid.h> // BT_UUID_16_ENCODE()

static const struct bt_data adv_data[] = {
	// BT Flags
	BT_DATA_BYTES(BT_DATA_FLAGS, BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR),
	// BT Payload
	BT_DATA_BYTES(BT_DATA_SVC_DATA16, BT_UUID_16_ENCODE(0xFCD2), 0x44, 0x00, 0x00, 0x2D, 0x00)
};

static void bt_ready(int err)
{
	bt_addr_le_t addr = {0};
	size_t count = 1;

	if (err) {
		printk("Bluetooth init failed: %d\n", err);
		return;
	}

	err = bt_le_adv_start(
			BT_LE_ADV_PARAM(BT_LE_ADV_OPT_USE_IDENTITY,
            				BT_GAP_ADV_SLOW_INT_MIN,
            				BT_GAP_ADV_SLOW_INT_MAX,
            				NULL),
			adv_data, ARRAY_SIZE(adv_data), 
			NULL, 0);
	if (err) {
		printk("Adv start fail: %d\n", err);
	}

	// Get the address
	bt_id_get(&addr, &count);
	printk("Beacon started on %s\n", bt_addr_le_str(&addr));
}

int main(void)
{
	k_sleep(K_SECONDS(10));

	int err = bt_enable(bt_ready);
	if (err) {
		printk("Bluetooth enable failed: %d\n", err);
	}

    while (true) {
        k_sleep(K_SECONDS(10));
    }

	return 0;
}