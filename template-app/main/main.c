#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define Led_GPIO 2
#define TAG "Led status"
void blink_task(void *pvParameter)
{
    gpio_pad_select_gpio(Led_GPIO);
    gpio_set_direction(Led_GPIO, GPIO_MODE_OUTPUT);
    while(1) {
        ESP_LOGI(TAG, "Turn on LED 1s");
        gpio_set_level(Led_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        ESP_LOGI(TAG, "Turn off LED 1s");
        gpio_set_level(Led_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    xTaskCreate(&blink_task, "blink_task", 2048, NULL, 5, NULL);
}