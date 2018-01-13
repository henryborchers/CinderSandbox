//
// Created by Borchers, Henry Samuel on 1/13/18.
//

#include "cinder/gl/gl.h"
#include "Circle.h"

Circle::Circle(const vec2 &m_center, float m_radius, const Color &m_fillColor) :
        m_center(m_center),
        m_radius(m_radius),
        m_fillColor(m_fillColor) {}

void Circle::draw() {
    gl::color(m_fillColor);
    gl::drawSolidCircle(m_center, m_radius);
}
