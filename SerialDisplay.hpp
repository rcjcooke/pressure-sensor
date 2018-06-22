#ifndef __SERIALDISPLAY_H_INCLUDED__
#define __SERIALDISPLAY_H_INCLUDED__

#include "SerialDisplayConfiguration.hpp"

class SerialDisplay {

public:
  /*******************************
   * Constructors
   *******************************/
  SerialDisplay(SerialDisplayConfiguration* configuration);

protected:
  /*******************************
   * Actions
   *******************************/
  // Clears down the serial display
  void clearSerialDisplay();

private:
  /*******************************
   * Member variables
   *******************************/
  // The display configuration
  SerialDisplayConfiguration* mConfigurationPtr;

};

#endif // __SERIALDISPLAY_H_INCLUDED__