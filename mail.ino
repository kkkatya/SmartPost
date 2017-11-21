int led = 11;
int sensor = A0;
int button = 10;
bool turnOn = false;
bool mailSent = false;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //Serial.println(analogRead(sensor));
  //Serial.print("button ");
  //Serial.println(button);
  if(analogRead(sensor)>0) turnOn = true;
  if(digitalRead(button)==HIGH)turnOn = false;
  if(turnOn){
  	digitalWrite(led, HIGH);
  	if(!mailSent){
  		Particle.publish("mail", PRIVATE);
  		mailSent = true;
  	}
  } 
  else{
  	digitalWrite(led, LOW);
  	mailSent = false;
  } 
}
