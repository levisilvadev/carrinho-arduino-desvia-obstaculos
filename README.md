# Carrinho autônomo desviador de obstáculos

Carrinho com Arduino que anda sozinho e desvia de obstáculos usando um sensor ultrassônico. Projeto desenvolvido em grupo na disciplina **Experimentação Orientada**, do curso de Análise e Desenvolvimento de Sistemas da **Universidade de Fortaleza (Unifor)**, em 2026.1.

<table>
  <tr>
    <td><video src="https://github.com/user-attachments/assets/748662c5-646f-4dc7-a620-afba436d7b2c" width="300" controls></video></td>
    <td><img width="300" alt="Foto do carrinho" src="https://github.com/user-attachments/assets/d091a785-e417-476d-91d0-6b975823279d" /></td>
  </tr>
</table>


## Como funciona

1. O sensor ultrassônico mede continuamente a distância até o que está à frente do carrinho.
2. Se não há nada a menos de **20 cm**, o carrinho segue em frente.
3. Se detecta um obstáculo a menos de 20 cm, o carrinho **para**, **dá ré** e **gira para a direita**.
4. Depois de desviar, volta a andar para frente e o ciclo recomeça.

## Componentes

| Componente | Função |
|---|---|
| Arduino Uno (compatível) | Placa que executa o código e controla tudo |
| Ponte H L298N | Permite girar os motores nos dois sentidos (frente e ré) |
| Sensor ultrassônico HC-SR04 | Mede a distância emitindo um som inaudível e cronometrando o eco |
| 2 motores DC com caixa de redução (motor TT) | Movimentam as rodas do carrinho |
| Chassi de acrílico 2WD com roda boba | Estrutura com duas rodas motorizadas e uma roda livre na frente |
| Suporte para 4 pilhas AA | Alimenta os motores pela ponte H |
| Power bank | Alimenta o Arduino pelo cabo USB |
| Jumpers | Fazem as ligações entre os componentes |

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

## Observações

O kit previa uma bateria de 9V para alimentar o Arduino, mas ela apresentou problemas durante os testes. Substituímos por um power bank ligado pelo cabo USB, enquanto os motores continuaram alimentados pelas pilhas AA.
