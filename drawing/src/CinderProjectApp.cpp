#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const Color white(1.00f, 1.00f, 1.00f);
const Color red(1.00f, 0.00f, 0.00f);
const Color black(0.00f, 0.00f, 0.00f);
const Color green(0.00f, 0.50f, 0.27f);

class CinderProjectApp : public App {
private:
    void draw_x() const;

public:
    void setup() override;

    void mouseDown(MouseEvent event) override;

    void update() override;

    void draw() override;


    void draw_circle();

    void draw_ellipses();

    void draw_rectangle();
};


void CinderProjectApp::setup() {
}

void CinderProjectApp::mouseDown(MouseEvent event) {
}

void CinderProjectApp::update() {
}

void CinderProjectApp::draw() {
    gl::clear(white);
//    draw_x();
//    this->draw_circle();
//    this->draw_ellipses();
    this->draw_rectangle();

}

void CinderProjectApp::draw_x() const {
    const int w = getWindowWidth();
    const int h = getWindowHeight();

    gl::color(Color(1, 1, 0));  // set color to yellow
    gl::lineWidth(5);
    gl::drawLine(vec2(0, 0), vec2(w, h));

    gl::color(Color(0, 0, 1));  // set color to blue
    gl::lineWidth(5);
    gl::drawLine(vec2(w, 0), vec2(0, h));
}

void CinderProjectApp::draw_circle() {


    gl::color(red);
    gl::drawSolidCircle(getWindowCenter(), getWindowWidth() / 5.0f);

    gl::color(black);
    gl::lineWidth(100.0f);
    gl::drawStrokedCircle(getWindowCenter(), getWindowWidth() / 5.0f, 2.0f, -1);


}

void CinderProjectApp::draw_ellipses() {
    gl::color(red);
    gl::drawSolidEllipse(getWindowCenter(), getWindowWidth() / 3.0f, getWindowHeight() / 3.0f, -1);
}

void CinderProjectApp::draw_rectangle() {


//    left bar
    gl::color(green);
    gl::drawSolidRect(Rectf(0, 0, getWindowWidth() / 3.0f, getWindowHeight()));

//    Right bar
    gl::color(red);
    gl::drawSolidRect(Rectf(2.0f * getWindowWidth() / 3.0f, 0, getWindowWidth(), getWindowHeight()));

//    Draw Oval
    gl::color(black);


    auto oval = Rectf(1.0f * getWindowWidth() / 3.0f, getWindowHeight() / 3.0f, 2.0f * getWindowWidth() / 3.0f, getWindowHeight() / 1.5f);
//    auto oval = Rectf(getWindowWidth() / 3.0f, getWindowHeight() / 3.0f, getWindowWidth() / 1.5f, getWindowHeight() / 1.5f);
//    gl::drawSolidRoundedRect(oval, 0.0f);
    gl::drawSolidRoundedRect(oval, getWindowHeight() / 15.0f);
}

CINDER_APP(CinderProjectApp, RendererGl)
