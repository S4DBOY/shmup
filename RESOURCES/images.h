#ifndef IMAGES_H
#define IMAGES_H

namespace sf
{
    class Sprite;
    class RectangleShape;
}

extern sf::Sprite bulletGraphic;
extern sf::Sprite playerGraphic;
extern sf::Sprite hitboxGraphic;
extern sf::Sprite yinYangGraphic;
extern sf::Sprite backgroundGraphic;

/**
\brief Loads all images and converts them to textures.
*/
void LoadImages();

void DrawRect(sf::RectangleShape shape);
void DrawRect(sf::RectangleShape shape, float x, float y);
void DrawSprite(sf::Sprite sprite);
void DrawSprite(sf::Sprite sprite, float x, float y);

#endif // IMAGES_H
