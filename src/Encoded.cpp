#include "include/Encoded.hpp"

void Encoded::display(Model* weatherModel) {
    double temp = weatherModel->getTemp();
    double airPressure = weatherModel->getAirPressure();
    double humidity = weatherModel->getHumidity();
    double windSpeed = weatherModel->getWindSpeed();

    std::cout << encodedTemp(temp) << encodedAirPressure(airPressure)
    << encodedHumidity(humidity) << encodedWindSpeed(windSpeed) << std::endl;
}

char Encoded::encodedTemp(double temp) {
    if (temp <= FREEZING_TEMP_CUTOFF) {
        return 'F';
    } else if (temp <= COOL_TEMP_CUTOFF) {
        return 'C';
    } else if (temp <= WARM_TEMP_CUTOFF) {
        return 'W';
    } else {
        return 'H';
    }
}

char Encoded::encodedAirPressure(double airPressure) {
    if (airPressure <= LOW_PRESSURE_CUTOFF) {
        return 'L';
    } else if (airPressure <= MODERATE_PRESSURE_CUTOFF) {
        return 'M';
    } else {
        return 'H';
    }
}

char Encoded::encodedHumidity(double humidity) {
    if (humidity <= DRY_HUMIDITY_CUTOFF) {
        return 'D';
    } else if (humidity <= MODERATE_HUMIDITY_CUTOFF) {
        return 'M';
    } else {
        return 'H';
    }
}

char Encoded::encodedWindSpeed(double windSpeed) {
    if (windSpeed < NO_WIND_CUTOFF) {
        return 'N';
    } else if (windSpeed <= LIGHT_WIND_CUTOFF) {
        return 'L';
    } else if (windSpeed <= MODERATE_WIND_CUTOFF) {
        return 'M';
    } else if (windSpeed <= STRONG_WIND_CUTOFF) {
        return 'S';
    } else {
        return 'D';
    }
}
