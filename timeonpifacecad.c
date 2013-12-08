#include <stdio.h>
#include <time.h>
#include "pifacecad.h"

/*
    Time display on PiFace PifaceCAD (Control and Display)
    By Gregory Fenton
    http://labby.co.uk
    
    Language: C
    To generate the required libraries, follow the instructions at
    http://piface.github.io/libpifacecad/
    
    Compilation:
        gcc -o timeonpifacecad timeonpifacecad.c -Isrc/ -L. -lpifacecad -L../libmcp23s17/ -lmcp23s17
    Usage:
        ./timeonpiface
*/

int main (void)
{
   time_t rawtime;
   struct tm * timeinfo;
   char buffer[128];

   pifacecad_open();
   pifacecad_lcd_clear();
   pifacecad_lcd_backlight_on();
   while(1)
   {
      time ( &rawtime );
      timeinfo = localtime ( &rawtime );
      pifacecad_lcd_home();
      pifacecad_lcd_write(buffer);
      strftime(buffer, sizeof(buffer), "%X", timeinfo);
      sleep(1);
   }
   pifacecad_close();
   
   return 0;
}
