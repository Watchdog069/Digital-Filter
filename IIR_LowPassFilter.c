/********************************************
Sketch by Watchdog
IIR Example
Created On: August 22, 2021

Cutoff Frequency of Low Pass Filter 160Hz
Sampling Time T = 100uS
R = 1kohm , C = 1uF
********************************************/
#define DACOUT 25
#define ADCIN 34
void setup() {
  Serial.begin(115200); //debug purposes
  // put your setup code here, to run once:
}

double output=0,outputPrev=0,voltagePrev=0;
void loop() {
  //put your main code here, to run repeatedly:
  
  //Take ADC input
  double adcval = analogRead(ADCIN);
  
  //convert it to Voltage readings
  double voltage = adcval / 4096;
  voltage *= 3.3;   

  //Determine output voltage
  output = 0.047*voltage + 0.047*voltagePrev + 0.9*outputPrev;
  
  //Serial.print(voltage); //debug statements
  //Serial.print(",");
  //Serial.println(output);
  
  //Scale it as per DAC Resolution and output to DAC
  double out = output*256;
  out /= 3.3;
  int DACoutput = (int)out;
  dacWrite(DACOUT,DACoutput);
  
  
  //Assign variables for next iteration
  outputPrev=output;
  voltagePrev=voltage;

  //sample time T
  delayMicroseconds(100); 
}
