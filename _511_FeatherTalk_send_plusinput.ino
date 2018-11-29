/*
  Code to demonstrate sending a signal from an Adafruit Feather
  using a button to detect user input.

  If the button is pressed, an alternating HIGH and LOW signal
  is sent out over the xmitPin every 250ms and the onboard
  LED flashes.

  B. Craft 11.28.18
*/

// variables to keep track of things
const int ledPin = 13;
const int xmitPin = 3;
const int buttonPin = 6;
int state = HIGH;

// the setup function runs once when you press reset or power up the board

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("This board is running _511_FeatherTalk_send_plusinput.");
  // initialize ledPin as an output
  pinMode(ledPin, OUTPUT);
  // initialize xmitPin as an output
  pinMode(xmitPin, OUTPUT);
  // Initialize buttonPin as an output:
  // INPUT_PULLUP is a way of detecting button presses
  // without any additional components in the circuit.
  // To detect a button press, wire up a button between
  // the buttonPin and GND. If the button is pressed
  // the buttonPin will register LOW when you use
  // the digitalRead() function.
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(ledPin, LOW);
}

// the loop function runs over and over again forever

void loop() {
  state = digitalRead(buttonPin);
  if (state == LOW) {
    sendSignal();
  } else {
    awaitingInput();
  }
}

// This function sends an alternating HIGH and LOW signal
// over the xmitPin every 250ms flashes and the onboard LED.

void sendSignal() {
  Serial.println("Sending high signal.");
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(xmitPin, HIGH);   // transmit HIGH signal
  delay(250);                  // wait for a quarter second
  Serial.println("Sending low signal.");
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(xmitPin, LOW);  // transmit LOW signal
  delay(250);
}

void awaitingInput(){
  digitalWrite(ledPin, HIGH);   // turn the LED on
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  
}

