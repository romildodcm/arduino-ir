/*******************************************************************
 * Electrical scheme: https://github.com/romildodcm/arduino-ir/blob/main/electrical_scheme/circuit.png
 * Complete project on GitHub: https://github.com/romildodcm/arduino-ir
 * Author: Romildo C Marques
********************************************************************/

const int phototransistor = A0,
          signal_limit = 900;
int measurement = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(phototransistor, INPUT);
}

void loop()
{
    measurement = analogRead(phototransistor);
    Serial.print(measurement);

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