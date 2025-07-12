# LuxPower SNA ESPHome Integration

This ESPHome custom component provides full-featured integration for LuxPower inverters, ported from the Home Assistant Python integration. It supports sensors, switches, numbers, buttons, and time entities, as well as service helpers for device control and robust state management.

## Features

- Live sensor readings (voltages, currents, power, energy, temperatures, etc.)
- Switches for inverter features (with bitmask support)
- Number entities for setpoints (voltage, current, percentage, etc., with scaling)
- Button entities for actions (reconnect, restart, reset, sync time, refresh)
- Time entity for inverter time synchronization
- Service helpers for reconnect, restart, reset settings, sync time, and refresh data
- Robust error handling and state management (entities marked unavailable on comms failure)
- Test scaffold using GoogleTest

## Example ESPHome YAML

```yaml
esphome:
  name: luxpower_inverter
  platform: ESP32
  board: esp32dev

external_components:
  - source: github://your-repo/luxpower_sna/components

wifi:
  ssid: "your-ssid"
  password: "your-password"

logger:

# Example sensor
sensor:
  - platform: luxpower_sna
    id: pv1_voltage
    name: "PV1 Voltage"

# Example switch
switch:
  - platform: luxpower_sna
    id: inverter_enable
    name: "Inverter Enable"
    register: 0x10
    bitmask: 0x01

# Example number
number:
  - platform: luxpower_sna
    id: charge_voltage
    name: "Charge Voltage"
    register: 0x20
    min_value: 48.0
    max_value: 58.0
    step: 0.1
    scale: 10.0

# Example button
button:
  - platform: luxpower_sna
    id: reconnect
    name: "Reconnect"
    action: reconnect

# Example time
time:
  - platform: luxpower_sna
    id: inverter_time
    name: "Inverter Time"
```

## Services

You can trigger the following services via ESPHome or Home Assistant:
- `reconnect`
- `restart`
- `reset_settings`
- `sync_time`
- `refresh_data`
- `write_register` (custom service for direct register writes)

### Example: Write Register from YAML

You can call the `write_register` service from ESPHome automations or Home Assistant scripts:

```yaml
# Example: Set charge voltage register to 54.0 (scaled by 10)
script:
  - id: set_charge_voltage
    then:
      - service: luxpower_sna.write_register
        data:
          register: 0x20
          value: 540
          bitmask: 0
```

You can use this in automations, scripts, or call it from the Home Assistant UI.

## Testing

A basic test scaffold is provided in `test_luxpower_sna.cpp` using GoogleTest. To run tests:

```sh
g++ -std=c++17 -Icomponents -I. test_luxpower_sna.cpp -lgtest -lpthread -o test_luxpower_sna
./test_luxpower_sna
```

## Troubleshooting

- Ensure your ESPHome device has network access to the inverter.
- If entities are marked unavailable, check network and inverter status.
- Use the logger for detailed debug output.

---

For advanced usage, see the source code and comments.
