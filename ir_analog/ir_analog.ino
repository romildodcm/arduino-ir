/*******************************************************************
 * CONNECTIONS
 *  check 
 * 
 * 
 * 
 * 
 * Author: Romildo C Marques
 * E-mail: romildodcm@gmail.com
********************************************************************/

//#define SENSOR1 A1
const int phototransistor = A0, n = 10;

// Most recent: 0
// Oldest: N-1
int sensorMeasurements[n];

int cont = 0, measurement, filteredMeasurement;
float time;
long measurementsSum = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(phototransistor, INPUT);
}

void loop()
{
    // read the analog signal from phototransistor
    measurement = analogRead(phototransistor);

    // Begin the moving average filter
    for (int i = n; i > 0; i--)
    {
        sensorMeasurements[i] = sensorMeasurements[i - 1];
    }

    sensorMeasurements[0] = measurement;

    for (int i = 0; i < n; i++)
    {
        measurementsSum = measurementsSum + sensorMeasurements[i];
    }

    filteredMeasurement = measurementsSum / n;
    measurementsSum = 0;

    if (filteredMeasurement > 800)
    {
        Serial.println("Interrupted");
    }
    
    // Print the output every 100 milliseconds
    else if (abs(millis() - time) > 500)
    {
        Serial.println("Not Interrupted");
        time = millis();
    }
}
