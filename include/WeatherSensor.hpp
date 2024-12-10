#ifndef WEATHERSENSOR_H_INCLUDED
#define WEATHERSENSOR_H_INCLUDED

#include <string>
#include <vector>

class WeatherSensor {
 public:
  WeatherSensor();
  /*
   * Provides a weather reading in the format:
   *
   * <Temperature>|<Air Pressure>|<Humidity>|<WindSpeed>
   *
   * where the following units are used:
   *     - Temperature: degrees Celsius
   *     - Air Pressure: hectoPascals
   *     - Humidity: Relative percentage
   *     - Windspeed: kilometres/hour
   *
   * @return Returns an empty string when there are no more readings.
   */
  std::string getReading();
};

#endif
