#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "driver/sdmmc_host.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "aws_iot_config.h"
#include "aws_iot_log.h"
#include "aws_iot_version.h"
#include "aws_iot_mqtt_client_interface.h"
#include "driver/gpio.h"
#include <esp_idf_version.h>

#ifndef MAIN_AWS_CONNECTION_H_
#define MAIN_AWS_CONNECTION_H_
#define EXAMPLE_WIFI_SSID CONFIG_WIFI_SSID
#define EXAMPLE_WIFI_PASS CONFIG_WIFI_PASSWORD
#define ESP_NETIF_SUPPORTED

static const char *TAG = "subpub";
static EventGroupHandle_t wifi_event_group;
int mode;
int i;
extern const uint8_t aws_root_ca_pem_start[] asm("_binary_aws_root_ca_pem_start");
extern const uint8_t aws_root_ca_pem_end[] asm("_binary_aws_root_ca_pem_end");
extern const uint8_t certificate_pem_crt_start[] asm("_binary_certificate_pem_crt_start");
extern const uint8_t certificate_pem_crt_end[] asm("_binary_certificate_pem_crt_end");
extern const uint8_t private_pem_key_start[] asm("_binary_private_pem_key_start");
extern const uint8_t private_pem_key_end[] asm("_binary_private_pem_key_end");

static void event_handler(void*, esp_event_base_t, int32_t, void*);
void iot_subscribe_callback_handler(AWS_IoT_Client*, char*, uint16_t, IoT_Publish_Message_Params*, void*);
void disconnectCallbackHandler(AWS_IoT_Client*, void*);
void aws_iot_task(void*);
static void initialise_wifi(void);
void aws_connection();

#endif
