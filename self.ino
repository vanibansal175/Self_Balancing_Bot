#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Motor pins
int ENA = 5;
int IN1 = 6;
int IN2 = 7;
int ENB = 10;
int IN3 =  8;
int in4 = 9;

// PID constants (tune these!)
float Kp = 25;
float Ki = 1;
float Kd = 0.5;

float setpoint = 0;     // upright position
float input, output;

float error, previous_error = 0;
float integral = 0;

// Timing
unsigned long lastTime;
float elapsedTime;

// MPU values
int16_t ax, ay, az;
int16_t gx, gy, gz;

float angle;

void setup() {
    Serial.begin(9600);
    Wire.begin();
    mpu.intialize();

    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    lastTime = millis();
}


void loop() {
    // Time Calculation
    unsigned long currentTime = millis();
    elapsedTime = (currentTime - lastTime) / 1000.0;
    lastTime = currentTime;

    // Read MPU6050
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // Calculate angle (simplified)
    angle = atan2(ay, az) * 180 / PI;

    input = angle;

    //PID calculations
    error = setpoint - input;
    integral += error * elapsedTime;
    float derivative = (error - previous_error) / elapsedTime;

    output = Kp *  error +  Ki * integral + Kd * derivative;
    previous_error = error;

    // Control motors
    moveMotors(output);

}

void moveMotors(float spped) {
    int pwn = constrain(abs(speed), 0, 255);

    if (spped > 0) {
        //Forward
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, Low);
        digitalWrite(In3, HIGH);
        digitalWrite(IN4, LOW);
    }

    else {
        // Backward
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
    

    analogWrite(ENA, pwm);
    analogWrite(ENB, pwm);
}

