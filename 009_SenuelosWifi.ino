#include <ESP8266WiFi.h>

#define SSID_SIZE    0x0E
#define SSID_SIZE1   0x0F
#define SSID_SIZE2   0x10
#define SSID_SIZE3   0x11
#define SSID_SIZE4   0x12
#define SSID_SIZE5   0x13
#define SSID_SIZE6   0x14
#define SSID_SIZE7   0x15
#define SSID_SIZE8   0x16
#define SSID_SIZE9   0x17

extern "C" {
  #include "user_interface.h"
}

String ssid = "Red no segura";
String ssid1 = "Red no segura ";
String ssid2 = "Red no segura  ";
String ssid3 = "Red no segura   ";
String ssid4 = "Red no segura    ";
String ssid5 = "Red no segura     ";
String ssid6 = "Red no segura      ";
String ssid7 = "Red no segura       ";
String ssid8 = "Red no segura        ";
String ssid9 = "Red no segura         ";

String AS_ssid  = "ASUSRTX5G";
String AS_ssid1 = "ASUSRTX5G ";
String AS_ssid2 = "ASUSRTX5G  ";
String AS_ssid3 = "ASUSRTX5G   ";
String AS_ssid4 = "ASUSRTX5G    ";
String AS_ssid5 = "ASUSRTX5G     ";
String AS_ssid6 = "ASUSRTX5G      ";
String AS_ssid7 = "ASUSRTX5G       ";
String AS_ssid8 = "ASUSRTX5G        ";
String AS_ssid9 = "ASUSRTX5G         ";

int ssid_sel=0;
int ssid_sel_1=0;
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
                                     
uint8_t packet2[128] = { 0x80, 0x00, 0x00, 0x00, 
                        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0xc0, 0x6c, 
                        0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, 
                        0x64, 0x00, 
                        0x01, 0x04, 
                
                        0x00, SSID_SIZE2, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
                        0x01, 0x08, 0x82, 0x84,
                        0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 
                        0x04};
                        
uint8_t packet3[128] = { 0x80, 0x00, 0x00, 0x00, 
                        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0xc0, 0x6c, 
                        0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, 
                        0x64, 0x00, 
                        0x01, 0x04, 
                
                        0x00, SSID_SIZE3, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
                        0x01, 0x08, 0x82, 0x84,
                        0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 
                        0x04};

uint8_t packet4[128] = { 0x80, 0x00, 0x00, 0x00, 
                        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0xc0, 0x6c, 
                        0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, 
                        0x64, 0x00, 
                        0x01, 0x04, 
                
                        0x00, SSID_SIZE4, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
                        0x01, 0x08, 0x82, 0x84,
                        0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 
                        0x04};

uint8_t packet5[128] = { 0x80, 0x00, 0x00, 0x00, 
                        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0xc0, 0x6c, 
                        0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, 
                        0x64, 0x00, 
                        0x01, 0x04, 
                
                        0x00, SSID_SIZE5, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
                        0x01, 0x08, 0x82, 0x84,
                        0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 
                        0x04};

uint8_t packet6[128] = { 0x80, 0x00, 0x00, 0x00, 
                        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0xc0, 0x6c, 
                        0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, 
                        0x64, 0x00, 
                        0x01, 0x04, 
                
                        0x00, SSID_SIZE6, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
                        0x01, 0x08, 0x82, 0x84,
                        0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 
                        0x04};

uint8_t packet7[128] = { 0x80, 0x00, 0x00, 0x00, 
                        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0xc0, 0x6c, 
                        0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, 
                        0x64, 0x00, 
                        0x01, 0x04, 
                
                        0x00, SSID_SIZE7, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,  0x72,
                        0x01, 0x08, 0x82, 0x84,
                        0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 
                        0x04};                

uint8_t packet8[128] = { 0x80, 0x00, 0x00, 0x00, 
                        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0xc0, 0x6c, 
                        0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, 
                        0x64, 0x00, 
                        0x01, 0x04, 
                
                        0x00, SSID_SIZE8, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
                        0x01, 0x08, 0x82, 0x84,
                        0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 
                        0x04};

uint8_t packet9[128] = { 0x80, 0x00, 0x00, 0x00, 
                        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0xc0, 0x6c, 
                        0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, 
                        0x64, 0x00, 
                        0x01, 0x04, 
                
                        0x00, SSID_SIZE9, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,  0x72,
                        0x01, 0x08, 0x82, 0x84,
                        0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 
                        0x04};

void setup() {
  //Serial.begin(9600);
  delay(500);
  wifi_set_opmode(STATION_MODE);
  wifi_promiscuous_enable(1); 
}



void loop() { 
    channel = random(1,12); 
    wifi_set_channel(channel);
    for (int j=10; j<=15; j++){
      packet[j] = packet[j+6] = random(256);
      packet1[j] = packet1[j+6] = random(256);
      packet2[j] = packet2[j+6] = random(256);
      packet3[j] = packet3[j+6] = random(256);
      packet4[j] = packet4[j+6] = random(256);
      packet5[j] = packet5[j+6] = random(256);
      packet6[j] = packet6[j+6] = random(256);
      packet7[j] = packet7[j+6] = random(256);
      packet8[j] = packet8[j+6] = random(256);
      packet9[j] = packet9[j+6] = random(256);
    }
    


    switch(ssid_sel){
      case 0:
        //Serial.println ("SSID");
        for (int i = 0; i<SSID_SIZE; i++){
          if(ssid_sel_1 == 0){
            packet[38+i] =  ssid[i];
          }else if(ssid_sel_1 == 1){
            packet[38+i] =  AS_ssid[i];
          }
          wifi_send_pkt_freedom(packet, 51 + SSID_SIZE + ssid_sel, 0);
          wifi_send_pkt_freedom(packet, 51 + SSID_SIZE + ssid_sel, 0);
          wifi_send_pkt_freedom(packet, 51 + SSID_SIZE + ssid_sel, 0);
        }
        break;
      case 1:
        //Serial.println ("SSID 1");
        for (int i = 0; i<SSID_SIZE1; i++){
          if(ssid_sel_1 == 0){
            packet[38+i] =  ssid1[i];
          }else if(ssid_sel_1 == 1){
            packet[38+i] =  AS_ssid1[i];
          }
          wifi_send_pkt_freedom(packet1, 51 + SSID_SIZE + ssid_sel, 0);
          wifi_send_pkt_freedom(packet1, 51 + SSID_SIZE + ssid_sel, 0);
          wifi_send_pkt_freedom(packet1, 51 + SSID_SIZE + ssid_sel, 0);
        }
        break;
      case 2:
        //Serial.println ("SSID 2");
        for (int i = 0; i<SSID_SIZE2; i++){
          if(ssid_sel_1 == 0){
            packet[38+i] =  ssid2[i];
          }else if(ssid_sel_1 == 1){
            packet[38+i] =  AS_ssid2[i];
          }
          wifi_send_pkt_freedom(packet2, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet2, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet2, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 3:
        //Serial.println ("SSID 3");
        for (int i = 0; i<SSID_SIZE3; i++){
          if(ssid_sel_1 == 0){
            packet[38+i] =  ssid3[i];
          }else if(ssid_sel_1 == 1){
            packet[38+i] =  AS_ssid3[i];
          }
          wifi_send_pkt_freedom(packet3, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet3, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet3, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 4:
        //Serial.println ("SSID 4");
        for (int i = 0; i<SSID_SIZE4; i++){
          if(ssid_sel_1 == 0){
            packet[38+i] =  ssid4[i];
          }else if(ssid_sel_1 == 1){
            packet[38+i] =  AS_ssid4[i];
          }
          wifi_send_pkt_freedom(packet4, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet4, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet4, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 5:
        //Serial.println ("SSID 5");
        for (int i = 0; i<SSID_SIZE5; i++){
          if(ssid_sel_1 == 0){
            packet[38+i] =  ssid5[i];
          }else if(ssid_sel_1 == 1){
            packet[38+i] =  AS_ssid5[i];
          }
          wifi_send_pkt_freedom(packet5, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet5, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet5, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 6:
        //Serial.println ("SSID 6");
        for (int i = 0; i<SSID_SIZE6; i++){
          if(ssid_sel_1 == 0){
            packet[38+i] =  ssid6[i];
          }else if(ssid_sel_1 == 1){
            packet[38+i] =  AS_ssid6[i];
          }
          wifi_send_pkt_freedom(packet6, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet6, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet6, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 7:
        //Serial.println ("SSID 7");
        for (int i = 0; i<SSID_SIZE7; i++){
          if(ssid_sel_1 == 0){
            packet[38+i] =  ssid7[i];
          }else if(ssid_sel_1 == 1){
            packet[38+i] =  AS_ssid7[i];
          }
          wifi_send_pkt_freedom(packet7, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet7, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet7, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 8:
        //Serial.println ("SSID 8");
        for (int i = 0; i<SSID_SIZE8; i++){
          if(ssid_sel_1 == 0){
            packet[38+i] =  ssid8[i];
          }else if(ssid_sel_1 == 1){
            packet[38+i] =  AS_ssid8[i];
          }
          wifi_send_pkt_freedom(packet8, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet8, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet8, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 9:
        //Serial.println ("SSID 9");
        for (int i = 0; i<SSID_SIZE9; i++){
          if(ssid_sel_1 == 0){
            packet[38+i] =  ssid9[i];
          }else if(ssid_sel_1 == 1){
            packet[38+i] =  AS_ssid9[i];
          }
          wifi_send_pkt_freedom(packet9, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet9, 51 + SSID_SIZE+ ssid_sel, 0);
          wifi_send_pkt_freedom(packet9, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
    }
    ssid_sel++;
    ssid_sel_1++;
    if ( ssid_sel == 10 ){
      ssid_sel = 0;
    }
    if ( ssid_sel_1 == 2 ){
      ssid_sel_1 = 0;
    }
    
    packet[56] = channel;
    packet1[56] = channel;
    packet2[56] = channel;
    packet3[56] = channel;
    packet4[56] = channel;
    packet5[56] = channel;
    packet6[56] = channel;
    packet7[56] = channel;
    packet8[56] = channel;
    packet8[56] = channel;
    
    
    delay(1);
}
