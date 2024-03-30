#include <ESP8266WiFi.h>

#define SSID_SIZE   0x0E

extern "C" {
  #include "user_interface.h"
}

String ssid = "Red no segura";
byte channel;

uint8_t packet[128] = { 0x80, 0x00, 0x00, 0x00, 
                        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0xc0, 0x6c, 
                        0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, 
                        0x64, 0x00, 
                        0x01, 0x04, 
                
                        0x00, SSID_SIZE, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
                        0x01, 0x08, 0x82, 0x84,
                        0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 
                        0x04};                       


void setup() {
  delay(500);
  wifi_set_opmode(STATION_MODE);
  wifi_promiscuous_enable(1); 
}



void loop() { 
    channel = random(1,12); 
    wifi_set_channel(channel);

    packet[10] = packet[16] = random(256);
    packet[11] = packet[17] = random(256);
    packet[12] = packet[18] = random(256);
    packet[13] = packet[19] = random(256);
    packet[14] = packet[20] = random(256);
    packet[15] = packet[21] = random(256);

    packet[38] = ssid[0];
    packet[39] = ssid[1];
    packet[40] = ssid[2];
    packet[41] = ssid[3];
    packet[42] = ssid[4];
    packet[43] = ssid[5];
    packet[44] = ssid[6];
    packet[45] = ssid[7];
    packet[46] = ssid[8];
    packet[47] = ssid[9];
    packet[48] = ssid[10];
    packet[49] = ssid[11];
    packet[50] = ssid[12];
    packet[51] = ssid[13];
    
    packet[56] = channel;
    
    wifi_send_pkt_freedom(packet, 51 + SSID_SIZE, 0);
    wifi_send_pkt_freedom(packet, 51 + SSID_SIZE, 0);
    wifi_send_pkt_freedom(packet, 51 + SSID_SIZE , 0);
    delay(1);
}
