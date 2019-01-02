//Joystick_main.cpp
//

#include "config.hpp"
#include "JoystickTester.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(640, 520), "Test", Style::Close);

	window.setJoystickThreshold(1.f);

	Font font;
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
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::JoystickConnected)
			{
				int ID = event.joystickConnect.joystickId;

				cout << "Joystick connected" << endl;
				cout << "ID: " << ID << endl;
				auto identification = Joystick::getIdentification(ID);

				cout << "Name: " << string(identification.name) << endl;
				cout << "Product ID: " << identification.productId << endl;
				cout << "Vendor ID: " << identification.vendorId << endl;
			}
			if (event.type == Event::JoystickDisconnected)
			{
				cout << "Joystick disconnected\nID: " << event.joystickConnect.joystickId << endl;
			}

			if (event.type == Event::JoystickButtonPressed)
			{
				cout << "Button pressed: " << event.joystickButton.button << endl;
			}
			if (event.type == Event::JoystickMoved)
			{
				switch (event.joystickMove.axis)
				{
				case Joystick::X: joystick1.setStickPositionX(event.joystickMove.position);	break;
				case Joystick::Y: joystick1.setStickPositionY(event.joystickMove.position);	break;
				case Joystick::Z: joystick2.setStickPositionX(event.joystickMove.position);	break;
				case Joystick::R: joystick2.setStickPositionY(event.joystickMove.position);	break;
				case Joystick::U: joystick4.setStickPositionX(event.joystickMove.position);	break;
				case Joystick::V: joystick4.setStickPositionY(event.joystickMove.position);	break;
				case Joystick::PovX: joystick3.setStickPositionX(event.joystickMove.position); break;
				case Joystick::PovY: joystick3.setStickPositionY(-event.joystickMove.position); break;
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
