#pragma once

#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"
#include "luxpower_sna.h"

namespace esphome {
namespace luxpower_sna {

static constexpr uint16_t AC_CHARGE_REG = 21;
static constexpr uint16_t AC_CHARGE_BITMASK = 0x80;

class AcChargeSwitch : public switch_::Switch, public Component {
 public:
  void set_parent(LuxpowerSNAComponent *parent) { parent_ = parent; }
  void setup() override;
  void write_state(bool state) override;
 protected:
  LuxpowerSNAComponent *parent_{nullptr};
};

}  // namespace luxpower_sna
}  // namespace esphome

// ESPHome platform registration
#include "esphome/core/automation.h"
#include "esphome/core/helpers.h"
#include "esphome/components/switch/switch.h"

namespace esphome {
namespace luxpower_sna {

class AcChargeSwitchConstructor : public Component {
 public:
  AcChargeSwitchConstructor() = default;
  AcChargeSwitch *ac_charge_switch = nullptr;
  void setup() override {}
};

}  // namespace luxpower_sna
}  // namespace esphome