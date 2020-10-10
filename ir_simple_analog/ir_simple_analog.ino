const int phototransistor = A0;
int measurement = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(phototransistor, INPUT);
}

void loop()
{
    measurement = analogRead(pinoFototransistor);
    Serial.print(measurement);

    if (valor < 800)
    {
        Serial.println(" | Infrared signal received");
    }
    else
    {
        Serial.println(" | Infrared signal interrupted!");
    }
    
    delay(500);
}