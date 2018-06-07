#pragma once
#include "SFML\Graphics.hpp"
#include "Typedef.h"
#include "GameObject.h"
#include <list>
using namespace std;
class RoleState;
class Menu;

class Role: public GameObject
{
public:
	Role(int hp, int agg, ROLETYPE type);
	~Role();
	sf::Sprite* getSprite();
	sf::Texture*** getMoveTexture();
	sf::Texture** getattackTexture();
	sf::Texture** getStandTexture();
	sf::Texture** getBattleTexture();
	sf::Texture** getBeBattledTexture();
	sf::Texture** getInBattleTexture();
	void setDirection(DIRECTION* dir);
	void setState(RoleState * rs);
	void setPosition(sf::Vector2i pos);
	void setTalkState(bool isTalking);
	void setInBattleTexture(bool isFriend);

	void addHp(int hp);
	void addAttackP(int ap);
	void pushDialog(Menu* m);
	list<Menu*> getDialogList();
	DIRECTION* getDirection();
	ROLETYPE getType();
	int getHp();
	sf::Vector2i* getPosition();
	void attack(Role * obj);
	void injured(int agg);
	void update();
	bool isDied();
	bool isTalking();
	//
protected:
	sf::Sprite _mySprite;
	sf::Texture* _beBattledTexture;
	sf::Texture* _standTexture;
	sf::Texture* _battleTexture;
	sf::Texture* _inBattleTexture;
	sf::Texture** _moveTexture;
	sf::Texture* _attackTexture;
	RoleState * _state;
	DIRECTION _direction;
	sf::Vector2i _position;
	int _hp;
	int _attackPower;
	bool _isDied;
	bool _isTalking;
	list<Menu*> _dialogList;
	ROLETYPE _type;
};
