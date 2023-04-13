/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-17 - 14:40 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: surface isometric
 */

#include "fonction.h"
#include <lapin.h>

static void surface_isometric_X(const int x,
                                const int y,
                                const int z,
                                struct surface *sinfo)
{
    t_bunny_position pos_a;
    t_bunny_position pos_b;
    int X;
    int Y;

    X = 0;
    Y = 0;
    while (Y <= y - 1) {
        while (X < x - 1) {
            pos_a = project_isometric(X, Y, z, sinfo->pas);
            pos_a.x += sinfo->width;
            pos_a.y += sinfo->height;
            pos_b = project_isometric((X + 1), Y, z, sinfo->pas);
            pos_b.x += sinfo->width;
            pos_b.y += sinfo->height;
            stu_draw_line(sinfo->px, &pos_a, &pos_b, mk_colour(0, 0, 255, 1));
            X += 1;
        }
        X = 0;
        Y += 1;
    }
}

static void surface_isometric_Y(const int x,
                                const int y,
                                const int z,
                                struct surface *sinfo)
{
    t_bunny_position pos_a;
    t_bunny_position pos_b;
    int X;
    int Y;

    X = 0;
    Y = 0;
    while (X <= x - 1) {
        while (Y < y - 1) {
            pos_a = project_isometric(X, Y, z, sinfo->pas);
            pos_a.x += sinfo->width;
            pos_a.y += sinfo->height;
            pos_b = project_isometric(X, (Y + 1), z, sinfo->pas);
            pos_b.x += sinfo->width;
            pos_b.y += sinfo->height;
            stu_draw_line(sinfo->px, &pos_a, &pos_b, mk_colour(0, 0, 255, 1));
            Y += 1;
        }
        Y = 0;
        X += 1;
    }
}

static void surface_paralell_X(const int x,
                        const int y,
                        const int z,
                        struct surface *sinfo)
{
    t_bunny_position pos_a;
    t_bunny_position pos_b;
    int X;
    int Y;

    X = 0;
    Y = 0;
    while (Y <= y - 1) {
        while (X < x - 1) {
            pos_a = project_paralell(X, Y, z, sinfo->pas);
            pos_a.x += sinfo->width;
            pos_a.y += sinfo->height;
            pos_b = project_paralell((X + 1), Y, z, sinfo->pas);
            pos_b.x += sinfo->width;
            pos_b.y += sinfo->height;
            stu_draw_line(sinfo->px, &pos_a, &pos_b, mk_colour(0, 0, 255, 1));
            X += 1;
        }
        X = 0;
        Y += 1;
    }
}

static void surface_paralell_Y(const int x,
                        const int y,
                        const int z,
                        struct surface *sinfo)
{
    t_bunny_position pos_a;
    t_bunny_position pos_b;
    int X;
    int Y;

    X = 0;
    Y = 0;
    while (X <= x - 1) {
        while (Y < y - 1) {
            pos_a = project_paralell(X, Y, z, sinfo->pas);
            pos_a.x += sinfo->width;
            pos_a.y += sinfo->height;
            pos_b = project_paralell(X, (Y + 1), z, sinfo->pas);
            pos_b.x += sinfo->width;
            pos_b.y += sinfo->height;
            stu_draw_line(sinfo->px, &pos_a, &pos_b, mk_colour(0, 0, 255, 1));
            Y += 1;
        }
        Y = 0;
        X += 1;
    }
}

void surface(const int x,
             const int y,
             const int z,
             struct surface *sinfo)
{
    if (sinfo->is_paralell == 0) {
        surface_isometric_X(x, y, z, sinfo);
        surface_isometric_Y(x, y, z, sinfo);
    } else if (sinfo->is_paralell == 1) {
        surface_paralell_X(x, y, z, sinfo);
        surface_paralell_Y(x, y, z, sinfo);
    }
}
