#include <SFML/Graphics.hpp>

#include "DecisionManager.h"
#include "ExplorationManager.h"
#include "MapManager.h"
#include "ExecutionManager.h"
#include "Hero.h"
#include "Typedef.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	Hero* myHero = new Hero();

	MapManager *myMapManager = new MapManager();
	ExplorationManager * myExpManager = new ExplorationManager();
	ExecutionManager * myExeManager = new ExecutionManager();
	DecisionManager * myDecManager = new DecisionManager(myExpManager);
	//myExpManager->init();
	{
		myExpManager->setExeManager(myExeManager);
		myExpManager->setDecManager(myDecManager);
		myExpManager->setHero(myHero);
		myExpManager->setMapManager(myMapManager);

	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				myDecManager->keyDown(event.key.code);
			}
		}
		myExeManager->execute();
		window.draw(*(myMapManager->getMapSprite()));
		window.draw(*(myHero->getSprite()));
		window.display();
		window.clear();
	}
	return 0;
}
