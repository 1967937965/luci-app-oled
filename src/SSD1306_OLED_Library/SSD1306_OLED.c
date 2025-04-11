// ... 现有代码 ...

#ifdef ST7735S_SUPPORT
#include "ST7735S.h"
#endif

void init_display() {
    char *screen_type = uci_get("oled.@oled[0].screen_type");
    if (strcmp(screen_type, "st7735s") == 0) {
        ST7735S_Init();
    } else {
        SSD1306_Init();
    }
}

void draw_pixel(int x, int y, int color) {
    char *screen_type = uci_get("oled.@oled[0].screen_type");
    if (strcmp(screen_type, "st7735s") == 0) {
        ST7735S_DrawPixel(x, y, color);
    } else {
        SSD1306_DrawPixel(x, y, color);
    }
}

// ... 其他函数也需要类似修改 ...