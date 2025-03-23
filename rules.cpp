// |--- Humidity (%) <= 59.50
// |   |--- class: 0
// |--- Humidity (%) >  59.50
// |   |--- Temperature (°C)' <= 29.70
// |   |   |--- class: 0
// |   |--- Temperature (°C)' >  29.70
// |   |   |--- class: 1

const char* predictHeatwave(float temp, float hum) {
    if (hum <= 59.5) {
            return "No Heatwave";
        } else {
            if(temp<=29.7){
                return "No Heatwave";
            } else {
                return "Heatwave";
        }
    }
}  

