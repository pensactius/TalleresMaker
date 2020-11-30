int pinVT=8;
int pinA=2;
int pinB=3;
int pinC=11;
int pinD=12;
int rightA = 10; 
int rightB = 9; 
int leftA = 5; 
int leftB = 6; 
int vel = 0; // Velocidad de los motores (0-255)

void setup() 
{
  //PUERTO DE COMUNICACIÓN SERIE
  Serial.begin (9600);
  //CONEXIÓN DEL MANDO RF
  pinMode(pinVT, INPUT);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinC, INPUT);
  pinMode(pinD, INPUT);
  //CONEXIÓN MOTOR
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  //MOTOR PARADO
  analogWrite(rightA, 0); 
  analogWrite(rightB, 0); 
  analogWrite(leftA, 0); 
  analogWrite(leftB, 0);   
}

void loop() 
{ 
  if (digitalRead(pinVT) )  // Si hay dato valido
      {  
        Serial.print("Data available \t");
        if (digitalRead(pinA)){ //avanzar
            Serial.print( "Pressed button A"); 
            vel=vel+10;
              if (vel<80){
                vel=80;      
              }
              if (vel>255){
                vel=255;
              }
            analogWrite(rightA, 0); 
            analogWrite(rightB, vel); 
            analogWrite(leftA, 0); 
            analogWrite(leftB, vel); 
            delay(50);
        }
        
        if (digitalRead(pinB)){  //frenar
            Serial.print( "Pressed button B");
            vel=vel-10;
              if (vel<80){
                vel=0;      
              }
            analogWrite(rightA, 0); 
            analogWrite(rightB, vel); 
            analogWrite(leftA, 0); 
            analogWrite(leftB, vel); 
            delay(50);
        }
        if (digitalRead(pinC)){  //girar izquierda           
            Serial.print( "Pressed button C");
            analogWrite(rightA, 0); 
            analogWrite(rightB, 255); 
            analogWrite(leftA, 0); 
            analogWrite(leftB, 0); 
        }
        if (digitalRead(pinD)){  //girar derecha
            Serial.print( "Pressed button D");
            analogWrite(rightA, 0); 
            analogWrite(rightB, 0); 
            analogWrite(leftA, 0); 
            analogWrite(leftB, 255); 
        }

        Serial.println("\t");
      }
  
  
}
