/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-09 - 16:30 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: refresh
 */

#include <lapin.h>

void refresh(t_bunny_window *win,
             t_bunny_pixelarray *px,
             t_bunny_position origin)
{
    bunny_blit(&win->buffer, &px->clipable, &origin);
    bunny_display(win);
    usleep(1e6);
}
