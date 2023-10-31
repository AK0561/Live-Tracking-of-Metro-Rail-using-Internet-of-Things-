#include <TinyGPS++.h>
#include <HardwareSerial.h>
// Set serial ports for GPS and ESP32
#define GPS_SERIAL Serial2
#define ESP_SERIAL Serial
// Create GPS object
TinyGPSPlus gps;
void setup() {
 // Start serial communications for GPS and ESP32
 GPS_SERIAL.begin(9600);
 ESP_SERIAL.begin(115200);
}
void loop() {
 // Read GPS data until a full sentence is received
 while (GPS_SERIAL.available() > 0) {
   gps.encode(GPS_SERIAL.read());
 }
  // Check if valid GPS data is available
 if (gps.location.isValid()) {
   // Get latitude and longitude from GPS
float latitude = gps.location.lat();
   float longitude = gps.location.lng();
   // Print latitude and longitude to ESP32 serial monitor
   ESP_SERIAL.print("Latitude: ");
   ESP_SERIAL.print(latitude, 6);
   ESP_SERIAL.print(", Longitude: ");
   ESP_SERIAL.println(longitude, 6);
} 