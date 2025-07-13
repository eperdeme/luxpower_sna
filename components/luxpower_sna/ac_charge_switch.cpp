#include "ac_charge_switch.h"
#include "esphome/core/log.h"

namespace esphome {
namespace luxpower_sna {

static const char *const TAG = "luxpower.ac_charge_switch";

void AcChargeSwitch::setup() {
  ESP_LOGCONFIG(TAG, "Setting up AC Charge Switch...");
}

void AcChargeSwitch::write_state(bool state) {
  ESP_LOGD(TAG, "Setting AC Charge: %s", state ? "ON" : "OFF");
  if (this->parent_ != nullptr) {
    this->parent_->write_register(AC_CHARGE_REG, state ? AC_CHARGE_BITMASK : 0, AC_CHARGE_BITMASK);
  }
  this->publish_state(state);
}

}  // namespace luxpower_sna
}  // namespace esphome