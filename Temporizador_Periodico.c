/*
*************************************************
Letícia Gonçalves Souza
EmbarcaTech - Tarefa 1, unidade 4 (Temporizador Periódico)
*************************************************
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define RED_LED_PIN 13
#define BLUE_LED_PIN 12
#define GREEN_LED_PIN 11

/**
 * @brief Define o brilho de um LED conectado a um pino específico
 *
 * @param pin Pino GPIO conectado ao LED
 * @param brightness Nível de brilho do LED
 */
void set_led_brightness(uint pin, uint16_t brightness)
{
    pwm_set_gpio_level(pin, brightness);
}

/**
 * @brief Inicializa o PWM em um pino específico
 *
 * @param pin Pino GPIO a ser configurado para PWM
 */
void init_pwm(uint pin)
{
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(slice_num, 255);
    pwm_set_enabled(slice_num, true);
}

/**
 * @brief Função principal
 */
int main()
{
    stdio_init_all();

    // Inicializa PWM para os LEDs
    init_pwm(RED_LED_PIN);
    init_pwm(BLUE_LED_PIN);
    init_pwm(GREEN_LED_PIN);

    while (true)
    {
        // Luz vermelha
        set_led_brightness(RED_LED_PIN, 30);
        set_led_brightness(BLUE_LED_PIN, 0);
        set_led_brightness(GREEN_LED_PIN, 0);
        for (int i = 0; i < 3; i++)
        {
            printf("Luz vermelha\n");
            sleep_ms(1000);
        }

        // Luz verde
        set_led_brightness(RED_LED_PIN, 0);
        set_led_brightness(BLUE_LED_PIN, 30);
        set_led_brightness(GREEN_LED_PIN, 0);
        for (int i = 0; i < 3; i++)
        {
            printf("Luz verde\n");
            sleep_ms(1000);
        }

        // Luz amarela (combinação de vermelho e verde)
        set_led_brightness(RED_LED_PIN, 0);
        set_led_brightness(BLUE_LED_PIN, 0);
        set_led_brightness(GREEN_LED_PIN, 30);
        for (int i = 0; i < 3; i++)
        {
            printf("Luz amarela\n");
            sleep_ms(1000);
        }
    }
}