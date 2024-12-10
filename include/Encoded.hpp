#ifndef ENCODED_H
#define ENCODED_H
#include <iostream>
#include <string>
#include "include/Model.hpp"
#include "include/constants.hpp"

class Encoded {
 public:
    void display(Model* weatherModel);
    char encodedTemp(double temp);
    char encodedAirPressure(double airPressure);
    char encodedHumidity(double humidity);
    char encodedWindSpeed(double windSpeed);
};

#endif //ENCODED_H
