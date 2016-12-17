#ifndef TOOLS_HPP_INCLUDED
#define TOOLS_HPP_INCLUDED

#include "sl.h"

struct PVector
{
    float x;
    float y;
    PVector(float, float);
};

struct Color
{
    float r;
    float g;
    float b;
    float a;
    Color(float, float, float, float);
    void setForeColor();
};

class Shape
{
protected:
    PVector position;
    Color color;
public:
    Shape();
    void setPosition(PVector);
    void setPosition(float, float);
    void setColor(Color);
    void setColor(float, float, float, float);
    PVector getPosition();
    Color getColor();
};

class CircleShape: public Shape
{
    float radius;
public:
    CircleShape(float, float, float);
    void drawFill();
    void drawOutline();
    float getRadius();
};

class RectangleShape: public Shape
{
    PVector size;
public:
    RectangleShape(float, float, float, float);
    void drawFill();
    void drawOutline();
    PVector getSize();
};

#endif // TOOLS_HPP_INCLUDED
