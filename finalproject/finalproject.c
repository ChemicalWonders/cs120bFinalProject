#include <avr/io.h>
#include <avr/pgmspace.h> // Built in avr library

#include "header/timer.h"
#include "header/io.c"
#include "header/seven_seg.h"
#include "header/fix_fft.c"

#include <string.h>

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital convers ion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	// in Free Running Mode, a new conversion will trigger
	// whenever the previous conversion completes.
}

// This is how we define a binary array of our character pattern.
// Each const represents a 5x8 pixel grid, with ONES representing 
// illuminated pixels, and ZEROS representing non-illuminated pixels.

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

// The following function can be found in the lcd_lib.c file found on the accompanying website
// The only change I made was the function names to our pre-built functions (LCD_WriteCommand and LCD_WriteData)
// as they have the same functionality.
void LCDdefinechar(const uint8_t *pc, uint8_t char_code){
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	
	LCD_init();
	const unsigned char* note = "note:   fr:  ";
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
	
	LCD_Cursor(7);
	LCD_WriteData(0b01000001);
	
	LCD_Cursor(12);
	LCD_WriteData(0b00110100);
	LCD_Cursor(13);
	LCD_WriteData(0b00110100);
	LCD_Cursor(14);
	LCD_WriteData(0b00110000);
   
   LCDdefinechar(filledcircle, 1);
   LCD_Cursor(24);
   LCD_WriteData(0b00001001);
   
   LCDdefinechar(LINE, 2);
   LCD_Cursor(17);
   LCD_WriteData(0b00001010);
   
   LCD_Cursor(31);
   LCD_WriteData(0b00001010);
   //PORTB = 0x0B | PORTB;
   Write7Seg(SS_A);
   
   ADC_init();

   TimerSet(6000);
   TimerOn();

   int value = 128;
   unsigned char x[value];
   int inverse = 0;
   unsigned char maximum = 0;
   unsigned char location = 0;
   unsigned char A_TONE = 440;
   int v = 0;
   
   while(!TimerFlag)
   {
      for (int i = 0; i < value; ++i)
      {
         x[i] = ADC;
      }
	  
	  v = fix_fftr(x, value, inverse);
	  
	  for (int j = 0; j < value; ++j)
	  {
		  if (x[j] > maximum)
		  {
			  maximum  = x[j];
			  location = j;
		  }
	  }
	  
	  if (maximum > A_TONE){
		  Write7Seg(SS_B);
		  LCD_Cursor(7);
		  LCD_WriteData(0b01000010);
	  }
	  else{
		  Write7Seg(SS_A);
		  LCD_Cursor(7);
		  LCD_WriteData(0b01000001);
	  }
	  
	  
	  TimerFlag = 0;
		
		
	  maximum = 0;
	  
	  //LCD_DisplayString(1, maximum);
   }
   
   return 0;
}