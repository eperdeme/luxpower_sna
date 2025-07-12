#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/switch/switch.h"
#include "esphome/components/number/number.h"
#include "esphome/components/button/button.h"
#include "esphome/components/time/real_time_clock.h"

namespace esphome {
namespace luxpower_sna {

// Switch entity for controlling inverter features
class LuxPowerSwitch : public switch_::Switch, public Component {
 public:
  void write_state(bool state) override;
  void set_parent(class LuxpowerSNAComponent *parent) { parent_ = parent; }
  void set_register(uint16_t reg) { register_ = reg; }
  void set_bitmask(uint16_t bitmask) { bitmask_ = bitmask; }
 protected:
  LuxpowerSNAComponent *parent_{nullptr};
  uint16_t register_{0};
  uint16_t bitmask_{0};
};

// Number entity for setting values (e.g., voltage, current, percentage)
class LuxPowerNumber : public number::Number, public Component {
 public:
  void control(float value) override;
  void set_parent(class LuxpowerSNAComponent *parent) { parent_ = parent; }
  void set_register(uint16_t reg) { register_ = reg; }
  void set_scale(float scale) { scale_ = scale; }
  void set_bitmask(uint16_t bitmask) { bitmask_ = bitmask; }
 protected:
  LuxpowerSNAComponent *parent_{nullptr};
  uint16_t register_{0};
  float scale_{1.0f};
  uint16_t bitmask_{0};
};

// Button entity for triggering actions (e.g., reconnect, restart)
class LuxPowerButton : public button::Button, public Component {
 public:
  void press_action() override;
  void set_parent(class LuxpowerSNAComponent *parent) { parent_ = parent; }
  void set_action(const std::string &action) { action_ = action; }
 protected:
  LuxpowerSNAComponent *parent_{nullptr};
  std::string action_;
};

// Time entity for setting inverter time
class LuxPowerTime : public time::RealTimeClock, public Component {
 public:
  void set_parent(class LuxpowerSNAComponent *parent) { parent_ = parent; }
  void set_register(uint16_t reg) { register_ = reg; }
 protected:
  LuxpowerSNAComponent *parent_{nullptr};
  uint16_t register_{0};
};

}  // namespace luxpower_sna
}  // namespace esphome