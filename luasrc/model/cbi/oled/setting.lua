// ... 现有代码 ...

o = s:taboption("info", ListValue, "screen_type", translate("屏幕类型"))
o:value("ssd1306", "SSD1306 (0.91', 128x32, I2C)")
o:value("st7735s", "ST7735S (0.96', 80x160, SPI)")
o.default = "ssd1306"

o = s:taboption("info", ListValue, "interface", translate("接口类型"))
o:value("i2c", "I2C")
o:value("spi", "SPI")
o.default = "i2c"
o:depends("screen_type", "st7735s")

o = s:taboption("info", TextValue, "init_commands", translate("Initialization Commands"))
o.rows = 5
o.wrap = "off"
o:depends("screen_type", "st7735s")
o.validate = function(self, value)
    if value:match("[^0-9A-Fa-fx, ]") then
        return nil, translate("Invalid initialization commands")
    end
    return value
end

o = s:taboption("info", Value, "refresh_rate", translate("Refresh Rate (Hz)"))
o.default = "60"
o.datatype = "uinteger"
o:depends("screen_type", "st7735s")

o = s:taboption("info", ListValue, "color_mode", translate("Color Mode"))
o:value("rgb", "RGB")
o:value("bgr", "BGR")
o.default = "rgb"
o:depends("screen_type", "st7735s")

o = s:taboption("info", Value, "screen_width", translate("Screen Width"))
o.default = "80"
o.datatype = "uinteger"
o:depends("screen_type", "st7735s")

o = s:taboption("info", Value, "screen_height", translate("Screen Height"))
o.default = "160"
o.datatype = "uinteger"
o:depends("screen_type", "st7735s")

o = s:taboption("info", ListValue, "rotation", translate("Screen Rotation"))
o:value("0", "0° (默认)")
o:value("90", "90° (顺时针)")
o:value("180", "180° (上下翻转)")
o:value("270", "270° (逆时针)")
o.default = "0"
o:depends("screen_type", "st7735s")