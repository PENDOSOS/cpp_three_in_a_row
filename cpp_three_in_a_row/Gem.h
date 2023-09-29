#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

class Gem
{
public:
	Gem();

	~Gem() = default;

	void moveDown();
	void moveUp();

	String setColor();
	String setColor(int new_color);
	int getColor();

	Sprite& getSprite();
	void updateSprite(int new_color);

	Texture& getTexture();

	void switchToChosen();
	void switchToNormal();

	void markToDelete();
	void unmarkToDelete();
	bool getStatus();

	void changeMarking();
	void unchangeMarking();
	bool getMarking();

private:
	Texture main_texture;
	Texture choise_texture;

	Sprite sprite;

	int color = 0;

	bool already_marked = false;

	bool to_delete = false;

	enum Colors
	{
		black,
		red,
		green,
		blue,
		orange,
		yellow,
		cyan
	};
};