#pragma once

#include "ac_charge_switch_platform.h"
#include "max_charge_current_number_platform.h"
#include "forced_charge_switch_platform.h"
#include "battery_soc_number_platform.h"
#include "system_restart_button_platform.h"

#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"
#include "esphome/components/number/number.h"
#include "esphome/components/button/button.h"

namespace esphome {
namespace luxpower_sna {

// Registration macros for ESPHome platforms
ESPHome_REGISTER_SWITCH("luxpower_ac_charge", esphome::luxpower_sna::AcChargeSwitchPlatform, esphome::luxpower_sna::AcChargeSwitchConstructor);
ESPHome_REGISTER_NUMBER("luxpower_max_charge_current", esphome::luxpower_sna::MaxChargeCurrentNumberPlatform, esphome::luxpower_sna::MaxChargeCurrentNumberConstructor);
ESPHome_REGISTER_SWITCH("luxpower_forced_charge", esphome::luxpower_sna::ForcedChargeSwitchPlatform, esphome::luxpower_sna::ForcedChargeSwitchConstructor);
ESPHome_REGISTER_NUMBER("luxpower_battery_soc", esphome::luxpower_sna::BatterySocNumberPlatform, esphome::luxpower_sna::BatterySocNumberConstructor);
ESPHome_REGISTER_BUTTON("luxpower_system_restart", esphome::luxpower_sna::SystemRestartButtonPlatform, esphome::luxpower_sna::SystemRestartButtonConstructor);

}  // namespace luxpower_sna
}  // namespace esphome