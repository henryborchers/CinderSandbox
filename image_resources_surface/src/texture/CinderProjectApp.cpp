//
// Created by Borchers, Henry Samuel on 1/13/18.
//

#include "cinder/gl/gl.h"
#include "CinderProjectApp.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#ifdef resources
#include "Resources.h"
#endif

//#define RESOURCE_PATH "../Resources"

using namespace ci;
using namespace ci::app;
using namespace std;

void CinderProjectApp::setup() {

#ifdef assets
    std::cout << "Loading assets\n";
    addAssetDirectory(RESOURCE_PATH);
    mOriginal = gl::Texture::create(loadImage(loadAsset("dummy.png")));
#endif
#ifdef resources
    std::cout << "Loading resources\n";
    mOriginal = gl::Texture::create(loadImage(loadResource(RES_DUMMY)));

#endif

}


void CinderProjectApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    gl::draw(mOriginal, getWindowBounds());
}