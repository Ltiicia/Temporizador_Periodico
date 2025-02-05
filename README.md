# Atividade 1 - Temporizador Periódico

**Desenvolvido por:** Letícia Gonçalves Souza  

Este projeto foi desenvolvido como parte do programa **EmbarcaTech**, com o objetivo de aplicar conceitos de **temporizadores periódicos**, **controle de LEDs** e **manipulação de GPIOs**. A atividade visa consolidar o entendimento prático desses conceitos através da implementação de um semáforo com temporização controlada por software.

---

## Sobre o Projeto

O projeto consiste na implementação de um **semáforo** utilizando o **Raspberry Pi Pico W**. O controle do ciclo de luzes é feito com a função `add_repeating_timer_ms()` da biblioteca **Pico SDK**, que permite alternar entre os LEDs vermelho, amarelo e verde com um intervalo de 3 segundos para cada cor. Além disso, o programa imprime mensagens pela porta serial a cada segundo.

---

## Funcionalidades

1. **Ciclo de Luzes do Semáforo:**  
   - O semáforo inicia com a luz **vermelha** acesa.  
   - A cada **3 segundos**, alterna para **amarelo** e depois para **verde**, repetindo o ciclo continuamente.

2. **Mensagens Seriais:**  
   - O programa envia mensagens pela **porta serial** a cada **1 segundo**, indicando o status da rotina principal.

3. **Controle de LEDs com PWM:**  
   - O brilho dos LEDs é controlado via **PWM**, permitindo ajustar a intensidade da luz.

---

## Tecnologias e Ferramentas Utilizadas

- **Hardware:**
  - **Raspberry Pi Pico W**
  - **03 LEDs** (vermelho, amarelo e verde)
  - **03 Resistores de 330 Ω**

- **Software:**
  - Linguagem de programação: **C**
  - Ambiente de Desenvolvimento: **Visual Studio Code**
  - **Pico SDK** para controle de hardware

---

## Como Executar o Projeto

1. **Configuração do Ambiente:**
   - Certifique-se de ter o **Visual Studio Code** instalado e configurado para desenvolvimento em C.
   - Instale o **Pico SDK** e configure o ambiente para o **Raspberry Pi Pico W**.
   - Conecte o Pico W ao computador.

2. **Clonar o Repositório:**

```bash
git clone https://github.com/Ltiicia/SemaforoTemporizado.git
cd SemaforoTemporizado
```

3. **Compilar e Enviar o Código:**
   - Compile o código usando o **CMake** ou diretamente pelo VS Code.
   - Envie o binário para o Raspberry Pi Pico W.

4. **Conectar e Testar:**
   - Conecte os LEDs aos pinos GPIOs **11 (verde)**, **12 (amarelo)** e **13 (vermelho)**, utilizando resistores de 330 Ω.
   - Abra um monitor serial para visualizar as mensagens de status.

---

## Esquema de Ligação (Simulação no Wokwi)

- **LED Vermelho:** GPIO 13 com resistor de 330 Ω
- **LED Amarelo:** GPIO 12 com resistor de 330 Ω
- **LED Verde:** GPIO 11 com resistor de 330 Ω

---

## Requisitos da Atividade

1. O semáforo deve iniciar com a luz **vermelha** acesa.
2. O **temporizador periódico** deve alternar os LEDs a cada **3 segundos**.
3. As mudanças de estado devem ser implementadas na **função de callback** do temporizador.
4. A **rotina principal** deve imprimir mensagens na **porta serial** a cada **1 segundo**.
5. O experimento também deve ser testado utilizando o **LED RGB** nos GPIOs 11, 12 e 13.

