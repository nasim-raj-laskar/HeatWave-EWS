from django.contrib import admin
from django.urls import path, include
from api.views import home

urlpatterns = [
    path('admin/', admin.site.urls),
    path('api/', include('api.urls')),  # Include API routes
    path('', home),  # Home route for the main page
]
