# Introducción a ESP32 con Arduino
Minicurso de instalación y ejemplos con WiFi sencillos con Arduino. Está pensado para ejemplos que se puedan ver y resolver en un par de horas, siempre que los alumnos ya hayan trabajdo con arduino previamente.

* ## ESP32
ESP32 es una familia de microcontroladores tipo SoC (System On a Chip) con soporte para Wi-Fi y Bluetooth ambos en 2.4GHz. Junto a su precio, esto le hace ser un chip muy interesante para proyectos de IoT, computación ubícua y similares.
Existen diversas chips ESP32 dentro de la familia ESP32 (https://docs.espressif.com/projects/arduino-esp32/en/latest/getting_started.html) y no todas ellas están soportadas en Arduino.
Sobre estos chips se construyen placas de desarrollo (e.g., [firebeetle](https://wiki.dfrobot.com/FireBeetle_ESP32_IOT_Microcontroller%28V3.0%29__Supports_Wi-Fi_&_Bluetooth__SKU__DFR0478), cada ella con un pinout, dimensiones, etc. diferentes.
![pinout de firebeattle](https://raw.githubusercontent.com/mlinaje/introESP32/main/pinout-firebeetle.png)

* ## Arduino para ESP32
Una ventaja de usar Arduino es que existe de este modo una amplia portabilidad en el código que escribamos para migrar entre distintas placas de desarrollo y microcontroladores.
Otra ventaja, es que desde el entorno arduino se sigue teniendo acceso al sistema base desde C/C++ con la funcionalidad propocionada por el fabricante. A este sistema base se le conoce como ESP-IDF. Encima de este sistema base que ofrece funcionalidad básica, el fabricante añadió un sistema operativo en tiempo real (freeRTOS) también accesible desde el IDE de Arduino, pudiéndose mezclar funcionalidad de las 3 capas de manera directa. 
Por último, con diferencia Arduino es el entorno de programación que más soporte de hardware de terceros (sensores y actuadores por medio de librerías) soporta.
* ### Instalar el IDE de desarrollo
Para el curso vamos a utilizar arduino IDE, que puede descargarse aquí **https://www.arduino.cc/en/Main/Software**.
Aunque en principio mientras el IDE soporte el compilado de este tipo de código, podrías usar tu IDE favorito. Mucha gente ha comenzado más recientemente a usar platoformIO (**https://platformio.org/platformio-ide**) que funciona sobre atom y que facilita mucho la instalación de librerías y plataformas hardware. VisualStudio y otros IDE son usables, pero más difíciles de configurar. Como iniciación, yo recomendaría quedarse en el entorno de desarrollo original de Arduino.

* ### Instalar una nueva placa hardware en Arduino IDE
En la siguiente animación podéis ver el detalle de como instalar una nueva placa de prototipado (wemos, nodemcu, esp32...). La animación tiene un enlace a un vídeo más extenso donde se ve paso a paso la forma de instalar nuevas placas (en el vídeo se hace para una nodemcu, pero es identico para eSP32 salvo por la URL que debemos incluir). La URL del json que debéis incluir en el cuadro de texto para placas ESP32 es:
**https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json**
[![Instalar nueva placa de prototipado](https://j.gifs.com/APDP1z.gif)](https://www.youtube.com/watch?v=14jI7ineMzM)

Tras instalar la placa (se instalan archivos que contienen la configuración de placas de desarrollo basadas en ESP32, cadenas de compilación específicas y alguna herramienta de compilación que usa ESP32 y no otras placas Arduino), debemos añadirla al IDE. Esto se hace en el IDE de Arduino mediante el menú **Herramientas>Gestor de tarjetas** y buscando e instalando ESP32 (es un proceso que tarda varios minutos).
(recuerda que para usar la placa, siempre debe estar seleccionada antes de verificar o subir el código a la placa).
Si alguno de estos pasos te falla, puede que expressif, el fabricante del ESP32 haya cambiado algo. Esto puedes verificarlo en la siguiente página web: [Installación de ESP32 en Arduino por Expressif](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)

* ### Instalar una nueva librería
Es probable que cuando uséis nuevo hardware (lector de tarjetas RFID,...) necesitéis instalar librerias específicas. A continuación te indico los pasos en una animación. De nuevo se enlaza un vídeo con información detallada al respecto.
[![Instalar nueva librería](https://j.gifs.com/0VRV9X.gif)](https://www.youtube.com/watch?v=RzLoHEC_0e8)
