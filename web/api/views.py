from rest_framework.decorators import api_view
from rest_framework.response import Response
from django.shortcuts import render
from .models import HeatwaveData
from .serializers import HeatwaveDataSerializer
from rest_framework import status
import logging

# Setup logging for debugging
logger = logging.getLogger(__name__)

def home(request):
    return render(request, "index.html")

@api_view(['POST'])
def post_data(request):
    try:
        
        data = request.data  
        new_entry = HeatwaveData.objects.create(
            temperature=data.get("temperature"),
            humidity=data.get("humidity"),
            prediction="Heatwave" if data.get("prediction") == 1 else "No Heatwave"
        )
        
        logger.info(f"New data entry added: {new_entry}")
        return Response({"status": "success", "message": "Data received!"}, status=status.HTTP_201_CREATED)

    except Exception as e:
        logger.error(f"Error in post_data: {e}")
        return Response({"status": "error", "message": str(e)}, status=status.HTTP_400_BAD_REQUEST)

@api_view(['GET'])
def latest_data_view(request):
    """Returns the most recent heatwave data."""
    try:
        latest_entry = HeatwaveData.objects.latest("id")  
        serializer = HeatwaveDataSerializer(latest_entry)
        return Response(serializer.data)
    except HeatwaveData.DoesNotExist:
        return Response({"error": "No data available"}, status=status.HTTP_404_NOT_FOUND)
    except Exception as e:
        logger.error(f"Error in latest_data_view: {e}")
        return Response({"error": str(e)}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)
