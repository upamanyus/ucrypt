// Copyright (c) 2016 Upamanyu Sharma

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
};

struct menu_t
{
	struct option_t *options;
	size_t num_options;
};

// Draws the menu on the given window. The menu is drawn in the center.
// <- (window): The window to display on.
// <- (menu): The menu to be display.
void
draw_menu(struct window_t *window, const struct menu_t *menu);

// This synchronously runs the menu. It will display the options and wait for
// the user to select one, then execute that option's action.
// <> (window): The window to be display the menu on.
// -> (menu): The menu to show the user.
// <- (return): The option selected by the user.
int
run_menu(struct window_t *window, const struct menu_t *menu);

#endif // _MENU_H_
