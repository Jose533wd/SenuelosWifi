#include <ESP8266WiFi.h>

#define SSID_SIZE    0x0E
#define SSID_SIZE1   0x0F

extern "C" {
  #include "user_interface.h"
}

String ssid = "Red no segura";
String ssid2 = "Red no segura ";
String ssid3 = "Red no segura";
int ssid_sel=1;
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

uint8_t packet1[128] = { 0x80, 0x00, 0x00, 0x00, 
                        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0xc0, 0x6c, 
                        0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, 
                        0x64, 0x00, 
                        0x01, 0x04, 
                
                        0x00, SSID_SIZE1, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
                        0x01, 0x08, 0x82, 0x84,
                        0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 
                        0x04};
                                     


void setup() {
  Serial.begin(9600);
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

    packet1[10] = packet1[16] = random(256);
    packet1[11] = packet1[17] = random(256);
    packet1[12] = packet1[18] = random(256);
    packet1[13] = packet1[19] = random(256);
    packet1[14] = packet1[20] = random(256);
    packet1[15] = packet1[21] = random(256);

    switch(ssid_sel){
      case 1:
        Serial.println ("SSID");
        for (int i = 0; i<SSID_SIZE; i++){
              packet[38+i] =  ssid[i];
              wifi_send_pkt_freedom(packet, 51 + SSID_SIZE, 0);
              wifi_send_pkt_freedom(packet, 51 + SSID_SIZE, 0);
              wifi_send_pkt_freedom(packet, 51 + SSID_SIZE, 0);
        }
        break;
      case 2:
        Serial.println ("SSID 1");
        for (int i = 0; i<SSID_SIZE1; i++){
            packet1[38+i] =  ssid2[i];
            wifi_send_pkt_freedom(packet1, 51 + SSID_SIZE1, 0);
            wifi_send_pkt_freedom(packet1, 51 + SSID_SIZE1, 0);
            wifi_send_pkt_freedom(packet1, 51 + SSID_SIZE1, 0);
        }
        break;
    }
    ssid_sel++;
    if ( ssid_sel == 3 ){
      ssid_sel = 1;
    }
    
    packet[56] = channel;
    packet1[56] = channel;
    
    
    delay(1);
}
