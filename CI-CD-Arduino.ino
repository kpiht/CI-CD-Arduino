#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- Configuración de la Pantalla OLED SSD1306 ---
#define SCREEN_WIDTH 128 // Ancho de la pantalla OLED en píxeles
#define SCREEN_HEIGHT 64 // Alto de la pantalla OLED en píxeles (o 32 para pantallas más pequeñas)

// Dirección I2C de la pantalla OLED. Comúnmente 0x3C o 0x3D.
#define OLED_RESET -1 // Pin de RESET (o -1 si está conectado al VCC)

#define BUILD  "  v0.0.2"
#define CUSTOM "Vargas David"
#define BRAND  "John Deere"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() 
{
    pinMode(LED_BUILTIN, OUTPUT);

    Wire.begin(); // Inicializa la comunicación I2C

    // Inicializar la pantalla con la dirección I2C correcta
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    { 
      Serial.println(F("SSD1306 allocation failed"));
      for(;;); // No continuar si falla
    }

    display.clearDisplay();

    display.setTextSize(2);             
    display.setTextColor(SSD1306_WHITE);       
    display.setCursor(0,0);             
    display.println(F(BRAND));

    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); 
    display.setCursor(0,20); 
    display.println(CUSTOM);           
    display.setCursor(0,40); 
    display.print(F(BUILD));

    display.display();
}

void loop() 
{                   
    digitalWrite(LED_BUILTIN, HIGH);  
    delay(500);                      
    digitalWrite(LED_BUILTIN, LOW);  
    delay(500);  
}
