#include "BASIC/globals.h"
#include "RESOURCES/images.h"
#include "UTILITIES/collision.h"

#include "bullet.h"
#include <cmath>
#define M_PI		3.14159265358979323846

struct Rect{ double x, y; int w, h; };

struct BulletInfo
{
	std::string spriteName;
	int drawingOrder;
	int animationFrames;
	int animationDelay;
	int hitboxWidth;
	int hitboxHeight;
};

std::map<BulletType, BulletInfo> bulletTypes = {
		{ B_BULLET1, BulletInfo{ "B_BULLET1", 2, 16, 10, 10, 6 } },
		{ B_BULLET1_P, BulletInfo{ "B_BULLET1_P", 2, 1, 1, 10, 6 } },
};

BulletBase::BulletBase(BulletType type, double x, double y) :
	type(type), x(x), y(y)
{
	BulletInfo info = bulletTypes[type];

	drawingOrder = info.drawingOrder;
	animationFrames = info.animationFrames;
	animationDelay = info.animationDelay;

	int scale = 2;

	hitboxW = info.hitboxWidth*scale; hitboxH = info.hitboxHeight*scale;
	hitbox.setSize(sf::Vector2f((float)hitboxW, (float)hitboxH));
	hitbox.setOutlineColor(sf::Color::Black);
	hitbox.setOutlineThickness(1);
	hitbox.setOrigin(hitboxW / 2.0f, hitboxH / 2.0f);
}

void BulletBase::SetTiming(int n_delay, int n_lifetime)
{
	time = 0;
	delay = n_delay;
	lifetime = n_lifetime;
}

void BulletBase::Move()
{
	currentFrame = (frameCounter / animationDelay) % animationFrames;
	//hitbox.setRotation(angle);
	MovePattern();
}

bool BulletBase::CheckBounds() const
{
	if (y > SCREEN_HEIGHT + 50 || y<-200 || x<-80 || x>SCREEN_WIDTH + 80) return 1;
	if (lifetime != 0 && time>lifetime) return 1;
	return 0;
}

int BulletBase::IsRectHit(Rect r) const
{
	if (time <= delay) return 0;

	if (BoxBox(Rect{ x, y, hitboxW, hitboxH }, angle, r)) return damage;
	else return 0;
}

int BulletBase::IsCircleHit(double Cx, double Cy, double Cr) const
{
	if (time <= delay) return 0;

	if (BoxCircle(Rect{ x, y, hitboxW, hitboxH }, angle, Cx, Cy, Cr)) return damage;
	else return 0;
}

void BulletBase::Draw() const
{
	if (time < delay) return;
	DrawSprite(bulletTypes[type].spriteName, x, y, angle + 90, currentFrame);

	//DrawRect(hitbox, x, y);
}

BulletXY::BulletXY(BulletType type, double x, double y, double vx, double vy) :
	BulletBase(type, x, y),
	vx(vx), vy(vy)
{
	angle = atan2(vy, vx)*(180 / M_PI);
}

void BulletXY::Move(){
	time++;
	if (time <= delay) return;
	x += vx;
	y += vy;
	vx += accelX;
	vy += accelY;

	BulletBase::Move();
}

Bullet::Bullet(BulletType type, double x, double y, double v, double angle) :
	BulletBase(type, x, y),
	v(v)
{
	this->angle = angle;
}

void Bullet::Move(){
	time++;
	if (time <= delay) return;
	x += v*cos((angle)*(M_PI / 180));
	y += v*sin((angle)*(M_PI / 180));
	v += accel;
	angle += angularV;

	BulletBase::Move();
}