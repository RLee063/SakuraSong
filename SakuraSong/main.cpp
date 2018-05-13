#include <SFML/Graphics.hpp>

#include "DecisionManager.h"
#include "ExplorationManager.h"
#include "MapManager.h"
#include "ExecutionManager.h"
#include "Hero.h"
#include "MenuManager.h"
#include "Includes.h"

int main()
{
	ExplorationManager * myExpManager = new ExplorationManager();
	//myExpManager->init();
	MapManager * myMapManager = myExpManager->getMapManager();
	DecisionManager * myDecManager = myExpManager->getDecManager();
	ExecutionManager * myExeManager = myExpManager->getExeManager();
	MenuManager * myMenuManager = myExpManager->getMenuManager();
	Hero * myHero = myExpManager->getHero();

	sf::RenderWindow* window = myExpManager->getWindow();
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

			if (event.type == sf::Event::KeyPressed)
			{
				myDecManager->keyDown(event.key.code);
			}
		}
		myExeManager->execute();

		window->draw(*(myMapManager->getMapSprite()));
		window->draw(*(myHero->getSprite()));
		window->draw(*(myMenuManager->getMainMenu()->getFramWorkS()));
		for (auto i : myMenuManager->getMainMenu()->getButtonsSList()) {
			window->draw(*i);
		}
		window->display();
		window->clear();
	}
	return 0;
}
