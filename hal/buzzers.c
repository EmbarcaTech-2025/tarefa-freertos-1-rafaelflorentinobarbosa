#include "include/buzzers.h" // Inclui o cabeçalho que você definiu
#include "pico/stdlib.h"     // Necessário para funções GPIO e sleep
#include "hardware/gpio.h"   // Funções específicas de GPIO

// Função para inicializar o pino do buzzer
void buzzers_init() {
    gpio_init(BUZZER_PIN);          // Inicializa o pino GPIO
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Define o pino como saída
    buzzer_stop();                  // Garante que o buzzer está desligado na inicialização

    gpio_init(BUZZER_PIN_B);          // Inicializa o pino GPIO
    gpio_set_dir(BUZZER_PIN_B, GPIO_OUT); // Define o pino como saída
    buzzer_stop();                  // Garante que o buzzer está desligado na inicialização
}

// Função para fazer o buzzer tocar (ligar o pino)
void buzzer_play() {
    gpio_put(BUZZER_PIN, 1); // Coloca o pino em HIGH (ligado)
    gpio_put(BUZZER_PIN_B, 1); // Coloca o pino em HIGH (ligado)
}

// Função para parar o buzzer de tocar (desligar o pino)
void buzzer_stop() {
    gpio_put(BUZZER_PIN, 0); // Coloca o pino em LOW (desligado)
    gpio_put(BUZZER_PIN_B, 0); // Coloca o pino em LOW (desligado)
}