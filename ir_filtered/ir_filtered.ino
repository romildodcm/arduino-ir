/*******************************************************************
 * Electrical scheme:
 * Complete project on GitHub:
 * Author: Romildo C Marques
********************************************************************/


const int phototransistor = A0, // Phototransistor analog input pin
          n = 10;   // Number of samples for moving average filter

// Vector/array of samples for moving average filter
int sensorMeasurements[n]; 


int measurement,          // The measurement ¯\_(ツ)_/¯ 
    filteredMeasurement;  // The filtered measurement ¯\_(ツ)_/¯ 
long measurementsSum = 0; // Sum of samples for moving average filter

void setup()
{
    Serial.begin(9600); // Begin the serial
    pinMode(phototransistor, INPUT); // Sensor input setup

    // Output with the CSV header 
    Serial.print("Time");
    Serial.print(",");
    Serial.print("Measurement");
    Serial.print(",");
    Serial.println("Filtered_Measurement");
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

    // Data output
    Serial.print(millis());
    Serial.print(",");
    Serial.print(measurement);
    Serial.print(",");
    Serial.println(filteredMeasurement);
}