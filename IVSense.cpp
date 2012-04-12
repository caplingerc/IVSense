/*

  Christopher S. Caplinger
  2012

*/

#include "IVSense.h"

IVSense::IVSense(int i_pin, int v_pin, float v_scale)
{
  _ipin = i_pin;
  _vpin = v_pin;
  _vscale = v_scale;
}

void IVSense::readData()
{
  // with 10k & 1k resistor, this value is Vout/(gain*Rsense).
  // With Rsense of 0.1Ohms, this is 11*0.1 = 1.1. Adjusted due to tolerance issues with resistors.
  current =  ( ( analogRead(_ipin) / 1023.0 ) * 5.0 )/1.15 ; 

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
