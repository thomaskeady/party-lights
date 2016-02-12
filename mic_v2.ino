#define IN A0
#define AVG_SIZE 500
#define TEST 12

int input = 0;
int base[AVG_SIZE];
int baseline = 0;

boolean led = false;




void setup() {
  // put your setup code here, to run once:
  pinMode(IN, INPUT);
  Serial.begin(57600);
  
  pinMode(TEST, OUTPUT);
  
  writeLED();
  
  calculateBaseline();
  Serial.println(baseline);
}

unsigned long timer = 0;
unsigned long Now = 0;
boolean gotHigh = false;
int firstHigh = 0;
int firstLow = 0;

boolean changeState = false;

int reading = 0;

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(IN);
  Now = millis();
  
  // Look for a high
  if (reading > baseline + 20) {
    timer = Now;  // This will cause an ignore if waits too long
    changeState = true;
    firstHigh = reading;
  }
  
  if (changeState) {
    led = !led;
    writeLED();
    changeState = false;
    Serial.print("State change");
    Serial.println(firstHigh);
    delay(100);
  }
  
  
}

void writeLED() {
  if (led) {
      digitalWrite(TEST, HIGH);
  } else {
      digitalWrite(TEST, LOW);
  }
}


void calculateBaseline() {
  int counter = 0;
  while (counter < AVG_SIZE) {
    base[counter++] = analogRead(IN);
  }
  counter--;
  long sum = 0;
  while (counter > 0) {
    sum += base[counter--];
  }
  
  baseline = sum / AVG_SIZE;
}
