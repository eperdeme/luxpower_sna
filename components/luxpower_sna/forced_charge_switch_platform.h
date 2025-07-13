#pragma once

#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"
#include "forced_charge_switch.h"

namespace esphome {
namespace luxpower_sna {

class ForcedChargeSwitchPlatform : public Component {
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
class ForcedChargeSwitchConstructor : public esphome::switch_::SwitchConstructor<Ts...> {
 public:
  ForcedChargeSwitchConstructor() = default;
  esphome::luxpower_sna::ForcedChargeSwitch *forced_charge_switch = nullptr;
  esphome::switch_::Switch *get_switch() override { return forced_charge_switch; }
};

}  // namespace luxpower_sna
}  // namespace esphome