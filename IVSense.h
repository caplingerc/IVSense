#ifndef IVSense_h
#define IVSense_h

/*


*/

#include "Arduino.h"
  
class IVSense
{
  public:
    IVSense(int i_pin, int v_pin, float v_scale);
    void readData(void);
    float getCurrent(void);
    float getVoltage(void);

  private:
    float voltage;
    float current;
    float _vscale;
    int _ipin;
    int _vpin;
};
#endif