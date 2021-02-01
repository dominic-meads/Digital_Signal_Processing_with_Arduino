/*
   A short demo to show how the ADC works. 
   Hook up a jumper from pin A0 to the 3.3V header and see if it works!
   
   The correct conversion should be around 675 in decimal. This is calculated 
   by the ratio of the sample voltage to the reference voltage (5V), multiplied
   by 2^n where n is the resolution of the ADC (10 bits in our case).
   
   Ex. Sample voltage is 3.3V, so 3.3V/5V = 0.66
       0.66 * 2^10 = 675 (approx.)
       
  Author: Dom
  Created: 1/31/2021
*/

int ADC_pin = A0;  // set up the pin to read the ADC
int ADC_data = 0;  // 10 bit quantity that is the result of the analogRead() function

void setup() {
  pinMode(7,OUTPUT);  // this pin will pulse and we can read using a scope how long one sample is taking. 
  Serial.begin(9600);    
}

void loop() {
  digitalWrite(7,HIGH);                  // indicate the conversion has begun
  ADC_data = analogRead(ADC_pin);        // read the data on the ADC, then store it in the ADC_data variable
  digitalWrite(7,LOW);                   // indicate conversion has ended
  Serial.println(ADC_data);        // the correct serial printout should read 675 (3.3/5*1023)
  
  if (ADC_data > 649 && ADC_data < 701)  // give +-5% (51 units) of error to allow for conversion error and noise
  {
    Serial.println("Success!");
  }
  else
  {
    Serial.println("failure");
  }  
}
