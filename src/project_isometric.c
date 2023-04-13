/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-16 - 16:48 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: isometric
 */

#include "struct.h"
#include "fonction.h"
#include <lapin.h>

t_bunny_position project_isometric(int x, int y, int z, int coef)
{
    t_bunny_position W;
    float i;
    float j;

    i = 0.75;
    j = 0.25;
    W.x = (x * i - y * i) * coef;
    W.y = (-z * coef * 0.5) + (x * j + y * j) * coef;
    return W;
}
