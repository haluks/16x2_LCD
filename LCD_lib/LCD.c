/*
 * Karakakter_LCD.c
 *
 * Created: 18.03.2022 11:37:49
 * Author : haluk
 */ 
#include "lcd.h"
#define F_CPU 16000000ul
#include <util/delay.h>

void lcd_data(uint8_t  gelen){
	DATA_PORT=(DATA_PORT&0x0f)|(gelen & 0xF0);
	EN_HIGH;
	_delay_us(1);
	EN_LOW;
	_delay_us(100);
}
void lcd_cmd(uint8_t  cmd){
	RS_LOW;
	lcd_data(cmd);
	lcd_data(cmd<<4);
}
void lcd_yaz(uint8_t  data){
	RS_HIGH;
	lcd_data(data);
	lcd_data(data<<4);
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
	CMD_OUT;
	DATA_OUT;
	_delay_ms(1000);
	lcd_data(0x03);//resetleme
	_delay_us(4100);
	lcd_data(0x03);
	_delay_us(100);
	lcd_data(0x03);
	lcd_data(0x02);
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


