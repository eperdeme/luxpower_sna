#pragma once

#include "esphome/core/component.h"
#include "esphome/components/number/number.h"
#include "max_charge_current_number.h"

namespace esphome {
namespace luxpower_sna {

class MaxChargeCurrentNumberPlatform : public Component {
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
class MaxChargeCurrentNumberConstructor : public esphome::number::NumberConstructor<Ts...> {
 public:
  MaxChargeCurrentNumberConstructor() = default;
  esphome::luxpower_sna::MaxChargeCurrentNumber *max_charge_number = nullptr;
  esphome::number::Number *get_number() override { return max_charge_number; }
};

}  // namespace luxpower_sna
}  // namespace esphome