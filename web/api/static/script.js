let tempData = [];
let humData = [];
let labels = [];

// Chart Setup
const ctx = document.getElementById("tempChart").getContext("2d");
const tempChart = new Chart(ctx, {
    type: "line",
    data: {
        labels: labels,
        datasets: [
            {
                label: "Temperature (°C)",
                data: tempData,
                borderColor: "red",
                borderWidth: 2,
                fill: false
            },
            {
                label: "Humidity (%)",
                data: humData,
                borderColor: "blue",
                borderWidth: 2,
                fill: false
            }
        ]
    },
    options: {
        responsive: true,
        scales: {
            y: { beginAtZero: true }
        }
    }
});

function updateChart(temperature, humidity) {
    if (labels.length >= 10) {
        labels.shift();
        tempData.shift();
        humData.shift();
    }

    let timestamp = new Date().toLocaleTimeString();
    labels.push(timestamp);
    tempData.push(temperature);
    humData.push(humidity);

    tempChart.update();
}

function updateData() {
    fetch("/api/latest-data/")  // Django API endpoint
        .then(response => response.json())
        .then(data => {
            document.getElementById("temp").innerText = data.temperature;
            document.getElementById("hum").innerText = data.humidity;

            let statusElement = document.getElementById("prediction");
            let warningBox = document.getElementById("warning-box");

            if (data.prediction === 1) {
                statusElement.innerText = "🔥 Heatwave Warning!";
                statusElement.style.color = "red";
                warningBox.style.display = "block";
            } else {
                statusElement.innerText = "✅ Normal Conditions";
                statusElement.style.color = "green";
                warningBox.style.display = "none";
            }

            updateChart(data.temperature, data.humidity);
        })
        .catch(error => console.error("Error fetching data:", error));
}

setInterval(updateData, 5000);
updateData();
