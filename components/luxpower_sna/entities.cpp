#include "entities.h"
#include "luxpower_sna.h"
#include "esphome/core/log.h"

namespace esphome {
namespace luxpower_sna {

// Switch entity: write state to inverter register
void LuxPowerSwitch::write_state(bool state) {
  ESP_LOGD("luxpower_sna.switch", "Switch write_state called: %d", state);
  if (parent_) {
    // Bitmask logic: set or clear only the bits specified by bitmask_
    // Read-modify-write would be ideal, but here we just set/clear the mask
    uint16_t value = 0;
    if (bitmask_ != 0) {
      value = state ? bitmask_ : 0;
    } else {
      value = state ? 1 : 0;
    }
    parent_->write_register(register_, value, bitmask_);
  }
  this->publish_state(state);
}

// Number entity: set value to inverter register
void LuxPowerNumber::control(float value) {
  ESP_LOGD("luxpower_sna.number", "Number control called: %f", value);
  if (parent_) {
    // Apply scaling for voltage/percentage if needed
    uint16_t reg_value = static_cast<uint16_t>(value * scale_);
    // Bitmask logic: if bitmask_ is set, only update those bits
    if (bitmask_ != 0) {
      // In a real implementation, you'd read the current register value, mask, and write back
      // Here, we just send the value with the bitmask for demonstration
      parent_->write_register(register_, reg_value, bitmask_);
    } else {
      parent_->write_register(register_, reg_value, 0);
    }
  }
  this->publish_state(value);
}

// Button entity: trigger action (e.g., reconnect, restart)
void LuxPowerButton::press_action() {
  ESP_LOGD("luxpower_sna.button", "Button press_action called: %s", action_.c_str());
  if (parent_) {
    if (action_ == "reconnect") parent_->service_reconnect();
    else if (action_ == "restart") parent_->service_restart();
    else if (action_ == "reset_settings") parent_->service_reset_settings();
    else if (action_ == "sync_time") parent_->service_sync_time();
    else if (action_ == "refresh_data") parent_->service_refresh_data();
    // Add more actions as needed
  }
}

// Time entity: set time on inverter
// (No override needed unless custom logic is required)

}  // namespace luxpower_sna
}  // namespace esphome