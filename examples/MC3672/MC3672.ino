#include <Wire.h>
#include <MC3672.h>

MC3672 MC3672_acc = MC3672();

void setup()
{
  	Serial.begin(115200);
	MC3672_acc.start();
  	Serial.println("mCube Accelerometer MC3672:");
  	checkRange();
  	checkResolution();
  	checkSamplingRate();
  	Serial.println();
}

void checkRange()
{
	switch(MC3672_acc.GetRangeCtrl())
	{
		case MC3672_RANGE_16G:            		Serial.println("Range: +/- 16 g"); break;
		case MC3672_RANGE_12G:            		Serial.println("Range: +/- 12 g"); break;
		case MC3672_RANGE_8G:             		Serial.println("Range: +/- 8 g"); break;
		case MC3672_RANGE_4G:             		Serial.println("Range: +/- 4 g"); break;
		case MC3672_RANGE_2G:             		Serial.println("Range: +/- 2 g"); break;
		default:                          		Serial.println("Range: +/- 8 g"); break;
	}
}

void checkResolution()
{
	switch(MC3672_acc.GetResolutionCtrl())
	{
		case MC3672_RESOLUTION_6BIT:            Serial.println("Resolution: 6bit"); break;
		case MC3672_RESOLUTION_7BIT:            Serial.println("Resolution: 7bit"); break;
		case MC3672_RESOLUTION_8BIT:            Serial.println("Resolution: 8bit"); break;
		case MC3672_RESOLUTION_10BIT:           Serial.println("Resolution: 10bit"); break;
		case MC3672_RESOLUTION_14BIT:           Serial.println("Resolution: 14bit"); break;
		case MC3672_RESOLUTION_12BIT:           Serial.println("Resolution: 12bit"); break;
		default:                                Serial.println("Resolution: 14bit"); break;
	}
}

void checkSamplingRate()
{
	Serial.println("Low Power Mode"); 
	switch(MC3672_acc.GetCWakeSampleRate())
	{
		MC3672_CWAKE_SR_DEFAULT_50Hz:			Serial.println("Output Sampling Rate: 54 Hz"); break;
		MC3672_CWAKE_SR_14Hz:               	Serial.println("Output Sampling Rate: 14 Hz"); break;
		MC3672_CWAKE_SR_28Hz:        			Serial.println("Output Sampling Rate: 28 Hz"); break;
		MC3672_CWAKE_SR_54Hz:                   Serial.println("Output Sampling Rate: 54 Hz"); break;
		MC3672_CWAKE_SR_105Hz:                  Serial.println("Output Sampling Rate: 105 Hz"); break;
		MC3672_CWAKE_SR_210Hz:                  Serial.println("Output Sampling Rate: 210 Hz"); break;
		MC3672_CWAKE_SR_400Hz:                  Serial.println("Output Sampling Rate: 400 Hz"); break;
		MC3672_CWAKE_SR_600Hz:                  Serial.println("Output Sampling Rate: 600 Hz"); break;
		default:                                Serial.println("Output Sampling Rate: 54 Hz"); break;
	}
}

void loop()
{
	// Read the raw sensor data count
	MC3672_acc_t rawAccel = MC3672_acc.readRawAccel();
	delay(10);
	Serial.print("X:\t"); Serial.print(rawAccel.XAxis); Serial.print("\t");
	Serial.print("Y:\t"); Serial.print(rawAccel.YAxis); Serial.print("\t");
	Serial.print("Z:\t"); Serial.print(rawAccel.ZAxis); Serial.print("\t");
	Serial.println("counts");

	// Display the results (acceleration is measured in m/s^2)
	Serial.print("X: \t"); Serial.print(rawAccel.XAxis_g); Serial.print("\t");
	Serial.print("Y: \t"); Serial.print(rawAccel.YAxis_g); Serial.print("\t");
	Serial.print("Z: \t"); Serial.print(rawAccel.ZAxis_g); Serial.print("\t");
	Serial.println("m/s^2");

  Serial.println("--------------------------------------------------------------");
  delay(1000);
}
