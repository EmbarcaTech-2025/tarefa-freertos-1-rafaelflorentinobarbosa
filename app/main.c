#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "include/buttons.h"
#include "include/led.h"
#include "include/buzzers.h"

TaskHandle_t ledTaskHandle = NULL;
TaskHandle_t buzzerTaskHandle = NULL;

void led_task(void *params) {
    led_init();
    while (true) {
        turn_on_red();
        vTaskDelay(pdMS_TO_TICKS(500));
        turn_on_green();
        vTaskDelay(pdMS_TO_TICKS(500));
        turn_on_blue();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void buzzer_task(void *params) {
    buzzers_init();
    while (true) {
        buzzer_play();
        vTaskDelay(pdMS_TO_TICKS(200));
        buzzer_stop();
        vTaskDelay(pdMS_TO_TICKS(800));
    }
}

void button_task(void *params) {
    buttons_init();

    while (true) {
        bool button_a_pressed = !gpio_get(BUTTON_A); // pressionado = 0
        bool button_b_pressed = !gpio_get(BUTTON_B);

        // Controle do LED via botão A
        if (button_a_pressed) {
            vTaskSuspend(ledTaskHandle);
        } else {
            vTaskResume(ledTaskHandle);
        }

        // Controle do buzzer via botão B
        if (button_b_pressed) {
            vTaskSuspend(buzzerTaskHandle);
        } else {
            vTaskResume(buzzerTaskHandle);
        }

        vTaskDelay(pdMS_TO_TICKS(100)); // polling a cada 100ms
    }
}

int main() {
    stdio_init_all();

    xTaskCreate(led_task, "LED", 256, NULL, 1, &ledTaskHandle);
    xTaskCreate(buzzer_task, "Buzzer", 256, NULL, 1, &buzzerTaskHandle);
    xTaskCreate(button_task, "Buttons", 256, NULL, 2, NULL); // prioridade maior

    vTaskStartScheduler();

    while (true) {}
}
