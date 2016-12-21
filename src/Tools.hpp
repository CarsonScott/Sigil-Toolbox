#ifndef TOOLS_HPP_INCLUDED
#define TOOLS_HPP_INCLUDED

#include <vector>
#include "sl.h"

struct PVector
{
    float x;
    float y;
    PVector(float, float);
};

PVector operator +(PVector, PVector);
PVector operator -(PVector, PVector);
PVector operator *(PVector, PVector);
PVector operator /(PVector, PVector);

struct Color
{
    float r;
    float g;
    float b;
    float a;
    Color(float, float, float, float);
    void setForeColor();
};

PVector getMousePosition();

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
    void setRadius(float);
    float getRadius();
};

class RectangleShape: public Shape
{
    PVector size;
public:
    RectangleShape(float, float, float, float);
    void drawFill();
    void drawOutline();
    void setSize(PVector);
    PVector getSize();
};

class TriangleShape: public Shape
{
    PVector size;
public:
    TriangleShape(float, float, float, float);
    void drawFill();
    void drawOutline();
    void setSize(PVector);
    PVector getSize();
};

class Polygon: public Shape
{
    int point_count;
    std::vector<PVector> points;
    PVector center;
public:
    Polygon(float, float, int);
    void drawOutline();
    void setPoint(int, PVector);
    PVector getPoint(int);
    int getPointCount();
};

#endif // TOOLS_HPP_INCLUDED
