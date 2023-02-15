#ifndef REGISTER_DEF_H
#define REGISTER_DEF_H

#include <stdint.h>

#ifndef __IO
	#define __IO volatile  // MISRA C standard
#endif


/******************************** RCC Structures ***************************************/
#define RCC_BASE_RD					   0x40021000UL
#define RCC_AHBENR_OFFSET    0x14UL
#define RCC_APB2ENR_OFFSET   0x18UL
#define RCC_APB1ENR_OFFSET   0x1CUL
#define RCC_CFGR_OFFSET      0x04UL
#define RCC_APB2ENR_R 		   (RCC_BASE_RD + RCC_APB2ENR_OFFSET)
#define RCC_APB1ENR_R 		   (RCC_BASE_RD + RCC_APB1ENR_OFFSET)

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t afio_en : 1;
		uint32_t reserved_1 : 1;
		uint32_t iop_a_en : 1;
		uint32_t iop_b_en : 1;
		uint32_t iop_c_en : 1;
		uint32_t iop_d_en : 1;
		uint32_t iop_e_en : 1;
		uint32_t iop_f_en : 1;
		uint32_t iop_g_en : 1;
		uint32_t adc_1_en : 1;
		uint32_t adc_2_en : 1;
		uint32_t tim_1_en : 1;
		uint32_t spi_1_en : 1;
		uint32_t tim_8_en : 1;
		uint32_t usart_1_en : 1;
		uint32_t adc_3_en : 1;
		uint32_t reserved_2 : 3;
		uint32_t tim_9_en : 1;
		uint32_t tim_10_en : 1;
		uint32_t tim_11_en : 1;
		uint32_t reserved_3 : 10;
	} fields;

} RCC_APB2ENR_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t dma1_en 			: 1;
		uint32_t dma2_en 			: 1;
		uint32_t sram_en 			: 1;
		uint32_t reserved1 		: 1;
		uint32_t flitf_en 		: 1;
		uint32_t reserved2 		: 1;
		uint32_t crc_en 			: 1;
		uint32_t reserved3 		: 5;
		uint32_t otgfs_en 		: 1;
		uint32_t reserved4 		: 1;
		uint32_t ethmac_en 		: 1;
		uint32_t ethmactx_en	: 1;
		uint32_t reserved5 		: 16;
	} fields;

} RCC_AHBENR_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t tim2_en 				: 1;
		uint32_t tim3_en 				: 1;
		uint32_t tim4_en 				: 1;
		uint32_t tim5_en 				: 1;
		uint32_t tim6_en 				: 1;
		uint32_t tim7_en 				: 1;
		uint32_t tim12_en 			: 1;
		uint32_t tim13_en 			: 1;
		uint32_t tim14_en 			: 1;
		uint32_t reserved1 			: 2;
		uint32_t wwdg_en 				: 1;
		uint32_t reserved2 			: 2;
		uint32_t spi2_en 				: 1;
		uint32_t spi3_en 				: 1;
		uint32_t reserved3 			: 1;
		uint32_t usart2_en 			: 1;
		uint32_t usart3_en 			: 1;
		uint32_t usart4_en 			: 1;
		uint32_t usart5_en 			: 1;
		uint32_t i2c1_en 				: 1;
		uint32_t i2c2_en 				: 1;
		uint32_t usb_en 				: 1;
		uint32_t reserved4 			: 1;
		uint32_t can_en 				: 1;
		uint32_t reserved5 			: 1;
		uint32_t bkp_en 				: 1;
		uint32_t pwr_en 				: 1;
		uint32_t dac_en 				: 1;
		uint32_t reserved6 			: 2;
	} fields;

} RCC_APB1ENR_t;

/******************************** GPIO Structures ***************************************/
#define GPIOA_BASE_RD				   0x40010800UL
#define GPIOB_BASE_RD				   0x40010C00UL
#define GPIOC_BASE_RD				   0x40011000UL
#define GPIO_CRL_OFFSET 		 0x00UL
#define GPIO_CRH_OFFSET 		 0x04UL
#define GPIO_IDR_OFFSET 		 0x08UL
#define GPIO_ODR_OFFSET			 0x0CUL
#define GPIO_BSRR_OFFSET		 0x10UL
#define GPIO_BRR_OFFSET			 0x14UL

#define GPIO_CNF_GENERAL_OUT_PP  0
#define GPIO_CNF_GENERAL_OUT_OD  1
#define GPIO_CNF_ALTERNATE_OUT_PP  2
#define GPIO_CNF_ALTERNATE_OUT_OD  3

#define GPIO_CNF_INPUT_ANALOG 0
#define GPIO_CNF_INPUT_FLOATING 1
#define GPIO_CNF_INPUT_PD 2
#define GPIO_CNF_INPUT_PU 2

#define GPIO_INPUT_MODE   		0
#define GPIO_OUT_MODE_10MHz 	1
#define GPIO_OUT_MODE_2MHz 		2
#define GPIO_OUT_MODE_50MHz 	3

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t mode8 : 2;
		uint32_t cnf8 : 2;
		uint32_t mode9 : 2;
		uint32_t cnf9 : 2;
		uint32_t mode10 : 2;
		uint32_t cnf10 : 2;
		uint32_t mode11 : 2;
		uint32_t cnf11 : 2;
		uint32_t mode12 : 2;
		uint32_t cnf12 : 2;
		uint32_t mode13 : 2;
		uint32_t cnf13 : 2;
		uint32_t mode14 : 2;
		uint32_t cnf14 : 2;
		uint32_t mode15 : 2;
		uint32_t cnf15 : 2;
	
	} fields;

} GPIOx_CRH_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t mode0 : 2;
		uint32_t cnf0 : 2;
		uint32_t mode1 : 2;
		uint32_t cnf1 : 2;
		uint32_t mode2 : 2;
		uint32_t cnf2 : 2;
		uint32_t mode3 : 2;
		uint32_t cnf3 : 2;
		uint32_t mode4 : 2;
		uint32_t cnf4 : 2;
		uint32_t mode5 : 2;
		uint32_t cnf5 : 2;
		uint32_t mode6 : 2;
		uint32_t cnf6 : 2;
		uint32_t mode7 : 2;
		uint32_t cnf7 : 2;
	
	} fields;

} GPIOx_CRL_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t odr0 : 1;
		uint32_t odr1 : 1;
		uint32_t odr2 : 1;
		uint32_t odr3 : 1;
		uint32_t odr4 : 1;
		uint32_t odr5 : 1;
		uint32_t odr6 : 1;
		uint32_t odr7 : 1;
		uint32_t odr8 : 1;
		uint32_t odr9 : 1;
		uint32_t odr10 : 1;
		uint32_t odr11 : 1;
		uint32_t odr12 : 1;
		uint32_t odr13 : 1;
		uint32_t odr14 : 1;
		uint32_t odr15 : 1;
		uint32_t reserved : 15;
		
	} fields;

} GPIOx_ODR_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t bs0 : 1;
		uint32_t bs1 : 1;
		uint32_t bs2 : 1;
		uint32_t bs3 : 1;
		uint32_t bs4 : 1;
		uint32_t bs5 : 1;
		uint32_t bs6 : 1;
		uint32_t bs7 : 1;
		uint32_t bs8 : 1;
		uint32_t bs9 : 1;
		uint32_t bs10 : 1;
		uint32_t bs11 : 1;
		uint32_t bs12 : 1;
		uint32_t bs13 : 1;
		uint32_t bs14 : 1;
		uint32_t bs15 : 1;
		uint32_t br0 : 1;
		uint32_t br1 : 1;
		uint32_t br2 : 1;
		uint32_t br3 : 1;
		uint32_t br4 : 1;
		uint32_t br5 : 1;
		uint32_t br6 : 1;
		uint32_t br7 : 1;
		uint32_t br8 : 1;
		uint32_t br9 : 1;
		uint32_t br10 : 1;
		uint32_t br11 : 1;
		uint32_t br12 : 1;
		uint32_t br13 : 1;
		uint32_t br14 : 1;
		uint32_t br15 : 1;
	} fields;

} GPIOx_BSRR_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t br0 : 1;
		uint32_t br1 : 1;
		uint32_t br2 : 1;
		uint32_t br3 : 1;
		uint32_t br4 : 1;
		uint32_t br5 : 1;
		uint32_t br6 : 1;
		uint32_t br7 : 1;
		uint32_t br8 : 1;
		uint32_t br9 : 1;
		uint32_t br10 : 1;
		uint32_t br11 : 1;
		uint32_t br12 : 1;
		uint32_t br13 : 1;
		uint32_t br14 : 1;
		uint32_t br15 : 1;
		uint32_t reserved : 16;
	} fields;

} GPIOx_BRR_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t idr0 : 1;
		uint32_t idr1 : 1;
		uint32_t idr2 : 1;
		uint32_t idr3 : 1;
		uint32_t idr4 : 1;
		uint32_t idr5 : 1;
		uint32_t idr6 : 1;
		uint32_t idr7 : 1;
		uint32_t idr8 : 1;
		uint32_t idr9 : 1;
		uint32_t idr10 : 1;
		uint32_t idr11 : 1;
		uint32_t idr12 : 1;
		uint32_t idr13 : 1;
		uint32_t idr14 : 1;
		uint32_t idr15 : 1;
		uint32_t reserved : 16;
	} fields;

} GPIOx_IDR_t;


/************************* USART Structures ********************************/
#define USART1_BASE_RD					 0x40013800UL
#define USART_SR_OFFSET			 0x00UL
#define USART_DR_OFFSET			 0x04UL
#define USART_BRR_OFFSET		 0x08UL
#define USART_CR1_OFFSET 		 0x0CUL
#define USART_CR3_OFFSET     0x14UL

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t parity_error : 1;
		uint32_t framing_error : 1;
		uint32_t noise_error_flag : 1;
		uint32_t overrun_error : 1;
		uint32_t idle_line_detected : 1;
		uint32_t rdr_not_empty : 1;
		uint32_t transmission_complete : 1;
		uint32_t tdr_empty : 1;
		uint32_t LIN_break_detection_flag : 1;
		uint32_t CTS_flag : 1;
		uint32_t reserved : 22;
	} fields;

} USART_SR_t;


typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t data : 9;
		uint32_t reserved : 23;
	} fields;

} USART_DR_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t baudrate : 16;
		uint32_t reserved : 16;
	} fields;

} USART_BRR_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t send_break : 1;
		uint32_t receiver_wakeup : 1;
		uint32_t receiver_en : 1;
		uint32_t transmitter_en : 1;
		uint32_t idle_interrupt_en : 1;
		uint32_t rxne_interrupt_en : 1;
		uint32_t transmission_complete_interrupt_en : 1;
		uint32_t txe_interrupt_en : 1;
		uint32_t pe_interrupt_en : 1;
		uint32_t parity_selection : 1;
		uint32_t parity_control_en : 1;
		uint32_t wakeup_method : 1;
		uint32_t word_length : 1;
		uint32_t usart_en : 1;
		uint32_t reserved : 19;
	} fields;

} USART1_CR1_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t eie : 1;
		uint32_t iren : 1;
		uint32_t irlp : 1;
		uint32_t hdsel : 1;
		uint32_t nack : 1;
		uint32_t scen : 1;
		uint32_t dmar : 1;
		uint32_t dmat : 1;
		uint32_t rtse : 1;
		uint32_t ctse : 1;
		uint32_t ctsie : 1;
		uint32_t reserved : 21;
	} fields;

} USART1_CR3_t;


/************************* DMA Structures ********************************/
#define DMA1_BASE_RD 						  0x40020000UL
#define DMA_ICFR_OFFSET 			  0x04UL
#define DMA_CCRx_BASE_OFFSET 	  0x08UL
#define DMA_CNDTRx_BASE_OFFSET 	0x0CUL
#define DMA_CPARx_BASE_OFFSET 	0x10UL
#define DMA_CMARx_BASE_OFFSET 	0x14UL

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t en 			: 1;
		uint32_t tcie 		: 1;
		uint32_t htie 		: 1;
		uint32_t teie 		: 1;
		uint32_t dir 			: 1;
		uint32_t circ 		: 1;
		uint32_t pinc 		: 1;
		uint32_t minc 		: 1;
		uint32_t psize 		: 2;
		uint32_t msize 		: 2;
		uint32_t pl 			: 2;
		uint32_t mem2mem 	: 1;
		uint32_t reserved : 17;
	} fields;

} DMA_CCRx_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t cgif1 			: 1;
		uint32_t ctcif1 		: 1;
		uint32_t chtif1 		: 1;
		uint32_t cteif1 		: 1;
		uint32_t cgif2 			: 1;
		uint32_t ctcif2 		: 1;
		uint32_t chtif2 		: 1;
		uint32_t cteif2 		: 1;
		uint32_t cgif3 			: 1;
		uint32_t ctcif3 		: 1;
		uint32_t chtif3 		: 1;
		uint32_t cteif3 		: 1;
		uint32_t cgif4 			: 1;
		uint32_t ctcif4 		: 1;
		uint32_t chtif4 		: 1;
		uint32_t cteif4 		: 1;
		uint32_t cgif5 			: 1;
		uint32_t ctcif5 		: 1;
		uint32_t chtif5 		: 1;
		uint32_t cteif5 		: 1;
		uint32_t cgif6 			: 1;
		uint32_t ctcif6 		: 1;
		uint32_t chtif6 		: 1;
		uint32_t cteif6 		: 1;
		uint32_t cgif7 			: 1;
		uint32_t ctcif7 		: 1;
		uint32_t chtif7 		: 1;
		uint32_t cteif7 		: 1;
		uint32_t reserved : 4;
	} fields;

} DMA_IFCR_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t pa 			: 32;
	} fields;

} DMA_CPARx_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t pa 			: 32;
	} fields;

} DMA_CMARx_t;

typedef union
{
	uint32_t _register;
	
	struct
	{
		uint32_t ndt 			: 16;
		uint32_t reserved : 16;
	} fields;

} DMA_CNDTRx_t;


/************************* General Purpose Timer Structures ********************************/
#define TIM2_BASE_RD 0x40000000UL
#define TIM3_BASE_RD 0x40000400UL

#define TIMx_CR1_OFFSET 0x00UL
#define TIMx_CR2_OFFSET 0x04UL
#define TIMx_SR_OFFSET  0x10UL
#define TIMx_CCMR1_OFFSET 0x18UL
#define TIMx_CCMR2_OFFSET 0x1CUL
#define TIMx_CCER_OFFSET 0x20UL
#define TIMx_CNT_OFFSET 0x24UL
#define TIMx_PSC_OFFSET 0x28UL
#define TIMx_ARR_OFFSET 0x2CUL
#define TIMx_CCR1_OFFSET 0x34UL
#define TIMx_CCR2_OFFSET 0x38UL
#define TIMx_CCR3_OFFSET 0x3CUL
#define TIMx_CCR4_OFFSET 0x40UL

typedef union
{
	uint16_t _register;
	
	struct
	{
		uint16_t cen 					: 1;
		uint16_t udis   		 	: 1;
		uint16_t urs	   		 	: 1;
		uint16_t opm	   		 	: 1;
		uint16_t dir	   		 	: 1;
		uint16_t cms	   		 	: 2;
		uint16_t arpe   		 	: 1;
		uint16_t ckd	   		 	: 2;
		uint16_t reserved   	: 6;
	} fields;

} TIMx_CR1_t;

typedef union
{
	uint16_t _register;
	
	struct
	{
		uint16_t reserved1 		: 3;
		uint16_t ccds   		 	: 1;
		uint16_t mms	   		 	: 3;
		uint16_t ti1s	   		 	: 1;
		uint16_t reserved2   	: 8;
	} fields;

} TIMx_CR2_t;

typedef union
{
	uint16_t _register;
	
	struct
	{
		uint16_t uif 						: 1;
		uint16_t cc1if 					: 1;
		uint16_t cc2if 					: 1;
		uint16_t cc3if 					: 1;
		uint16_t cc4if 					: 1;
		uint16_t reserved1 			: 1;
		uint16_t tif	   		 		: 1;
		uint16_t reserved2	   	: 2;
		uint16_t cc1of 					: 1;
		uint16_t cc2of 					: 1;
		uint16_t cc3of 					: 1;
		uint16_t cc4of 					: 1;
		uint16_t reserved3   		: 3;
	} fields;

} TIMx_SR_t;

typedef union
{
	uint16_t _register;
	
	struct
	{
		uint16_t cnt 	: 16;
	} fields;

} TIMx_CNT_t;

typedef union
{
	uint16_t _register;
	
	struct
	{
		uint16_t psc 	: 16;
	} fields;

} TIMx_PSC_t;

typedef union
{
	uint16_t _register;
	
	struct
	{
		uint16_t arr 	: 16;
	} fields;

} TIMx_ARR_t;

typedef union
{
	uint16_t _register;
	
	struct
	{
		uint16_t ccrx 	: 16;
	} fields;

} TIMx_CCRx_t;


/************************* SPI Structures ********************************/
#define SPI1_BASE_RD			 0x40013000UL
#define SPI2_BASE_RD      0x40003800UL
#define SPI_CR1_OFFSET 0x00UL
#define SPI_SR_OFFSET  0x08UL
#define SPI_DR_OFFSET  0x0CUL

typedef union
{
	uint16_t _register;
	
	struct
	{
		uint16_t cpha 				: 1;
		uint16_t cpol 				: 1;
		uint16_t mstr 				: 1;
		uint16_t br 					: 3;
		uint16_t spe	 				: 1;
		uint16_t lsb_first 		: 1;
		uint16_t ssi			 		: 1;
		uint16_t ssm			 		: 1;
		uint16_t rx_only	 		: 1;
		uint16_t dff			 		: 1;
		uint16_t crc_next 		: 1;
		uint16_t crc_en		 		: 1;
		uint16_t bidi_oe 			: 1;
		uint16_t bidi_mode 		: 1;
	} fields;

} SPI_CR1_t;

typedef union
{
	uint16_t _register;
	
	struct
	{
		uint16_t rxne 		: 1;
		uint16_t txe 			: 1;
		uint16_t chside 	: 1;
		uint16_t udr 			: 1;
		uint16_t crc_err	: 1;
		uint16_t modf 		: 1;
		uint16_t ovr			: 1;
		uint16_t bsy			: 1;
		uint16_t reserved	: 8;
	} fields;

} SPI_SR_t;

typedef union
{
	uint16_t _register;
	
	struct
	{
		uint16_t data : 16;
	} fields;
} SPI_DR_t;

#endif
