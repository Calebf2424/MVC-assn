#include "include/Descriptive.hpp"

void Descriptive::display(Model* weatherModel) {
    double temp = weatherModel->getTemp();
    double airPressure = weatherModel->getAirPressure();
    double humidity = weatherModel->getHumidity();
    double windSpeed = weatherModel->getWindSpeed();

    std::cout << descriptiveTemp(temp) << descriptiveAirPressure(airPressure)
    << descriptiveHumidity(humidity)
    << descriptiveWindSpeed(windSpeed) << std::endl;
}

std::string Descriptive::descriptiveTemp(double temp) {
    if (temp <= FREEZING_TEMP_CUTOFF) {
        return "Freezing, ";
    } else if (temp <= COOL_TEMP_CUTOFF) {
        return "Cool, ";
    } else if (temp <= WARM_TEMP_CUTOFF) {
        return "Warm, ";
    } else {
        return "Hot, ";
    }
}

std::string Descriptive::descriptiveAirPressure(double airPressure) {
    if (airPressure <= LOW_PRESSURE_CUTOFF) {
        return "Low Pressure, ";
    } else if (airPressure <= MODERATE_PRESSURE_CUTOFF) {
        return "Moderate Pressure, ";
    } else {
        return "High Pressure, ";
    }
}

std::string Descriptive::descriptiveHumidity(double humidity) {
    if (humidity <= DRY_HUMIDITY_CUTOFF) {
        return "Dry, ";
    } else if (humidity <= MODERATE_HUMIDITY_CUTOFF) {
        return "Moderate, ";
    } else {
        return "Humid, ";
    }
}

std::string Descriptive::descriptiveWindSpeed(double windSpeed) {
    if (windSpeed < NO_WIND_CUTOFF) {
        return "No Wind.";
    } else if (windSpeed <= LIGHT_WIND_CUTOFF) {
        return "Light Breeze.";
    } else if (windSpeed <= MODERATE_WIND_CUTOFF) {
        return "Moderate Wind.";
    } else if (windSpeed <= STRONG_WIND_CUTOFF) {
        return "Strong Winds.";
    } else {
        return "Dangerous Winds.";
    }
}
