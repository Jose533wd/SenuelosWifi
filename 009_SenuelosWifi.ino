#include <ESP8266WiFi.h>

#define SSID_SIZE    0x0F
#define SSID_SIZE1   0x10
#define SSID_SIZE2   0x11
#define SSID_SIZE3   0x12
#define SSID_SIZE4   0x13
#define SSID_SIZE5   0x14
#define SSID_SIZE6   0x15
#define SSID_SIZE7   0x16
#define SSID_SIZE8   0x17
#define SSID_SIZE9   0x18

extern "C" {
  #include "user_interface.h"
}

char  ssid[] = "Red no segura";
char ssid1[] = "Red no segura ";
char ssid2[] = "Red no segura  ";
char ssid3[] = "Red no segura   ";
char ssid4[] = "Red no segura    ";
char ssid5[] = "Red no segura     ";
char ssid6[] = "Red no segura      ";
char ssid7[] = "Red no segura       ";
char ssid8[] = "Red no segura        ";
char ssid9[] = "Red no segura         ";

char* ssids[] = {ssid, ssid1, ssid2, ssid3, ssid4, ssid5, ssid6, ssid7, ssid8, ssid9};

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
                
                        0x00, SSID_SIZE, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
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
                
                        0x00, SSID_SIZE1, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
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
                
                        0x00, SSID_SIZE2, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
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
                
                        0x00, SSID_SIZE3, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
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
                
                        0x00, SSID_SIZE4, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
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
                
                        0x00, SSID_SIZE5, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
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
                
                        0x00, SSID_SIZE6, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
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
                
                        0x00, SSID_SIZE7, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,  0x72, 0x72,
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
                
                        0x00, SSID_SIZE8, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,
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
                
                        0x00, SSID_SIZE9, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,  0x72, 0x72,
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
    
  
    
    if ( ssid_sel_1 <= 2){
      strcpy(ssid,  " ASUSRTX5G    ");
      strcpy(ssid1, " ASUSRTX5G     ");
      strcpy(ssid2, " ASUSRTX5G      ");
      strcpy(ssid3, " ASUSRTX5G       ");
      strcpy(ssid4, " ASUSRTX5G        ");
      strcpy(ssid5, " ASUSRTX5G         ");
      strcpy(ssid6, " ASUSRTX5G          ");
      strcpy(ssid7, " ASUSRTX5G           ");
      strcpy(ssid8, " ASUSRTX5G            ");
      strcpy(ssid9, " ASUSRTX5G             ");
    }else{
      strcpy(ssid,  " Red no segura");
      strcpy(ssid1, " Red no segura ");
      strcpy(ssid2, " Red no segura  ");
      strcpy(ssid3, " Red no segura   ");
      strcpy(ssid4, " Red no segura    ");
      strcpy(ssid5, " Red no segura     ");
      strcpy(ssid6, " Red no segura      ");
      strcpy(ssid7, " Red no segura       ");
      strcpy(ssid8, " Red no segura        ");
      strcpy(ssid9, " Red no segura         ");
    }
    ssid_sel_1++;
    if( ssid_sel_1 == 6){
      ssid_sel_1 = 0;
    }
    
    switch(ssid_sel){
      case 0:
        //Serial.println ("SSID");
        for (int i = 0; i<SSID_SIZE; i++){
              packet[38+i] =  ssid[i];
              wifi_send_pkt_freedom(packet, 51 + SSID_SIZE + ssid_sel, 0);
              wifi_send_pkt_freedom(packet, 51 + SSID_SIZE + ssid_sel, 0);
              wifi_send_pkt_freedom(packet, 51 + SSID_SIZE + ssid_sel, 0);
        }
        break;
      case 1:
        //Serial.println ("SSID 1");
        for (int i = 0; i<SSID_SIZE1; i++){
            packet1[38+i] =  ssid1[i];
            wifi_send_pkt_freedom(packet1, 51 + SSID_SIZE + ssid_sel, 0);
            wifi_send_pkt_freedom(packet1, 51 + SSID_SIZE + ssid_sel, 0);
            wifi_send_pkt_freedom(packet1, 51 + SSID_SIZE + ssid_sel, 0);
        }
        break;
      case 2:
        //Serial.println ("SSID 2");
        for (int i = 0; i<SSID_SIZE2; i++){
            packet2[38+i] =  ssid2[i];
            wifi_send_pkt_freedom(packet2, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet2, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet2, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 3:
        //Serial.println ("SSID 3");
        for (int i = 0; i<SSID_SIZE3; i++){
            packet3[38+i] =  ssid3[i];
            wifi_send_pkt_freedom(packet3, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet3, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet3, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 4:
        //Serial.println ("SSID 4");
        for (int i = 0; i<SSID_SIZE4; i++){
            packet4[38+i] =  ssid4[i];
            wifi_send_pkt_freedom(packet4, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet4, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet4, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 5:
        //Serial.println ("SSID 5");
        for (int i = 0; i<SSID_SIZE5; i++){
            packet5[38+i] =  ssid5[i];
            wifi_send_pkt_freedom(packet5, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet5, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet5, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 6:
        //Serial.println ("SSID 6");
        for (int i = 0; i<SSID_SIZE6; i++){
            packet6[38+i] =  ssid6[i];
            wifi_send_pkt_freedom(packet6, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet6, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet6, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 7:
        //Serial.println ("SSID 7");
        for (int i = 0; i<SSID_SIZE7; i++){
            packet7[38+i] =  ssid7[i];
            wifi_send_pkt_freedom(packet7, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet7, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet7, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 8:
        //Serial.println ("SSID 8");
        for (int i = 0; i<SSID_SIZE8; i++){
            packet8[38+i] =  ssid8[i];
            wifi_send_pkt_freedom(packet8, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet8, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet8, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
      case 9:
        //Serial.println ("SSID 9");
        for (int i = 0; i<SSID_SIZE9; i++){
            packet9[38+i] =  ssid9[i];
            wifi_send_pkt_freedom(packet9, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet9, 51 + SSID_SIZE+ ssid_sel, 0);
            wifi_send_pkt_freedom(packet9, 51 + SSID_SIZE+ ssid_sel, 0);
        }
        break;
    }
    ssid_sel++;
    if ( ssid_sel == 10 ){
      ssid_sel = 0;
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
