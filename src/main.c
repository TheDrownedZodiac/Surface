/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-17 - 14:42 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: main
 */

#include "fonction.h"
#include <lapin.h> // For all bunny_ things
#include <unistd.h> // For usleep
#include <stdlib.h> // For EXIT_SUCCESS

const int z[] = {4, 3, 3, 2, 2, 2, 2, 3, 3, 4,
                 3, 3, 2, 2, 1, 1, 2, 2, 3, 3,
                 3, 2, 2, 1, 1, 1, 1, 2, 2, 3,
                 2, 2, 1, 1, 1, 1, 1, 1, 2, 2,
                 2, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                 2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                 2, 2, 1, 1, 1, 1, 1, 1, 1, 0,
                 3, 2, 2, 1, 1, 1, 1, 1, 0, -1,
                 3, 3, 2, 2, 1, 1, 1, 0, 0, -1,
                 4, 3, 3, 2, 2, 1, 0, -1, -1, -2};

static void project(t_bunny_window *win,
                    struct surface *sinfo,
                    t_bunny_position origin)
{
    clear_pixelarray(sinfo->px, mk_colour(0, 0, 0, 1));
    refresh(win, sinfo->px, origin);
    surface(sinfo->w, sinfo->h, 0, sinfo);
    refresh(win, sinfo->px, origin);
    height(sinfo->w, sinfo->h, z, sinfo);
    refresh(win, sinfo->px, origin);
    relief(sinfo->w, sinfo->h, z, sinfo);
    refresh(win, sinfo->px, origin);
}

int main(void)
{
    t_bunny_window *win;
    t_bunny_position origin;
    struct surface sinfo;

    sinfo.is_paralell = 1;
    sinfo.w = 10;
    sinfo.h = 10;
    sinfo.pas = 50;
    sinfo.width = 500;
    sinfo.height = 500;
    win = bunny_start(1000, 1000, false, "fl: Draw_line");
    sinfo.px = bunny_new_pixelarray(1000, 1000);
    origin.x = 0;
    origin.y = 0;
    project(win, &sinfo, origin);
    while (true) {
        usleep(1e7);
    }
    bunny_stop(win);
    return (EXIT_SUCCESS);
}
