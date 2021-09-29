#include <WiFi.h>
#include <WebServer.h>
#include <uri/UriBraces.h>

#define LED_GPIO LED_BUILTIN

const char *ssid = "El SSID de tu router o zona wifi";
const char *password = "El password de tu router o zona wifi";

WebServer server(80);

void setup(void) {
  pinMode(LED_GPIO, OUTPUT);
  
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) { //Espera hasta que haya conexión WiFi
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connectado a ");
  Serial.print(ssid);
  Serial.print("con la IP: ");
  Serial.println(WiFi.localIP());

  server.on(F("/"), []() {
    server.send(200, "text/html", "<!DOCTYPE HTML><html><p>bienvenid@ a la página de inicio de ESP32</p><p>Accede a los servicios REST <a href=\"/LED/ON\">/LED/ON</a> para encender el LED o a <a href=\"/LED/OFF\">/LED/OFF</a> para apagarlo</p></html>");
  });

  server.on(UriBraces("/LED/{}"), LED_REST_Functionality);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("Servidor HTTP arrancado");
}

void loop(void) {
  server.handleClient();
  //yield();//permite a la CP ocuparse de otras tareas hasta que no haya un cliente conectado
}

void handleNotFound() {
  server.send(404, "text/plain", "Funcionalidad o pagina no encontrada");
}

void LED_REST_Functionality() {
  String PrimerArgumento = server.pathArg(0);
  if (PrimerArgumento == "ON") {
    Serial.println("Encendiendo luz...");
    digitalWrite(LED_GPIO, HIGH);
    server.send(200, "", "");
  }
  else if (PrimerArgumento == "OFF") {
    Serial.println("Apagando luz...");
    digitalWrite(LED_GPIO, LOW);
    server.send(200, "", "");
  }
  else
    handleNotFound();
}
