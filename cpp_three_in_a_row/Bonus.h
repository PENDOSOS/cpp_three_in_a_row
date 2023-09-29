#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace std;
using namespace sf;

class Bonus
{
public:

	virtual ~Bonus() = default;

	virtual vector<Vector2i> useBonus(Vector2i const& gem) = 0;

	Texture texture;

	Sprite sprite;
};

class Bomb : public Bonus
{
public:

	Bomb();
	~Bomb() override = default;

	vector<Vector2i> coords;
	vector<Vector2i> useBonus(Vector2i const& gem) override; // возвращает массив с пятью парами координат, чтобы удалить гемы на этих координатах.

};

class Marker : public Bonus
{
public:

	Marker();
	~Marker() override = default;

	vector<Vector2i> useBonus(Vector2i const& gem) override; // возвращает массив с двумя парами координат несоседних гемов в окрестности
};