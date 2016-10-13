// Programa: Teste Display OLED SSD1306
// Autor: FILIPEFLOP

#include "U8glib.h"
#include "EmonLib.h"
#include <SPI.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK); // Display which does not send AC

EnergyMonitor sensor;

int Rede = 220; //Tensao da Rede eletrica

int PSCT = A1; //Pino do sensor SCT

void draw(String Rotulo, String Sigla, double Leitura)
{
  char *pRotulo, *pSigla;
  pRotulo = &Rotulo[0];
  pSigla = &Sigla[0];
  char pLeitura[sizeof(Leitura)];
  memcpy(&pLeitura,&Leitura,sizeof(Leitura));
  
  u8g.setFont(u8g_font_8x13B);;
  u8g.drawStr( 5, 15, pRotulo);
  //Hora
  u8g.setFont(u8g_font_fub30);
  u8g.drawStr( 10, 57, pLeitura);
  //Texto - AM
  u8g.setFont(u8g_font_5x7);
  u8g.drawStr( 115, 33, pSigla);
  //moldura relogio
  u8g.drawRFrame(0,18, 128, 46, 4);
  //Desenho bateria
  u8g.drawRFrame(105, 3, 20,12 , 0);
  u8g.drawBox(125, 6, 2,6);
  u8g.drawBox(107, 5, 4,8);
  u8g.drawBox(114, 5, 4,8);
  //Desenho linhas sinal
  u8g.drawVLine(99,0, 15);
  u8g.drawVLine(98,0, 15);
  u8g.drawVLine(96,4, 11);
  u8g.drawVLine(95,4, 11);
  u8g.drawVLine(93,8, 7);
  u8g.drawVLine(92,8, 7);
  u8g.drawVLine(90,12, 3);
  u8g.drawVLine(89,12, 3);
}

void setup(void) 
{
  Serial.begin(9600);

  if ( u8g.getMode() == U8G_MODE_R3G3B2 )
  {
    u8g.setColorIndex(255); // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )
  {
    u8g.setColorIndex(3); // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW )
  {
    u8g.setColorIndex(1); // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }

  //Pino, calibracao - Cur Const= Ratio/BurdenR. 2000/33 = 60
  sensor.current(PSCT, 60);
}

void loop(void)
{
  //Calcula a corrente
  double Irms = sensor.calcIrms(1480);

  u8g.firstPage();

  do
  {
    draw("CORRENTE", "A", Irms);
  } while( u8g.nextPage());

  delay(1000);
}
