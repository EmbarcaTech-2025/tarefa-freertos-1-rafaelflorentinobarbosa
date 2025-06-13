#ifndef BUZZERS_H
#define BUZZERS_H

#include <stdint.h>

#define BUZZER_PIN 21 
#define BUZZER_PIN_B 10 

void buzzers_init();
void buzzer_play();
void buzzer_stop();

#endif