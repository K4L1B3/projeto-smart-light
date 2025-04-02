Segue abaixo um exemplo de **README** em português para o projeto utilizando Arduino UNO, sensor PIR e LED. Você pode adaptar conforme suas necessidades.

---

# Projeto: Detecção de Movimento com Sensor PIR e Acionamento de LED

Este projeto utiliza um **sensor PIR** para detectar movimento e acender um **LED** por um período de tempo determinado quando o sensor é acionado. Ele também faz uso da comunicação serial para depurar o estado do sensor.

## Sumário

- [Visão Geral](#visão-geral)
- [Componentes Necessários](#componentes-necessários)
- [Esquema de Ligação (Fiação)](#esquema-de-ligação-fiação)
- [Código](#código)
- [Como Usar](#como-usar)
- [Licença](#licença)

---

## Visão Geral

![image](https://github.com/user-attachments/assets/134970f0-25cc-4838-ae2a-ea17c72c8aab)

O objetivo do projeto é **detectar movimento** usando um sensor PIR (Passive InfraRed) e, ao detectar, **ligar um LED** por um intervalo de tempo (por exemplo, 10 segundos). Caso não haja movimento, o LED permanece desligado.

### Como Funciona

1. O sensor PIR detecta variações de calor (infravermelho) na área de alcance.  
2. Quando o sensor detecta movimento, sua saída vai para **HIGH** (nível lógico 1).  
3. O Arduino lê esse sinal e aciona o LED, mantendo-o aceso por um tempo definido (`time2 = 10000 ms`, ou seja, 10 segundos).  
4. Se não há movimento, o LED permanece apagado.

---

## Componentes Necessários

1. **Arduino UNO** (ou compatível)  
2. **Sensor PIR** (módulo com 3 pinos: VCC, OUT, GND)  
3. **LED** (qualquer cor)  
4. **Resistor** de 220 Ω (aproximadamente) para o LED  
5. **Jumpers** (fios de conexão)  
6. **Protoboard**  

---

## Esquema de Ligação (Fiação)

1. **Sensor PIR**  
   - **VCC** → 5V do Arduino  
   - **GND** → GND do Arduino  
   - **OUT** → Pino digital 7 do Arduino  

2. **LED**  
   - Anodo (perna maior) → Pino digital 12 do Arduino (através de um resistor de 220 Ω)  
   - Catodo (perna menor) → GND do Arduino  

> **Observação:** A pinagem pode variar dependendo do modelo do seu sensor PIR. Verifique o datasheet do seu sensor para ter certeza de que está conectando os pinos corretamente.

---

## Código

```cpp
int led = 12;
int sensor = 7;
int sinal = 0;
int time = 500;      // Tempo de espera quando não há movimento (0,5s)
int time2 = 10000;   // Tempo que o LED fica aceso (10s)

void setup() {
  pinMode(led, OUTPUT);     // Configura pino do LED como saída
  pinMode(sensor, INPUT);   // Configura pino do sensor como entrada
  Serial.begin(9600);       // Inicializa a comunicação serial
}

void loop() {   
  sinal = digitalRead(sensor);  // Lê o estado do sensor (0 ou 1)
  Serial.println(sinal);        // Imprime no Serial Monitor para debug
  
  if (sinal > 0) {
    digitalWrite(led, HIGH);    // Acende o LED
    delay(time2);               // Fica aceso por 10 segundos
  } else {
    digitalWrite(led, LOW);     // Apaga o LED
    delay(time);                // Fica apagado por 0,5 segundo
  }
}
```

---

## Como Usar

1. **Monte o circuito** de acordo com o esquema descrito acima.  
2. **Conecte o Arduino** ao computador via cabo USB.  
3. **Abra a IDE do Arduino** (ou outra IDE compatível, como Arduino Web Editor ou PlatformIO).  
4. **Cole o código** acima em um novo arquivo (sketch) ou abra o arquivo já existente.  
5. Selecione a **placa Arduino UNO** e a **porta COM** correspondente na IDE.  
6. Clique em **Upload** para carregar o código na placa.  
7. Abra o **Serial Monitor** (no canto superior direito da IDE) para ver as leituras do sensor.  
8. **Teste o sensor** movendo a mão em frente ao PIR. Você deve ver o LED acender por 10 segundos e, no Serial Monitor, o valor `1` enquanto o sensor detecta movimento.

## Licença

Este projeto está disponível sob a licença de sua preferência (MIT, GPL, etc.). Sinta-se à vontade para usar, modificar e distribuir o código conforme necessário.

--- 

**Esperamos que este README seja útil para o seu projeto!**
