#include <gtest/gtest.h>
#include "components/luxpower_sna/luxpower_sna.h"
#include "components/luxpower_sna/entities.h"

using namespace esphome::luxpower_sna;

class LuxpowerSNATest : public ::testing::Test {
 protected:
  LuxpowerSNAComponent component;
};

TEST_F(LuxpowerSNATest, RegisterSwitch) {
  LuxPowerSwitch sw;
  sw.set_parent(&component);
  sw.set_register(0x10);
  sw.set_bitmask(0x01);
  sw.write_state(true);
  // No assertion: just ensure no crash and log output
}

TEST_F(LuxpowerSNATest, RegisterNumber) {
  LuxPowerNumber num;
  num.set_parent(&component);
  num.set_register(0x20);
  num.set_scale(10.0f);
  num.control(5.5f);
  // No assertion: just ensure no crash and log output
}

TEST_F(LuxpowerSNATest, ServiceHelpers) {
  component.service_reconnect();
  component.service_restart();
  component.service_reset_settings();
  component.service_sync_time();
  component.service_refresh_data();
  // No assertion: just ensure no crash and log output
}

TEST_F(LuxpowerSNATest, StateUnavailable) {
  component.set_all_entities_unavailable_();
  // No assertion: just ensure no crash and log output
}

TEST_F(LuxpowerSNATest, StateAvailable) {
  component.set_all_entities_available_();
  // No assertion: just ensure no crash and log output
}