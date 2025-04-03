# Heatwave Detection using ML on ESP32  

## **📌 Project Overview**  
This project implements a real-time **heatwave detection system** by combining **machine learning** with **IoT**. The system uses an **ESP32 microcontroller** connected to a **DHT11 sensor** to monitor temperature and humidity in real-time. A **decision tree model** trained on a **synthetic dataset** is used to classify whether a heatwave is occurring. The model's logic is extracted into **if-else rules** and embedded into the ESP32, allowing it to function without the need for heavy ML computations.  

📌 **Key Features:**  
- 📱 **Real-time heatwave detection** based on temperature and humidity  
- 📊 **ML-based decision-making** using a trained Decision Tree model  
- ⚡ **Lightweight and efficient deployment** on ESP32 (without ML libraries)  
- 🎧 **OLED Display** for showing real-time results  
- 🔌 **Low power consumption** and compact IoT design  
- 🌐 **Web-based Monitoring** using Django and ESP32 communication  

---

## **🛠️ Tech Stack**  

### **📌 Programming Languages:**  
- **Python** (ML model training, and Django backend)  
- **C++ (Arduino framework)** for ESP32 programming  
- **HTML, CSS, JavaScript** for the web-based frontend  

### **📌 Python Libraries Used:**  
- `pandas` → Data manipulation  
- `numpy` → Numerical operations  
- `scikit-learn` → Machine Learning (Decision Tree model)  
- `Django` → Web framework for backend  
- `djangorestframework` → API for ESP32 communication  

### **📌 Arduino Libraries Used:**  
- `DHT` → Reads temperature and humidity from DHT11 sensor  
- `Adafruit_GFX` → Graphics library for OLED display  
- `Adafruit_SSD1306` → OLED display driver  
- `WiFi` → ESP32 WiFi connectivity  
- `HTTPClient` → ESP32 communication with Django API  

---

## **⚙️ System Architecture**  

- 1️⃣ **Data Preparation:** A synthetic dataset is created with temperature and humidity values, labeled as either `"heatwave (1)"` or `"no heatwave (0)"`.  
- 2️⃣ **Model Training:** A **Decision Tree classifier** is trained using the dataset to recognize heatwave conditions.  
- 3️⃣ **Rule Extraction:** The trained model's decision logic is converted into **if-else conditions** for deployment.  
- 4️⃣ **ESP32 Deployment:** The **if-else rules** are embedded into the ESP32 code [Heatwave.ino](https://github.com/nasim-raj-laskar/HeatWave-EWS/blob/main/Heatwave.ino) to classify real-time sensor readings.  
- 5️⃣ **Web Integration:** The ESP32 [web-temp.ino](https://github.com/nasim-raj-laskar/HeatWave-EWS/blob/main/web-temp.ino) sends real-time sensor data to the **Django API**, which stores and displays the latest readings on the **web interface**.  
- 6️⃣ **Real-time Monitoring:** The ESP32 continuously reads data from the **DHT11 sensor**, updates the **OLED screen**, and sends data to the **Django backend** for web visualization.  
- 🔗 **Demo Note:** The API stores past data and continues displaying it even if the ESP32 is disconnected. When the ESP32 is online, it updates the database in real-time.  
---

## **🛠️ Hardware Components**  

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
   pip install pandas numpy scikit-learn django djangorestframework
   ```
3. Run the Python script to train the model:  
   ```bash
   python Model.ipynb
   ```

### **📌 Setting up Django Backend**  
1. Navigate to the `web` folder:
   ```bash
   cd web
   ```
2. Apply migrations and start the Django server:
   ```bash
   python manage.py makemigrations
   python manage.py migrate
   python manage.py runserver
   ```

### **📌 Uploading Code to ESP32**  
1. Install **Arduino IDE** and add the ESP32 board.  
2. Install the required Arduino libraries (`Adafruit_GFX`, `Adafruit_SSD1306`, `DHT`, `WiFi`, `HTTPClient`).  
3. Connect the ESP32 to your PC via USB.  
4. Open the `Heatwave.ino` file in Arduino IDE and upload it (for OLED display).  
5. Open `web-temp.ino` file and upload it (for Django communication).  

---

## **🌐 Hosted Django Backend**  
The backend is hosted on **PythonAnywhere** and can be accessed here:  
🔗 **[Live Server: https://nasim74.pythonanywhere.com/](https://nasim74.pythonanywhere.com/)**  

---

