/*
 * LCD16x2_4bit.h
 *
 * http://www.electronicwings.com
 */ 


#ifndef LCD16X2_4BIT_H_
#define LCD16X2_4BIT_H_
#define  F_CPU 11059200UL
#include <avr/io.h>
#include <util/delay.h>
#define LCD_DPRT PORTC
#define LCD_DDDR DDRC
#define LCD_RS 4
#define LCD_EN 5

void LCD_Command(unsigned char cmnd);
void LCD_Char(unsigned char data);
void LCD_Init();
void LCD_String_xy(unsigned char, unsigned char, char *);
void LCD_String(char *str);
void LCD_Clear();
void LCD_WriteInt(int val,unsigned int field_length);



#endif /* LCD16X2_4BIT_H_ */
