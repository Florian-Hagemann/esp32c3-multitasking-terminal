#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "cli.h"
#include "temp_sensor.h"

void app_main(void)
{
    start_cli();
    start_temperature_monitoring();
}
