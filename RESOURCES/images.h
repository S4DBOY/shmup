#ifndef IMAGES_H
#define IMAGES_H

#include <string>

namespace sf
{
    class RectangleShape;
}

/**
\brief Loads all images and converts them to textures.
*/
void LoadImages();

void DrawRect(sf::RectangleShape shape);
void DrawRect(sf::RectangleShape shape, float x, float y);

void DrawSprite(std::string type, float x=0.0f, float y=0.0f, float angle=0.0f);

#endif // IMAGES_H
