#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "Gem.h"
#include "Bonus.h"

#define WIDTH 1120
#define HEIGHT 630

using namespace sf;
using namespace std;

class Game
{
public:

	RenderWindow window;

	vector<vector<unique_ptr<Gem>>> gem;

	Vector2i chosen_gem_1;
	Vector2i chosen_gem_2;

	bool exist_choosen_gem = false;

	bool was_found_combination = false;

	void chooseGem(Vector2i position);
	void unchooseGem();

	void switchGems(Vector2i second_gem);
	void unswitchGems();

	void initialize();

	void draw();

	void checkHorizontal();
	void checkVertical();

	void destroyGems();
	void destroyGems(vector<Vector2i> coords);
	void changeColors(vector<Vector2i> coords);

	void replaceDestroyed();

	void moveGemsDown();

	void spawnBonus(Vector2i gem);
};