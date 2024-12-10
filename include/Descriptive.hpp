#ifndef DESCRIPTIVE_H
#define DESCRIPTIVE_H
#include <string>
#include <iostream>
#include "include/Model.hpp"
#include "include/constants.hpp"

class Descriptive {
 public:
    void display(Model* weatherModel);
    std::string descriptiveTemp(double temp);
    std::string descriptiveAirPressure(double airPressure);
    std::string descriptiveHumidity(double humidity);
    std::string descriptiveWindSpeed(double windSpeed);
};

#endif //DESCRIPTIVE_H
