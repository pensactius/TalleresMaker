int rightA = 10;
int rightB = 9;
int leftA = 5;
int leftB = 6;
int vel = 255;
void setup() {
pinMode (rightA, OUTPUT);
pinMode (rightB, OUTPUT);
pinMode (leftA, OUTPUT);
pinMode (leftB, OUTPUT);

}

void loop() {
analogWrite (rightA, 255);
analogWrite (rightB, 0);
analogWrite (leftA, 255);
analogWrite (leftB, 0);


}
