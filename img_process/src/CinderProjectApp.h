#ifndef CINDER_PROJECT_APP_H
#define CINDER_PROJECT_APP_H
#include "cinder/app/App.h"
#include "cinder/params/Params.h"
#include "cinder/gl/Texture.h"

class CinderProjectApp : public ci::app::App {
public:
    void setup() override;
    void update() override;
    void draw() override;
    void keyDown(cinder::app::KeyEvent event) override;

private:
    bool                    mShowOriginal   = false;

    float                   mBrightness     = 0.0f;
    float                   mBrightnessPrev = -0.5f;

    float                   mContrast       = 1.0f;
    float                   mContrastPrev   = 0.0f;

    ci::Surface32f          mImageInput;
    ci::Surface32f          mImageOutput;

    ci::gl::TextureRef      mDisplayImageOut;
    ci::gl::TextureRef      mDisplayImageOriginal;


    ci::params::InterfaceGl mParams;

    float  adjustBrightnessContrast(float value);


    /** Compares 2 values to see if they are within a tolerance
     *
     * @param x First value
     * @param y Second value
     * @param tolerance How close they the two values have to be if they are to be consider equal
     * @return If the two values are consider close enough to be equal
     *
     */
    static bool equal (float x, float y, float tolerance = 0.001f);

};

#endif