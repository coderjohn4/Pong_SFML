//-lsfml-graphics -lsfml-window -lsfml-system
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void showXY(sf::RenderWindow &window, sf::Font& font, int x, int y, sf::Vector2f& position)
{
    std::string xStr = std::to_string(x);
    std::string yStr = std::to_string(y);
    std::string text = xStr + ", " + yStr;
    sf::Text myText(text, font);
    myText.setCharacterSize(20);
    myText.setFillColor(sf::Color::White);
    myText.setPosition(position);
    window.draw(myText);
}

void showString(sf::RenderWindow &window, sf::Font& font, std::string text, sf::Vector2f& position)
{ 
    sf::Text myText(text, font);
    myText.setCharacterSize(20);
    myText.setFillColor(sf::Color::White);
    myText.setPosition(position);
    window.draw(myText);
}


void setVelocityFromAngle(float& xVelocity, float& yVelocity, float degrees)
{
    float degree = degrees;
    float radians = degrees*M_PI/180;
    xVelocity = cos(radians);
    yVelocity = sin(radians);
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Pong");
    window.setMouseCursorVisible(false);

    sf::Event event;
    sf::Font myFont;
    
    if (!myFont.loadFromFile("arial.ttf"))
    {
        cout << "Error loading file \"arial.ttf\"";
        return 0;
    }

    sf::Vector2f fontPosition(20,10);
    sf::Vector2f textPosition(20,50);

    sf::CircleShape Ball(15);
    sf::Vector2f Ball_Position(400,200);
    Ball.setPosition(Ball_Position);

    sf::RectangleShape Platform(sf::Vector2f(150,10));
    sf::Vector2f Platform_Position(20,580);
    Platform.setPosition(Platform_Position);

    float xVelocity = 0.75;
    float yVelocity = 0.4;

    int mouseX = 0;
    int mouseY = 0;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseMoved)
            {
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                Platform.setPosition(mouseX - 75, 580);
            }
        }
                
        if (Ball_Position.x < 10 || Ball_Position.x > 560) xVelocity *=-1;
        if (Ball_Position.y < 10 || Ball_Position.y > 550) yVelocity *=-1;

        Ball_Position.x += xVelocity;
        Ball_Position.y += yVelocity;
        Ball.setPosition(Ball_Position);
        
        window.clear();

        if (Ball_Position.x + 10 > Platform_Position.x)
        {
        
            if(Ball_Position.y > 560)
            {
                if(Ball_Position.x < (Platform_Position.x+50)) setVelocityFromAngle(xVelocity, yVelocity, -45.0);
                else if(Ball_Position.x < (Platform_Position.x+100))setVelocityFromAngle(xVelocity, yVelocity, 90.0);
                else if(Ball_Position.x < (Platform_Position.x+150))setVelocityFromAngle(xVelocity, yVelocity, -140.0);
            }
        }

        showXY(window, myFont, mouseX, mouseY, fontPosition);
        window.draw(Ball);
        window.draw(Platform);
        window.display();
    }
    return 0;   
};


  sf::Font myFont;
    
if (!myFont.loadFromFile("arial.ttf"))
{
    cout << "Error loading file \"arial.ttf\"";
    return 0;
}
    void showString(sf::RenderWindow &window, sf::Font& font, std::string text, sf::Vector2f& position)
{ 
    sf::Text myText(text, font);
    myText.setCharacterSize(20);
    myText.setFillColor(sf::Color::White);
    myText.setPosition(position);
    window.draw(myText);
}