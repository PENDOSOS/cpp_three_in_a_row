#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Square
{
public:

	virtual ~Square() = default;

	virtual void loadTexture(const String& dir);

private:

	Texture main_texture;

	Sprite sprite;
};