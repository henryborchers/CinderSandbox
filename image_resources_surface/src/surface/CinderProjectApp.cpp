//
// Created by Borchers, Henry Samuel on 1/13/18.
//

#include "cinder/gl/gl.h"
#include "CinderProjectApp.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

void CinderProjectApp::setup() {

#ifdef EDIT_SURFACE
    Surface image = loadImage(loadResource(RES_DUMMY));
    mOriginal = gl::Texture::create(image);
    mCurrent = mOriginal;
    Surface redImage = image.clone();
    Surface greenImage = image.clone();
    Surface blueImage = image.clone();

    Surface::Iter redIter = redImage.getIter();
    while (redIter.line()) {
        while (redIter.pixel()) {
            redIter.g() = 0;
            redIter.b() = 0;
        }
    }
    mOnlyRed = gl::Texture::create(redImage);

    Surface::Iter greenIter = greenImage.getIter();
    while (greenIter.line()) {
        while (greenIter.pixel()) {
            greenIter.r() = 0;
            greenIter.b() = 0;
        }
    }
    mOnlyGreen = gl::Texture::create(greenImage);

    Surface::Iter blueIter = blueImage.getIter();
    while (blueIter.line()) {
        while (blueIter.pixel()) {
            blueIter.r() = 0;
            blueIter.g() = 0;
        }
    }
    mOnlyBlue = gl::Texture::create(blueImage);
#elif EDIT_TEXTURE
    mTexture = gl::Texture::create(loadImage(loadResource(RES_DUMMY)));
    mShowMode = ShowMode::Complete;

#endif
}

void CinderProjectApp::draw() {
    gl::clear(Color(0, 0, 0));

#ifdef EDIT_SURFACE
    gl::draw(mCurrent, getWindowBounds());

#elif EDIT_TEXTURE
    switch (mShowMode) {

        case ShowMode::Complete:
            gl::color(1, 1, 1);
            break;
        case ShowMode::Red:
            gl::color(1, 0, 0);
            break;
        case ShowMode::Green:
            gl::color(0, 1, 0);
            break;
        case ShowMode::Blue:
            gl::color(0, 0, 1);
            break;
    }
    gl::draw(mTexture, getWindowBounds());
#endif

}

void CinderProjectApp::keyDown(KeyEvent event) {
#ifdef EDIT_SURFACE
    switch (event.getChar()) {
        case 'a' :
            cout << "All colors\n";
            mCurrent = mOriginal;
            return;

        case 'b' :
            cout << "Blue only\n";
            mCurrent = mOnlyBlue;
            return;

        case 'r' :
            cout << "Red only\n";
            mCurrent = mOnlyRed;
            return;

        case 'g' :
            cout << "Green only\n";
            mCurrent = mOnlyGreen;
            return;

        default:
            break;
    }

#elif EDIT_TEXTURE
    switch (event.getChar()) {
        case 'r':
            mShowMode = ShowMode::Red;
            break;
        case 'g':
            mShowMode = ShowMode::Green;
            break;
        case 'b':
            mShowMode = ShowMode::Blue;
            break;
        case 'a':
            mShowMode = ShowMode::Complete;
            break;
        default:
            break;
    }
#endif
}


