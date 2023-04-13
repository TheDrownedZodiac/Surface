/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-18 - 12:18 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: fonction
 */

#include <lapin.h>
#include "struct.h"

#ifndef STU_H_

#define STU_H_

float get_ratio(int a, int b, int x);

int get_value(int a, int b, float ratio);

void surface(const int x,
             const int y,
             const int z,
             struct surface *sinfo);

t_bunny_position project_paralell(int x, int y, int z, int coef);

t_bunny_position project_isometric(int x, int y, int z, int coef);

void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color);

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);

unsigned int mk_colour(unsigned char r,
                       unsigned char g,
                       unsigned char b,
                       unsigned char a);

void stu_set_pixel(t_bunny_pixelarray *pxa,
                   t_bunny_position *pos,
                   unsigned int color);

void refresh(t_bunny_window *win,
             t_bunny_pixelarray *px,
             t_bunny_position origin);

void relief(const int x,
            const int y,
            const int *z,
            struct surface *sinfo);

void height(const int x,
            const int y,
            const int *z,
            struct surface *sinfo);

#endif
