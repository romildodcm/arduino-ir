/*******************************************************************
 * Electrical scheme: https://github.com/romildodcm/arduino-ir/blob/main/electrical_scheme/circuit.png
 * Complete project on GitHub: https://github.com/romildodcm/arduino-ir
 * Author: Romildo C Marques
********************************************************************/

const int phototransistor = A0, // Phototransistor analog input pin
          signal_limit = 900;   // Limit for not interrupted
int measurement = 0;            // The measurement ¯\_(ツ)_/¯

void setup()
{
    Serial.begin(9600); // Beguin the serial
    pinMode(phototransistor, INPUT); // Sensor input setup
}

void loop()
{
    // Read the analog signal from phototransistor
    measurement = analogRead(phototransistor);
    // Signal serial output
    Serial.print(measurement);

    // Detects the interruption by the predefined limit 
    if (measurement < signal_limit)
    {
        Serial.println(" | Infrared signal received");
    }
    else
    {
        Serial.println(" | Infrared signal interrupted!");
    }
    
    delay(500);
}