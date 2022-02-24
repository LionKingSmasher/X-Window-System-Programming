// Header file for Xlib
#include <X11/Xlib.h>

// Header file for the C Standard library
#include <stdio.h>
#include <stdlib.h>

Display* display;

int main(int argc, char** argv){
    int display_num;
    Window rootWin, win;
    int screen_width, screen_height;
    unsigned long white_pixel, black_pixel;
    unsigned int win_x = 0, win_y = 0;
    unsigned int border_width = 4;
    unsigned int win_width = 800, win_height = 600;

    char* display_name = NULL, *progname = argv[0];
    // Connect to X Server
    if(!(display = XOpenDisplay(display_name))) {
        fprintf(stderr, "[%s] Cannot Connect to X Server!\n", progname);
        exit(-1);
    }

    display_num = DefaultScreen(display);
    screen_width = DisplayWidth(display, display_num);
    screen_height = DisplayHeight(display, display_num);
    rootWin = RootWindow(display, display_num);
    white_pixel = WhitePixel(display, display_num);
    black_pixel = BlackPixel(display, display_num);

    printf("[%s] Connect to Screen number %d!\n", progname, display_num);
    printf("[%s] Width: %d Height: %d\n", progname, screen_width, screen_height);
    printf("[%s] White: %ld Black: %ld\n", progname, white_pixel, black_pixel);

    win = XCreateSimpleWindow(display,
                              rootWin,
                              win_x,
                              win_y,
                              win_width,
                              win_height,
                              border_width,
                              black_pixel,
                              white_pixel);

    XMapWindow(display, win);

    // while(1);

    XCloseDisplay(display);
    return 0;
}