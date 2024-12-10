#include "include/Labelled.hpp"

void Labelled::display(Model* weatherModel) {
    double temp = weatherModel->getTemp();
    double airPressure = weatherModel->getAirPressure();
    double humidity = weatherModel->getHumidity();
    double windSpeed = weatherModel->getWindSpeed();

    std::cout << labelTemp(temp) << labelAirPressure(airPressure)
    << labelHumidity(humidity) << labelWindSpeed(windSpeed) << std::endl;
}

std::string Labelled::labelTemp(double temp) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1)
    << "Temperature: " << temp << " C, ";
    return oss.str();
}

std::string Labelled::labelAirPressure(double airPressure) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1)
    << "Pressure: " << airPressure << " hPa, ";
    return oss.str();
}

std::string Labelled::labelHumidity(double humidity) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1)
    << "Humidity: " << humidity << "%, ";
    return oss.str();
}

std::string Labelled::labelWindSpeed(double windSpeed) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1)
    << "Windspeed: " << windSpeed << " km/hr.";
    return oss.str();
}
