#include "include/led.h"
#include "hardware/gpio.h" // Inclui a biblioteca de GPIOs para o arquivo de implementação

void led_init(){
    // Inicializa cada pino como uma saída GPIO
    gpio_init(LED_PIN_AZUL);
    gpio_set_dir(LED_PIN_AZUL, GPIO_OUT);

    gpio_init(LED_PIN_VERDE);
    gpio_set_dir(LED_PIN_VERDE, GPIO_OUT);

    gpio_init(LED_PIN_VERMELHO);
    gpio_set_dir(LED_PIN_VERMELHO, GPIO_OUT);

    // Garante que todos os LEDs estão desligados na inicialização
    turn_off_led();
}

void turn_off_led(){
    gpio_put(LED_PIN_AZUL, 0);    
    gpio_put(LED_PIN_VERDE, 0);   
    gpio_put(LED_PIN_VERMELHO, 0); 
}

void turn_on_blue(){
    turn_off_led(); 
    gpio_put(LED_PIN_AZUL, 1); 
}

void turn_on_green(){
    turn_off_led();
    gpio_put(LED_PIN_VERDE, 1); 
}

void turn_on_red(){
    turn_off_led();
    gpio_put(LED_PIN_VERMELHO, 1);
}
