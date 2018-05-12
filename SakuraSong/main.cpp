#include <SFML/Graphics.hpp>
#include "Decider.h"
#include "DecisionManager.h"
#include "ExplorationManager.h"
#include "ExecutionManager.h"
#include "Hero.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1800, 1000), "SFML works!");

	Hero* myHero = new Hero();

	ExplorationManager * myExpManager = new ExplorationManager();
	ExecutionManager * myExeManager = new ExecutionManager();
	DecisionManager * myDecManager = new DecisionManager(myExpManager);

	myExpManager->setExeManager(myExeManager);
	myExpManager->setDecManager(myDecManager);
	myExpManager->setHero(myHero);

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
		window.draw(*(myHero->getSprite()));
		window.display();
		window.clear();
	}
	return 0;
}
