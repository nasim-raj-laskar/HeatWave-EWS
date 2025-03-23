
# Heatwave Detection using ML on ESP32  

## **📌 Project Overview**  
This project implements a real-time **heatwave detection system** by combining **machine learning** with **IoT**. The system uses an **ESP32 microcontroller** connected to a **DHT11 sensor** to monitor temperature and humidity in real-time. A **decision tree model** trained on a **synthetic dataset** is used to classify whether a heatwave is occurring. The model's logic is extracted into **if-else rules** and embedded into the ESP32, allowing it to function without the need for heavy ML computations.  

📌 **Key Features:**  
- 📡 **Real-time heatwave detection** based on temperature and humidity  
- 📊 **ML-based decision-making** using a trained Decision Tree model  
- ⚡ **Lightweight and efficient deployment** on ESP32 (without ML libraries)  
- 🎛️ **OLED Display** for showing real-time results  
- 🔌 **Low power consumption** and compact IoT design  

---

## **🛠️ Tech Stack**  

### **📌 Programming Languages:**  
- **Python** (for dataset generation and ML model training)  
- **C++ (Arduino framework)** for ESP32 programming  

### **📌 Python Libraries Used:**  
- `pandas` → Data manipulation  
- `numpy` → Numerical operations  
- `scikit-learn` → Machine Learning (Decision Tree model)  

### **📌 Arduino Libraries Used:**  
- `DHT` → Reads temperature and humidity from DHT11 sensor  
- `Adafruit_GFX` → Graphics library for OLED display  
- `Adafruit_SSD1306` → OLED display driver  

---

## **⚙️ System Architecture**  

The project follows this workflow:  

1️⃣ **Data Preparation:** A synthetic dataset is created with temperature and humidity values, labeled as either `"heatwave (1)"` or `"no heatwave (0)"`.  
2️⃣ **Model Training:** A **Decision Tree classifier** is trained using the dataset to recognize heatwave conditions.  
3️⃣ **Rule Extraction:** The trained model's decision logic is converted into **if-else conditions** for deployment.  
4️⃣ **ESP32 Deployment:** The **if-else rules** are embedded into the ESP32 code to classify real-time sensor readings.  
5️⃣ **Real-time Monitoring:** The ESP32 continuously reads data from the **DHT11 sensor** and displays "Heatwave Detected" or "No Heatwave" on the **OLED screen**.  

---

## **🔧 Hardware Components**  

| Component | Description |  
|-----------|------------|  
| **ESP32** | Microcontroller used for processing and display |  
| **DHT11 Sensor** | Measures temperature and humidity |  
| **OLED Display (SSD1306)** | Displays real-time heatwave detection results |  
| **Breadboard & Jumper Wires** | For circuit connections | 
| **Buzzer** | For triggering alarm |

### **🔌 Circuit Diagram**  
📌 *Insert an image of your circuit diagram here*  

---

## **📜 Code Explanation**  

### **📌 ML Model Training (Python)**
1. **Create a synthetic dataset:**  
   ```python
   import pandas as pd
   import numpy as np
   from sklearn.tree import DecisionTreeClassifier

   # Generate synthetic data
   data = {
       "temperature": np.random.randint(25, 50, 100),
       "humidity": np.random.randint(10, 90, 100),
   }
   df = pd.DataFrame(data)
   df["heatwave"] = np.where((df["temperature"] > 40) & (df["humidity"] < 30), 1, 0)  # Labeling

   # Train Decision Tree Model
   X = df[["temperature", "humidity"]]
   y = df["heatwave"]
   model = DecisionTreeClassifier()
   model.fit(X, y)

   # Export decision rules
   from sklearn.tree import export_text
   print(export_text(model, feature_names=["temperature", "humidity"]))
   ```
   
2. **Convert Decision Tree to If-Else Rules**  
   After training the model, we extract the conditions and manually implement them in the ESP32 code.

---

### **📌 ESP32 Code (Arduino/C++)**  
1. **Include Necessary Libraries & Define Pins**
   ```cpp
   #include <DHT.h>
   #include <Adafruit_GFX.h>
   #include <Adafruit_SSD1306.h>

   #define DHTPIN 4   // DHT11 sensor connected to GPIO 4
   #define DHTTYPE DHT11
   DHT dht(DHTPIN, DHTTYPE);

   #define SCREEN_WIDTH 128
   #define SCREEN_HEIGHT 64
   Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
   ```

2. **Setup Function**
   ```cpp
   void setup() {
       Serial.begin(115200);
       dht.begin();
       if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
           Serial.println("OLED allocation failed");
           for (;;);
       }
       display.clearDisplay();
   }
   ```

3. **Real-time Heatwave Detection Logic**
   ```cpp
   void loop() {
       float temperature = dht.readTemperature();
       float humidity = dht.readHumidity();
       
       if (isnan(temperature) || isnan(humidity)) {
           Serial.println("Failed to read from DHT sensor!");
           return;
       }

       // Decision Tree Logic for Heatwave Detection
       bool heatwave = (temperature > 40) && (humidity < 30);

       display.clearDisplay();
       display.setTextSize(1);
       display.setTextColor(WHITE);
       display.setCursor(0, 10);
       
       if (heatwave) {
           display.println("Heatwave Detected!");
       } else {
           display.println("No Heatwave.");
       }
       
       display.display();
       delay(2000);  // Update every 2 seconds
   }
   ```

---

## **🚀 How to Run the Project**  

### **📌 Running the ML Model**  
1. Clone the repository:  
   ```bash
   git clone https://github.com/yourusername/heatwave-detection.git
   cd heatwave-detection
   ```
2. Install dependencies:  
   ```bash
   pip install pandas numpy scikit-learn
   ```
3. Run the Python script to train the model:  
   ```bash
   python train_model.py
   ```

### **📌 Uploading Code to ESP32**  
1. Install **Arduino IDE** and add the ESP32 board.  
2. Install the required Arduino libraries (`Adafruit_GFX`, `Adafruit_SSD1306`, `DHT`).  
3. Connect the ESP32 to your PC via USB.  
4. Open the `heatwave_esp32.ino` file in Arduino IDE and upload it.  

---

## **🎥 Demo Video**  
📌 *[Insert YouTube or Drive link of your demo video here]*  

---

## **📌 Future Improvements**  
✔️ Use **real-world climate data** instead of synthetic data  
✔️ Add a **buzzer alert system** for warnings  
✔️ Implement **cloud connectivity** for remote monitoring  
✔️ Extend project to detect **other extreme weather conditions** (floods, droughts)  

---

## **📜 License**  
📌 This project is open-source and licensed under the **MIT License**. Feel free to use and modify it!  

---

## **🔗 Repository Link**  
📌 GitHub Repo: *[Insert your GitHub repo link here]*  

---

### **📩 Contact**  
For any queries, reach out at **your.email@example.com**  

---

This README is **highly structured**, **detailed**, and **professional**. Let me know if you need any modifications! 🚀🔥
