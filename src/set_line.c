/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-09 - 11:27 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: set line
 */

#include <lapin.h> // For all bunny_ things
#include "fonction.h"

static void stu_draw_line_AA(t_bunny_pixelarray *px,
                             t_bunny_position *pos_a,
                             t_bunny_position *pos_b,
                             unsigned int color)
{
    int k;
    int l;
    t_bunny_position pos;

    k = pos_a->x;
    l = pos_a->y;
    if ((pos_b->x - pos_a->x) >= (pos_b->y - pos_a->y)) {
        while (k <= pos_b->x) {
            pos.x = k;
            pos.y = get_value(pos_a->y, pos_b->y,
                              get_ratio(pos_a->x, pos_b->x, k));
            stu_set_pixel(px, &pos, color);
            k += 1;
        }
    } else if ((pos_b->x - pos_a->x) < (pos_b->y - pos_a->y)) {
        while (l <= pos_b->y) {
            pos.y = l;
            pos.x = get_value(pos_a->x, pos_b->x,
                              get_ratio(pos_a->y, pos_b->y, l));
            stu_set_pixel(px, &pos, color);
            l += 1;
        }
    }
}

static void stu_draw_line_AB(t_bunny_pixelarray *px,
                             t_bunny_position *pos_a,
                             t_bunny_position *pos_b,
                             unsigned int color)
{
    int k;
    int l;
    t_bunny_position pos;

    k = pos_a->x;
    l = pos_b->y;
    if ((pos_b->x - pos_a->x) >= (pos_a->y - pos_b->y)) {
        while (k <= pos_b->x) {
            pos.x = k;
            pos.y = get_value(pos_a->y, pos_b->y,
                              get_ratio(pos_a->x, pos_b->x, k));
            stu_set_pixel(px, &pos, color);
            k += 1;
        }
    } else if ((pos_b->x - pos_a->x) < (pos_a->y - pos_b->y)) {
        while (l <= pos_a->y) {
            pos.y = l;
            pos.x = get_value(pos_a->x, pos_b->x,
                              get_ratio(pos_a->y, pos_b->y, l));
            stu_set_pixel(px, &pos, color);
            l += 1;
        }
    }
}

static void stu_draw_line_BA(t_bunny_pixelarray *px,
                             t_bunny_position *pos_a,
                             t_bunny_position *pos_b,
                             unsigned int color)
{
    int k;
    int l;
    t_bunny_position pos;

    k = pos_b->x;
    l = pos_a->y;
    if ((pos_a->x - pos_b->x) >= (pos_b->y - pos_a->y)) {
        while (k <= pos_a->x) {
            pos.x = k;
            pos.y = get_value(pos_a->y, pos_b->y,
                              get_ratio(pos_a->x, pos_b->x, k));
            stu_set_pixel(px, &pos, color);
            k += 1;
        }
    } else if ((pos_a->x - pos_b->x) < (pos_b->y - pos_a->y)) {
        while (l <= pos_b->y) {
            pos.y = l;
            pos.x = get_value(pos_a->x, pos_b->x,
                              get_ratio(pos_a->y, pos_b->y, l));
            stu_set_pixel(px, &pos, color);
            l += 1;
        }
    }
}

static void stu_draw_line_BB(t_bunny_pixelarray *px,
                             t_bunny_position *pos_a,
                             t_bunny_position *pos_b,
                             unsigned int color)
{
    int k;
    int l;
    t_bunny_position pos;

    k = pos_b->x;
    l = pos_b->y;
    if ((pos_a->x - pos_b->x) >= (pos_a->y - pos_b->y)) {
        while (k <= pos_a->x) {
            pos.x = k;
            pos.y = get_value(pos_a->y, pos_b->y,
                              get_ratio(pos_a->x, pos_b->x, k));
            stu_set_pixel(px, &pos, color);
            k += 1;
        }
    } else if ((pos_a->x - pos_b->x) < (pos_a->y - pos_b->y)) {
        while (l <= pos_a->y) {
            pos.y = l;
            pos.x = get_value(pos_a->x, pos_b->x,
                              get_ratio(pos_a->y, pos_b->y, l));
            stu_set_pixel(px, &pos, color);
            l += 1;
        }
    }
}

void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color)
{
    if (pos_a->x <= pos_b->x && pos_a->y <= pos_b->y) {
        stu_draw_line_AA(px, pos_a, pos_b, color);
    } else if (pos_a->x <= pos_b->x && pos_a->y > pos_b->y) {
        stu_draw_line_AB(px, pos_a, pos_b, color);
    } else if (pos_a->x > pos_b->x && pos_a->y <= pos_b->y) {
        stu_draw_line_BA(px, pos_a, pos_b, color);
    } else {
        stu_draw_line_BB(px, pos_a, pos_b, color);
    }
}
