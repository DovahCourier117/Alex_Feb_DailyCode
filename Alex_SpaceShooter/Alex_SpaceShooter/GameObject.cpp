#include "GameObject.h"

GameObject::GameObject() {
	x = 0;
	y = 0;

	velx = 0;
	vely = 0;

	boundX = 0;
	boundY = 0;

	maxFrame = 0;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 0;
	frameWidth = 0;
	frameHeight = 0;
	animationColumns = 0;
	animationDirection = 0;

	image = NULL;

	alive = true;
	collidable = true;

}

void GameObject::Destroy() {

	if (image != NULL)
		al_destroy_bitmap(image);
}

void GameObject::Init(float X, float y, float velx, float vely, int dirX, int dirY, int boundX, int boundY) {
	GameObject::x = x;
	GameObject::y = y;

	GameObject::velx = velx;
	GameObject::vely = vely;

	GameObject::dirX = dirX;
	GameObject::dirY = dirY;

	GameObject::boundX = boundX;
	GameObject::boundY = boundY;
}
void GameObject::Update() {

	x = +velx + dirX;
	y = +vely + dirY;

}

void GameObject::Render() {

}

bool GameObject::CheckCollisions(GameObject *otherObject) {

	float oX = otherObject->GetX();
	float oY = otherObject->GetY();

	int obX = otherObject->GetBoundX();
	int obY = otherObject->GetBoundY();

	if (
		x + boundX > oX - obX &&
		x - boundX < oX + obX &&
		y + boundY > oY - obY &&
		y - boundY < oY + obY
		)
		return true;
	else
		return false;
}

void GameObject::Collided(int objectID) {


}

bool GameObject::Collidable() {

	return alive && collidable;
}