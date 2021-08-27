/********************************
  Sketch by Watchdog
  Moving Average Filter Example
  Created On: August 25, 2021
 ********************************/

#define MPoint 100
#define ADCIN 34
double ADCinput();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  //debug purposes
}

void loop() {
  // put your main code here, to run repeatedly:
  double x[MPoint],finalVal=0.0;
  uint8_t i;

  //take M point inputs in M sized array 
  for(i=0;i<MPoint;i++){
    x[i]=ADCinput();
    delayMicroseconds(100);   //sampling time between each input taken
  }

  //Summation of all inputs and taking average
  for(i=0;i<MPoint;i++){
     finalVal += x[i];
  }
  finalVal /= MPoint;

  //output to serial plotter to visualize
  Serial.print((float)ADCinput());
  Serial.print(",");
  Serial.println(finalVal);
}


//function to take ADC inputs
double ADCinput(void){
 //Take ADC input
  double adcval = analogRead(ADCIN);
  
  //convert it to Voltage readings
  double voltage = adcval / 4096;
  voltage *= 3.3; 

  return voltage;
}
