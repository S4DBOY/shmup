#pragma once

#include <vector>
#include <memory>
#include <string>

struct Rect;
class Bullet;
class BulletManager;
extern BulletManager bulletManager;

enum BULLET_INSTRUCTION{
	BULLET_ANGLE,
	BULLET_VELOCITY,
	BULLET_ANGULAR_VELOCITY,
	BULLET_ACCEL,
};
enum SET_OR_CHANGE{
	SET,
	CHANGE,
};

class BulletManager
{
public:
	BulletManager();

	void Move();
	void Logic();
	void Draw() const;
	int IsEnemyHit(Rect loc);
	int IsPlayerHit(double x, double y, double radius);

	void AddBasicBulletXY(const std::string & type, int damage,
		double x, double y, double vx, double vy);
	void AddBasicBullet(const std::string & type, int damage,
		double x, double y, double v, double angle);
	void AddAccelBullet(const std::string & type, int damage,
		double x, double y, double v, double angle, double accel, double minmaxV);
	void AddAccelBulletXY(const std::string & type, int damage,
		double x, double y, double vx, double vy, double accelX, double accelY, double minmaxX, double minmaxY);
	void AddComplexBullet(const std::string & type, int damage,
		double x, double y, double v, double angle, double angularV, double accel);

	void AddBulletData(int time, int instruction, int setOrChange, double data);

	void SetBulletTiming(int delay, int lifetime);

	void SetOwner(bool owner){ currentOwner = owner; };

	void EraseAllBullets();
protected:
private:
	bool currentOwner;  //determines whether the last bullet added belonged to the enemy or to the player

	std::vector<std::unique_ptr<Bullet>> bullets;
};