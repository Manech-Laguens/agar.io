#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Dot : public sf::CircleShape
{
    public:
    bool isEaten = false;

    //constructor
    Dot(float radius) : sf::CircleShape(radius)
    {
        setFillColor(sf::Color::White);
    }


};

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "agar.io", sf::Style::Fullscreen); // window name and size
    sf::CircleShape shape(50.f); // set the size/shape of the circle
    sf::CircleShape shape2(50.f); // set the size/shape of the circle

    shape.setFillColor(sf::Color::Green); // set the color of the circle
    shape2.setFillColor(sf::Color::Red); // set the color of the circle
    shape.setPosition(window.getSize().x - shape.getRadius()*2, window.getSize().y / 2); // set the starting position of the circle
    shape2.setPosition(0, window.getSize().y / 2);    
    
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); // get the desktop size
    window.setPosition(sf::Vector2i((desktop.width - window.getSize().x) / 2, (desktop.height - window.getSize().y) / 2)); // set the window position to the center of the screen
    
    // If the framerate is not limited, the balls will be execively fast.
    window.setFramerateLimit(60);
    
    sf::RectangleShape button1(sf::Vector2f(200, 50)); // create a button
    button1.setFillColor(sf::Color::Cyan);
    button1.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 60);

    sf::RectangleShape button2(sf::Vector2f(200, 50));
    button2.setFillColor(sf::Color::Cyan);
    button2.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 + 10);

    sf::RectangleShape button3(sf::Vector2f(200, 50));
    button3.setFillColor(sf::Color::Cyan);
    button3.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 + 80);



    sf::RectangleShape button1Label(sf::Vector2f(20, 20)); // create a label for the button
    button1Label.setPosition(button1.getPosition().x + button1.getSize().x / 2 - 10, button1.getPosition().y + button1.getSize().y / 2 - 10);

    sf::RectangleShape button2Label(sf::Vector2f(20, 20)); // create a label for the button2
    button2Label.setPosition(button2.getPosition().x + button2.getSize().x / 2 - 10, button2.getPosition().y + button2.getSize().y / 2 - 10);

    sf::RectangleShape button3Label(sf::Vector2f(20, 20)); // create a label for the button3
    button3Label.setPosition(button3.getPosition().x + button3.getSize().x / 2 - 10, button3.getPosition().y + button3.getSize().y / 2 - 10);

    // font written in the buttons, button1 : Exit the game, button2 : Resume the game, button3 : Credits
    sf::Font font;
    font.loadFromFile("font/OpenSans-Regular.ttf");
    

    sf::Text button1Text;
    button1Text.setFont(font);
    button1Text.setString("Restart");
    button1Text.setCharacterSize(24);
    button1Text.setFillColor(sf::Color::Black);
    button1Text.setPosition(button1Label.getPosition().x - 20, button1Label.getPosition().y - 20);

    sf::Text button2Text;
    button2Text.setFont(font);
    button2Text.setString("Exit");
    button2Text.setCharacterSize(24);
    button2Text.setFillColor(sf::Color::Black);
    button2Text.setPosition(button2Label.getPosition().x - 20, button2Label.getPosition().y - 20);

    sf::Text button3Text;
    button3Text.setFont(font);
    button3Text.setString("Credits");
    button3Text.setCharacterSize(24);
    button3Text.setFillColor(sf::Color::Black);
    button3Text.setPosition(button3Label.getPosition().x - 20, button3Label.getPosition().y - 20);
    




    bool areButtonsVisible = false;

    float speed = 15;
    float speed2 = 15;

    sf::Clock clock;
    std::vector<Dot> dots;

    for (int i = 0; i < 15; i++)
    {
        Dot dot(5);
        dot.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
        dot.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        dots.push_back(dot);
    }


    while (window.isOpen())
    {
        
        sf::Event event; // create an event
        while (window.pollEvent(event)) // check if there is an event
        {
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) // close the window if esc is pressed
                window.close(); // close the window
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) // Set the pause button
                areButtonsVisible = !areButtonsVisible;

            if (areButtonsVisible && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) // check if the mouse is clicked
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(button1.getGlobalBounds().contains(mousePos.x, mousePos.y)) // check if the mouse is on the button
                        {
                        std::cout << "Reset button clicked" << std::endl;
                            shape.setPosition(window.getSize().x - shape.getRadius()*2, window.getSize().y / 2); // set the starting position of the circle
                            shape2.setPosition(0, window.getSize().y / 2); // set the starting position of the circle2
                            shape.setRadius(50); // set the radius of the circle
                            shape2.setRadius(50); // set the radius of the circle2
                            speed = 15; // set the speed of the circle
                            speed2 = 15;    // set the speed of the circle2
                            dots.clear(); // clear the dots
                            for (int i = 0; i < 15; i++) // create 15 dots
                            {
                                Dot dot(5); // set the radius of the dot
                                dot.setPosition(rand() % window.getSize().x, rand() % window.getSize().y); // set the position of the dot
                                dot.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256)); // set the color of the dot
                                dots.push_back(dot); // add the dot to the vector
                            }
                        }


                        
                    else if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) // check if the mouse is on the button
                      {  std::cout << "Exit button clicked" << std::endl; // print in the console
                        window.close(); // close the window
                       }
                    else if (button3.getGlobalBounds().contains(mousePos.x, mousePos.y)) // check if the mouse is on the button
                      {  std::cout << "Credits button clicked" << std::endl; // print in the console 
                        sf::Text line1; // create a first text
                        line1.setFont(font); // set the font of the text 
                        line1.setCharacterSize(24); // set the size of the text
                        line1.setFillColor(sf::Color::White); // set the color of the text
                        line1.setPosition(window.getSize().x / 2 - line1.getGlobalBounds().width / 2, 1); // set the position of the text
                        line1.setString("This game was created with the help of Antoine and Malo for the code,"); // set the text of the text ^^

                        sf::Text line2;
                        line2.setFont(font); // set the font of the text
                        line2.setCharacterSize(24); // set the size of the text
                        line2.setFillColor(sf::Color::White); // set the color of the text
                        line2.setPosition(window.getSize().x / 2 - line2.getGlobalBounds().width / 2, 1 + line1.getGlobalBounds().height);
                        line2.setString("and Victor for the tests."); // set the text of the text ^^

                        window.draw(line1); // draw the text
                        window.draw(line2); // draw the text2
                        window.display(); // display the window
                        sf::sleep(sf::seconds(5)); // wait 5 seconds for you to read

                        // sf::Font font;
                        // font.loadFromFile("font/OpenSans-Regular.ttf");
                        // text.setFont(font);
                        // text.setCharacterSize(24);
                        // text.setFillColor(sf::Color::White);
                        // text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, 1);
                        // text.setString("This game was created with the help of Antoine and Malo for the code, and Victor for the tests.");
                        // window.draw(text); 
                        // window.display();
                        // sf::sleep(sf::seconds(5));
                       }
                }
        }
        if (areButtonsVisible == false) // if "pause" is disabled, the circles will move
            if (clock.getElapsedTime().asSeconds() >= 1.5) // create a dot every 1.5 seconds
            {
            for (int i = 0; i < 5; i++) // create 5 dots at the beginning
            {
                Dot dot(5); // DOT SETTINGS
                dot.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
                dot.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
                dots.push_back(dot);
                clock.restart();
            }
        }

        int shape1Dots = 0; // number of dots eaten by the first circle
        int shape2Dots = 0; // number of dots eaten by the second circle
        int i = 0; // counter

        for (auto &it : dots) 
        {
            i++; 
            bool collided = false; 

            //collision with shape 
            sf::Vector2f diff = sf::Vector2f(shape.getPosition().x + shape.getRadius() - it.getPosition().x, shape.getPosition().y + shape.getRadius() - it.getPosition().y);
            if (sqrt(diff.x * diff.x + diff.y * diff.y) < shape.getRadius() + it.getRadius())
            {
                collided = true;
                shape1Dots++;
            }
            if (collided)
            {
                it.isEaten = true; // erase the dot
                collided = false;
                shape.setRadius(shape.getRadius() + 1);
                dots.erase(std::remove_if(dots.begin(), dots.end(), [](const Dot& dot) {
                    return dot.isEaten;
                }), dots.end());
                speed = speed * 98/100;
            } 
            diff = sf::Vector2f(shape2.getPosition().x + shape2.getRadius() - it.getPosition().x, shape2.getPosition().y + shape2.getRadius() - it.getPosition().y);
            if (sqrt(diff.x * diff.x + diff.y * diff.y) < shape2.getRadius() + it.getRadius())
            {
                collided = true;
                shape2Dots++;
            }
            if (collided)
            {
                it.isEaten = true; // erase the dot
                collided = false;
                shape2.setRadius(shape2.getRadius() + 1);
                dots.erase(std::remove_if(dots.begin(), dots.end(), [](const Dot& dot) {
                    return dot.isEaten;
                }), dots.end());
                speed2 = speed2 * 98/100;
        
            }
        }

        // collision between the two circles
        sf::Vector2f diff = sf::Vector2f(shape.getPosition().x + shape.getRadius() - shape2.getPosition().x, shape.getPosition().y + shape.getRadius() - shape2.getPosition().y);
        if (sqrt(diff.x * diff.x + diff.y * diff.y) < shape.getRadius() + shape2.getRadius())
        {
            if (shape.getRadius() * 9/10 > shape2.getRadius()) // if the first circle is bigger than the second one, the second one will be eaten
            {
                shape.setRadius(shape.getRadius() + shape2.getRadius());
                shape2.setRadius(0);
            }
            else if (shape.getRadius() < shape2.getRadius() * 9/10) // if the second circle is bigger than the first one, the first one will be eaten
            {
                shape2.setRadius(shape2.getRadius() + shape.getRadius());
                shape.setRadius(0);
            }
        }


        if (areButtonsVisible == false) // if "pause" is disabled, the circles will move
            {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                shape.move(speed, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                shape.move(-speed, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                shape.move(0, -speed);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
                shape.move(0, speed);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                shape2.move(speed2, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
                shape2.move(-speed2, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
                shape2.move(0, -speed2);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                shape2.move(0, speed2);
            }

     // Get the current position of the shape
     sf::Vector2f shapePosition = shape.getPosition();
     sf::Vector2f shapePosition2 = shape2.getPosition();

     // Check if the shape is out of the window, if so, it will set the position to the edge of the window
     if (shapePosition.x < 0)
     shape.setPosition(0, shapePosition.y);
     if (shapePosition.x > window.getSize().x - shape.getRadius() * 2)
     shape.setPosition(window.getSize().x - shape.getRadius() * 2, shapePosition.y);
     if (shapePosition.y < 0)
     shape.setPosition(shapePosition.x, 0);
     if (shapePosition.y > window.getSize().y - shape.getRadius() * 2)
     shape.setPosition(shapePosition.x, window.getSize().y - shape.getRadius() * 2);
     if (shapePosition2.x < 0)
     shape2.setPosition(0, shapePosition2.y);
     if (shapePosition2.x > window.getSize().x - shape2.getRadius() * 2)
     shape2.setPosition(window.getSize().x - shape2.getRadius() * 2, shapePosition2.y);
     if (shapePosition2.y < 0)
     shape2.setPosition(shapePosition2.x, 0);
     if (shapePosition2.y > window.getSize().y - shape2.getRadius() * 2)
     shape2.setPosition(shapePosition2.x, window.getSize().y - shape2.getRadius() * 2);

    // if the radius of the circle is less than 1, the game will end. The winner will be displayed on the screen
    if (shape.getRadius() < 1)
    {
        sf::Text text;
        sf::Font font;
        font.loadFromFile("font/OpenSans-Regular.ttf");
        text.setFont(font);
        text.setString("Red wins");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Red);
        text.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 60); // set the position of the text
        window.draw(text);
        window.display();
        sf::sleep(sf::seconds(2.5)); // wait 5 seconds
        shape.setPosition(window.getSize().x - shape.getRadius()*2, window.getSize().y / 2); // set the starting position of the circle
        shape2.setPosition(0, window.getSize().y / 2); // set the starting position of the circle2
        shape.setRadius(50); // set the radius of the circle
        shape2.setRadius(50); // set the radius of the circle2
        speed = 15; // set the speed of the circle
        speed2 = 15; // set the speed of the circle2 
        dots.clear(); // clear the dots
        for (int i = 0; i < 15; i++)
        {
            Dot dot(5);
            dot.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
            dot.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            dots.push_back(dot);
        }        
        
    }

    if (shape2.getRadius() < 1)
    {
        sf::Text text;
        sf::Font font;
        font.loadFromFile("font/OpenSans-Regular.ttf");
        text.setFont(font);
        text.setString("Green wins");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Green);
        text.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 60);
        window.draw(text);
        window.display();
        sf::sleep(sf::seconds(2.5));
        shape.setPosition(window.getSize().x - shape.getRadius()*2, window.getSize().y / 2); // set the starting position of the circle
        shape2.setPosition(0, window.getSize().y / 2);
        shape.setRadius(50);
        shape2.setRadius(50);
        speed = 15;
        speed2 = 15;
        dots.clear();
        for (int i = 0; i < 15; i++)
        {
            Dot dot(5);
            dot.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
            dot.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            dots.push_back(dot);
        }

    }

    window.clear(); // clear the window
        for (auto & dot : dots)
        {
            if (!dot.isEaten)
            window.draw(dot);
        }
        window.draw(shape); // draw the circle
        window.draw(shape2); // draw the circle 2
        
     if (areButtonsVisible)
    {
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.draw(button1Text);
        window.draw(button2Text);
        window.draw(button3Text);
    }


        window.display(); // display the window
    }

    return 0;
}