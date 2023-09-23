#include "Bonus.h"
#include <cmath>

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
	int a = 0;

	for (int i = 0; i < 4; i++)
	{
		a = rand() % this->coords.size();
		chosen_gems.push_back(this->coords[a]);
		this->coords.erase(this->coords.begin() + a);
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
	vector<Vector2i> chosen_gems;
	chosen_gems.push_back(gem);
	if (gem.y == 0)
	{
		if (gem.x == 0) { chosen_gems.push_back({ 1, 1 }); }
		else if (gem.x == 9) { chosen_gems.push_back({ 8, 1 }); }
		else
		{
			chosen_gems.push_back({ gem.x + 1, gem.y + 1 });
			chosen_gems.push_back({ gem.x - 1, gem.y + 1 });
		}
	}
	else if (gem.y == 9)
	{
		if (gem.x == 0) { chosen_gems.push_back({ 1, 8 }); }
		else if (gem.x == 9) { chosen_gems.push_back({ 8, 8 }); }
		else
		{
			chosen_gems.push_back({ gem.x + 1, gem.y - 1 });
			chosen_gems.push_back({ gem.x - 1, gem.y - 1 });
		}
	}
	else if (gem.x == 0)
	{
		chosen_gems.push_back({ gem.x + 1, gem.y + 1 });
		chosen_gems.push_back({ gem.x + 1, gem.y - 1 });
	}
	else if (gem.x == 9)
	{
		chosen_gems.push_back({ gem.x - 1, gem.y + 1 });
		chosen_gems.push_back({ gem.x - 1, gem.y - 1 });
	}
	else
	{
		int a = 0;
		vector<Vector2i> temp;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				temp.push_back({ gem.x + int(pow((-1), j)), gem.y + int(pow((-1), i)) });
		for (int i = 0; i < 2; i++)
		{
			a = rand() % temp.size();
			chosen_gems.push_back(temp[a]);
			temp.erase(temp.begin() + a);
		}
	}
	return chosen_gems;
}