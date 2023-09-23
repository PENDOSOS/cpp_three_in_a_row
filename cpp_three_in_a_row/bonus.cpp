#include "Bonus.h"

Bomb::Bomb()
{
	this->texture.loadFromFile("gems_assets/bomb.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.9675f, 1.9675f);

	Vector2i temp;

	for (int i = 0; i < 10; i++)
	{
		temp.y = i;
		for (int j = 0; j < 10; j++)
		{
			temp.x = j;
			coords.push_back(temp);
		}
	}
}

vector<Vector2i> Bomb::useBonus(Vector2i gem)
{
	vector<Vector2i> chosen_gems;

	for (int i = 0; i < 4; i++)
	{
		chosen_gems.push_back(this->coords[rand() % 100]);
	}
	chosen_gems.push_back(gem);
	return chosen_gems;
}

Marker::Marker()
{
	this->texture.loadFromFile("gems_assets/marker.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.9675f, 1.9675f);
}

vector<Vector2i> Marker::useBonus(Vector2i gem)
{
	if (gem)

	return coords;
}