void toneBars(char key)
{
	if (key == '0')
	{
		for(int i = 17; i < 32; ++i)
		{
			LCD_Cursor(i);
			LCD_WriteData(0b00001001);
		}
	}
	
	else if (key == 'C')
	{
		LCD_Cursor(17);
		LCD_WriteData(0b00001111);

      LCD_Cursor(18);
      LCD_WriteData(0b00001110);

      LCD_Cursor(19);
      LCD_WriteData(0b00001101);

      LCD_Cursor(20);
      LCD_WriteData(0b00001100);

      LCD_Cursor(21);
      LCD_WriteData(0b00001011);

      LCD_Cursor(22);
      LCD_WriteData(0b00001010);

      for(int i = 23; i < 32; ++i)
      {
         LCD_Cursor(i);
         LCD_WriteData(0b00001001);
      }
	}

   else if (key == 'Q')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001110);

      LCD_Cursor(18);
      LCD_WriteData(0b00001111);

      LCD_Cursor(19);
      LCD_WriteData(0b00001110);

      LCD_Cursor(20);
      LCD_WriteData(0b00001101);

      LCD_Cursor(21);
      LCD_WriteData(0b00001100);

      LCD_Cursor(22);
      LCD_WriteData(0b00001011);

      LCD_Cursor(23);
      LCD_WriteData(0b00001001);

      for(int i = 24; i < 32; ++i)
      {
         LCD_Cursor(i);
         LCD_WriteData(0b00001001);
      }
   }
   
   else if (key == 'D')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001101);

      LCD_Cursor(18);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(19);
      LCD_WriteData(0b00001111);
      
      LCD_Cursor(20);
      LCD_WriteData(0b00001110);

      LCD_Cursor(21);
      LCD_WriteData(0b00001101);

      LCD_Cursor(22);
      LCD_WriteData(0b00001100);

      LCD_Cursor(23);
      LCD_WriteData(0b00001011);

      LCD_Cursor(24);
      LCD_WriteData(0b00001001);

      for(int i = 25; i < 32; ++i)
      {
         LCD_Cursor(i);
         LCD_WriteData(0b00001001);
      }
   }

   else if (key == 'W')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001100);

      LCD_Cursor(18);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(19);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(20);
      LCD_WriteData(0b00001111);

      LCD_Cursor(21);
      LCD_WriteData(0b00001110);

      LCD_Cursor(22);
      LCD_WriteData(0b00001101);

      LCD_Cursor(23);
      LCD_WriteData(0b00001100);
      
      LCD_Cursor(24);
      LCD_WriteData(0b00001011);

      LCD_Cursor(25);
      LCD_WriteData(0b00001010);

      for(int i = 26; i < 32; ++i)
      {
         LCD_Cursor(i);
         LCD_WriteData(0b00001001);
      }
   }
   
   else if (key == 'E')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001011);

      LCD_Cursor(18);
      LCD_WriteData(0b00001100);
      
      LCD_Cursor(19);
      LCD_WriteData(0b00001101); 
      
      LCD_Cursor(20);
      LCD_WriteData(0b00001110);

      LCD_Cursor(21);
      LCD_WriteData(0b00001111);
      
      LCD_Cursor(22);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(23);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(24);
      LCD_WriteData(0b00001100);     

      LCD_Cursor(25);
      LCD_WriteData(0b00001011);

      LCD_Cursor(26);
      LCD_WriteData(0b00001010);

      for(int i = 27; i < 32; ++i)
      {
         LCD_Cursor(i);
         LCD_WriteData(0b00001001);
      }
   }

   else if (key == 'F')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001010);

      LCD_Cursor(18);
      LCD_WriteData(0b00001011);
      
      LCD_Cursor(19);
      LCD_WriteData(0b00001100);
      
      LCD_Cursor(20);
      LCD_WriteData(0b00001101); 
      
      LCD_Cursor(21);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(22);
      LCD_WriteData(0b00001111);
      
      LCD_Cursor(23);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(24);
      LCD_WriteData(0b00001101);
         
      LCD_Cursor(25);
      LCD_WriteData(0b00001100);  
      
      LCD_Cursor(26);
      LCD_WriteData(0b00001011);

      LCD_Cursor(27);
      LCD_WriteData(0b00001010);

      for(int i = 28; i < 32; ++i)
      {
         LCD_Cursor(i);
         LCD_WriteData(0b00001001);
      }
   }
   
   else if (key == 'S')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001001);

      LCD_Cursor(18);
      LCD_WriteData(0b00001010);
      
      LCD_Cursor(19);
      LCD_WriteData(0b00001011);
      
      LCD_Cursor(20);
      LCD_WriteData(0b00001100);
      
      LCD_Cursor(21);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(22);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(23);
      LCD_WriteData(0b00001111);
      
      LCD_Cursor(24);
      LCD_WriteData(0b00001110);
         
      LCD_Cursor(25);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(26);
      LCD_WriteData(0b00001100); 

      LCD_Cursor(27);
      LCD_WriteData(0b00001011);

      LCD_Cursor(28);
      LCD_WriteData(0b00001010);

      for(int i = 29; i < 32; ++i)
      {
         LCD_Cursor(i);
         LCD_WriteData(0b00001001);
      }
   }

   else if (key == 'G')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001001);

      LCD_Cursor(18);
      LCD_WriteData(0b00001001);

      LCD_Cursor(19);
      LCD_WriteData(0b00001010);
      
      LCD_Cursor(20);
      LCD_WriteData(0b00001011);
      
      LCD_Cursor(21);
      LCD_WriteData(0b00001100);
      
      LCD_Cursor(22);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(23);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(24);
      LCD_WriteData(0b00001111);
      
      LCD_Cursor(25);
      LCD_WriteData(0b00001110);
         
      LCD_Cursor(26);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(27);
      LCD_WriteData(0b00001100); 

      LCD_Cursor(28);
      LCD_WriteData(0b00001011);

      LCD_Cursor(29);
      LCD_WriteData(0b00001010);

      for(int i = 30; i < 32; ++i)
      {
         LCD_Cursor(i);
         LCD_WriteData(0b00001001);
      }
   }
   
   else if (key == 'U')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001001);

      LCD_Cursor(18);
      LCD_WriteData(0b00001001);

      LCD_Cursor(19);
      LCD_WriteData(0b00001001);

      LCD_Cursor(20);
      LCD_WriteData(0b00001010);
      
      LCD_Cursor(21);
      LCD_WriteData(0b00001011);
      
      LCD_Cursor(22);
      LCD_WriteData(0b00001100);
      
      LCD_Cursor(23);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(24);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(25);
      LCD_WriteData(0b00001111);
      
      LCD_Cursor(26);
      LCD_WriteData(0b00001110);
         
      LCD_Cursor(27);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(28);
      LCD_WriteData(0b00001100); 

      LCD_Cursor(29);
      LCD_WriteData(0b00001011);

      LCD_Cursor(30);
      LCD_WriteData(0b00001010);

      for(int i = 31; i < 32; ++i)
      {
         LCD_Cursor(i);
         LCD_WriteData(0b00001001);
      }
   }

   else if (key == 'A')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001001);

      LCD_Cursor(18);
      LCD_WriteData(0b00001001);

      LCD_Cursor(19);
      LCD_WriteData(0b00001001);

      LCD_Cursor(20);
      LCD_WriteData(0b00001001);

      LCD_Cursor(21);
      LCD_WriteData(0b00001010);
      
      LCD_Cursor(22);
      LCD_WriteData(0b00001011);
      
      LCD_Cursor(23);
      LCD_WriteData(0b00001100);
      
      LCD_Cursor(24);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(25);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(26);
      LCD_WriteData(0b00001111);
      
      LCD_Cursor(27);
      LCD_WriteData(0b00001110);
         
      LCD_Cursor(28);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(29);
      LCD_WriteData(0b00001100); 

      LCD_Cursor(30);
      LCD_WriteData(0b00001011);

      LCD_Cursor(31);
      LCD_WriteData(0b00001010);

      LCD_Cursor(32);
      LCD_WriteData(0b00001001);

   }
   
   else if (key == 'B')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001001);

      LCD_Cursor(18);
      LCD_WriteData(0b00001001);

      LCD_Cursor(19);
      LCD_WriteData(0b00001001);

      LCD_Cursor(20);
      LCD_WriteData(0b00001001);

      LCD_Cursor(21);
      LCD_WriteData(0b00001001);

      LCD_Cursor(22);
      LCD_WriteData(0b00001010);
      
      LCD_Cursor(23);
      LCD_WriteData(0b00001011);
      
      LCD_Cursor(24);
      LCD_WriteData(0b00001100);
      
      LCD_Cursor(25);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(26);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(27);
      LCD_WriteData(0b00001111);
      
      LCD_Cursor(28);
      LCD_WriteData(0b00001110);
         
      LCD_Cursor(29);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(30);
      LCD_WriteData(0b00001100); 

      LCD_Cursor(31);
      LCD_WriteData(0b00001011);

      LCD_Cursor(32);
      LCD_WriteData(0b00001010);
   }

   else if (key == 'Y')
   {
      LCD_Cursor(17);
      LCD_WriteData(0b00001001);

      LCD_Cursor(18);
      LCD_WriteData(0b00001001);

      LCD_Cursor(19);
      LCD_WriteData(0b00001001);

      LCD_Cursor(20);
      LCD_WriteData(0b00001001);

      LCD_Cursor(21);
      LCD_WriteData(0b00001001);

      LCD_Cursor(22);
      LCD_WriteData(0b00001001);

      LCD_Cursor(23);
      LCD_WriteData(0b00001010);
      
      LCD_Cursor(24);
      LCD_WriteData(0b00001011);
      
      LCD_Cursor(25);
      LCD_WriteData(0b00001100);
      
      LCD_Cursor(26);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(27);
      LCD_WriteData(0b00001110);
      
      LCD_Cursor(28);
      LCD_WriteData(0b00001111);
      
      LCD_Cursor(29);
      LCD_WriteData(0b00001110);
         
      LCD_Cursor(30);
      LCD_WriteData(0b00001101);
      
      LCD_Cursor(31);
      LCD_WriteData(0b00001100); 

      LCD_Cursor(32);
      LCD_WriteData(0b00001011);
   }
   
	return;
}