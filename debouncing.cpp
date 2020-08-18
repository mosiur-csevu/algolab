const int led_green = 12;
const int led_red = 13;
const int button = 2;

bool state = false;


unsigned long last_toggle = 0;
unsigned toggle_delay = 50;



void setup()
{
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green, LOW);
}

void loop()
{
  state = digitalRead(button);
  
  Serial.println(state);
  
  if(state == true && (millis() - last_toggle > toggle_delay) ) {
    toggle();
  }
}


void toggle()
{
  digitalWrite(led_red, !digitalRead(led_red));
  digitalWrite(led_green, !digitalRead(led_green));
  last_toggle = millis();
  
}
