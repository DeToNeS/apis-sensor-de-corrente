#include "EmonLib.h"
#include <swDuino.h>

swDuino objswDuino;

EnergyMonitor sensor;

int Rede = 220; //Tensao da Rede eletrica

int PSCT = A1; //Pino do sensor SCT

void setup(void) 
{
  // put your setup code here, to run once:
  objswDuino.begin(9600);

  //Pino, calibracao - Cur Const= Ratio/BurdenR. 2000/33 = 60
  sensor.current(PSCT, 60);
}

void loop(void)
{
  //Calcula a corrente
  double Irms = sensor.calcIrms(1480);
  objswDuino.write("P", String(Irms));
  delay(500);
}
