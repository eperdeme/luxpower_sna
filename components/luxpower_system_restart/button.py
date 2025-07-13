import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import button
from esphome.const import CONF_ID

luxpower_ns = cg.esphome_ns.namespace("luxpower_sna")
SystemRestartButton = luxpower_ns.class_("SystemRestartButton", button.Button, cg.Component)

CONFIG_SCHEMA = button.button_schema(SystemRestartButton)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await button.register_button(var, config)