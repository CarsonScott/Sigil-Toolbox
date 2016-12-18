#include "Tools.hpp"

PVector::PVector(float x=0, float y=0)
{
    this->x = x;
    this->y = y;
}

Color::Color(float red=1, float green=1, float blue=1, float alpha=1)
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

PVector getMousePosition()
{
    return PVector(float(slGetMouseX()), float(slGetMouseY()));
}

void Color::setForeColor()
{
    slSetForeColor(r, g, b, a);
}

Shape::Shape(){}

void Shape::setPosition(PVector pos)
{
    position = pos;
}

void Shape::setPosition(float x, float y)
{
    position = PVector(x, y);
}

void Shape::setColor(Color c)
{
    color = c;
}

void Shape::setColor(float r, float g, float b, float a)
{
    color = Color(r, g, b, a);
}

PVector Shape::getPosition()
{
    return position;
}

Color Shape::getColor()
{
    return color;
}

CircleShape::CircleShape(float x=0, float y=0, float r=0)
{
    position = PVector(x, y);
    radius = r;
    color = Color();
}

void CircleShape::drawFill()
{
    color.setForeColor();
    slCircleFill(position.x, position.y, radius, radius*2);
}

void CircleShape::drawOutline()
{
    color.setForeColor();
    slCircleOutline(position.x, position.y, radius, radius*2);
}

float CircleShape::getRadius()
{
    return radius;
}

RectangleShape::RectangleShape(float x=0, float y=0, float w=0, float h=0)
{
    position = PVector(x, y);
    size = PVector(w, h);
    color = Color();
}

void RectangleShape::drawFill()
{
    color.setForeColor();
    slRectangleFill(position.x, position.y, size.x, size.y);
}

void RectangleShape::drawOutline()
{
    color.setForeColor();
    slRectangleOutline(position.x, position.y, size.x, size.y);
}

PVector RectangleShape::getSize()
{
    return size;
}
