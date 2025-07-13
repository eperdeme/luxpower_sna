#pragma once

#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"
#include "ac_charge_switch.h"

namespace esphome {
namespace luxpower_sna {

class AcChargeSwitchPlatform : public Component {
 public:
  void setup() override {}
  void dump_config() override {}
};

}  // namespace luxpower_sna
}  // namespace esphome

#include "esphome/core/automation.h"
#include "esphome/core/helpers.h"

namespace esphome {
namespace luxpower_sna {

template<typename... Ts>
class AcChargeSwitchConstructor : public esphome::switch_::SwitchConstructor<Ts...> {
 public:
  AcChargeSwitchConstructor() = default;
  esphome::luxpower_sna::AcChargeSwitch *ac_charge_switch = nullptr;
  esphome::switch_::Switch *get_switch() override { return ac_charge_switch; }
};

}  // namespace luxpower_sna
}  // namespace esphome