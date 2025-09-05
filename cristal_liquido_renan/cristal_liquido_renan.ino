
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

LiquidCrystal_I2C display(0x27, 16, 2);
Ultrasonic sonic(2,4);

void setup(){
  
  display.init(); // inicializa o display
  display.backlight(); // acende a luz de fundo
  display.print("Inicializando..."); // mostra inicializando na tela
  delay(2000); // aguarda 2 segundos
  display.clear(); // apaga escrito no  display
  
   
} 


void loop() {
  // put your main code here, to run repeatedly:
  float tempo = sonic.timing();
  float cm = sonic.convert(tempo,Ultrasonic::CM);
  display.print("Distancia: ");
  display.print(cm);
  delay(3000);
  display.clear();
  delay(3000);



}
