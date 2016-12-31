#ifndef _MENU_H_
#define _MENU_H_
#include <stdlib.h>
#include "window.h"

// A single entry in a menu. The text is what is shown immediately to the user.
// The action is executed when the option is selected. The action could be, for
// instance, another menu.
struct option_t
{
	const char *text;
	const char *long_description;
	void (*action)(void);
};

struct menu_t
{
	struct option_t *options;
	size_t num_options;
};

// Runs the action specified by an `option_t`
// -> (option): The option for which to run the action. If there is no action
// associated with the option (NULL), nothing happens.
void
run_option(const struct option_t *option);

// Draws a box with the specified corners.
// <- (x0, y0): The top right corner
// <- (x1, y1): The bottom left corner
void
draw_box(int x0, int y0, int x1, int y1);

// Draws the menu on the given window. The menu is drawn in the center.
// <- (window): The window to display on.
// <- (menu): The menu to be display.
void
draw_menu(struct window_t *window, const struct menu_t *menu);

// This synchronously runs the menu. It will display the options and wait for
// the user to select one, then execute that option's action.
// <> (window): The window to be display the menu on.
// <- (menu): The menu to show the user.
void
run_menu(struct window_t *window, const struct menu_t *menu);

// This initializes ncurses colors for menu use.
// <- (return): Returns zero when the colors were successfully initialized,
//     nonzero otherwise.
int
initialize_colors();


// These constants are the color pairs used for drawing things.
extern const int HIGHLIGHT_COLOR;

#endif // _MENU_H_
