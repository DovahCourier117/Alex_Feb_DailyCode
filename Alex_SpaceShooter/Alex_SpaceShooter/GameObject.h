#pragma once

#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

#include "Globals.h"



class GameObject {


private:
	int ID;
	bool alive;
	bool collidable;

protected:
	float x;
	float y;

	float velx;
	float vely;

	int dirX;
	int dirY;

	int boundX;
	int boundY;

	//variables for animation
	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	int animationDirection;

	ALLEGRO_BITMAP *image;

public:

	GameObject();
	void virtual Destroy();

	void Init(float x, float y, float velx, float vely, int dirX, int dirY, int boundX, int boundY);
	void virtual Update();
	void virtual Render();

	float GetX() { return x; }
	float GetY() { return y; }

	void SetX(float x) { GameObject::x = x; }
	void SetY(float y) { GameObject::y = y; }

	int GetBoundX() { return boundX; }
	int GetBoundY() { return boundY; }

	int GetID() { return ID; }
	void setID(int ID) { GameObject::alive = alive; }

	bool GetAlive() { return alive; }
	void SetAlive(bool alive) { GameObject::alive = alive; }

	bool GetCollidable() { return collidable; }
	void SetCollidable(bool collidable) { GameObject::collidable = collidable; }

	bool CheckCollisions(GameObject *otherObject);
	void virtual Collided(int objectID);
	bool Collidable();







};