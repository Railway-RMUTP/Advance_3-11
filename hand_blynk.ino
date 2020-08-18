#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// our servo # counter
char auth[] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "xxxxx";
char pass[] = "xxxxxxxxxxxxxx";


void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");
  Wire.begin();
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);  // The int.osc. is closer to 27MHz
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  Blynk.begin(auth, ssid, pass);
//  Serial.begin(9600);
  delay(10);
}





int setdegree(int degrees)
{
  int pulselength = map(degrees, 0, 180, SERVOMIN, SERVOMAX);
  return pulselength;
}


void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0)
{
  int pa = param.asInt();
  pwm.setPWM(0, 0, setdegree(pa));
}

BLYNK_WRITE(V1)
{
  int pa = param.asInt();
  pwm.setPWM(1, 0, setdegree(pa));
}

BLYNK_WRITE(V2)
{
  int pa = param.asInt();
  pwm.setPWM(2, 0, setdegree(pa));
}

BLYNK_WRITE(V3)
{
  int pa = param.asInt();
  pwm.setPWM(3, 0, setdegree(pa));
}

BLYNK_WRITE(V4)
{
  int pa = param.asInt();
  pwm.setPWM(4, 0, setdegree(pa));
}


BLYNK_WRITE(V5)
{
  int pa = param.asInt();
  pwm.setPWM(5, 0, setdegree(pa));
}


 
