
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

### 🔌 Circuit Diagram & Deployment  

<div align="center">
  <img src="https://github.com/nasim-raj-laskar/HeatWave-EWS/blob/main/img/pin-out.png" alt="Circuit Diagram" width="50%">
  <img src="https://github.com/nasim-raj-laskar/HeatWave-EWS/blob/main/img/1.jpg" alt="Deployment" width="42%">
</div>


---

## **🚀 How to Run the Project**  

### **📌 Running the ML Model**  
1. Clone the repository:  
   ```bash
   git clone https://github.com/yourusername/HeatWave-EWS.git
   cd HeatWave-EWS
   ```
2. Install dependencies:  
   ```bash
   pip install pandas numpy scikit-learn
   ```
3. Run the Python script to train the model:  
   ```bash
   python Model.ipynb
   ```

### **📌 Uploading Code to ESP32**  
1. Install **Arduino IDE** and add the ESP32 board.  
2. Install the required Arduino libraries (`Adafruit_GFX`, `Adafruit_SSD1306`, `DHT`).  
3. Connect the ESP32 to your PC via USB.  
4. Open the `Heatwave.ino` file in Arduino IDE and upload it.  
---


