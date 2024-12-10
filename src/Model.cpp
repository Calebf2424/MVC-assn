#include "include/Model.hpp"

Model::~Model() {
    if (sensor) {
        delete sensor;
        sensor = nullptr;
    }
}
//function to read data from input text file and store the results in variables
void Model::readDataFromString(const std::string& data) {
    std::stringstream ss(data);
    std::string token;
    // Extract each value separated by '|'
    std::getline(ss, token, '|');
    _tempInCelsius = std::stod(token);
    std::getline(ss, token, '|');
    _airPressureInHectoPascals = std::stod(token);
    std::getline(ss, token, '|');
    _percentHumidity = std::stod(token);
    std::getline(ss, token, '|');
    _windSpeedInKMH = std::stod(token);
    std::cout << "Data loaded from string" << std::endl;
}

void Model::readDataFromSensor() {
    std::string sensorData = sensor->getReading();
    readDataFromString(sensorData);
}
