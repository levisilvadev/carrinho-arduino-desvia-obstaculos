// Projeto: Carrinho autônomo com Arduino
// Disciplina: Experimentação Orientada
// Equipe: Ana Carolina Aleixo Correa, Clarisse Holanda de Castro, Kayla Gabrielle Medeiros, Levi Rocha Silva

// Definição dos pinos dos Motores
const int motorEsquerdoA = 9;
const int motorEsquerdoB = 10;
const int motorDireitoA = 13;
const int motorDireitoB = 12;

// Definição dos pinos do Sensor Ultrassônico
const int pinTrig = A0;
const int pinEcho = A1;

// Variáveis do sensor
unsigned long duracao;
float distancia;

// Distância mínima para considerar um obstáculo
const int distanciaLimite = 20;

// Tempos das manobras
const int tempoParadoAntesRe = 500;
const int tempoRe = 400;
const int tempoParadoAntesGiro = 300;
const int tempoGiro = 400;

// Intervalo entre leituras do sensor
const int intervaloLeitura = 100;

void setup() {
  // Configura os pinos dos motores como saídas
  pinMode(motorEsquerdoA, OUTPUT);
  pinMode(motorEsquerdoB, OUTPUT);
  pinMode(motorDireitoA, OUTPUT);
  pinMode(motorDireitoB, OUTPUT);

  // Configura os pinos do sensor
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);

  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {

  // 1. Leitura do sensor

  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  // Aguarda o retorno do sinal por no máximo 25 ms
  duracao = pulseIn(pinEcho, HIGH, 25000);

  distancia = (duracao * 0.0343) / 2;

  // Exibe a distância no Monitor Serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // 2. Tomada de decisão do robô

  if (distancia <= distanciaLimite && distancia > 0) {
    // Se encontrou obstáculo
    ficarParado();
    delay(500);

    andarParaTras();
    delay(tempoRe);

    ficarParado();
    delay(300);

    girarParaDireita();
    delay(tempoGiro);

  } else {
    // Se o caminho estiver livre
    andarParaFrente();
  }

  delay(100);
}

// --- FUNÇÕES DE MOVIMENTO ---

void andarParaFrente() {
  digitalWrite(motorEsquerdoA, HIGH);
  digitalWrite(motorEsquerdoB, LOW);
  digitalWrite(motorDireitoA, HIGH);
  digitalWrite(motorDireitoB, LOW);
}

void andarParaTras() {
  digitalWrite(motorEsquerdoA, LOW);
  digitalWrite(motorEsquerdoB, HIGH);
  digitalWrite(motorDireitoA, LOW);
  digitalWrite(motorDireitoB, HIGH);
}

void girarParaDireita() {
  // Para girar para a direita:
  // motor esquerdo vai para frente e direito vai para trás
  digitalWrite(motorEsquerdoA, HIGH);
  digitalWrite(motorEsquerdoB, LOW);
  digitalWrite(motorDireitoA, LOW);
  digitalWrite(motorDireitoB, HIGH);
}

void ficarParado() {
  digitalWrite(motorEsquerdoA, LOW);
  digitalWrite(motorEsquerdoB, LOW);
  digitalWrite(motorDireitoA, LOW);
  digitalWrite(motorDireitoB, LOW);
}
