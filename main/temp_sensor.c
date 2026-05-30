#include "temp_sensor.h"
#include "driver/temperature_sensor.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static volatile float latest_temp = 0.0f;

float get_latest_temperature(void *pvParameters) {
    return latest_temp;
}

void start_temperature_monitoring(void) {
    // TODO: start task for temperature monitoring 
}