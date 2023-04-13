/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-16 - 17:03 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: relief isometric
 */

#include "fonction.h"
#include <lapin.h>

static void relief_isometric_X(const int x,
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
        while (X < x - 1) {
            W = project_isometric(X, Y, z[i], sinfo->pas);
            W.x += sinfo->width;
            W.y += sinfo->height;
            V = project_isometric((X + 1), Y, z[i + 1], sinfo->pas);
            V.x += sinfo->width;
            V.y += sinfo->height;
            stu_draw_line(sinfo->px, &W, &V, mk_colour(0, 255, 0, 1));
            X += 1;
            i += 1;
        }
        i += 1;
        X = 0;
        Y += 1;
    }
}

static void relief_isometric_Y(const int x,
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
    while (Y < y - 1) {
        while (X <= x - 1) {
            W = project_isometric(X, Y, z[i], sinfo->pas);
            W.x += sinfo->width;
            W.y += sinfo->height;
            V = project_isometric(X, (Y + 1), z[i + x], sinfo->pas);
            V.x += sinfo->width;
            V.y += sinfo->height;
            stu_draw_line(sinfo->px, &W, &V, mk_colour(0, 255, 0, 1));
            X += 1;
            i += 1;
        }
        X = 0;
        Y += 1;
    }
}

static void relief_paralell_X(const int x,
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
        while (X < x - 1) {
            W = project_paralell(X, Y, z[i], sinfo->pas);
            W.x += sinfo->width;
            W.y += sinfo->height;
            V = project_paralell((X + 1), Y, z[i + 1], sinfo->pas);
            V.x += sinfo->width;
            V.y += sinfo->height;
            stu_draw_line(sinfo->px, &W, &V, mk_colour(0, 255, 0, 1));
            X += 1;
            i += 1;
        }
        i += 1;
        X = 0;
        Y += 1;
    }
}

static void relief_paralell_Y(const int x,
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
    while (Y < y - 1) {
        while (X <= x - 1) {
            W = project_paralell(X, Y, z[i], sinfo->pas);
            W.x += sinfo->width;
            W.y += sinfo->height;
            V = project_paralell(X, (Y + 1), z[i + x], sinfo->pas);
            V.x += sinfo->width;
            V.y += sinfo->height;
            stu_draw_line(sinfo->px, &W, &V, mk_colour(0, 255, 0, 1));
            X += 1;
            i += 1;
        }
        X = 0;
        Y += 1;
    }
}

void relief(const int x,
            const int y,
            const int *z,
            struct surface *sinfo)
{
    if (sinfo->is_paralell == 0) {
        relief_isometric_X(x, y, z, sinfo);
        relief_isometric_Y(x, y, z, sinfo);
    } else if (sinfo->is_paralell == 1) {
        relief_paralell_X(x, y, z, sinfo);
        relief_paralell_Y(x, y, z, sinfo);
    }
}
