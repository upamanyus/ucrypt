#include "interactive.h"
#include "menu.h"

#include <stdio.h>
#include <ncurses.h>

int
initialize_colors()
{
	if (has_colors() == FALSE)
	{
		return 1;
	}
	start_color();
	init_pair(HIGHLIGHT_COLOR, COLOR_BLACK, COLOR_WHITE);
	return 0;
}

int
run_interactive()
{
	initscr();
	raw();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	initialize_colors();

	struct menu_t main_menu;
	struct option_t options[] = 
	{
		{"Encrypt", "Encrypt text with a known key", NULL},
		{"Decrypt", "Decrypt text with a known key", NULL},
	};
	main_menu.options = options;
	main_menu.num_options = 2;

	run_menu(&main_menu);

	refresh();
	endwin();

	return 0;
}
