#ifndef SPI_H
#define SPI_H

#include "RegisterDefinitions.h"

void spi1_init(void);
void spi2_init(void);
void spi1_transmit(uint8_t *data, uint32_t size);
void spi1_receive(uint8_t *data, uint32_t size);
void spi2_transmit(uint8_t *data, uint32_t size);
void spi2_receive(uint8_t *data, uint32_t size);

#endif
