# LuxPower Inverter Control Register Reference

This table lists common controls for LuxPower inverters, with register addresses, bitmasks, and value meanings. Use these for advanced YAML automations or to understand what each native ESPHome entity does.

| Control Name         | Register (Hex) | Bitmask | Value(s) | Description / Usage Example                |
|--------------------- |:-------------:|:-------:|:--------:|--------------------------------------------|
| AC Charge Enable     | 0x100         | 0x01    | 0=Off, 1=On | Enable/disable AC charging                 |
| Grid Charge Mode     | 0x101         | 0x03    | 0=Off, 1=On, 2=Auto | Set grid charge mode                      |
| Force Charge         | 0x102         | 0x01    | 0=Off, 1=On | Force battery charge                       |
| Battery Mode         | 0x103         | 0x0F    | 0=Auto, 1=Eco, 2=UPS | Select battery mode                        |
| Max Charge Current   | 0x104         |   -     | 0-100    | Set max charge current (A)                 |
| Max Discharge Current| 0x105         |   -     | 0-100    | Set max discharge current (A)              |
| Charge Voltage       | 0x106         |   -     | 480-580  | Set charge voltage (scaled by 10, e.g. 540=54.0V) |
| Discharge Cutoff Volt| 0x107         |   -     | 400-520  | Set discharge cutoff voltage (scaled by 10)|
| Battery SOC Target   | 0x108         |   -     | 0-100    | Set battery state-of-charge target (%)     |
| System Restart       | 0x200         | 0x01    | 1=Restart| Restart inverter system                    |

**Note:**  
- Register addresses and bitmasks are examples. Please confirm with your inverter’s protocol documentation or Python integration source for your model.
- For writable values (numbers), scale as needed (e.g., voltage * 10).
- For switches, use the bitmask and value as shown.

---

## Example: YAML for AC Charge Enable

```yaml
switch:
  - platform: template
    name: "AC Charge Enable"
    turn_on_action:
      - lambda: |-
          id(luxpower_sna_component).write_register(0x100, 1, 0x01);
    turn_off_action:
      - lambda: |-
          id(luxpower_sna_component).write_register(0x100, 0, 0x01);
```

## Example: YAML for Max Charge Current

```yaml
number:
  - platform: template
    name: "Max Charge Current"
    min_value: 0
    max_value: 100
    step: 1
    set_action:
      - lambda: |-
          id(luxpower_sna_component).write_register(0x104, (uint16_t)x, 0);
```

---

For more controls, refer to this table and adapt the YAML as needed.  
If you want these controls as native ESPHome entities, they can be added to the C++ code for even easier YAML configuration.