# LuxPower SNA ESPHome Integration

This ESPHome custom component provides native, user-friendly platforms for LuxPower inverters. All controls are available as first-class ESPHome entities—no lambda or custom registration required.

## Features

- Native ESPHome platforms for:
  - AC Charge Enable (switch)
  - Max Charge Current (number)
  - Forced Charge (switch)
  - Battery SOC Target (number)
  - System Restart (button)
- Simple YAML configuration
- No register/bitmask knowledge required for users
- Full compatibility with ESPHome’s new requirements

## Example YAML

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

switch:
  - platform: luxpower_ac_charge
    name: "AC Charge Enable"
  - platform: luxpower_forced_charge
    name: "Forced Charge"

number:
  - platform: luxpower_max_charge_current
    name: "Max Charge Current"
    min_value: 0
    max_value: 100
    step: 1
  - platform: luxpower_battery_soc
    name: "Battery SOC Target"
    min_value: 0
    max_value: 100
    step: 1

button:
  - platform: luxpower_system_restart
    name: "System Restart"
```

## Register Reference

See [`CONTROL_REGISTERS.md`](CONTROL_REGISTERS.md) for a full list of supported controls, register numbers, bitmasks, and value meanings.

## How it Works

- Each control is implemented as a native ESPHome platform.
- No lambda or custom registration is needed.
- All controls are available in Home Assistant and the ESPHome dashboard.

## Troubleshooting

- If a platform is not found, ensure you have the latest ESPHome and that your `external_components` source is correct.
- For advanced usage or to add more controls, see the register reference.

---

This integration is future-proof, user-friendly, and ready for the next generation of ESPHome.
