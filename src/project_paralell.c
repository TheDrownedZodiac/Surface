/*
 * E89 Pedagogical & Technical Lab
 * project:     paralell
 * created on:  2022-11-14 - 10:10 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: surface
 */

#include "fonction.h"
#include <lapin.h>

t_bunny_position project_paralell(int x, int y, int z, int coef)
{
    t_bunny_position W;
    float i;
    float j;

    i = 1;
    j = 0.7;
    W.x = (x - i * y) * coef;
    W.y = (-z * coef * 0.5) + (j * y) * coef;
    return W;
}



