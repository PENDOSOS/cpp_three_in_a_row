#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Gem.h"


using namespace sf;

Gem::Gem()
{
	this->choise_texture.loadFromFile("gems_assets/white.png");
	this->main_texture.loadFromFile(this->setColor());
	this->sprite.setTexture(this->main_texture);
	this->sprite.setScale(1.9675f, 1.9675f);
}

void Gem::moveDown()
{
	sprite.move(Vector2f(0.f, 63.f));
}

void Gem::moveUp()
{
	sprite.move(Vector2f(0.f, -63.f));
}

String Gem::setColor()
{
	int temp_color = 1 + rand() % 6;
	switch (temp_color)
	{
	case red:
		color = red;
		return "gems_assets/red.png";
		break;
	case green:
		color = green;
		return "gems_assets/green.png";
		break;
	case blue:
		color = blue;
		return "gems_assets/blue.png";
		break;
	case orange:
		color = orange;
		return "gems_assets/orange.png";
		break;
	case yellow:
		color = yellow;
		return "gems_assets/yellow.png";
		break;
	case cyan:
		color = cyan;
		return "gems_assets/cyan.png";
		break;
	default:
		break;
	}
}

int Gem::getColor()
{
	return color;
}

Sprite& Gem::getSprite()
{
	return sprite;
}

Texture& Gem::getTexture()
{
	return main_texture;
}

void Gem::switchToChosen()
{
	sprite.setTexture(choise_texture);
}

void Gem::switchToNormal()
{
	sprite.setTexture(main_texture);
}

void Gem::markToDelete()
{
	to_delete = true;
}

void Gem::unmarkToDelete()
{
	to_delete = false;
}

bool Gem::getStatus()
{
	return to_delete;
}

void Gem::changeMarking()
{
	already_marked = true;
}

void Gem::unchangeMarking()
{
	already_marked = false;
}

bool Gem::getMarking()
{
	return already_marked;
}