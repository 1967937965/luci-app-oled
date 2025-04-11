#include "SSD1306_OLED.h"
#include <spi.h>

static unsigned char screen_buffer[ST7735S_WIDTH * ST7735S_HEIGHT];

void ST7735S_Init() {
    // 初始化 SPI 接口
    spi_init();
    
    // 发送初始化命令序列
    spi_write_command(0x11); // Sleep out
    delay_ms(120);
    
    spi_write_command(0x36); // MADCTL
    spi_write_data(0x08);    // RGB color filter panel
    
    spi_write_command(0x3A); // COLMOD
    spi_write_data(0x05);    // 16 bits per pixel
    
    spi_write_command(0x21); // Display inversion on
    spi_write_command(0x29); // Display on
}

void ST7735S_DrawPixel(int x, int y, int color) {
    if (x >= 0 && x < ST7735S_WIDTH && y >= 0 && y < ST7735S_HEIGHT) {
        screen_buffer[y * ST7735S_WIDTH + x] = color;
    }
}

void ST7735S_ClearScreen() {
    memset(screen_buffer, 0, sizeof(screen_buffer));
}

void ST7735S_UpdateScreen() {
    spi_write_command(0x2A); // Column address set
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x4F);
    
    spi_write_command(0x2B); // Row address set
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x9F);
    
    spi_write_command(0x2C); // Memory write
    spi_write(screen_buffer, sizeof(screen_buffer));
}