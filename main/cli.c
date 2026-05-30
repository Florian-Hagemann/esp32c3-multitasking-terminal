#include <stdio.h>
#include <string.h>

#include "cli.h"
#include "temp_sensor.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


static void serial_cli_task(void *pvParameters) {
    
    int idx = 0;
    char input_buffer[20];

    memset(input_buffer, 0, sizeof(input_buffer));
    int input;

    while(1) {
        input = getchar();
        if (input == EOF || input < 0) {
            vTaskDelay(10 / portTICK_PERIOD_MS); // Sleep for 10ms
            continue;                            // Jump back to the top of while(1)
        }
        putchar(input);

        if(input != '\n' && input != '\r') { // Added '\r' check for different terminals
            if (idx < sizeof(input_buffer) - 1) {
                input_buffer[idx] = input;
                idx++;
            }
        } else {

            if(strcmp(input_buffer, "temp") == 0) {
                printf("The internal temperature is %.2f \n", get_latest_temperature());
            } else {
                printf("Unknown command: use \"temp\" to read internal temp.\n");
            }

            memset(input_buffer, 0, sizeof(input_buffer));
            idx = 0;

        }

    }
    // TODO: get user input

    // TODO: if input == "temp" call get_latest_temperature() and output that
}

void start_cli(void) {
    xTaskCreate(
        serial_cli_task,
        "Serial CLI Task",
        2064,
        NULL,
        1,
        NULL
    );
}
