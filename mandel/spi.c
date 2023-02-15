#include "spi.h"

// #define DEBUG(field_name) printf(#field_name ": %zu\n\r", field_name);

__IO SPI_SR_t *spi1_sr = (__IO SPI_SR_t *)(SPI1_BASE_RD + SPI_SR_OFFSET);
__IO SPI_DR_t *spi1_dr = (__IO SPI_DR_t *)(SPI1_BASE_RD + SPI_DR_OFFSET);

__IO SPI_SR_t *spi2_sr = (__IO SPI_SR_t *)(SPI2_BASE_RD + SPI_SR_OFFSET);
__IO SPI_DR_t *spi2_dr = (__IO SPI_DR_t *)(SPI2_BASE_RD + SPI_DR_OFFSET);

/*
* SPI1_NSS  : PA4
* SPI1_SCK  : PA5
* SPI1_MISO : PA6
* SPI1_MOSI : PA7
* Slave Select : PA2
*/
void spi1_init(void)
{
	__IO RCC_APB2ENR_t *apb2 = (__IO RCC_APB2ENR_t *)(RCC_BASE_RD + RCC_APB2ENR_OFFSET);
	__IO GPIOx_CRL_t *crl    = (__IO GPIOx_CRL_t *)(GPIOA_BASE_RD + GPIO_CRL_OFFSET);
	__IO SPI_CR1_t *spi1_cr = (__IO SPI_CR1_t *)(SPI1_BASE_RD + SPI_CR1_OFFSET);
	
	// Enable clock for SPI1 / GPIOA / AFIO
	apb2->fields.spi_1_en = 1;
	apb2->fields.iop_a_en = 1;
	apb2->fields.afio_en = 1;
	
	/* Enable GPIO Pins */
	// NSS
	//crl->fields.cnf4 = GPIO_CNF_ALTERNATE_OUT_PP;
	//crl->fields.mode4 = GPIO_OUT_MODE_50MHz;
	
	// SCK
	crl->fields.cnf5 = GPIO_CNF_ALTERNATE_OUT_PP;
	crl->fields.mode5 = GPIO_OUT_MODE_50MHz;
	// MISO
//	crl->fields.cnf6 = GPIO_CNF_ALTERNATE_OUT_PP;
//	crl->fields.mode6 = GPIO_OUT_MODE_50MHz;
	// MOSI
	crl->fields.cnf7 = GPIO_CNF_ALTERNATE_OUT_PP;
	crl->fields.mode7 = GPIO_OUT_MODE_50MHz;
//	// SS
//	crl->fields.cnf2 = GPIO_CNF_GENERAL_OUT_PP;
//	crl->fields.mode2 = GPIO_OUT_MODE_2MHz;
	
	
	// Configure BaudRate
	spi1_cr->fields.br = 5; // fpclk/ 64
	
	// Configure clock polarity
	spi1_cr->fields.cpol = 0;
	
	// Configure clock phase
	spi1_cr->fields.cpha = 0;
	
	spi1_cr->fields.bidi_mode = 0;
	spi1_cr->fields.bidi_oe = 1;
	
	// Enable full duplex
	spi1_cr->fields.rx_only = 0;
	
	// Enable MSB first
	spi1_cr->fields.lsb_first = 0;
	
	// Select 8 bit data frame
	spi1_cr->fields.dff = 0;
	
	// Enable software slave management
	spi1_cr->fields.ssm = 1;
	spi1_cr->fields.ssi = 1;
	
	// Select as master device
	spi1_cr->fields.mstr = 1;
	
	// Enable SPI1
	spi1_cr->fields.spe = 1;
}

/*
* SPI1_NSS  : PB12
* SPI1_SCK  : PB13
* SPI1_MISO : PB14
* SPI1_MOSI : PB15
* Slave Select : 
*/
void spi2_init(void)
{
	__IO RCC_APB2ENR_t *apb2 = (__IO RCC_APB2ENR_t *)(RCC_BASE_RD + RCC_APB2ENR_OFFSET);
	__IO RCC_APB1ENR_t *apb1 = (__IO RCC_APB1ENR_t *)(RCC_BASE_RD + RCC_APB1ENR_OFFSET);
	__IO GPIOx_CRH_t *crh    = (__IO GPIOx_CRH_t *)(GPIOB_BASE_RD + GPIO_CRH_OFFSET);
	__IO SPI_CR1_t *spi2_cr = (__IO SPI_CR1_t *)(SPI2_BASE_RD + SPI_CR1_OFFSET);
	
	// Enable clock for SPI2 / GPIOB / AFIO
	apb1->fields.spi2_en = 1;
	apb2->fields.iop_b_en = 1;
	apb2->fields.afio_en = 1;
	
	/* Enable GPIO Pins */
	// NSS
	//crl->fields.cnf4 = GPIO_CNF_ALTERNATE_OUT_PP;
	//crl->fields.mode4 = GPIO_OUT_MODE_50MHz;
	
	// SCK
	crh->fields.cnf13 = GPIO_CNF_ALTERNATE_OUT_PP;
	crh->fields.mode13 = GPIO_OUT_MODE_50MHz;
	// MISO
//	crl->fields.cnf6 = GPIO_CNF_ALTERNATE_OUT_PP;
//	crl->fields.mode6 = GPIO_OUT_MODE_50MHz;
	// MOSI
	crh->fields.cnf14 = GPIO_CNF_ALTERNATE_OUT_PP;
	crh->fields.mode14 = GPIO_OUT_MODE_50MHz;
//	// SS
//	crl->fields.cnf2 = GPIO_CNF_GENERAL_OUT_PP;
//	crl->fields.mode2 = GPIO_OUT_MODE_2MHz;
	
	
	// Configure BaudRate
	spi2_cr->fields.br = 4; // fpclk/ 36
	
	// Configure clock polarity
	spi2_cr->fields.cpol = 0;
	
	// Configure clock phase
	spi2_cr->fields.cpha = 0;
	
	// Enable full duplex
	spi2_cr->fields.rx_only = 0;
	
	// Enable MSB first
	spi2_cr->fields.lsb_first = 0;
	
	spi2_cr->fields.bidi_mode = 0;
	spi2_cr->fields.bidi_oe = 1;
	
	// Select as master device
	spi2_cr->fields.mstr = 1;
	
	// Select 8 bit data frame
	spi2_cr->fields.dff = 0;
	
	// Enable software slave management
	spi2_cr->fields.ssm = 1;
	spi2_cr->fields.ssi = 1;
	
	// Enable SPI1
	spi2_cr->fields.spe = 1;
	
	
}

void spi1_transmit(uint8_t *data, uint32_t size)
{
	uint32_t i = 0;
	volatile uint8_t temp = 0;
	
	while(i < size)
	{
		// Wait until TXE is set
		while(!spi1_sr->fields.txe);
		
		// Write data to data register
		spi1_dr->fields.data = data[i];
		i++;
	}
	
	// Wait until TXE is set
	while(!spi1_sr->fields.txe);
	
	// Wait while SPI is busy
	while(spi1_sr->fields.bsy);
	
	// Clear OVR flag
	temp = spi1_dr->fields.data;
}

void spi2_transmit(uint8_t *data, uint32_t size)
{
	uint32_t i = 0;
	volatile uint8_t temp = 0;
	
	while(i < size)
	{
		// Wait until TXE is set
		while(!spi2_sr->fields.txe);
		
		// Write data to data register
		spi2_dr->fields.data = data[i];
		i++;
	}
	
	// Wait until TXE is set
	while(!spi2_sr->fields.txe);
	
	// Wait while SPI is busy
	while(spi2_sr->fields.bsy);
	
	// Clear OVR flag
	temp = spi2_dr->fields.data;
}

void spi1_receive(uint8_t *data, uint32_t size)
{
	while(size)
	{
		// Send dummy data
		spi1_dr->fields.data = 0;
		
		// Wait for RXNE flag to be set
		while(!spi1_sr->fields.rxne);
		
		// Read data from register
		*data = spi1_dr->fields.data;
		
		--size;
		++data;
	}
	
}

void spi2_receive(uint8_t *data, uint32_t size)
{
	while(size)
	{
		// Send dummy data
		spi2_dr->fields.data = 0;
		
		// Wait for RXNE flag to be set
		while(!spi2_sr->fields.rxne);
		
		// Read data from register
		*data = spi2_dr->fields.data;
		
		--size;
		++data;
	}
	
}
