#include <Stepper.h>

const int passos = 2048;
Stepper motor(passos, 8, 10 , 9, 11);

int andar_desejado;
int andar_atual;

void setup() {
  motor.setSpeed(10);
  Serial.begin(9600);
  andar_atual = 1 ;// inicializa corretamente a variável global
}

void loop() {
  if (Serial.available()){
  String comando = Serial.readStringUntil('\n');
  andar_desejado = comando.toInt();

  int diferenca = andar_desejado - andar_atual;
  motor.step(diferenca*512); // 512 passos = 1/4 devolta no 28BYJ-48
  andar_atual = andar_desejado; // atualiza o andar
  }

}
