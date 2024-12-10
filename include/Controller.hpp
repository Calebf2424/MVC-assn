#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include <cstdlib>
#include "include/Model.hpp"
#include "include/Descriptive.hpp"
#include "include/Labelled.hpp"
#include "include/Encoded.hpp"

class Controller {
 public:
    Controller(Model* weatherModel, Labelled* labelledView,
    Descriptive* descriptiveView,
    Encoded* encodedView) :  weatherModel(weatherModel),
    labelledView(labelledView), descriptiveView(descriptiveView),
    encodedView(encodedView) {}
    ~Controller();
    void showLabelledView();
    void showDescriptiveView();
    void showEncodedView();
    void switchUserView();
    void switchView(int view);
    int getInput();
    void clrScreen();

 private:
    Model* weatherModel;
    Labelled* labelledView;
    Descriptive* descriptiveView;
    Encoded* encodedView;
};
#endif //CONTROLLER_H
