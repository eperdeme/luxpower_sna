import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import switch
from esphome.const import CONF_ID

luxpower_ns = cg.esphome_ns.namespace("luxpower_sna")
AcChargeSwitch = luxpower_ns.class_("AcChargeSwitch", switch.Switch, cg.Component)

CONFIG_SCHEMA = switch.switch_schema(AcChargeSwitch)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await switch.register_switch(var, config)