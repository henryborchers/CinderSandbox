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
#ifdef EDIT_SURFACE
    ci::gl::TextureRef mCurrent;
    ci::gl::TextureRef mOriginal;
    ci::gl::TextureRef mOnlyRed;
    ci::gl::TextureRef mOnlyGreen;
    ci::gl::TextureRef mOnlyBlue;
#endif // EDIT_SURFACE

#ifdef EDIT_TEXTURE
    enum class ShowMode {
        Complete,
        Red,
        Green,
        Blue
    };

    ShowMode mShowMode;

    ci::gl::TextureRef mTexture;
#endif // EDIT_TEXTURE
};

#endif // CINDER_PROJECT_APP_H