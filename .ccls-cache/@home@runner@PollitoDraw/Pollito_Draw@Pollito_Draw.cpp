#include <SFML/Graphics.hpp>

using namespace sf;

#define posX 100.f
#define posY 110.f
#define dim 75.f
const Color color = Color:: Yellow;

void drawPollito(float, float, float, Color, RenderWindow*);

int main()
{
    


    RenderWindow window(VideoMode(500.f, 500.f), "Pollito Project");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        drawPollito(dim, posX, posY, color, &window);
        window.display();
    }

    return 0;
}

void drawPollito(float dim, float posX, float posY,Color color, RenderWindow* window)
{
    CircleShape body(dim);
    body.setFillColor(color);
    body.setPosition(Vector2f{ posX, posY + dim });
    (*window).draw(body);

    CircleShape leftWing(dim / 4);
    leftWing.setFillColor(color);
    leftWing.setOutlineThickness(2);
    leftWing.setOutlineColor(Color::Black);
    leftWing.setPosition(Vector2f{ (float) (0.8 * posX),posY + (float)(1.5* dim) });
    (*window).draw(leftWing);

    CircleShape rightWing(dim / 4);
    rightWing.setFillColor(color);
    rightWing.setOutlineThickness(2);
    rightWing.setOutlineColor(Color::Black);
    rightWing.setPosition(Vector2f{ (float)(posX + 0.8 * posX),posY + (float)(1.5 * dim) });
    (*window).draw(rightWing);

    CircleShape head(dim / 2);
    head.setFillColor(color);
    head.setPosition(Vector2f{ posX + dim / 2, (float) (posY * 1.5) });
    (*window).draw(head);

    CircleShape rightEye(dim / 12);
    rightEye.setFillColor(Color::Black);
    rightEye.setPosition(posX + 5 * dim / 8, (float)(posY * 1.5) + dim / 3);
    (*window).draw(rightEye);

    CircleShape leftEye(dim / 12);
    leftEye.setFillColor(Color::Black);
    leftEye.setPosition(posX + 10 * dim / 8, (float)(posY * 1.5) + dim / 3);
    (*window).draw(leftEye);

    CircleShape beack(dim / 6, 3);
    beack.setFillColor(Color::Color(250, 150, 10));
    beack.setPosition(posX + 19 * dim / 16, (float)(posY * 1.5) + 7 * dim / 8);
    beack.setRotation(180.f);
    (*window).draw(beack);

    RectangleShape leftFoot(Vector2f{ 2 * dim / 3, dim / 6 });
    leftFoot.setFillColor(Color::Color(250, 150, 10));
    leftFoot.setPosition(posX, posY + 3 * dim - dim / 6);
    (*window).draw(leftFoot);

    RectangleShape rightFoot(Vector2f{ 2 * dim / 3, dim / 6 });
    rightFoot.setFillColor(Color::Color(250, 150, 10));
    rightFoot.setPosition(posX + 2 * dim - 2 * dim / 3, posY + 3 * dim - dim / 6);
    (*window).draw(rightFoot);
}
