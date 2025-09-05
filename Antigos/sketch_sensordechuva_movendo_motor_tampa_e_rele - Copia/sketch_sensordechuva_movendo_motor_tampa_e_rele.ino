// C++ code
//
const int IN1 = 1; 
const int IN2 = 2; 
const int IN3 = 3; 
const int IN4 = 4; 
const int IN5 = 5; 
const int IN6 = 6; 
const int IN7 = 7; 
const int IN8 = 8; 
const int RELE = 9;
const int SENSOR_CHUVA = 10;
const int SENSOR_NIVEL_SUPERIOR = 11;
const int grau = 0;


const int PASSOS_POR_VOLTA = 512;
const float GRAUS_DESEJADOS = 110; // Altere para o grau desejado (0 a 360)

// Sequência de passos
const int passos[4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};

float posicaoAtual = grau; // Armazena o ângulo atual do motor



void setup()
{
  pinMode(SENSOR_CHUVA,INPUT);
  pinMode(SENSOR_NIVEL_SUPERIOR,INPUT);
  pinMode(RELE, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  // moverAmbosOsMotores(GRAUS_DESEJADOS);
  // desligarMotor();
}

void loop()
{
  controle_motores();
}


void controle_motores(){

      if(digitalRead(SENSOR_NIVEL_SUPERIOR)==HIGH){
    digitalWrite(RELE, HIGH);
  }
      if (digitalRead(SENSOR_CHUVA) == HIGH && digitalRead(SENSOR_NIVEL_SUPERIOR)== LOW)
        {
            moverAmbosOsMotores(90);
        }

  else
        {
            moverAmbosOsMotores(0);
        }
}

void moverAmbosOsMotores(float novoAngulo) {
  float diferenca = novoAngulo - posicaoAtual;
  int passosParaMover = (int)((abs(diferenca) / 360.0) * PASSOS_POR_VOLTA);

  if (diferenca > 0) {
    for (int i = 0; i < passosParaMover; i++) {
      for (int j = 0; j < 4; j++) {
        // Motor 1 - horário
        digitalWrite(IN1, passos[j][0]);
        digitalWrite(IN5, passos[3 - j][0]);
        digitalWrite(IN2, passos[j][1]);
        digitalWrite(IN6, passos[3 - j][1]);
        digitalWrite(IN3, passos[j][2]);
        digitalWrite(IN7, passos[3 - j][2]);
        digitalWrite(IN4, passos[j][3]);
        digitalWrite(IN8, passos[3 - j][3]);

        // Motor 2 - anti-horário
        
        
        
        

        delay(2);
      }
    }
  } else if (diferenca < 0) {
    for (int i = 0; i < passosParaMover; i++) {
      for (int j = 3; j >= 0; j--) {
        // Motor 1 - anti-horário
        digitalWrite(IN1, passos[j][0]);
        digitalWrite(IN5, passos[3 - j][0]);
        digitalWrite(IN2, passos[j][1]);
        digitalWrite(IN6, passos[3 - j][1]);
        digitalWrite(IN3, passos[j][2]);
        digitalWrite(IN7, passos[3 - j][2]);
        digitalWrite(IN4, passos[j][3]);
        digitalWrite(IN8, passos[3 - j][3]);

        delay(2);
      }
    }
  }

  posicaoAtual = novoAngulo;
}






