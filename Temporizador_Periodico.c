#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define RED_LED_PIN 13
#define BLUE_LED_PIN 12
#define GREEN_LED_PIN 11

void set_led_brightness(uint pin, uint16_t brightness)
{
    pwm_set_gpio_level(pin, brightness);
}

void init_pwm(uint pin)
{
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(slice_num, 255);
    pwm_set_enabled(slice_num, true);
}

int main()
{
    stdio_init_all();

    // Initialize LED pins with PWM
    init_pwm(RED_LED_PIN);
    init_pwm(BLUE_LED_PIN);
    init_pwm(GREEN_LED_PIN);

    while (true)
    {
        // Red light
        set_led_brightness(RED_LED_PIN, 30);
        set_led_brightness(BLUE_LED_PIN, 0);
        set_led_brightness(GREEN_LED_PIN, 0);
        for (int i = 0; i < 3; i++)
        {
            printf("Red light\n");
            sleep_ms(1000);
        }

        // Green light
        set_led_brightness(RED_LED_PIN, 0);
        set_led_brightness(BLUE_LED_PIN, 30);
        set_led_brightness(GREEN_LED_PIN, 0);
        for (int i = 0; i < 3; i++)
        {
            printf("Yellow light\n");
            sleep_ms(1000);
        }

        // Yellow light (combination of red and green)
        set_led_brightness(RED_LED_PIN, 0);
        set_led_brightness(BLUE_LED_PIN, 0);
        set_led_brightness(GREEN_LED_PIN, 30);
        for (int i = 0; i < 3; i++)
        {
            printf("Green light\n");
            sleep_ms(1000);
        }
    }
}