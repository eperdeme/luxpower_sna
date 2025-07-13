from esphome.components import switch
import esphome.config_validation as cv
import esphome.codegen as cg

luxpower_ns = cg.esphome_ns.namespace("luxpower_sna")
AcChargeSwitch = luxpower_ns.class_("AcChargeSwitch", switch.Switch, cg.Component)

CONFIG_SCHEMA = switch.SWITCH_SCHEMA.extend({}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = await switch.new_switch(config)
    await cg.register_component(var, config)