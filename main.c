// *********************************************************************
// A4_led.c										Version 05.01.2025  hpw
// Blinken einer LED
// Dokumentation bcm2835:
// https://www.airspayce.com/mikem/bcm2835/index.html
// *********************************************************************

#include <stdio.h>					// Header fuer Ein-/Ausgaben
#include "bcm2835.h"					    // Header fuer Broadcom

#define PIN RPI_GPIO_P1_12 // GPIO 18 auf dem Raspberry Pi Pinout (Pin 12)

int main(void) {
    int i;
    if (!bcm2835_init()) {
        printf("bcm2835 konnte nicht initialisiert werden.\n");
        return 1;}

    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    printf("Blinke die LED...\n");
    for (i = 0; i < 5; i++) {
        bcm2835_gpio_set(PIN);
        bcm2835_delay(500);

        bcm2835_gpio_clr(PIN);
        bcm2835_delay(500);
    }

    bcm2835_close();

    return 0;
}
