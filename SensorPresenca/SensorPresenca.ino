/***esp******************************************************/
/*Bibliotecas e Definições para conexão com a thinger.IO**/ 
/*********************************************************/
#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "USERNAME"
#define DEVICE_ID "DEVICE_ID"
#define DEVICE_CREDENTIAL "DEVICE_CREDENTIAL"

#define SSID "SSID"
#define SSID_PASSWORD "PASSWORD"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

/*********************************************************/
/****************Definir Pino do sensor*******************/
/*********************************************************/
#define PIN_SENSOR 0

void setup() {
  //Faz a configuração dos pinas de entrada
  pinMode(PIN_SENSOR, INPUT);

  //conexão da rede
  thing.add_wifi(SSID, SSID_PASSWORD);

  //carrega os valores do sensor
  thing["presenca"] >> [](pson& out){  
    int sinal = digitalRead(PIN_SENSOR);
      if(sinal == HIGH) {
          out = "OCUPADO";
        }
      else {
          out = "VAZIO";
        }  
  }; 
}

void loop() {
  thing.handle();
}
