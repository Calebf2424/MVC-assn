#include "include/Controller.hpp"

Controller::~Controller() {
    if (weatherModel) {
        delete weatherModel;
        weatherModel = nullptr;
    }
    if (labelledView) {
        delete labelledView;
        labelledView = nullptr;
    }
    if (descriptiveView) {
        delete descriptiveView;
        descriptiveView = nullptr;
    }
    if (encodedView) {
        delete encodedView;
        encodedView = nullptr;
    }
}

void Controller::showLabelledView() {
    labelledView->display(weatherModel);
}

void Controller::showDescriptiveView() {
    descriptiveView->display(weatherModel);
}

void Controller::showEncodedView() {
    encodedView->display(weatherModel);
}

void Controller::switchUserView() {
    if (std::getenv("CI")) {
        // Running in CI environment, use default non-interactive behavior
        std::cout << "Detected CI environment. Using"
        << " default view (Labelled)." << std::endl;
        showLabelledView();
        return;
    }
    int view = 0;
    view = getInput();
    clrScreen();
    switchView(view);
}

void Controller::switchView(int view) {
    switch (view) {
        case 1:
            showLabelledView();
            break;
        case 2:
            showDescriptiveView();
            break;
        case 3:
            showEncodedView();
            break;
        default:
            std::cout << "ERROR" << std::endl;
    }
}

int Controller::getInput() {
    int input = 0;
    bool valid = false;
    while (!valid) {
        std::cout << "Choose view model to display: Labelled = 1,"
                  << "Descriptive = 2, Encoded = 3" << std::endl;
        std::cin >> input;
        if (input == 1 || input == 2 || input == 3) {
            valid = true;
        } else {
            std::cout << "Invalid input. Please enter 1-3 " << std::endl;
        }
    }
    return input;
}

void Controller::clrScreen() {
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux/macOS
    #endif
}
