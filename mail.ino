void setup() {

}

void loop() {
    Particle.publish("mail", PRIVATE);
    delay(1000000);
}