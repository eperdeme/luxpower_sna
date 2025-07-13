import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import number
from esphome.const import CONF_ID

luxpower_ns = cg.esphome_ns.namespace("luxpower_sna")
MaxChargeCurrentNumber = luxpower_ns.class_("MaxChargeCurrentNumber", number.Number, cg.Component)

CONFIG_SCHEMA = number.number_schema(MaxChargeCurrentNumber)

async def to_code(config):
    var = await cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await number.register_number(var, config)