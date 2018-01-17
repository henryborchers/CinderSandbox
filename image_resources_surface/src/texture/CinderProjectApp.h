#ifndef CINDER_PROJECT_APP_H
#define CINDER_PROJECT_APP_H
#include "cinder/app/App.h"
#include "cinder/gl/Texture.h"

class CinderProjectApp : public ci::app::App {
public:
    void setup() override;
    void draw() override;

    void keyDown(cinder::app::KeyEvent event) override;

private:
    ci::gl::TextureRef mOriginal;
};

#endif