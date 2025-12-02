#include <Servo.h>

#define NUM_SERVOS 6

// Assign pins for servos
int servoPins[NUM_SERVOS] = {5, 6, 7, 8, 9, 10};
Servo servos[NUM_SERVOS];
int currentPos[NUM_SERVOS] = {90, 90, 90, 90, 90, 90}; // start at mid-position
int targetPos[NUM_SERVOS]  = {90, 90, 90, 90, 90, 90};


// Automation Strings
String instructions[9] = {
  "90 90 90 90 90 90\n", // Home
  "98 60 165 90 150 165\n", // Head to duck
  "98 60 165 90 150 90\n", // Grip Duck
  "90 0 90 90 90 90\n", // Go up
  "30 0 90 90 90 90\n", // Turn
  "30 20 140 90 150 90\n", // Go Down
  "30 20 140 90 150 165\n", // Drop Duck
  "30 0 90 90 90 90\n", // Go Up
  "90 90 90 90 90 90\n" // Home
};

String testInstructions[2] = {
  "90 0 90 90 90 90\n",
  "50 30 50 90 90 90\n"
};

int numInstructions = 9;


void setup() {
  Serial.begin(9600);
  Serial.println("6-DOF Robotic Arm Controller Ready");
  
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(currentPos[i]);
  }
  reportPositions();
}

void loop() {
  // Check if new command is available

  int i = 0;
  for (i = 0; i < numInstructions; i++) {
    String input = instructions[i];
    input.trim();
    parseCommand(input);
    moveSmooth();
    reportPositions();
    delay(1000);
  }


}

void parseCommand(String input) {
  input.replace(',', ' ');  // allow comma or space separated values
  int idx = 0;
  while (input.length() > 0 && idx < NUM_SERVOS) {
    int spaceIndex = input.indexOf(' ');
    String value = (spaceIndex == -1) ? input : input.substring(0, spaceIndex);
    value.trim();
    if (value.length() > 0) {
      targetPos[idx] = constrain(value.toInt(), 0, 180);
      idx++;
    }
    if (spaceIndex == -1) break;
    input = input.substring(spaceIndex + 1);
  }
}

void moveSmooth() {
  bool moving = true;
  while (moving) {
    moving = false;
    for (int i = 0; i < NUM_SERVOS; i++) {
      if (currentPos[i] != targetPos[i]) {
        moving = true;
        if (currentPos[i] < targetPos[i]) currentPos[i]++;
        else currentPos[i]--;
        servos[i].write(currentPos[i]);
      }
    }
    delay(15); // controls smoothness (smaller = smoother but slower)
  }
}

void reportPositions() {
  Serial.print("Current positions: ");
  for (int i = 0; i < NUM_SERVOS; i++) {
    Serial.print(currentPos[i]);
    if (i < NUM_SERVOS - 1) Serial.print(' ');
  }
  Serial.println();
}

