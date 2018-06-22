#ifndef __SERIALDISPLAYCONFIGURATION_H_INCLUDED__
#define __SERIALDISPLAYCONFIGURATION_H_INCLUDED__


//: std::int8_t
enum class SerialDisplayType {
  ansi_vt100,
  serialMonitor
};

class SerialDisplayConfiguration {

public:

  /*******************************
   * Constructors
   *******************************/
  SerialDisplayConfiguration(SerialDisplayType displayType);

  /*******************************
   * Accessors
   *******************************/
  SerialDisplayType getSerialDisplayType() const;

  /*******************************
   * Actions
   *******************************/

private:
  /*******************************
   * Member variables
   *******************************/
  // Defines the type of output interface we're using
  SerialDisplayType mSerialDisplay;

};

#endif // __SERIALDISPLAYCONFIGURATION_H_INCLUDED__
