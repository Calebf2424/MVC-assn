#include <iostream>
#include <cctype>
#include "include/Controller.hpp"
#include "include/Descriptive.hpp"
#include "include/Labelled.hpp"
#include "include/Encoded.hpp"
#include "include/Model.hpp"
#include "include/constants.hpp"

int main(int argc, char const *argv[]) {
  Model* weatherModel = new Model();
  weatherModel->readDataFromSensor();
  Labelled* labelledView = new Labelled();
  Descriptive* descriptiveView = new Descriptive();
  Encoded* encodedView = new Encoded();
  Controller* controller = new Controller(weatherModel,
  labelledView, descriptiveView, encodedView);
  bool quit = false;

  while (!quit) {
    controller->switchUserView();
    std::cout << "Close Program? (Y/N)" << std::endl;
    // Check if running in CI environment (to simulate input)
    if (std::getenv("CI")) {
      std::cout << "Detected CI environment."
      << "Simulating input 'Y'." << std::endl;
      break;
    }
    char choice = '\0';
    bool isValid = false;
    while (!isValid) {
      std::cin >> choice;
      choice = std::toupper(static_cast<unsigned char>(choice));
      if (choice == 'Y') {
        isValid = true;
        quit = true;
      } else if (choice == 'N') {
        isValid = true;
      } else {
        std::cout << "Invalid input, please enter Y/N" << std::endl;
      }
    }
  }
  std::cout << "Goodbye!" << std::endl;
  if (controller) {
    delete controller;
    controller = nullptr;
  }

  return 0;
}
