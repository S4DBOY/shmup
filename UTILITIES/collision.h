#ifndef COLLISION_H
#define COLLISION_H

struct Rect;

/**
    \brief Checks for a collision between a rotated rect and a non-rotated rect.
    I assume/hope that there won't be a need for a rotated rect-rotated rect collision
    \param hitbox a Rect struct holding the hirst entity's hitbox
    \param angle rotation of the first entity's hitbox. Angle 0 indicates direction towards right side of the screen. Please be careful about the sprite's original rotation.
    \param r a Rect struct holding the second entity's hitbox. This hitbox must not be rotated.
 */
bool BoxBox(Rect hitbox, double angle, Rect r);


/**
    \brief Checks for a collision between a rotated rect and a given circle.
    \param hitbox a Rect struct holding the hirst entity's hitbox
    \param angle rotation of the first entity's hitbox. Angle 0 indicates direction towards right side of the screen. Please be careful about the sprite's original rotation.
    \param Cx X location of the second entity's centre point.
    \param Cy Y location of the second entity's centre point.
    \param Cr radius of the second entity's circular hitbox
 */
bool BoxCircle (Rect hitbox, double angle, double Cx, double Cy, double Cr);

inline bool CircleCircle (double x1, double y1, double r1, double x2, double y2, double r2)
{
    double dx=x2-x1; double dy=y2-y1;
    if( (dx*dx+dy*dy)    >   ((r1+r2)*(r1+r2))  ) return 0;
    return 1;
}

#endif // COLLISION_H
