#include "SpaceShip.h"

SpaceShip::SpaceShip() {

}


void SpaceShip::Destroy() {
	GameObject::Destroy();
}


void SpaceShip::Init(ALLEGRO_BITMAP *image) {

	GameObject::Init(HEIGHT/2, WIDTH/2, 6, 6, 0, 0, 10, 12);

	setID(PLAYER);
	SetAlive(true);

	lives = 3;
	score = 0;

	//sprites stuff
	maxFrame = 3;
	curFrame = 0;
	frameWidth = 46;
	frameHeight = 41;
	animationColumns = 3;
	animationDirection = 1;
	animationRow = 1;

	if (image != NULL)
		SpaceShip::image = image;
}


void SpaceShip::Update() {
	GameObject::Update();


	if (x < 0)
		x = 0;
	else if (x > WIDTH)
		x = WIDTH;

	if (y < 0)
		y = 0;
	else if (y > WIDTH)
		y = WIDTH;
}


void SpaceShip::Render() {

	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = animationRow * frameHeight;

	al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight,
	x-frameWidth/2, y-frameHeight/2, 0);
}

void SpaceShip::MoveUp() {
	animationRow = 0;
	dirY = -1;

}

void SpaceShip::MoveDown() {
	animationRow = 0;
	dirY = 1;

}

void SpaceShip::MoveLeft() {
	animationRow = 0;
	dirX = -1;

}

void SpaceShip::MoveRight() {
	animationRow = 0;
	dirX = 1;

}

void SpaceShip::ResetAnimation(int position) {
	if (position == 1) {
		animationRow = 1;
		dirY = 0;
	}
	else{
		curFrame = 0;
		dirX = 0;
	}
}

void SpaceShip::Collide(int objectID) {
	if (objectID == ENEMY)
		lives--;

}
