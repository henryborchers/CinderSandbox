//
// Created by Borchers, Henry Samuel on 1/13/18.
//

#include "cinder/gl/gl.h"
#include "CinderProjectApp.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

void CinderProjectApp::setup() {
//    Load Parameter interface
    mParams = params::InterfaceGl("Adjustment params", ivec2(200, 20));
    mParams.addParam("Brightness", &mBrightness, "min=-0.5 max=0.5 step=0.01 keyIncr== keyDecr=-");
    mParams.addParam("Contrast", &mContrast, "min=-0 max=10 step=0.01");

//    Load the image
    mImageInput = loadImage(loadResource(RES_DUMMY));
    mImageOutput = Surface32f(mImageInput.getWidth(), mImageInput.getHeight(), false);

    mDisplayImageOriginal = gl::Texture::create(mImageInput);
    equal(1.0f, 2.0f , 3.0);
//    gl::TextureRef texture = gl::Texture2d::create(loadImage(loadResource(RES_DUMMY)));

//    gl::Texture texture = loadImage(loadResource(RES_DUMMY));


}


void CinderProjectApp::update() {
    // If no changes, there is no reason to recalculate everything
    if (equal(mBrightness, mBrightnessPrev) && equal(mContrast, mContrastPrev)){
        return;
    }

    Surface32f::ConstIter pixelInIter = mImageInput.getIter();
    Surface32f::Iter pixelOutIter = mImageOutput.getIter();

    while (pixelInIter.line()){
        pixelOutIter.line();;
        while(pixelInIter.pixel()){
            pixelOutIter.pixel();
            pixelOutIter.r() = adjustBrightnessContrast(pixelInIter.r());
            pixelOutIter.g() = adjustBrightnessContrast(pixelInIter.g());
            pixelOutIter.b() = adjustBrightnessContrast(pixelInIter.b());
        }
    }

    // Update the last values so that a new calculation doesn't need to done if nothing has changed
    mBrightnessPrev = mBrightness;
    mContrastPrev = mContrast;
    mDisplayImageOut = gl::Texture::create(mImageOutput);
}

void CinderProjectApp::draw() {
    gl::clear(Color(0, 0, 0));
    if (mShowOriginal){
        gl::draw(mDisplayImageOriginal, getWindowBounds());

    } else{
        gl::draw(mDisplayImageOut, getWindowBounds());

        mParams.draw();
    }
}

float CinderProjectApp::adjustBrightnessContrast(float value) {
    return (value - 0.5f) * mContrast + 0.5f + mBrightness;
}

void CinderProjectApp::keyDown(KeyEvent event) {
    if (event.getChar() == ' ') {
        mShowOriginal = !mShowOriginal;
    }
}

bool CinderProjectApp::equal(float x, float y, float tolerance) {
//bool CinderProjectApp::equal(float x, float y, float tolerance) {
    if (fabs(x - y) < tolerance) {
        return true;
    } else {
        return false;
    }
}
