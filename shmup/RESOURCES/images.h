#pragma once

#include <string>

namespace sf
{
	class RectangleShape;
}

void LoadImages();

void DrawRect(sf::RectangleShape shape);
void DrawRect(sf::RectangleShape shape, double x, double y);

void DrawSprite(const std::string &type, double x = 0.0, double y = 0.0, double angle = 0.0, int animationFrame = 0);
