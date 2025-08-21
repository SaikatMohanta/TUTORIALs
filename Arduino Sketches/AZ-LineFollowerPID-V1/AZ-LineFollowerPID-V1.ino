//Here's a sketch for an Arduino-based line follower robot using an L293D motor driver with enable pins (EN1 and EN2), 3x IR digital line 
//sensors, and PID control. This code does not rely on pre-made libraries for PID control.

// Motor pin definitions
#define MOTOR_A1 7
#define MOTOR_A2 6
#define MOTOR_B1 10
#define MOTOR_B2 11
#define EN1 5
#define EN2 9

// Line sensor pin definitions
#define SENSOR1 2
#define SENSOR2 3
#define SENSOR3 4

// PID parameters
double kp = 10;   // Proportional gain
double ki = 0.045;   // Integral gain
double kd = 0.1;   // Derivative gain

// Setpoint and sensor variables
int setpoint = 2;  // Middle sensor as setpoint
int sensor1, sensor2, sensor3;

// PID variables
double input, output;
double previous_error = 0;
double integral = 0;

// PID constants
double dt = 0.01;  // Time step (seconds)
double max_output = 255;  // Maximum output value
double min_output = -255;  // Minimum output value

void setup() {
  // Motor pins as output
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  
  // Enable pins as output
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);

  // Initialize line sensors
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(SENSOR3, INPUT);
}

void loop() {
  // Read line sensor values
  sensor1 = digitalRead(SENSOR1);
  sensor2 = digitalRead(SENSOR2);
  sensor3 = digitalRead(SENSOR3);

  // Calculate the error
  double error = setpoint - sensor2;
  
  // Calculate the integral term
  integral += error * dt;
  
  // Calculate the derivative term
  double derivative = (error - previous_error) / dt;
  
  // Calculate the PID output
  output = kp * error + ki * integral + kd * derivative;
  
  // Restrict the PID output within limits
  if (output > max_output) {
    output = max_output;
  } else if (output < min_output) {
    output = min_output;
  }
  
  // Update the previous error
  previous_error = error;

  // Adjust motor speeds based on PID output
  int motorSpeedA = constrain(output, -255, 255);
  int motorSpeedB = constrain(-output, -255, 255);

  // Apply motor speeds
  analogWrite(EN1, abs(motorSpeedA));
  analogWrite(EN2, abs(motorSpeedB));

  if (motorSpeedA >= 0) {
    digitalWrite(MOTOR_A1, HIGH);
    digitalWrite(MOTOR_A2, LOW);
  } else {
    digitalWrite(MOTOR_A1, LOW);
    digitalWrite(MOTOR_A2, HIGH);
  }

  if (motorSpeedB >= 0) {
    digitalWrite(MOTOR_B1, HIGH);
    digitalWrite(MOTOR_B2, LOW);
  } else {
    digitalWrite(MOTOR_B1, LOW);
    digitalWrite(MOTOR_B2, HIGH);
  }
}


//In this sketch, we calculate the PID terms (proportional, integral, and derivative) manually without using pre-made libraries. 
//The dt variable represents the time step between iterations, 
//and max_output and min_output define the limits for the PID output.

//Please note that the code assumes you have connected the motor driver's enable pins (EN1 and EN2) to digital pins 5 and 9 of the Arduino, 
//respectively. Adjust these pin assignments if necessary.

//Make sure to review and adjust the PID gains (kp, ki, kd) according to your robot's behavior. Also, ensure that the L293D motor driver, 
//line sensors, and other hardware connections are set up correctly