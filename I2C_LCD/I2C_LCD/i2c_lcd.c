/*
 * i2c_lcd.c
 *
 * Created: 2.03.2022 12:14:00
 *  Author: haluk
 */ 
#include "i2c_lcd.h"
#define F_CPU 16000000ul
#include <util/delay.h>
uint8_t light;
void lcd_data(uint8_t  gelen){
	i2c_adr(LCD_ADDR, I2C_WRITE);
	i2c_data(gelen|light);
	i2c_end( _REPEAT);
	i2c_adr(LCD_ADDR, I2C_WRITE);
	i2c_data((gelen|light)|EN);
	i2c_end( _REPEAT);
	i2c_adr(LCD_ADDR, I2C_WRITE);
	i2c_data((gelen|light)&~EN);
	i2c_end(N_REPEAT);	
}
void lcd_light(light_t _light){
	light=_light;
}
void lcd_cmd(uint8_t  cmd){
	//_delay_us(300);	
	lcd_data((cmd&0xf0));
	lcd_data(((cmd<<4)&0xf0));	
}
void lcd_yaz(uint8_t  data){	
	//_delay_us(300);
	lcd_data((data&0xf0)|RS);
	lcd_data(((data<<4)&0xf0)|RS);
}

void lcd_git(uint8_t  x, uint8_t y){
	if (y==0)
	lcd_cmd(0x80+x);
	if (y==1)
	lcd_cmd(0xC0+x);
	if (y==2)
	lcd_cmd(0x94+x);
	if (y>=3)
	lcd_cmd(0xD4+x);
	
}
void lcd_krk(uint8_t  adresi,  uint8_t  *karakter){
	lcd_cmd(0x40+(adresi*8));
	for (uint8_t i=0;i<8;i++){
		lcd_yaz(karakter[i]);
	}
}
void lcd_dizi (char *str)
{
	
	while(*str){
		lcd_yaz (*str++);
	}
}
void lcd_basla(){
	_delay_ms(1000);
	lcd_data(0x30);//resetleme
	_delay_us(4100);
	lcd_data(0x30);
	_delay_us(100);
	lcd_data(0x30);
	lcd_data(0x20);
	LCD_4L2;
	_delay_ms(2);	
	LCD_DOFF;
	_delay_ms(2);
	LCD_DON;
	_delay_ms(2);
	LCD_NSCR_LR;
	_delay_ms(2);
	LCD_HOME;
	_delay_ms(2);
	LCD_CL;
	_delay_ms(2);
}

