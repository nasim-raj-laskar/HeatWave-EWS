#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// WiFi Credentials
const char* ssid = "yourwifiname";       // Your WiFi SSID
const char* password = "yourwifipassword";  
const char* serverName = "http://Nasim74.pythonanywhere.com/api/post-data/";    //hosted at pythonanyhwere


#define DHTPIN 4      // GPIO pin where DHT11 is connected
#define DHTTYPE DHT11 // Using DHT11 sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    
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

    
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }
    //logic
    int prediction = (humidity > 59.5 && temperature > 29.7) ? 1 : 0;

    //JSON
    String jsonPayload = "{";
    jsonPayload += "\"temperature\":" + String(temperature) + ",";
    jsonPayload += "\"humidity\":" + String(humidity) + ",";
    jsonPayload += "\"prediction\":" + String(prediction);
    jsonPayload += "}";

    Serial.print("Sending JSON: ");
    Serial.println(jsonPayload);

    //POST request
    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
        Serial.print("Data sent successfully! HTTP Response code: ");
        Serial.println(httpResponseCode);
    } else {
        Serial.print("Error sending data! HTTP Response code: ");
        Serial.println(httpResponseCode);
    }

    http.end(); 

    delay(5000);  // Send data every 5 seconds
}
