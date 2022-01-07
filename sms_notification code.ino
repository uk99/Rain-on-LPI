#include <WiFi.h>
#include "twilio.hpp"
int digitalPin = 6; // pour le relais
int analogPin = A0; // pour le capteur de l'humidité du    sol
int digitalVal; // digital readings
int analogVal; //analog readings
int val ;
int sensordistance = 0; // Set these - but DON'T push them to GitHub!
static const char *ssid = "CRI-WIFI";
static const char *password = "--criWIFI--";

// Values from Twilio (find them on the dashboard)
static const char *account_sid = "ACf260c84a6be994b83163671ebdcbdd3d";
static const char *auth_token = "5472db1d5bc0ac9e2e14a6670cca0108";
// Phone number should start with "+<countrycode>"
static const char *from_number = "+12672146890";

// You choose!
// Phone number should start with "+<countrycode>"
static const char *to_number = "+33604919508";
static const char *message = "Im thirsty, water me please :)";

String response;
Twilio *twilio;

//void loop()
//{
//  val = digitalRead (3);
//  if (val == LOW) { // if module detects an obstacle,
//    Serial.println("La bassine est vide"); // show message on serial monitor and
//  }
//  else {
//    Serial.println("La basssine est pleine ");
//  }
//  analogVal = analogRead(analogPin);//lire la valeur retournée par le capteur de l'humidité
//  Serial.print(analogVal);// affiche la valeur
//
//  if (analogVal > 800) { //si la capteur de l'humidité retourne une valeur<500
//    Serial.print(" il fait sec");
//    digitalWrite(digitalPin, HIGH);//La pompe à eau arrose la plante
//
//  } else { // sinon
//    Serial.print(" il fait humide");
//    digitalWrite(digitalPin, LOW); //La pompe à eau arrête l'arrosage
//  }
//  Serial.print("\n");
//}




void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.print("Connecting to WiFi network ;");
  Serial.print(ssid);
  Serial.println("'...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting...");
    delay(5000);
  }
  Serial.println("Connected!");
  pinMode(digitalPin, OUTPUT);
  pinMode (3, INPUT); // module signal output connected to Arduino pin 8
  digitalWrite(digitalPin, LOW);
  twilio = new Twilio(account_sid, auth_token);

}



void loop()
{
  val = digitalRead (3);
  if (val == LOW) { // if module detects an obstacle,
    Serial.println("Water me please, im thirsty"); // show message on serial monitor andString response;
    bool success = twilio->send_message(to_number, from_number, message, response);
    if (success) {
      Serial.println("Sent message successfully!");
    } else {
      Serial.println(response);
    }
              
     delay(10000);
} 
}
