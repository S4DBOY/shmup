#include "../RESOURCES/images.h"
#include "../BASIC/globals.h"

typedef sf::IntRect Rect;

sf::Texture bulletSheet;
sf::Sprite bulletGraphic;

sf::Texture playerSheet;
sf::Sprite playerGraphic;
sf::Sprite yinYangGraphic;

sf::Texture effectSheet;
sf::Sprite hitboxGraphic;

sf::Texture background;
sf::Sprite backgroundGraphic;

sf::Sprite createSprite(sf::Texture &texture, Rect source)
{
    sf::Sprite temp;
    temp.setTexture(texture);
    temp.setTextureRect(source);
    temp.setOrigin(source.width/2, source.height/2);
    temp.setScale(2, 2);
    return temp;
}

void LoadImages()
{
    bulletSheet.loadFromFile("data/bullet.dat");
    playerSheet.loadFromFile("data/player.dat");
    effectSheet.loadFromFile("data/effects.dat");
    background.loadFromFile("data/bg.dat");

    bulletGraphic=createSprite(bulletSheet, Rect{0, 112, 16, 16});
    playerGraphic=createSprite(playerSheet, Rect{0, 0, 32, 48});
    yinYangGraphic=createSprite(playerSheet, Rect{64, 144, 16, 16});
    hitboxGraphic=createSprite(effectSheet, Rect{0, 16, 64, 64});

    backgroundGraphic.setTexture(background);
    backgroundGraphic.setScale(SCREEN_WIDTH/256.0f, SCREEN_HEIGHT/256.0f);
}

void DrawRect(sf::RectangleShape shape)
{window.draw(shape);}

void DrawRect(sf::RectangleShape shape, float x, float y)
{shape.setPosition(x, y);
    window.draw(shape);}

void DrawSprite(sf::Sprite sprite)
{window.draw(sprite);}

void DrawSprite(sf::Sprite sprite, float x, float y)
{sprite.setPosition(x, y);
    window.draw(sprite);}
