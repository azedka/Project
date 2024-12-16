#include <LiquidCrystal.h>
#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 2;

DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Initialise l'écran LCD avec 16 colonnes et 2 lignes
  lcd.begin(16, 2);
}

static bool measure_environment(float *temperature, float *humidity) {
  static unsigned long measurement_timestamp = millis();

  // Mesure toutes les secondes
  if (millis() - measurement_timestamp > 1000ul) {
    if (dht_sensor.measure(temperature, humidity) == true) {
      measurement_timestamp = millis();
      return true;
    }
  }

  return false;
}

void loop() {
  float temperature;
  float humidity;

  // Mesure la température et l'humidité. Si la fonction retourne vrai, alors une mesure est disponible.
  if (measure_environment(&temperature, &humidity) == true) {
    lcd.clear();  // Efface l'écran avant de mettre à jour les valeurs
    lcd.setCursor(0, 0);
    lcd.print("T = ");
    lcd.print(temperature);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("H = ");
    lcd.print(humidity);
    lcd.print(" %");
  }
}
