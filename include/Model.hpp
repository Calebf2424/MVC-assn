#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <sstream>
#include "include/WeatherSensor.hpp"

class Model {
 public:
    Model() : sensor(new WeatherSensor()) {}
    ~Model();
    void readDataFromString(const std::string& data);
    void readDataFromSensor();
    double getTemp() const { return _tempInCelsius; }
    double getAirPressure() const { return _airPressureInHectoPascals; }
    double getHumidity() const { return _percentHumidity; }
    double getWindSpeed() const { return _windSpeedInKMH; }

 private:
    WeatherSensor* sensor;
    double _tempInCelsius;
    double _airPressureInHectoPascals;
    double _percentHumidity;
    double _windSpeedInKMH;
};

#endif //MODEL_H
