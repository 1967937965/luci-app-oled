#include <stdio.h>

void ST7735S_Init() {
    if (spi_init() < 0) {
        fprintf(stderr, "Failed to initialize SPI interface\n");
        exit(1);
    }
    spi_write_command(0x36); // MADCTL
    switch (rotation) {
        case 0:
            spi_write_data(0x08); // RGB color filter panel, no rotation
            break;
        case 90:
            spi_write_data(0x68); // Rotate 90°
            break;
        case 180:
            spi_write_data(0xC8); // Rotate 180°
            break;
        case 270:
            spi_write_data(0xA8); // Rotate 270°
            break;
    }
}

void ST7735S_SetRotation(int rotation) {
    spi_write_command(0x36); // MADCTL
    switch (rotation) {
        case 0:
            spi_write_data(0x08); // RGB color filter panel, no rotation
            break;
        case 90:
            spi_write_data(0x68); // Rotate 90°
            break;
        case 180:
            spi_write_data(0xC8); // Rotate 180°
            break;
        case 270:
            spi_write_data(0xA8); // Rotate 270°
            break;
    }
}

void ST7735S_SetColorMode(const char *mode) {
    spi_write_command(0x3A); // COLMOD
    if (strcmp(mode, "rgb") == 0) {
        spi_write_data(0x05); // 16 bits per pixel, RGB
    } else {
        spi_write_data(0x06); // 16 bits per pixel, BGR
    }
}