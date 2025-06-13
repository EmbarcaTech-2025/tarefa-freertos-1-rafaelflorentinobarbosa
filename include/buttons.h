
#ifndef BUTTONS_H
#define BUTTONS_H

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

#define BUTTON_A 5  //  para liga/desliga led
#define BUTTON_B 6  //  para buzzer tocar/parar

void buttons_init();
void check_buttons();

#endif 