#define NOMINMAX
#include "Rounded_Rectangle_Shape.h"
using namespace sf;
RectangleShape draw_pixel(Vector2f position, int r, int g, int b)
{
    RectangleShape pixel;
    pixel.setSize({ 5, 5 });
    pixel.setFillColor(Color(r, g, b));
    pixel.setPosition(position);
    return pixel;
}
RectangleShape draw_rectangle(Vector2f size, Vector2f position, int dis_r, int dis_g, int dis_b, int outl, int r, int g, int b) 
{
    RectangleShape rectangle(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(Color(dis_r,dis_g,dis_b));
    rectangle.setOutlineThickness(outl);
    rectangle.setOutlineColor(Color(r,g,b));
    return rectangle;
}
RectangleShape draw_rectangle(Vector2f size, Vector2f position, int r, int g, int b)
{
    RectangleShape rectangle(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(Color(r,g,b));
    return rectangle;
}
ConvexShape draw_ellipse(int rad_x, int rad_y, int x0, int y0, int dis_r, int dis_g, int dis_b, int outl, int r, int g, int b)
{
    ConvexShape ellipse;
    int count_point = 70;
    ellipse.setPointCount(count_point);

    for (unsigned short i = 0; i < count_point; ++i) {
        float rad = (360 / count_point * i) / (360 / 3.14 / 2);
        float x = cos(rad) * rad_x;
        float y = sin(rad) * rad_y;

        ellipse.setPoint(i, Vector2f(x, y));
    };

    ellipse.setPosition(x0,y0);
    ellipse.setFillColor(Color(dis_r,dis_g,dis_b));
    ellipse.setOutlineThickness(outl);
    ellipse.setOutlineColor(Color(r,g,b));
    return ellipse;
}
ConvexShape draw_ellipse(int rad_x, int rad_y, int x0, int y0, int r, int g, int b)
{
    ConvexShape ellipse;
    int count_point = 70;
    ellipse.setPointCount(count_point);

    for (unsigned short i = 0; i < count_point; ++i) {
        float rad = (360 / count_point * i) / (360 / 3.14 / 2);
        float x = cos(rad) * rad_x;
        float y = sin(rad) * rad_y;

        ellipse.setPoint(i, Vector2f(x, y));
    };

    ellipse.setPosition(x0, y0);
    ellipse.setFillColor(Color(r,g,b));
    return ellipse;
}
CircleShape draw_circle(int radius, int x0, int y0,int dis_r,int dis_g,int dis_b,int outl, int r, int g, int b) 
{
    CircleShape circle(radius);
    circle.setPosition(x0,y0);
    circle.setFillColor(Color(dis_r,dis_g,dis_b));
    circle.setOutlineThickness(outl);
    circle.setOutlineColor(Color(r,g,b));
    return circle;
}
CircleShape draw_circle(int radius, int x0, int y0, int r, int g, int b)
{
    CircleShape circle(radius);
    circle.setPosition(x0, y0);
    circle.setFillColor(Color(r, g, b));
    return circle;
}
RoundedRectangleShape draw_rounded_rect(int w, int h, int rad,int dis_r, int dis_g, int dis_b,int x0,int y0,int outl,int r,int g,int b)
{
    RoundedRectangleShape rounded_rect;
    rounded_rect.setSize(Vector2f(w,h));
    rounded_rect.setCornersRadius(rad);
    rounded_rect.setFillColor(Color(dis_r,dis_g,dis_b));
    rounded_rect.setPosition(x0,y0);
    rounded_rect.setOutlineThickness(outl);
    rounded_rect.setOutlineColor(Color(r,g,b));
    return rounded_rect;
}
RoundedRectangleShape draw_rounded_rect(int w, int h, int rad, int x0, int y0,int r, int g, int b)
{
    RoundedRectangleShape rounded_rect;
    rounded_rect.setSize(Vector2f(w, h));
    rounded_rect.setCornersRadius(rad);
    rounded_rect.setFillColor(Color(r,g,b));
    rounded_rect.setPosition(x0, y0);
    return rounded_rect;
}
Text draw_text(int x0, int y0, int font_size, string txt,int r,int g,int b) 
{
    Text text;
    Font font;
    font.loadFromFile("Courier New.ttf");
    text.setFont(font);
    text.setString(txt);
    text.setPosition(x0,y0);
    text.setCharacterSize(font_size);
    text.setFillColor(Color(r,g,b));
    return text;
}