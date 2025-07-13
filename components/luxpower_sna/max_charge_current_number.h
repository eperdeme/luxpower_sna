#pragma once

#include "esphome/core/component.h"
#include "esphome/components/number/number.h"
#include "luxpower_sna.h"

namespace esphome {
namespace luxpower_sna {

// Register 66 = AC Charge Power Command (Max Charge Current)
static constexpr uint16_t MAX_CHARGE_CURRENT_REG = 66;

class MaxChargeCurrentNumber : public number::Number, public Component {
 public:
  void set_parent(LuxpowerSNAComponent *parent) { parent_ = parent; }
  void control(float value) override {
    if (parent_) {
      parent_->write_register(MAX_CHARGE_CURRENT_REG, static_cast<uint16_t>(value), 0);
    }
    publish_state(value);
  }
 protected:
  LuxpowerSNAComponent *parent_{nullptr};
};

}  // namespace luxpower_sna
}  // namespace esphome