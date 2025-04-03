from django.urls import path
from .views import post_data, latest_data_view ,home

urlpatterns = [
    path("", home, name="home"),
    path("post-data/", post_data,name="post_data"),          #esp32
    path("latest-data/", latest_data_view,name="latest_data"), #javascript 
]
