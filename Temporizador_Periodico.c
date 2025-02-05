/*
*************************************************
Letícia Gonçalves Souza
EmbarcaTech - Tarefa 1, unidade 4 (Temporizador Periódico)
*************************************************
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definição dos pinos dos LEDs
#define RED_LED_PIN 13
#define YELLOW_LED_PIN 12
#define GREEN_LED_PIN 11

// Variável global para controlar o estado do semáforo
volatile int semaforo_state = 0;

/**
 * @brief Define o brilho de um LED conectado a um pino específico.
 *
 * @param pin Pino GPIO conectado ao LED.
 * @param brightness Nível de brilho do LED (valor entre 0 e 255).
 */
void set_led_brightness(uint pin, uint16_t brightness)
{
    pwm_set_gpio_level(pin, brightness);
}

/**
 * @brief Inicializa o PWM em um pino específico.
 *
 * @param pin Pino GPIO a ser configurado para PWM.
 */
void init_pwm(uint pin)
{
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(slice_num, 255);
    pwm_set_enabled(slice_num, true);
}

/**
 * @brief Função callback do temporizador repetitivo.
 *
 * Essa função é chamada a cada 3000 ms para alternar o estado do semáforo.
 *
 * @param rt Ponteiro para a estrutura do temporizador (não utilizado).
 * @return true para manter o timer repetindo.
 */
bool timer_callback(repeating_timer_t *rt)
{
    // Atualiza o estado dos LEDs com base no estado atual do semáforo
    if (semaforo_state == 0)
    {
        // Estado 0: Luz Vermelha
        set_led_brightness(RED_LED_PIN, 30);
        set_led_brightness(YELLOW_LED_PIN, 0);
        set_led_brightness(GREEN_LED_PIN, 0);
        printf("Estado: VERMELHO\n");
    }
    else if (semaforo_state == 1)
    {
        // Estado 1: Luz Amarela
        set_led_brightness(RED_LED_PIN, 0);
        set_led_brightness(YELLOW_LED_PIN, 30);
        set_led_brightness(GREEN_LED_PIN, 0);
        printf("Estado: AMARELO\n");
    }
    else if (semaforo_state == 2)
    {
        // Estado 2: Luz Verde
        set_led_brightness(RED_LED_PIN, 0);
        set_led_brightness(YELLOW_LED_PIN, 0);
        set_led_brightness(GREEN_LED_PIN, 30);
        printf("Estado: VERDE\n");
    }

    // Atualiza o estado para a próxima transição (ciclo de 3 estados)
    semaforo_state = (semaforo_state + 1) % 3;
    return true; // Retorna true para manter o timer repetindo
}

/**
 * @brief Função principal.
 *
 * Inicializa o hardware, configura os timers e entra em loop,
 * imprimindo mensagens na porta serial a cada segundo.
 */
int main()
{
    stdio_init_all();

    // Inicializa o PWM para cada LED do semáforo
    init_pwm(RED_LED_PIN);
    init_pwm(YELLOW_LED_PIN);
    init_pwm(GREEN_LED_PIN);

    repeating_timer_t timer;
    // Configura um temporizador que dispara a cada 3000 ms (3 segundos)
    add_repeating_timer_ms(3000, timer_callback, NULL, &timer);

    // Loop principal: imprime uma mensagem a cada 1 segundo
    while (true)
    {
        printf("Rotina principal executando...\n");
        sleep_ms(1000);
    }

    return 0;
}
