//Joystick_main.cpp
//

#include "config.hpp"
#include "JoystickTester.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 520), "Test", sf::Style::Close);

	window.setJoystickThreshold(1.f);

	sf::Font font;
	font.loadFromFile("fonts/digifaw.TTF");

	JoystickTester joystick1(font);

	JoystickTester joystick2(font);
	joystick2.setPosition(255.f, 0.f);

	JoystickTester joystick3(font);
	joystick3.setPosition(0.f, 255.f);

	JoystickTester joystick4(font);
	joystick4.setPosition(255.f, 255.f);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::JoystickConnected)
			{
				int ID = event.joystickConnect.joystickId;

				std::cout << "Joystick connected" << std::endl;
				std::cout << "ID: " << ID << std::endl;
				auto identification = sf::Joystick::getIdentification(ID);

				std::cout << "Name: " << std::string(identification.name) << std::endl;
				std::cout << "Product ID: " << identification.productId << std::endl;
				std::cout << "Vendor ID: " << identification.vendorId << std::endl;
			}
			if (event.type == sf::Event::JoystickDisconnected)
			{
				std::cout << "Joystick disconnected\nID: " << event.joystickConnect.joystickId << std::endl;
			}

			if (event.type == sf::Event::JoystickButtonPressed)
			{
				std::cout << "Button pressed: " << event.joystickButton.button << std::endl;
			}
			if (event.type == sf::Event::JoystickMoved)
			{
				switch (event.joystickMove.axis)
				{
				case sf::Joystick::X: joystick1.setStickPositionX(event.joystickMove.position);	break;
				case sf::Joystick::Y: joystick1.setStickPositionY(event.joystickMove.position);	break;
				case sf::Joystick::Z: joystick2.setStickPositionX(event.joystickMove.position);	break;
				case sf::Joystick::R: joystick2.setStickPositionY(event.joystickMove.position);	break;
				case sf::Joystick::U: joystick4.setStickPositionX(event.joystickMove.position);	break;
				case sf::Joystick::V: joystick4.setStickPositionY(event.joystickMove.position);	break;
				case sf::Joystick::PovX: joystick3.setStickPositionX(event.joystickMove.position); break;
				case sf::Joystick::PovY: joystick3.setStickPositionY(-event.joystickMove.position); break;
				}
			}
		}

		window.clear();
		window.draw(joystick1);
		window.draw(joystick2);
		window.draw(joystick3);
		window.draw(joystick4);
		window.display();
	}

	return 0;
}
