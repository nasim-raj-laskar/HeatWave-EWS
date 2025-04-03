#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// WiFi Credentials
const char* ssid = "ngUsAmo";       // Your WiFi SSID
const char* password = "67000470";  // Your WiFi Password

// Django Server URL (Use HTTP if using a free PythonAnywhere account)
const char* serverName = "http://Nasim74.pythonanywhere.com/api/post-data/";

// DHT Sensor Setup
#define DHTPIN 4      // GPIO pin where DHT11 is connected
#define DHTTYPE DHT11 // Using DHT11 sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    // Connect to WiFi
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected!");
    Serial.print("ESP32 IP Address: ");
    Serial.println(WiFi.localIP());

    dht.begin();
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi Disconnected! Reconnecting...");
        WiFi.begin(ssid, password);
        delay(5000);
        return;
    }

    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    // Read sensor data
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Validate readings
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // Heatwave condition: Humidity > 59.5% and Temperature > 29.7°C
    int prediction = (humidity > 59.5 && temperature > 29.7) ? 1 : 0;

    // Create JSON payload
    String jsonPayload = "{";
    jsonPayload += "\"temperature\":" + String(temperature) + ",";
    jsonPayload += "\"humidity\":" + String(humidity) + ",";
    jsonPayload += "\"prediction\":" + String(prediction);
    jsonPayload += "}";

    Serial.print("Sending JSON: ");
    Serial.println(jsonPayload);

    // Send POST request
    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
        Serial.print("Data sent successfully! HTTP Response code: ");
        Serial.println(httpResponseCode);
    } else {
        Serial.print("Error sending data! HTTP Response code: ");
        Serial.println(httpResponseCode);
    }

    http.end(); // Close connection

    delay(5000);  // Send data every 5 seconds
}
