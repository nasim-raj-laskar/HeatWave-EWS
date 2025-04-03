from django.db import models

class HeatwaveData(models.Model):
    temperature = models.FloatField()
    humidity = models.FloatField()
    prediction = models.CharField(max_length=20)  # "Heatwave" or "No Heatwave"
    timestamp = models.DateTimeField(auto_now_add=True)  # Store the time of data entry

    def __str__(self):
        return f"{self.temperature}°C, {self.humidity}%, {self.prediction}"
