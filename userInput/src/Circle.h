//
// Created by Borchers, Henry Samuel on 1/13/18.
//

#ifndef HELLOCINDER_CIRCLE_H
#define HELLOCINDER_CIRCLE_H
#include "cinder/app/RendererGl.h"

using namespace ci;
class Circle {
public:

    Circle(const vec2 &m_center, float m_radius, const Color &m_fillColor);

    void draw();

private:
    vec2 m_center;
    float m_radius;
    Color m_fillColor;
};


#endif //HELLOCINDER_CIRCLE_H
