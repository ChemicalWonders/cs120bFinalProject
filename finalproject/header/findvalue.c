void findValue(unsigned char frequency, char* set)
{
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
}