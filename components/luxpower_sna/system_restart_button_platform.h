#pragma once

#include "esphome/core/component.h"
#include "esphome/components/button/button.h"
#include "system_restart_button.h"

namespace esphome {
namespace luxpower_sna {

class SystemRestartButtonPlatform : public Component {
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
class SystemRestartButtonConstructor : public esphome::button::ButtonConstructor<Ts...> {
 public:
  SystemRestartButtonConstructor() = default;
  esphome::luxpower_sna::SystemRestartButton *system_restart_button = nullptr;
  esphome::button::Button *get_button() override { return system_restart_button; }
};

}  // namespace luxpower_sna
}  // namespace esphome