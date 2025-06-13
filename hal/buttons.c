#include "include/buttons.h"

static bool button_a_last_state = true; 
static bool button_b_last_state = true;

void buttons_init(){
    // Inicializando os botões A e B
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);
}

void check_buttons(){
 // Read current button states buttons
    bool current_state_a = gpio_get(BUTTON_A);
    bool current_state_b = gpio_get(BUTTON_B);

    // Check for button A press (state change from high to low)
    if (current_state_a == false && button_a_last_state == true) {
        printf("Botao A\n");
        // Add a small delay for debounce after a press is detected
        // This prevents multiple detections if the button "bounces"
        sleep_ms(50);
    }

    // Check for button B press (state change from high to low)
    if (current_state_b == false && button_b_last_state == true) {
        printf("Botao B\n");
        // Add a small delay for debounce after a press is detected
        sleep_ms(50);
    }

    // Update last known states for the next iteration
    button_a_last_state = current_state_a;
    button_b_last_state = current_state_b;
}
