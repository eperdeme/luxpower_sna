#pragma once

#include "esphome/core/component.h"
#include "esphome/components/number/number.h"
#include "battery_soc_number.h"

namespace esphome {
namespace luxpower_sna {

class BatterySocNumberPlatform : public Component {
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
class BatterySocNumberConstructor : public esphome::number::NumberConstructor<Ts...> {
 public:
  BatterySocNumberConstructor() = default;
  esphome::luxpower_sna::BatterySocNumber *battery_soc_number = nullptr;
  esphome::number::Number *get_number() override { return battery_soc_number; }
};

}  // namespace luxpower_sna
}  // namespace esphome