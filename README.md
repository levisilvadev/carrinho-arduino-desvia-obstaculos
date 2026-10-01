# Carrinho autônomo desviador de obstáculos

Carrinho com Arduino que anda sozinho e desvia de obstáculos usando um sensor ultrassônico. Projeto desenvolvido em grupo na disciplina **Experimentação Orientada**, do curso de Análise e Desenvolvimento de Sistemas da **Universidade de Fortaleza (Unifor)**, em 2026.1.

https://github.com/user-attachments/assets/748662c5-646f-4dc7-a620-afba436d7b2c

## Como funciona

1. O sensor ultrassônico mede continuamente a distância até o que está à frente do carrinho.
2. Se não há nada a menos de **20 cm**, o carrinho segue em frente.
3. Se detecta um obstáculo a menos de 20 cm, o carrinho **para**, **dá ré** e **gira para a direita**.
4. Depois de desviar, volta a andar para frente e o ciclo recomeça.

## Componentes

| Componente | Função |
|---|---|
| Arduino Uno | Placa que executa o código e controla tudo |
| Sensor Shield v5.0 | Placa encaixada no Arduino que facilita a ligação dos fios |
| Sensor ultrassônico HC-SR04 | Mede a distância emitindo um som inaudível e cronometrando o eco |
| Ponte H | Permite girar os motores nos dois sentidos (frente e ré) |
| 2 motores DC com redução | Movimentam as rodas do carrinho |

## Ligações

| Componente | Pinos do Arduino |
|---|---|
| Motor esquerdo (via ponte H) | 9 e 10 |
| Motor direito (via ponte H) | 12 e 13 |
| HC-SR04 – Trig | A0 |
| HC-SR04 – Echo | A1 |

## Como rodar

1. Instale a [Arduino IDE](https://www.arduino.cc/en/software).
2. Abra o arquivo `.ino` deste repositório.
3. Conecte o Arduino ao computador pelo cabo USB.
4. Em **Ferramentas**, selecione a placa **Arduino Uno** e a porta correta.
5. Clique em **Carregar** para enviar o código para a placa.
6. Para acompanhar as leituras do sensor, abra o **Monitor Serial**.

## Tecnologias

- Arduino (C/C++)
- Arduino IDE

## Equipe

| Integrante | Responsabilidade |
|---|---|
| Levi Rocha Silva | Programação |
| Ana Carolina Aleixo Correa | Programação |
| Kayla Gabrielle Medeiros Alves | Montagem |
| Clarisse Holanda de Castro | Montagem |
