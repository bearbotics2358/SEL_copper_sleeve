// keyboard_test

#define TOP_LINEAR_ACTUATOR_A A4
#define TOP_LINEAR_ACTUATOR_B A3

#define BOTTOM_LINEAR_ACTUATOR_A A2
#define BOTTOM_LINEAR_ACTUATOR_B A1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial) {
    delay(10);
  }

  Serial.println("keyboard test\n");

  pinMode(TOP_LINEAR_ACTUATOR_A, OUTPUT);
  pinMode(TOP_LINEAR_ACTUATOR_B, OUTPUT);

  digitalWrite(TOP_LINEAR_ACTUATOR_A, 0);  
  digitalWrite(TOP_LINEAR_ACTUATOR_B, 0);

  pinMode(BOTTOM_LINEAR_ACTUATOR_A, OUTPUT);
  pinMode(BOTTOM_LINEAR_ACTUATOR_B, OUTPUT);

  digitalWrite(BOTTOM_LINEAR_ACTUATOR_A, 0);  
  digitalWrite(BOTTOM_LINEAR_ACTUATOR_B, 0);    
}

void loop() {
  char c;
  
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    c = Serial.read();
    Serial.print("Got a character: ");
    Serial.println(c);    

    switch(c) {
      case '3':
        Serial.println("Top Linear Actuator extend");
        digitalWrite(TOP_LINEAR_ACTUATOR_A, 1);
        digitalWrite(TOP_LINEAR_ACTUATOR_B, 0);
        break;

      case '4':
        Serial.println("Top Linear Actuator retract");
        digitalWrite(TOP_LINEAR_ACTUATOR_A, 0);
        digitalWrite(TOP_LINEAR_ACTUATOR_B, 1);
        break;

      case '5':
        Serial.println("Bottom Linear Actuator extend");
        digitalWrite(BOTTOM_LINEAR_ACTUATOR_A, 1);
        digitalWrite(BOTTOM_LINEAR_ACTUATOR_B, 0);
        break;

      case '6':
        Serial.println("Bottom Linear Actuator retract");
        digitalWrite(BOTTOM_LINEAR_ACTUATOR_A, 0);
        digitalWrite(BOTTOM_LINEAR_ACTUATOR_B, 1);
        break;
        
      default:
        Serial.print("unknown command received: *");
        Serial.print(c);
        Serial.println("*");
        break;
        
    }
  }
}
