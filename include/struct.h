/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-18 - 12:19 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: structure
 */

#include <lapin.h>

#ifndef STU_STRUCT_H_

#define STU_STRUCT_H_

struct surface {
    int width;
    int height;
    int pas;
    int w;
    int h;
    unsigned int is_paralell;
    t_bunny_pixelarray *px;
};

#endif
