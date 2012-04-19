/*

  Christopher S. Caplinger
  2012

*/

#include "IVSense.h"

IVSense::IVSense(int i_pin, int v_pin, float v_scale)
{
  _ipin = i_pin;
  _vpin = v_pin;
  _vscale = v_scale; // v_scale is used if sensing values larger than 5V on Arduino pins
                     //  Use v_scale = 2 for a voltage divider with R1 == R2
                     // Use v_scale = 1 if a divider is not being used
}

void IVSense::readData()
{
  // with 10k & 1k resistor, this value is Vout/(gain*Rsense).
  // With Rsense of 0.1Ohms, this is 11*0.1 = 1.1. The 2.5 is subtracted from the analog
  // voltage for bi-directional operation
  current = ( ( ( analogRead(_ipin) / 1023.0 ) * 5.0 ) - 2.5 ) / 1.1 ; 

  // max arduino resolution of 1023.0 divided by _vscale from resistor divider scales value
  // divide andlog read by this number, then multiply by reference voltage.
  voltage = ( analogRead(_vpin) / (1023.0 / _vscale) ) * 5.0;
}

float IVSense::getCurrent()
{ 
  return current;
}

float IVSense::getVoltage()
{ 
  return voltage;
}
