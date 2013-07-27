#include "collision.h"

#define M_PI		3.14159265358979323846
#include <cmath>
#include <algorithm>

struct SDL_Rect
{
    int x, y;
    int w, h;
};

bool BoxBox(SDL_Rect hitbox, double angle, SDL_Rect r)
{
    volatile double X1, Y1, X2, Y2, X3, Y3, X4, Y4;  //real hitbox corner coordinates
    double dx1, dx2, dy1, dy2;              //used to calculate X1, Y1...
    double Px, Py;              //vector we are checking against
    double P1, P2;              //distance on that vector
    double A1, A2, A3, A4, Amax, Amin;      //distance of the non-rotated rect on that vector
    double x=hitbox.x+hitbox.w/2, y=hitbox.y+hitbox.h/2;

    double t_cos=cos(angle*(M_PI/180)); double t_sin=sin(angle*(M_PI/180));

    /*calculating real coordinates, checking against bounding box */

    dx1=(hitbox.w/2)*t_cos-(hitbox.h/2)*t_sin;
    dx2=(hitbox.w/2)*t_cos+(hitbox.h/2)*t_sin;
    X1=x+dx1; X3=x-dx1; X2=x+dx2; X4=x-dx2;
    int Xmax=std::max(X1, std::max(X2, std::max(X3, X4))); int Xmin=std::min(X1, std::min(X2, std::min(X3, X4)));
    if(r.x+r.w<Xmin) return 0;
    if(r.x>Xmax) return 0;

    dy1=(hitbox.w/2)*t_sin+(hitbox.h/2)*t_cos;
    dy2=(hitbox.w/2)*t_sin-(hitbox.h/2)*t_cos;
    Y1=y+dy1; Y2=y+dy2; Y3=y-dy1; Y4=y-dy2;
    int Ymax=std::max(Y1, std::max(Y2, std::max(Y3, Y4))); int Ymin=std::min(Y1, std::min(Y2, std::min(Y3, Y4)));
    if(r.y+r.h<Ymin) return 0;
    if(r.y>Ymax) return 0;

    /* separating axis theorem */

    Px=X2-X1; Py=Y2-Y1;
    P1=X1*Px+Y1*Py; P2=X2*Px+Y2*Py;
    A1=(r.x)*Px+(r.y)*Py;
    A2=(r.x+r.w)*Px+(r.y)*Py;
    A3=(r.x)*Px+(r.y+r.h)*Py;
    A4=(r.x+r.w)*Px+(r.y+r.h)*Py;
    Amax=std::max(A1, std::max(A2, std::max(A3, A4))); Amin=std::min(A1, std::min(A2, std::min(A3, A4)));
    if(Amax<P1 && Amin<P2) return 0;
    if(Amax>P1 && Amin>P2) return 0;

    Px=X3-X2; Py=Y3-Y2;
    P1=X2*Px+Y2*Py; P2=X3*Px+Y3*Py;
    A1=(r.x)*Px+(r.y)*Py;
    A2=(r.x+r.w)*Px+(r.y)*Py;
    A3=(r.x)*Px+(r.y+r.h)*Py;
    A4=(r.x+r.w)*Px+(r.y+r.h)*Py;
    Amax=std::max(A1, std::max(A2, std::max(A3, A4))); Amin=std::min(A1, std::min(A2, std::min(A3, A4)));
    if(Amax<P1 && Amin<P2) return 0;
    if(Amax>P1 && Amin>P2) return 0;

    return 1;
}

#include <iostream>

bool BoxCircle (SDL_Rect hitbox, double angle, double Cx, double Cy, double Cr)
{
    volatile double X1, Y1, X2, Y2, X3, Y3, X4, Y4;  //real hitbox corner coordinates
    double dx1, dx2, dy1, dy2;              //used to calculate X1, Y1...
    double Px, Py;          //vector we are checking against
    double P1, P2, P3, P4, P, Pmax, Pmin;   //distance on that vector
    double A1, Amax, Amin;                  //distance of the circle's center on that vector
    double x=hitbox.x+hitbox.w/2, y=hitbox.y+hitbox.h/2;

    double t_cos=cos(angle*(M_PI/180)); double t_sin=sin(angle*(M_PI/180));

    /*checking against bounding box */

    dx1=(hitbox.w/2)*t_cos-(hitbox.h/2)*t_sin;
    dx2=(hitbox.w/2)*t_cos+(hitbox.h/2)*t_sin;
    X1=x+dx1; X3=x-dx1; X2=x+dx2; X4=x-dx2;
    int Xmax=std::max(X1, std::max(X2, std::max(X3, X4))); int Xmin=std::min(X1, std::min(X2, std::min(X3, X4)));
    if(Cx+Cr<Xmin) return 0;
    if(Cx-Cr>Xmax) return 0;

    dy1=(hitbox.w/2)*t_sin+(hitbox.h/2)*t_cos;
    dy2=(hitbox.w/2)*t_sin-(hitbox.h/2)*t_cos;
    Y1=y+dy1; Y2=y+dy2; Y3=y-dy1; Y4=y-dy2;
    int Ymax=std::max(Y1, std::max(Y2, std::max(Y3, Y4))); int Ymin=std::min(Y1, std::min(Y2, std::min(Y3, Y4)));
    if(Cy+Cr<Ymin) return 0;
    if(Cy-Cr>Ymax) return 0;

    /*checking against borders */

    Px=X2-X1; Py=Y2-Y1; P=sqrt(Px*Px+Py*Py);
    P1=X1*Px+Y1*Py; P2=X2*Px+Y2*Py;
    A1=Cx*Px+Cy*Py;
    Amax=A1+Cr*P; Amin=A1-Cr*P;
    if(Amax<P1 && Amin<P2) return 0;
    if(Amax>P1 && Amin>P2) return 0;

    Px=X3-X2; Py=Y3-Y2; P=sqrt(Px*Px+Py*Py);
    P1=X2*Px+Y2*Py; P2=X3*Px+Y3*Py;
    A1=Cx*Px+Cy*Py;
    Amax=A1+Cr*P; Amin=A1-Cr*P;
    if(Amax<P1 && Amin<P2) return 0;
    if(Amax>P1 && Amin>P2) return 0;

    /*checking against corners */

    Px=Cx-X1; Py=Cy-Y1; P=sqrt(Px*Px+Py*Py);
    P1=X1*Px+Y1*Py; P2=X2*Px+Y2*Py; P3=X3*Px+Y3*Py; P4=X4*Px+Y4*Py;
    Pmax=std::max(P1, std::max(P2, std::max(P3, P4))); Pmin=std::min(P1, std::min(P2, std::min(P3, P4)));
    A1=Cx*Px+Cy*Py; Amax=A1+Cr*P; Amin=A1-Cr*P;
    if(Amax<Pmax && Amin<Pmin) return 0;
    if(Amax>Pmin && Amin>Pmax) return 0;

    Px=Cx-X2; Py=Cy-Y2; P=sqrt(Px*Px+Py*Py);
    P1=X1*Px+Y1*Py; P2=X2*Px+Y2*Py; P3=X3*Px+Y3*Py; P4=X4*Px+Y4*Py;
    Pmax=std::max(P1, std::max(P2, std::max(P3, P4))); Pmin=std::min(P1, std::min(P2, std::min(P3, P4)));
    A1=Cx*Px+Cy*Py; Amax=A1+Cr*P; Amin=A1-Cr*P;
    if(Amax<Pmax && Amin<Pmin) return 0;
    if(Amax>Pmin && Amin>Pmax) return 0;

    Px=Cx-X3; Py=Cy-Y3; P=sqrt(Px*Px+Py*Py);
    P1=X1*Px+Y1*Py; P2=X2*Px+Y2*Py; P3=X3*Px+Y3*Py; P4=X4*Px+Y4*Py;
    Pmax=std::max(P1, std::max(P2, std::max(P3, P4))); Pmin=std::min(P1, std::min(P2, std::min(P3, P4)));
    A1=Cx*Px+Cy*Py; Amax=A1+Cr*P; Amin=A1-Cr*P;
    if(Amax<Pmax && Amin<Pmin) return 0;
    if(Amax>Pmin && Amin>Pmax) return 0;

    Px=Cx-X4; Py=Cy-Y4; P=sqrt(Px*Px+Py*Py);
    P1=X1*Px+Y1*Py; P2=X2*Px+Y2*Py; P3=X3*Px+Y3*Py; P4=X4*Px+Y4*Py;
    Pmax=std::max(P1, std::max(P2, std::max(P3, P4))); Pmin=std::min(P1, std::min(P2, std::min(P3, P4)));
    A1=Cx*Px+Cy*Py; Amax=A1+Cr*P; Amin=A1-Cr*P;
    if(Amax<Pmax && Amin<Pmin) return 0;
    if(Amax>Pmin && Amin>Pmax) return 0;

    return 1;
}
