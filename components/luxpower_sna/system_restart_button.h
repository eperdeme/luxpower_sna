#pragma once

#include "esphome/core/component.h"
#include "esphome/components/button/button.h"
#include "luxpower_sna.h"

namespace esphome {
namespace luxpower_sna {

// Register 200 (example) = System Restart
static constexpr uint16_t SYSTEM_RESTART_REG = 200;

class SystemRestartButton : public button::Button, public Component {
 public:
  void set_parent(LuxpowerSNAComponent *parent) { parent_ = parent; }
  void press_action() override {
    if (parent_) {
      parent_->write_register(SYSTEM_RESTART_REG, 1, 0);
    }
  }
 protected:
  LuxpowerSNAComponent *parent_{nullptr};
};

}  // namespace luxpower_sna
}  // namespace esphome