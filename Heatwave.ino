#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED Display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

TwoWire I2Cwire = TwoWire(1);  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &I2Cwire, OLED_RESET);

#define DHTPIN 21
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//logic
const char* predictHeatwave(float temp, float hum) {
  if (hum <= 59.5) {
    return "No Heatwave";
  } else {
    if (temp <= 29.7) {
      return "No Heatwave";
    } else {
      return "Heatwave";
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(DHTPIN, INPUT);
  dht.begin();
  delay(1000); 

  I2Cwire.begin(25, 26);  // SDA = 25, SCL = 26
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 allocation failed");
    for (;;)
      ;
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 10);
  display.print("OLED Ready!");
  display.display();
  delay(2000);
}

void loop() {
  delay(100); 

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read Sensor!");
    return;
  }
  const char* prediction = predictHeatwave(temp, hum);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);   
  display.setCursor(0, 5);  
  display.print(prediction);

  display.setTextSize(1);    
  display.setCursor(0, 40);  
  display.print("Temp: ");
  display.print(temp);
  display.print("C");

  display.setCursor(0, 50);  
  display.print("Hum: ");
  display.print(hum);
  display.print("%");

  display.display();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C, Humidity: ");
  Serial.print(hum);
  Serial.print("% => Prediction: ");
  Serial.println(prediction);

  delay(5000);  
}
