#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "Gem.h"
#include "Game.h"

using namespace sf;
using namespace std;

int main()
{
	srand(time(0));

	Game game;

	game.initialize();

	while (game.window.isOpen())
	{
		Event event;
		while (game.window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				game.window.close();
		}

		game.window.clear(Color::Black);

		game.draw();

		game.checkHorizontal();
		game.checkVertical();
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (!game.exist_choosen_gem)
				game.chooseGem(Mouse::getPosition(game.window));
		}
		if (Mouse::isButtonPressed(Mouse::Right))
			if (game.exist_choosen_gem)
			{
				game.switchGems(Mouse::getPosition(game.window));
				
				game.checkHorizontal();
				game.checkVertical();

				if (!game.was_found_combination)
					game.unswitchGems();
				
				game.unchooseGem();
			}

		game.destroyGems();
		game.moveGemsDown();
		game.replaceDestroyed();

		game.window.display();		
	}

	return 0;
}