/*
 * LCD.h
 *
 * Created: 18.03.2022 11:40:03
 *  Author: haluk
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>

//pin-port tanýmlarý
#define DATA_PORT PORTD
#define CMD_PORT PORTB
#define DS_PORT PORTB

#define EN_ PB1
#define RS_ PB0
#define CE_ PB3
#define IO_ PB4
#define CLK_ PB5
#define DATA_7 PD7
#define DATA_6 PD6
#define DATA_5 PD5
#define DATA_4 PD4
//io tanýmlarý
#define DATA_OUT DDRD|=(1<<DATA_7)|(1<<DATA_6)|(1<<DATA_5)|(1<<DATA_4)
#define DS_OUT DDRB|=(1<<CE_)|(1<<CLK_)
#define IO_OUT DDRB|=(1<<IO_)
#define IO_IN DDRB&=~(1<<IO_)
#define CMD_OUT DDRB|=(1<<RS_)|(1<<EN_)
//
#define EN_HIGH CMD_PORT|=(1<<EN_)
#define EN_LOW CMD_PORT&=~(1<<EN_)
#define RS_HIGH CMD_PORT|=(1<<RS_)
#define RS_LOW CMD_PORT&=~(1<<RS_)
#define CE_HIGH DS_PORT|=(1<<CE_)
#define CE_LOW DS_PORT&=~(1<<CE_)
#define IO_HIGH DS_PORT|=(1<<IO_)
#define IO_LOW DS_PORT&=~(1<<IO_)
#define CLK_HIGH DS_PORT|=(1<<CLK_)
#define CLK_LOW DS_PORT&=~(1<<CLK_)

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

void lcd_data(uint8_t  gelen);
void lcd_cmd(uint8_t  cmd);
void lcd_yaz(uint8_t  data);
void lcd_git(uint8_t  x, uint8_t y);
void lcd_krk(uint8_t  adresi,  uint8_t  *karakter);
void lcd_dizi (char *str);
void lcd_basla();


#endif /* LCD_H_ */