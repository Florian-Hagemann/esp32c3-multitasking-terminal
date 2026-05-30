#include <stdio.h>
#include <string.h>

#include "cli.h"
#include "temp_sensor.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static void serial_cli_task(void *pvParameters) {
    // TODO: get user input
    // TODO: if input == "temp" call get_latest_temperature() and output that
}

void start_cli(void) {
    // TODO: create task for serial_cli_task
}
