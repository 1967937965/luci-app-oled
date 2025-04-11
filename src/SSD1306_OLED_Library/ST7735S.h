#ifndef ST7735S_H
#define ST7735S_H

#define ST7735S_WIDTH  80
#define ST7735S_HEIGHT 160

void ST7735S_Init();
void ST7735S_DrawPixel(int x, int y, int color);
void ST7735S_ClearScreen();
void ST7735S_UpdateScreen();

#endif