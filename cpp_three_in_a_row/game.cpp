#include "Game.h"

void Game::chooseGem(Vector2i position)
{
	if (position.x > 0 )
	if (245 < position.x && position.x < 875 && 0 <= position.y && position.y <= 630)
	{
		int j = (position.x - 245) / 63;
		int i = position.y / 63;
		if (!exist_choosen_gem)
		{
			exist_choosen_gem = true;
			chosen_gem_1.x = j;
			chosen_gem_1.y = i;
			gem[chosen_gem_1.y][chosen_gem_1.x]->switchToChosen();
		}
	}
}

void Game::unchooseGem()
{
	if (exist_choosen_gem)
	{
		gem[chosen_gem_1.y][chosen_gem_1.x]->switchToNormal();
		exist_choosen_gem = false;
		chosen_gem_1.x = 0;
		chosen_gem_1.y = 0;
	}
}

void Game::switchGems(Vector2i second_gem)
{
	if (245 < second_gem.x && second_gem.x < 875)
	{
		Vector2i temp;

		chosen_gem_2.x = (second_gem.x - 245) / 63;
		chosen_gem_2.y = second_gem.y / 63;

		if ((abs(chosen_gem_2.y - chosen_gem_1.y) == 0) && (abs(chosen_gem_2.x - chosen_gem_1.x) == 1))
		{
			swap(gem[chosen_gem_2.y][chosen_gem_2.x], gem[chosen_gem_1.y][chosen_gem_1.x]);
			gem[chosen_gem_2.y][chosen_gem_2.x]->getSprite().move((chosen_gem_2.x - chosen_gem_1.x) * 63.f, 0);
			gem[chosen_gem_1.y][chosen_gem_1.x]->getSprite().move((chosen_gem_1.x - chosen_gem_2.x) * 63.f, 0);
			temp = chosen_gem_1;
			chosen_gem_1 = chosen_gem_2;
			chosen_gem_2 = temp;
			
		}
		if ((abs(chosen_gem_2.y - chosen_gem_1.y) == 1) && (abs(chosen_gem_2.x - chosen_gem_1.x) == 0))
		{
			swap(gem[chosen_gem_2.y][chosen_gem_2.x], gem[chosen_gem_1.y][chosen_gem_1.x]);
			gem[chosen_gem_2.y][chosen_gem_2.x]->getSprite().move(0, (chosen_gem_2.y - chosen_gem_1.y) * 63.f);
			gem[chosen_gem_1.y][chosen_gem_1.x]->getSprite().move(0, (chosen_gem_1.y - chosen_gem_2.y) * 63.f);
			temp = chosen_gem_1;
			chosen_gem_1 = chosen_gem_2;
			chosen_gem_2 = temp;
		}
	}
}

void Game::unswitchGems()
{
	was_found_combination = false;
	Vector2i temp;
	if ((abs(chosen_gem_2.y - chosen_gem_1.y) == 0) && (abs(chosen_gem_2.x - chosen_gem_1.x) == 1))
	{
		swap(gem[chosen_gem_2.y][chosen_gem_2.x], gem[chosen_gem_1.y][chosen_gem_1.x]);
		gem[chosen_gem_2.y][chosen_gem_2.x]->getSprite().move((chosen_gem_2.x - chosen_gem_1.x) * 63.f, 0);
		gem[chosen_gem_1.y][chosen_gem_1.x]->getSprite().move((chosen_gem_1.x - chosen_gem_2.x) * 63.f, 0);
		temp = chosen_gem_1;
		chosen_gem_1 = chosen_gem_2;
		chosen_gem_2 = temp;

	}
	if ((abs(chosen_gem_2.y - chosen_gem_1.y) == 1) && (abs(chosen_gem_2.x - chosen_gem_1.x) == 0))
	{
		swap(gem[chosen_gem_2.y][chosen_gem_2.x], gem[chosen_gem_1.y][chosen_gem_1.x]);
		gem[chosen_gem_2.y][chosen_gem_2.x]->getSprite().move(0, (chosen_gem_2.y - chosen_gem_1.y) * 63.f);
		gem[chosen_gem_1.y][chosen_gem_1.x]->getSprite().move(0, (chosen_gem_1.y - chosen_gem_2.y) * 63.f);
		temp = chosen_gem_1;
		chosen_gem_1 = chosen_gem_2;
		chosen_gem_2 = temp;
	}
}

void Game::initialize()
{
	unique_ptr<Gem> temp_gem;
	vector<unique_ptr<Gem>> temp_arr;

	window.create(VideoMode(WIDTH, HEIGHT), "three in a row");
	window.setFramerateLimit(10);

	for (int j = 0; j < 10; j++)
	{
		temp_arr.clear();
		for (int i = 0; i < 10; i++)
		{
			temp_gem = make_unique<Gem>();
			temp_arr.push_back(move(temp_gem));
		}
		gem.push_back(move(temp_arr));
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			gem[i][j]->getSprite().setPosition(Vector2f(245.f + (float)j * 63.f, (float)i * 63.f));
		}
}

void Game::draw()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			window.draw(gem[i][j]->getSprite());
}

void Game::checkHorizontal()
{
	int length = 1;
	for (int i = 0; i < 10; i++)
	{
		int j = 0;
		while (j < 10)
		{
			gem[i][j]->markToDelete();
			gem[i][j]->changeMarking();
			length = 1;
			while (j + length < 10)
			{
				if (gem[i][j + length]->getColor() == gem[i][j]->getColor())
				{
					gem[i][j + length]->markToDelete();
					gem[i][j + length]->changeMarking();
					length++;
				}
				else
				{
					break;
				}
			}
			if (length < 3)
			{
				for (int k = j; k < j + length; k++)
				{
					gem[i][k]->unmarkToDelete();
					gem[i][k]->unchangeMarking();
				}
			}
			else
				was_found_combination = true;
			j = j + length;
		}
	}
}

void Game::checkVertical()
{
	int length = 1;
	for (int j = 0; j < 10; j++)
	{
		int i = 0;
		while (i < 10)
		{
			if (!gem[i][j]->getMarking())
			{
				gem[i][j]->markToDelete();
			}
			length = 1;
			while (i + length < 10)
			{
				if (gem[i + length][j]->getColor() == gem[i][j]->getColor())
				{
					gem[i + length][j]->markToDelete();
					length++;
				}
				else
				{
					break;
				}
			}
			if (length < 3)
			{
				for (int k = i; k < i + length; k++)
				{
					if (!gem[k][j]->getMarking())
						gem[k][j]->unmarkToDelete();
				}
			}
			else
				was_found_combination = true;
			i = i + length;
		}
	}
}

void Game::destroyGems()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (gem[i][j]->getStatus())
			{
				gem[i][j].reset();
			}
		}
}

void Game::destroyGems(vector<Vector2i> coords)
{
	for (int i = 0; i < 4; i++)
	{
		gem[coords[i].y][coords[i].x].reset();
	}
}

void Game::changeColors(vector<Vector2i> coords)
{
	if (coords.size() == 2)
	{

	}
}

void Game::replaceDestroyed()
{
	unique_ptr<Gem> new_gem;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (gem[i][j] == nullptr)
			{
				new_gem = make_unique<Gem>();
				gem[i][j] = move(new_gem);
				gem[i][j]->getSprite().setPosition(Vector2f(245.f + (float)j * 63.f, (float)i * 63.f));
			}
		}
}

void Game::moveGemsDown()
{
	for (int i = 9; i > -1; i--)
		for (int j = 0; j < 10; j++)
		{
			if (gem[i][j] == nullptr)
			{
				int k = i - 1;
				while (k > -1)
				{
					if (gem[k][j] != nullptr)
					{
						for (int _ = 0; _ < i - k; _++)
							gem[k][j]->moveDown();
						swap(gem[i][j], gem[k][j]);
						break;
					}
					k--;
				}
			}
		}
	was_found_combination = false;
}

void Game::spawnBonus(Vector2i gem)
{
	Bonus* bonus = new Bomb;
	destroyGems(bonus->useBonus(gem));
	delete bonus;
}