#include <avr/io.h>
#include <avr/pgmspace.h> // Built in avr library

#include "header/timer.h"
#include "header/io.c"
#include "header/seven_seg.h"
#include "header/fix_fft.c"
#include "header/toneBars.c"

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital convers ion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	// in Free Running Mode, a new conversion will trigger
	// whenever the previous conversion completes.
}

//Levels

//Level 1
const uint8_t level1[8] PROGMEM = {
	0B00000, 0B00000, 0B00000, 0B00000, 0B00000, 0B00000, 0B00000, 0B11111
};

//Level 2
const uint8_t level2[8] PROGMEM = {
	0B00000, 0B00000, 0B00000, 0B00000, 0B00000, 0B00000, 0B11111, 0B11111
};

//Level 3
const uint8_t level3[8] PROGMEM = {
	0B00000, 0B00000, 0B00000, 0B00000, 0B00000, 0B11111, 0B11111, 0B11111
};

//Level 4
const uint8_t level4[8] PROGMEM = {
	0B00000, 0B00000, 0B00000, 0B00000, 0B11111, 0B11111, 0B11111, 0B11111
};

//Level 5
const uint8_t level5[8] PROGMEM = {
	0B00000, 0B00000, 0B00000, 0B11111, 0B11111, 0B11111, 0B11111, 0B11111
};
//Level 6
const uint8_t level6[8] PROGMEM = {
	0B00000, 0B00000, 0B11111, 0B11111, 0B11111, 0B11111, 0B11111, 0B11111
};

//Level 7
const uint8_t level7[8] PROGMEM = {
	0B00000, 0B11111, 0B11111, 0B11111, 0B11111, 0B11111, 0B11111, 0B11111
};

//Letters in binary for LCD
const char letterA = 0b01000001;
const char letterB = 0b01000010;
const char letterC = 0b01000011;
const char letterD = 0b01000100;
const char letterE = 0b01000101;
const char letterF = 0b01000110;
const char letterG = 0b01000111;
const char sharpkey = 0b00100011;
const char flatkey = 0b01100010;
const char blank   = 0b00100000;



// The following function can be found in the lcd_lib.c
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
	DDRA = 0x00; PORTA = 0xFF;		//Reading in for ADC port
	DDRB = 0xFF; PORTB = 0x00;		//Data Control Line
	DDRC = 0xFF; PORTC = 0x00;		//Data Input Line
	DDRD = 0xFF; PORTD = 0x00;		//Seven Segment Driver
	
	//Initing stuff
	LCD_init();
	ADC_init();
	
	//Setting up the timer
	TimerSet(500);
	TimerOn();
	
	const unsigned char* note = "note:";
	LCD_DisplayString(1,note);
	
	//LCD_Cursor(7);
	//LCD_WriteData(letterG);
	
	//Levels
	LCDdefinechar(level1, 1);
	//char level1key = 0b00001001;
	LCDdefinechar(level2, 2);
	//char level2key = 0b00001010;
	LCDdefinechar(level3, 3);
	//char level3key = 0b00001011;
	LCDdefinechar(level4, 4);
	//char level4key = 0b00001100;
	LCDdefinechar(level5, 5);
	//char level5key = 0b00001101;
	LCDdefinechar(level6, 6);
	//char level6key = 0b00001110;
	LCDdefinechar(level7, 7);
	//char level7key = 0b00001111;
	
   /*
   
   LCD_Cursor(17);
   LCD_WriteData(level1key);
   
   LCD_Cursor(18);
   LCD_WriteData(level2key);
   
   LCD_Cursor(19);
   LCD_WriteData(level3key);
   
   LCD_Cursor(20);
   LCD_WriteData(level4key);
   
   LCD_Cursor(21);
   LCD_WriteData(level5key);
   
   LCD_Cursor(22);
   LCD_WriteData(level6key);
   
   LCD_Cursor(23);
   LCD_WriteData(level7key);
   
   */
   
   int value = 128;
   int inverse = 0;
   char x[value];
   
   unsigned char maximum = 0;
   unsigned char frequency = 0;
   
   //Tone values
   unsigned char C4 = 15;
   unsigned char Csharp = 28;
   unsigned char D4 = 34;
   unsigned char Eflat = 46;
   unsigned char E4 = 57;
   unsigned char F4 = 68;
   unsigned char Fsharp = 79;
   unsigned char G4 = 82;
   unsigned char Gsharp = 94;
   unsigned char A4 = 105;
   unsigned char Bflat = 117;
   unsigned char B4 = 128;
   
   //int v = 0;
   
   char set = '0';
   
   while(1)
   {
      for (int i = 0; i < value; ++i)
      {
         x[i] = ADC;
      }
	  
	  fix_fftr(x, value, inverse);
	  
	  for (int j = 0; j < value; ++j)
	  {
		  if (x[j] > maximum)
		  {
			  maximum  = x[j];
			  frequency = j;
		  }
	  }
	  
	  if (frequency > C4 && frequency <= Csharp){
		  Write7Seg(SS_C);
		  LCD_Cursor(7);
		  LCD_WriteData(letterC);
		  LCD_Cursor(8);
		  LCD_WriteData(blank);
		  set = 'C';
	  }
	  else if (frequency > Csharp && frequency <= D4)
	  {
		  Write7Seg(SS_C);
		  LCD_Cursor(7);
		  LCD_WriteData(letterC);
		  LCD_Cursor(8);
		  LCD_WriteData(sharpkey);
		  set = 'Q';
		  
	  }
	  else if (frequency > D4 && frequency <= Eflat){
		  Write7Seg(SS_D);
		  LCD_Cursor(7);
		  LCD_WriteData(letterD);
		  LCD_Cursor(8);
		  LCD_WriteData(blank);
		  set = 'D';
	  }
	  
	  else if (frequency > Eflat && frequency <= E4)
	  {
		  Write7Seg(SS_E);
		  LCD_Cursor(7);
		  LCD_WriteData(letterE);
		  LCD_Cursor(8);
		  LCD_WriteData(flatkey);
		  set = 'W';
		  
	  }
	  
	  else if (frequency > E4 && frequency <= F4){
		  Write7Seg(SS_E);
		  LCD_Cursor(7);
		  LCD_WriteData(letterE);
		  LCD_Cursor(8);
		  LCD_WriteData(blank);
		  set = 'E';
	  }
	  
	  else if (frequency > F4 && frequency <= Fsharp){
		  Write7Seg(SS_F);
		  LCD_Cursor(7);
		  LCD_WriteData(letterF);
		  LCD_Cursor(8);
		  LCD_WriteData(blank);
		  set = 'F';
	  }
	  
	  else if (frequency > Fsharp && frequency <= G4)
	  {
		  Write7Seg(SS_F);
		  LCD_Cursor(7);
		  LCD_WriteData(letterF);
		  LCD_Cursor(8);
		  LCD_WriteData(sharpkey);
		  set = 'S';
		  
	  }
	  
	  else if (frequency > G4 && frequency <= Gsharp)
	  {
		  Write7Seg(SS_G);
		  LCD_Cursor(7);
		  LCD_WriteData(letterG);
		  LCD_Cursor(8);
		  LCD_WriteData(blank);
		  set = 'G';
	  }
	  
	  else if (frequency > Gsharp && frequency <= A4)
	  {
		  Write7Seg(SS_G);
		  LCD_Cursor(7);
		  LCD_WriteData(letterG);
		  LCD_Cursor(8);
		  LCD_WriteData(sharpkey);
		  set = 'U';
		  
	  }
	  
	  else if (frequency > A4 && frequency <= Bflat)
	  {
		  Write7Seg(SS_A);
		  LCD_Cursor(7);
		  LCD_WriteData(letterA);
		  LCD_Cursor(8);
		  LCD_WriteData(blank);
		  set = 'A';
	  }
	  
	  else if (frequency > Bflat && frequency <= B4)
	  {
		  Write7Seg(SS_B);
		  LCD_Cursor(7);
		  LCD_WriteData(letterB);
		  LCD_Cursor(8);
		  LCD_WriteData(flatkey);
		  set = 'B';
		  
	  }
	  
	  else if (frequency > B4)
	  {
		  Write7Seg(SS_B);
		  LCD_Cursor(7);
		  LCD_WriteData(letterB);
		  LCD_Cursor(8);
		  LCD_WriteData(blank);
		  set = 'Y';
	  }
	  
	  else
	  {
		  Write7Seg(SS_DP);
		  LCD_Cursor(7);
		  LCD_WriteData(blank);
		  LCD_Cursor(8);
		  LCD_WriteData(blank);
		  set = '0';
	  }
	  
	  toneBars(set);
	  
	  maximum = 0;
	  
	  while(!TimerFlag);
	  TimerFlag = 0;
	  
   }
   
   return 0;
}