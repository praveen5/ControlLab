int PWM_out1 = 2;
int PWM_out2 = 3;
int err = 0, POT = 0, ref = 0;

void setup()  { 
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    POT = analogRead(A0);
    if(POT>=512)
       {
        ref = POT - 512;
       }
     else
     {
        ref = POT + 512;
      }
     
     err = ref-POT;
    pinMode(PWM_out1, OUTPUT);
    pinMode(PWM_out2, OUTPUT);
    
} 

void loop()  { 
     if(err>=0)
     { 
     analogWrite(PWM_out1, err/2);
     analogWrite(PWM_out2, 0);
      }
     else{
     analogWrite(PWM_out2, -err);
     analogWrite(PWM_out1, 0);  
    }
    delay(1);
    POT = analogRead(A0);  
    err = ref - POT;
    Serial.println(POT);    
}


