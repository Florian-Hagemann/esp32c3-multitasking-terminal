idf_component_register(SRCS "multitasking-terminal.c" "temp_sensor.c" "cli.c"
                    INCLUDE_DIRS "."
                    REQUIRES esp_driver_tsens)
