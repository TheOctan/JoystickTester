#pragma once

#ifndef JOYSTICK_TESTER_HPP
#define JOYSTICK_TESTER_HPP

#include <SFML/Graphics.hpp>

class JoystickTester : public sf::Drawable, public sf::Transformable
{
public:
	JoystickTester(sf::Font& font);

	void setStickPositionX(int x);
	void setStickPositionY(int y);
	sf::Vector2i getPosition();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::RectangleShape box;
	sf::RectangleShape stick;
	sf::Text text;
};

#endif // !JOYSTICK_TESTER_HPP

