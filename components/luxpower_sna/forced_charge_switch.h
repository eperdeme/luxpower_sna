#pragma once

#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"
#include "luxpower_sna.h"

namespace esphome {
namespace luxpower_sna {

// Register 21, bit 2 (MSB) = Forced Charge Enable
static constexpr uint16_t FORCED_CHARGE_REG = 21;
static constexpr uint16_t FORCED_CHARGE_BITMASK = 0x0400; // bit 2 of MSB

class ForcedChargeSwitch : public switch_::Switch, public Component {
 public:
  void set_parent(LuxpowerSNAComponent *parent) { parent_ = parent; }
  void write_state(bool state) override {
    if (parent_) {
      parent_->write_register(FORCED_CHARGE_REG, state ? FORCED_CHARGE_BITMASK : 0, FORCED_CHARGE_BITMASK);
    }
    publish_state(state);
  }
 protected:
  LuxpowerSNAComponent *parent_{nullptr};
};

}  // namespace luxpower_sna
}  // namespace esphome