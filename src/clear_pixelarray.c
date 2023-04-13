/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-08 - 09:49 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: clear pixel
 */

#include <lapin.h>

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color)
{
    int i;
    int width;
    int height;
    int px;
    unsigned int *tmp;

    i = 0;
    width = pxa->clipable.clip_width;
    height = pxa->clipable.clip_height;
    px = width * height;
    tmp = (unsigned int *) pxa -> pixels;
    while (i <= px) {
        tmp[i] = color;
        i += 1;
    }
}
