#pragma once

#include "esphome/core/component.h"
#include "esphome/components/number/number.h"
#include "luxpower_sna.h"

namespace esphome {
namespace luxpower_sna {

// Register 67 = AC Charge SOC Limit (Battery SOC Target)
static constexpr uint16_t BATTERY_SOC_REG = 67;

class BatterySocNumber : public number::Number, public Component {
 public:
  void set_parent(LuxpowerSNAComponent *parent) { parent_ = parent; }
  void control(float value) override {
    if (parent_) {
      parent_->write_register(BATTERY_SOC_REG, static_cast<uint16_t>(value), 0);
    }
    publish_state(value);
  }
 protected:
  LuxpowerSNAComponent *parent_{nullptr};
};

}  // namespace luxpower_sna
}  // namespace esphome