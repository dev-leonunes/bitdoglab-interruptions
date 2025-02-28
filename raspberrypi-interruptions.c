#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pio_matrix/matriz_leds.h"
#include "hardware/timer.h"

PIO pio;
uint sm;

const uint LED_RED = 13;
const uint BTN_A = 5, BTN_B = 6;
#define LED_MATRIX 7
#define TIME_LED 200

volatile int number = 0; // Número exibido na matriz de LEDs

// Função para piscar o LED
int blink_led(uint led)
{
    gpio_put(led, 1);
    sleep_ms(TIME_LED);
    gpio_put(led, 0);
}

// Rotina de interrupção para os botões A e B
void irq_handler(uint gpio, uint32_t events)
{
    static absolute_time_t last_press = 0;

    // 200ms debounce
    if (absolute_time_diff_us(last_press, get_absolute_time()) > 200000)
    {
        if (gpio == BTN_A)
        {
            number = (number + 1) % 10; // Incrementa e mantém entre 0-9
            printf("Button A pressed, number: %d\n", number);
        }
        else if (gpio == BTN_B)
        {
            number = (number - 1 + 10) % 10; // Decrementa e mantém entre 0-9
            printf("Button B pressed, number: %d\n", number);
        }
        last_press = get_absolute_time();
    }
}

// Configuração dos pinos e interrupções
void setup()
{
    stdio_init_all();

    // Configurar LEDs RGB como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    // Configurar botões como entrada com pull-up interno
    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);
    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);

    // Configurar matriz de LEDs
    pio = pio0;
    sm = configurar_matriz(pio);

    // Configurar interrupções para botões (falling edge)
    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &irq_handler);
    gpio_set_irq_enabled_with_callback(BTN_B, GPIO_IRQ_EDGE_FALL, true, &irq_handler);
}

int main()
{
    setup();
    while (true)
    {
        blink_led(LED_RED);             // Piscar LED vermelho
        exibir_numero(pio, sm, number); // Exibir número na matriz de LEDs
        sleep_ms(100);
    }
}
