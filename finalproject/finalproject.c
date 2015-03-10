/*
 * Custom_character_display.c
 *	http://www.eng.utah.edu/~cs3710/slides/OtherIOx2.pdf
 *  http://winavr.scienceprog.com/example-avr-projects/simplified-avr-lcd-routines.html
 *  http://ieee.ucr.edu/cs120b/lcd/
 *  https://docs.google.com/document/d/1jOQ_47YrEyHdo-u9gBFaOsZT5hyGBkMQS8yxEIuIOZA/edit
 *		
 */ 

#include <avr/io.h>
#include "header/io.c" // Our io.c file from lab 5
#include <avr/pgmspace.h> // Built in avr library
#include "header/seven_seg.h"

// This is how we define a binary array of our character pattern.
// Each const represents a 5x8 pixel grid, with ONES representing 
// illuminated pixels, and ZEROS representing non-illuminated pixels.
const uint8_t dungeon_key[] PROGMEM = {
	0b01110,
	0b10001,
	0b01110,
	0b00100,
	0b00100,
	0b00110,
	0b00100,
	0b00110
}; // A basic, dungeon-esque key

const uint8_t pixel_man[] PROGMEM = {
	0b00100,
	0b01010,
	0b11111,
	0b10101,
	0b00100,
	0b01010,
	0b01010,
	0b11011
	
}; // biped that kinda looks like Buzz Lightyear on an Atari 2600

const uint8_t Links_shield[] PROGMEM = {
	0b00000,
	0b01110,
	0b11011,
	0b10001,
	0b11011,
	0b11011,
	0b11111,
	0b01110
}; // vaguely represents Links shield from The Legend of Zelda for the NES

const uint8_t LINE[8] PROGMEM = { 
	0B00100, 
	0B00100, 
	0B00100, 
	0B00100, 
	0B00100, 
	0B00100, 
	0B00100, 
	0B00100 
};

const uint8_t filledcircle[8] PROGMEM = { 
	0B00100, 
	0B00100,
	0B01110,
	0B11111, 
	0B11111, 
	0B11111, 
	0B01110, 
	0B00100
};

//const uint8_t Mario_TL[] PROGMEM = {
	//0b10001,
	//0b10011,
	//0b10011,
	//0b10101,
	//0b10101,
	//0b10110,
	//0b01000,
	//0b01011
//};
//
//const uint8_t Mario_TM[] PROGMEM = {
	//0b11110,
	//0b11111,
	//0b10010,
	//0b00010,
	//0b10001,
	//0b00011,
	//0b00000,
	//0b11110
//};
//
//const uint8_t Mario_TR[] PROGMEM = {
	//0b00011,
	//0b11011,
	//0b01001,
	//0b00101,
	//0b00010,
	//0b11011,
	//0b00111,
	//0b00111
//};
//
//const uint8_t Mario_BL[] PROGMEM = {
	//0b10111,
	//0b01111,
	//0b10011,
	//0b10001,
	//0b10011,
	//0b11011,
	//0b10111,
	//0b01111
//};
//
//const uint8_t Mario_BM[] PROGMEM = {
	//0b11111,
	//0b11111,
	//0b01101,
	//0b11111,
	//0b11111,
	//0b10011,
	//0b00001,
	//0b00001
//};
//
//const uint8_t Mario_BR[] PROGMEM = {
	//0b11011,
	//0b11101,
	//0b10011,
	//0b00011,
	//0b10011,
	//0b10111,
	//0b11011,
	//0b11101
//};// The preceding six declarations can be called to display a 3x2 block that resembles classic Mario


// The following function can be found in the lcd_lib.c file found on the accompanying website
// The only change I made was the function names to our pre-built functions (LCD_WriteCommand and LCD_WriteData)
// as they have the same functionality.
void LCDdefinechar(const uint8_t *pc,uint8_t char_code){
	uint8_t a, pcc;
	uint16_t i;
	a=(char_code<<3)|0x40;
	for (i=0; i<8; i++){
		pcc=pgm_read_byte(&pc[i]);
		LCD_WriteCommand(a++);
		LCD_WriteData(pcc);
	}
}

int main(void)
{
	DDRB = 0xFF; // LCD is hooked up using PORTD and PORTA, can easily be changed to accommodate your wiring.
	PORTB = 0x00;
	DDRD = 0xFF;
	PORTD = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;
	
	LCD_init();
	const char* note = "note:   fr:  ";
	// The following four calls of LCD_WriteData demonstrate how to call a few random,
	// pre-defined characters stored in the memory of the LCD screen.
	// The total LCD screen memory can be viewed by following the url for CS3710
	LCD_DisplayString(1,note);
	
	// Now I know how to freely access individual characters in LCD memory.
	// Need to define my own characters.
	
	// The following calls to LCDdefinechar define a special character in one of the
	// EIGHT AVAILABLE (0 - 7) spaces in the LCD memory.
	// Note that you can only have up to eight unique characters stored 
	// in LCD memory at any given time.
	// The binary address passed into LCD_WriteData was determined using the chart 
	// on slide 4 found by following the CS 3710 url
	
	//LCDdefinechar(dungeon_key,0);
	LCD_Cursor(7);
	LCD_WriteData(0b01000001);
	
	LCD_Cursor(12);
	LCD_WriteData(0b00110100);
	LCD_Cursor(13);
	LCD_WriteData(0b00110100);
	LCD_Cursor(14);
	LCD_WriteData(0b00110000);
	
   
   //LCDdefinechar(pixel_man,1);
   //LCD_Cursor(9);
   //LCD_WriteData(0b00001001);
   
   LCDdefinechar(filledcircle, 1);
   LCD_Cursor(24);
   LCD_WriteData(0b00001001);
   
   LCDdefinechar(LINE, 2);
   LCD_Cursor(17);
   LCD_WriteData(0b00001010);
   
   
   
   LCD_Cursor(31);
   LCD_WriteData(0b00001010);
   
   //LCDdefinechar(Mario_TL,2);
   //LCDdefinechar(Mario_TM,3);
   //LCDdefinechar(Mario_TR,4);
   //LCDdefinechar(Mario_BL,5);
   //LCDdefinechar(Mario_BM,6);
   //LCDdefinechar(Mario_BR,7);
   //
   //LCD_Cursor(13);
   //LCD_WriteData(0b00001010);
   //LCD_Cursor(14);
   //LCD_WriteData(0b00001011);
   //LCD_Cursor(15);
   //LCD_WriteData(0b00001100);
   //LCD_Cursor(29);
   //LCD_WriteData(0b00001101);
   //LCD_Cursor(30);
   //LCD_WriteData(0b00001110);
   //LCD_Cursor(31);
   //LCD_WriteData(0b00001111);
   
   
  PORTB = 0x0B | PORTB;
  Write7Seg(SS_A);
    while(1)
    {
		continue;
        //TODO:: Please write your application code 
    }
}