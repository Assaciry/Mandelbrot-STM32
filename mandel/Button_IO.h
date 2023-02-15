#ifndef BUTTON_IO_H
#define BUTTON_IO_H

#include "stm32f10x.h"
#include <stdbool.h>

void btn_io_init(void);
int btn_io_process_input(int current);

#endif
