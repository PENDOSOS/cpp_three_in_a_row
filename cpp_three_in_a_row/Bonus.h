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

	virtual vector<Vector2i> useBonus(Vector2i) = 0;

	Texture texture;

	Sprite sprite;

	vector<Vector2i> coords;
};

class Bomb : public Bonus
{
public:

	Bomb();
	~Bomb() override = default;

	vector<Vector2i> useBonus(Vector2i) override; // ���������� ������ �� ����� ���������� ������ ���������, ����� �������� �������� ������ �� ���.

};

class Marker : public Bonus
{
public:

	Marker();
	~Marker() override = default;

	vector<Vector2i> useBonus(Vector2i) override;

	//������� ������ �� ����� ������ ��������� ���������� ����� � �����������
};