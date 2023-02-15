#ifndef LCD_H
#define LCD_H

#include "spi.h"
#include <stdbool.h>

void LCD_init(void);

// There are two memory banks in the LCD, data/RAM and commands.
// This function sets the DC pin high or low depending, and then
// sends the data byte
void LCD_write(bool data_or_command, uint8_t data);
void set_pixel(int x, int y, bool bw);
void clear_display(bool bw);
void goto_xy(int x, int y);
void update_display(void);
void set_char(char character, int x, int y, bool bw);
void set_str(char *string, int x, int y, bool bw);
void set_line(int x0, int y0, int x1, int y1, bool bw);
void set_rect(int x0, int y0, int x1, int y1, bool fill, bool bw);
void set_contrast(uint8_t contrast);

#endif
