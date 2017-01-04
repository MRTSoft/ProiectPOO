#pragma once
#include "Misc.h"

using namespace ua_misc;

//! Clasa Entity ofera suportul pentru toate obiectele din joc
/*!
 Obiectele includ paretii, jucatorul in sine, monstri si multe altele. Un spatiu gol nu este o entitate
*/
class Entity {
public:
	Entity () {};
	Entity(Point pt) : mPosition(pt) {};
	~Entity() {};
	//TODO Adaugare in GAME.h un vector cu reprezentarea grafica a entitatilor
	
	Point getPosition();
	void setPosition(Point position);
	void setPosition(pointUnit x, pointUnit y);

protected:

private:
	Point mPosition;
};

class DynamicEntity : public Entity
{
public:

protected:

private:
	bool mHasAction;
};

class StaticEntity : public Entity
{

};