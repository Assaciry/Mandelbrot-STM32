#include <stdint.h>
#include "delay.h"
#include "stm32f10x.h"
#include "LCD.h"
#include "Button_IO.h"

#define LCD_WIDTH   50 // Note: x-coordinates go wide
#define LCD_HEIGHT  30 // Note: y-coordinates go high
#define WHITE       0  // For drawing pixels. A 0 draws white.
#define BLACK       1  // A 1 draws black.

/*
PINOUT:
	PC13: Onboard LED 
	
	PC15: 5110 LCD light 
	PA:
	PA:
	PA:
	PA:
	
	PB1:  Button for zoom out
	PB4:  Button for zoom in
	PB7:  Button for move left
	PB14: Button for move right
*/

const int MAXITER = 50;
volatile float coords[LCD_HEIGHT][LCD_WIDTH][2];
volatile bool res[LCD_HEIGHT][LCD_WIDTH];
int btn_state = 1;
bool btn_pressed = false;

// For screen light
static __IO GPIOx_ODR_t *gpioc_odr = (__IO GPIOx_ODR_t *)(GPIOC_BASE_RD + GPIO_ODR_OFFSET);

void init_on_board_led_screenlight()
{
	__IO RCC_APB2ENR_t *apb2 = (__IO RCC_APB2ENR_t *)(RCC_BASE_RD + RCC_APB2ENR_OFFSET);
	__IO GPIOx_CRH_t *crh    = (__IO GPIOx_CRH_t *)(GPIOC_BASE_RD + GPIO_CRH_OFFSET);
	
	apb2->fields.iop_c_en = 1;
	crh->fields.cnf13 = GPIO_CNF_GENERAL_OUT_PP;
	crh->fields.mode13 = GPIO_OUT_MODE_2MHz;
	
	// PC15 for screenlight
	crh->fields.cnf15 = GPIO_CNF_GENERAL_OUT_PP;
	crh->fields.mode15 = GPIO_OUT_MODE_2MHz;
}

void power_up_screen()
{
	gpioc_odr->fields.odr15 = 1;
}

void power_down_screen()
{
	gpioc_odr->fields.odr15 = 0;
}

void init_all()
{
	delayInit();
	init_on_board_led_screenlight();
	spi1_init();
	btn_io_init();
	power_up_screen();
	LCD_init();
}

bool my_roundf(float num){
	return num < 0.5f ? 0 : 1;
}

void calculate_mandelbrot(int MAX_ITER){
	int iter_num, i, j;
	float x,y,xt;
	for(i = 0; i < LCD_HEIGHT; ++i){
		for(j = 0; j < LCD_WIDTH; ++j){
			iter_num = 0;
			x = 0.0f;
			y = 0.0f;
			
			while(x*x+y*y < 4. && iter_num < MAX_ITER){
				xt = x*x-y*y+coords[i][j][0];
				y = 2.*x*y+coords[i][j][1];
				x=xt;
				++iter_num;
			}
			res[i][j] = my_roundf((float)iter_num/MAX_ITER);
		}
	}
}

void calculate_coords(float mult, float xoff, float yoff){
	int i, j;
	for(i = 0; i < LCD_HEIGHT; ++i){
		for(j=0;j<LCD_WIDTH;++j){
       coords[i][j][0] = (float)(j-xoff)*mult;
       coords[i][j][1] = (float)(i-yoff)*mult;
    }
  }
}

void update_mandelbrot(float mult, float xoff, float yoff){
	int i, j;
	calculate_coords(mult,xoff,yoff);
	calculate_mandelbrot(MAXITER);
	for(i = 0; i < LCD_HEIGHT; ++i){
		for(j=0;j<LCD_WIDTH;++j){
			set_pixel(j+(84-LCD_WIDTH)/2,i+(48-LCD_HEIGHT)/2,res[i][j]);
		}
	}
}

int main()
{
	float zoom = 0.1f;
	float xoff = 0;
	bool led = false;
	
	init_all();
	update_display();
	set_contrast(0xBB);
	delayMs(1000);
	clear_display(WHITE);
	
	update_mandelbrot(zoom,LCD_WIDTH/2.,LCD_HEIGHT/2.);
	update_display();
	
	while(1){
		gpioc_odr->fields.odr13 = led;
		led = !led;
		
		if(btn_pressed){
			if(btn_state == 1) zoom *= 2;
			else if(btn_state == 2) zoom *= 0.5;
			else if(btn_state == 3) xoff += 5;
			else if(btn_state == 4) xoff -= 5;
			
			clear_display(WHITE);
			update_mandelbrot(zoom,LCD_WIDTH/2. - xoff,LCD_HEIGHT/2.);
			update_display();
			
			btn_pressed = false;
		}
		
		delayMs(100);
		
	}
}
