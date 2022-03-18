/*
 * i2c_lcd.h
 *
 * Created: 2.03.2022 12:13:48
 *  Author: haluk
 */ 


#ifndef I2C_LCD_H_
#define I2C_LCD_H_

#include <avr/io.h>
#include "i2c_master.h"
#define LCD_ADDR	0x3c

//lcd komutlar
#define LCD_CL lcd_cmd(0x01)
#define LCD_HOME lcd_cmd(0x02)
#define LCD_NSCR_RL lcd_cmd(0x04)
#define LCD_SCR_RL lcd_cmd(0x05)
#define LCD_NSCR_LR lcd_cmd(0x06)
#define LCD_SCR_LR lcd_cmd(0x07)
#define LCD_DOFF lcd_cmd(0x08)
#define LCD_DON lcd_cmd(0x0C)
#define LCD_DBON lcd_cmd(0x0D)
#define LCD_DCON lcd_cmd(0x0E)
#define LCD_DCBON lcd_cmd(0x0F)
#define LCD_CR_L lcd_cmd(0x10)
#define LCD_CR_R lcd_cmd(0x14)
#define LCD_SC_L lcd_cmd(0x18)
#define LCD_SC_R lcd_cmd(0x1C)
#define LCD_4L1 lcd_cmd(0x20)
#define LCD_4L2 lcd_cmd(0x28)

#define EN 0x04
#define RW 0x02
#define RS 0x01

/*
uint8_t  zil[8] ={
	0x04, 0x0E,0x0E, 0x0E,0x1F,0x1F, 0x04, 0x00
};*/
typedef enum {
	LIGHT_ON	=0x08,
	LIGHT_OFF	=0x00
}light_t;
void lcd_light(light_t _light);
void lcd_data(uint8_t  gelen);
void lcd_cmd(uint8_t  cmd);
void lcd_yaz(uint8_t  data);

void lcd_git(uint8_t  x, uint8_t y);
void lcd_krk(uint8_t  adresi,  uint8_t  *karakter);
void lcd_dizi (char *str);
void lcd_basla();


#endif /* LCD_H_ */