#include "JoystickTester.hpp"

JoystickTester::JoystickTester(sf::Font & font)
:	box(sf::Vector2f(220, 220)),
	stick(sf::Vector2f(20, 20)),
	text("X 0 Y 0", font)
{
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineColor(sf::Color::Red);
	box.setOutlineThickness(-2);

	stick.setFillColor(sf::Color::Green);
	stick.setPosition(100, 100);

	text.setPosition(0, 220);
}

void JoystickTester::setStickPositionX(int x)
{
	stick.setPosition(float(x + 100), stick.getPosition().y);
	text.setString("X " + std::to_string(getPosition().x) + " Y " + std::to_string(getPosition().y));
}

void JoystickTester::setStickPositionY(int y)
{
	stick.setPosition(stick.getPosition().x, float(y + 100));
	text.setString("X " + std::to_string(getPosition().x) + " Y " + std::to_string(getPosition().y));
}

sf::Vector2i JoystickTester::getPosition()
{
	return sf::Vector2i(stick.getPosition()) - sf::Vector2i(100, 100);
}

void JoystickTester::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(box, states);
	target.draw(stick, states);
	target.draw(text, states);
}
