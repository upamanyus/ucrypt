#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <ncurses.h>

// This stores some extra data (size, position) about the window to assist in
// drawing functions.
struct window_t
{
	WINDOW *win;
	int x;
	int y;
	int w;
	int h;
};

// Creates a window_t object
// -> (x): X position of the window from the top left corner
// -> (y): Y position of the window from the top left corner
// -> (w): Width of the desired window
// -> (h): Height of the desired window
// <- (return): The window_t for the requested parameter. If something went
//     wrong, this returns NULL.
struct window_t*
create_window(int x, int y, int w, int h);

// Frees up the window
// <> (window): A valid window_t; after this function, the window should not be
//     used because it will be invalidated.
void
delete_window(struct window_t *window);

// Prints the given string centered on the window
// -> (window): The window to print to
// -> (str): The string to print
// -> (y): The height to print at
void
print_centered(struct window_t *window, const char *str, int y);

void
update_window();

// Prints the given string centered on the window, with highlight
// -> (window): The window to print to
// -> (str): The string to print
// -> (y): The height to print at
void
print_centered_highlighted(struct window_t *window, const char *str, int y);

#endif // _WINDOW_H_
