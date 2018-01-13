#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>


using namespace ci;
using namespace ci::app;
using namespace std;

#include "Circle.h"


class CinderProjectApp : public App {
public:
    void setup() override;

    void mouseDown(MouseEvent event) override;

    void update() override;

    void draw() override;

    void keyDown(KeyEvent event) override;

private:
    std::vector<Circle> circles;

    Circle generateCircle(const vec2 &location) const;
};

void CinderProjectApp::keyDown(KeyEvent event) {
    char key = event.getChar();
    if (key == 'c') {
        circles.clear();
    }
}

void CinderProjectApp::setup() {
    Rand::randomize();
}

void CinderProjectApp::mouseDown(MouseEvent event) {
    if (event.isLeft()) {
        circles.push_back(generateCircle(event.getPos()));
        return;

    }
    if (event.isRight()) {
        if(!circles.empty()){
            circles.pop_back();
            return;
        }
    };
}

Circle CinderProjectApp::generateCircle(const vec2 &location) const {
    float radius = Rand::randFloat(10.0f, 50.0f);

    Color my_color(CM_HSV, Rand::randFloat(0.0f, 1.0f), 1, 1);
    return Circle{location, radius, my_color };
}

void CinderProjectApp::update() {
}

void CinderProjectApp::draw() {
    gl::clear(Color(0, 0, 0));
    for (auto &circle: circles) {
        circle.draw();
    }
}

CINDER_APP(CinderProjectApp, RendererGl)
