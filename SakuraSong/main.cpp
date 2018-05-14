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
	ExplorationManager * myExpManager;
	myExpManager = new ExplorationManager();
	MapManager * myMapManager = myExpManager->getMapManager();
	DecisionManager * myDecManager = myExpManager->getDecManager();
	ExecutionManager * myExeManager = myExpManager->getExeManager();
	MenuManager * myMenuManager = myExpManager->getMenuManager();
	RenderManager * myRenderManager = myExpManager->getRenderManager();
	Hero * myHero = myExpManager->getRoleManager()->getHero();
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
				myDecManager->add(new KeyDown(event.key.code, myExpManager));
			}
		}
		myDecManager->decide();
		myExeManager->execute();
		myRenderManager->rendering();
		window->display();
		window->clear();
	}
	return 0;
}
