/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-18 - 11:22 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: hauteur z
 */

#include "fonction.h"
#include <lapin.h>

static void height_isometric(const int x,
                             const int y,
                             const int *z,
                             struct surface *sinfo)
{
    int X;
    int Y;
    int i;
    t_bunny_position W;
    t_bunny_position V;

    X = 0;
    Y = 0;
    i = 0;
    while (Y <= y - 1) {
        while (X <= x - 1) {
            W = project_isometric(X, Y, 0, sinfo->pas);
            W.x += sinfo->width;
            W.y += sinfo->height;
            V = project_isometric(X, Y, z[i], sinfo->pas);
            V.x += sinfo->width;
            V.y += sinfo->height;
            stu_draw_line(sinfo->px, &W, &V, mk_colour(255, 0, 0, 1));
            X += 1;
            i += 1;
        }
        X = 0;
        Y += 1;
    }
}

static void height_paralell(const int x,
                            const int y,
                            const int *z,
                            struct surface *sinfo)
{
    int X;
    int Y;
    int i;
    t_bunny_position W;
    t_bunny_position V;

    X = 0;
    Y = 0;
    i = 0;
    while (Y <= y - 1) {
        while (X <= x - 1) {
            W = project_paralell(X, Y, 0, sinfo->pas);
            W.x += sinfo->width;
            W.y += sinfo->height;
            V = project_paralell(X, Y, z[i], sinfo->pas);
            V.x += sinfo->width;
            V.y += sinfo->height;
            stu_draw_line(sinfo->px, &W, &V, mk_colour(255, 0, 0, 1));
            X += 1;
            i += 1;
        }
        X = 0;
        Y += 1;
    }
}

void height(const int x,
            const int y,
            const int *z,
            struct surface *sinfo)
{
    if (sinfo->is_paralell == 0) {
        height_isometric(x, y, z, sinfo);
    } else if (sinfo->is_paralell == 1) {
        height_paralell(x, y, z, sinfo);
    }
}

