
# NPM13XX Fuel Gauge

This is a small fork of the official nRF Connect SDK [NPM1300 and nPM1304: Fuel Gauge](https://github.com/nrfconnect/sdk-nrf/tree/main/samples/pmic/native/npm13xx_fuel_gauge) example to make it work with the XIAO nRF54LM20A.

Changes are to the DT_NODELABEL macro calls to match the devicetree on the XIAO.

### Battery connected
```
nRF Fuel Gauge version: 2.0.0
No previous fuel gauge state found, starting fresh
Constant voltage charging
PMIC device ok
Constant voltage charging
V: 4.233, I: -0.038, T: 25.00, SoC: 99.00, TTE: nan, TTF: 1029, SoH: 100.00, Cycles: 0, Chg: 0.00
V: 4.233, I: -0.040, T: 25.00, SoC: 99.00, TTE: nan, TTF: 1076, SoH: 100.00, Cycles: 0, Chg: 0.01
...
V: 4.233, I: -0.020, T: 25.00, SoC: 99.00, TTE: nan, TTF: 338, SoH: 100.00, Cycles: 0, Chg: 0.18
Charge complete
V: 4.228, I: -0.000, T: 24.90, SoC: 99.00, TTE: nan, TTF: nan, SoH: 100.00, Cycles: 0, Chg: 0.18
```

### Battery disconnected
```
nRF Fuel Gauge version: 2.0.0
No previous fuel gauge state found, starting fresh
Trickle charging
PMIC device ok
Trickle charging
V: 4.233, I: -0.000, T: 25.00, SoC: 99.00, TTE: nan, TTF: nan, SoH: 100.00, Cycles: 0, Chg: 0.00
V: 4.233, I: -0.000, T: 25.00, SoC: 99.00, TTE: nan, TTF: nan, SoH: 100.00, Cycles: 0, Chg: 0.00
V: 4.233, I: -0.000, T: 25.00, SoC: 99.00, TTE: nan, TTF: nan, SoH: 100.00, Cycles: 0, Chg: 0.00
Constant current charging
V: 4.238, I: -0.000, T: 25.00, SoC: 99.00, TTE: nan, TTF: nan, SoH: 100.00, Cycles: 0, Chg: 0.00
Trickle charging
V: 4.238, I: -0.000, T: 25.00, SoC: 99.00, TTE: nan, TTF: nan, SoH: 100.00, Cycles: 0, Chg: 0.00
...
V: 4.233, I: -0.000, T: 25.00, SoC: 99.00, TTE: nan, TTF: nan, SoH: 100.00, Cycles: 0, Chg: 0.00
Charger idle
V: 4.003, I: -0.000, T: 25.00, SoC: 98.98, TTE: nan, TTF: nan, SoH: 100.00, Cycles: 0, Chg: 0.00
```