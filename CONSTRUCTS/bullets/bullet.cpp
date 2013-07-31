#include "../../BASIC/globals.h"
#include "../../RESOURCES/images.h"
#include "../../UTILITIES/collision.h"

#include "bullet.h"
#include <cmath>
#define M_PI		3.14159265358979323846

struct Rect{double x, y; int w, h;};

struct BulletType
{
    int drawingOrder;
    int animationFrames;
    int animationDelay;
    double hitboxWidth;
    double hitboxHeight;
};

std::map<std::string, BulletType> bulletTypes={
    {"B_BULLET1", BulletType{2, 16, 10, 10, 6}},
    {"B_BULLET1_P", BulletType{2, 1, 1, 10, 6}},
};

Bullet::Bullet(std::string ntype, double nx, double ny, double nvx, double nvy):
    x(nx), y(ny), vx(nvx), vy(nvy)
{
    type=ntype;
    BulletType temp=bulletTypes[ntype];

    angle=atan2(vy, vx)*(180/M_PI);
    drawingOrder=temp.drawingOrder;
    animationFrames=temp.animationFrames;
    animationDelay=temp.animationDelay;

    int scale=2;

    hitboxW=temp.hitboxWidth*scale; hitboxH=temp.hitboxHeight*scale;

    hitbox.setSize(sf::Vector2f(hitboxW, hitboxH));
    hitbox.setOutlineColor(sf::Color::Black); hitbox.setOutlineThickness(1);
    hitbox.setOrigin(hitboxW/2, hitboxH/2);
}

void Bullet::SetDamage(int n_damage)
{
    damage=n_damage;
}

void Bullet::SetTiming(int n_delay, int n_lifetime)
{
    time=0;
    delay=n_delay;
    lifetime=n_lifetime;
}

void Bullet::Move()
{
    time++;
    if(time<=delay) return;
    x+=vx;
    y+=vy;
};

bool Bullet::CheckBounds()
{
    if(y>SCREEN_HEIGHT+50|| y<-200 || x<-80 || x>SCREEN_WIDTH+80) return 1;
    if(lifetime!=0 && time>lifetime) return 1;
    return 0;
};

int Bullet::IsRectHit(Rect r)
{
    if(time<=delay) return 0;

    if(BoxBox(Rect{x, y, hitboxW, hitboxH}, angle, r)) return damage;
    else return 0;
};

int Bullet::IsCircleHit(double Cx, double Cy, double Cr)
{
    if(time<=delay) return 0;

    if(BoxCircle(Rect{x, y, hitboxW, hitboxH}, angle, Cx, Cy, Cr)) return damage;
    else return 0;
};

void Bullet::Draw()
{
    if(time<delay) return;
    int temp_bounds=16;
    if(y-temp_bounds/2>SCREEN_HEIGHT|| y<-temp_bounds/2 || x<-temp_bounds/2 || x>SCREEN_WIDTH+temp_bounds/2) return;
    int currentFrame=(frameCounter/animationDelay)%animationFrames;

    DrawSprite(type, x, y, angle+90, currentFrame);

    //hitbox.setRotation(angle);
    //DrawRect(hitbox, x, y);
};
