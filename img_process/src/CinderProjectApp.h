#ifndef CINDER_PROJECT_APP_H
#define CINDER_PROJECT_APP_H
#include "cinder/app/App.h"

class CinderProjectApp : public ci::app::App {
public:
    void setup() override;
    void mouseDown( ci::app::MouseEvent event ) override;
    void update() override;
    void draw() override;
};

#endif