from rest_framework import serializers
from .models import HeatwaveData

class HeatwaveDataSerializer(serializers.ModelSerializer):
    class Meta:
        model = HeatwaveData
        fields = '__all__'
