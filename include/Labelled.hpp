#ifndef LABELLED_H
#define LABELLED_H
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "include/Model.hpp"

class Labelled {
 public:
    void display(Model* weatherModel);
    std::string labelTemp(double temp);
    std::string labelAirPressure(double airPressure);
    std::string labelHumidity(double humidity);
    std::string labelWindSpeed(double windSpeed);
};

#endif //LABELLED_H
