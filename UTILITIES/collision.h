#ifndef COLLISION_H
#define COLLISION_H

#include "../BASIC/globals.h"

/*
    Checks for a collision between a rotated rect and a non-rotated rect.
    I assume/hope that there won't be a need for a rotated rect-rotated rect collision
*/
bool BoxBox(SDL_Rect hitbox, double angle, SDL_Rect r);


/*
    Checks for a collision between a rotated rect and a given circle.
*/
bool BoxCircle (SDL_Rect hitbox, double angle, double Cx, double Cy, double Cr);

#endif // COLLISION_H
