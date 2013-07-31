#include "../RESOURCES/images.h"
#include "../BASIC/globals.h"

#include <map>
#include <string>

std::map<std::string, sf::Sprite> sprites;
std::map <int, sf::Texture> textures;

typedef sf::IntRect Rect;

enum textures{
    bulletSheet,
    playerSheet,
    effectSheet,
    background
};

sf::Sprite CreateSprite(int textureNo, Rect source)
{
    sf::Sprite temp;
    temp.setTexture(textures[textureNo]);
    temp.setTextureRect(source);
    temp.setOrigin(source.width/2, source.height/2);
    temp.setScale(2, 2);
    return temp;
}

void LoadImages()
{
    textures[bulletSheet].loadFromFile("data/bullet.dat");
    textures[playerSheet].loadFromFile("data/player.dat");
    textures[effectSheet].loadFromFile("data/effects.dat");
    textures[background].loadFromFile("data/bg.dat");

    sprites["B_BULLET1"]=CreateSprite(bulletSheet, Rect{0, 112, 16, 16});
    sprites["PLAYER"]=CreateSprite(playerSheet, Rect{0, 0, 32, 48});
    sprites["B_BULLET1_P"]=CreateSprite(bulletSheet, Rect{0, 112, 16, 16}); sprites["B_BULLET1_P"].setColor(sf::Color{255, 255, 255, 128});
    sprites["YINYANGOPTION"]=CreateSprite(playerSheet, Rect{64, 144, 16, 16});
    sprites["HITBOX"]=CreateSprite(effectSheet, Rect{0, 16, 64, 64});

    sf::Sprite temp;
    temp.setTexture(textures[background]);
    temp.setScale(SCREEN_WIDTH/256.0f, SCREEN_HEIGHT/256.0f);
    sprites["BACKGROUND"]=temp;

}

void DrawRect(sf::RectangleShape shape)
{window.draw(shape);}

void DrawRect(sf::RectangleShape shape, float x, float y)
{shape.setPosition(x, y);
    window.draw(shape);}


void DrawSprite(std::string type, float x, float y, float angle, int animationFrame)
{
    sf::Sprite temp=sprites[type];
    Rect t=temp.getTextureRect();
    temp.setTextureRect(Rect{t.left+t.width*animationFrame, t.top, t.width, t.height});
    temp.setRotation(angle);
    temp.setPosition(x, y);
    window.draw(temp);
}
