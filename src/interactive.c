#include "interactive.h"
#include "menu.h"

#include <stdio.h>
#include <ncurses.h>

int
initialize_colors(void)
{
	if (has_colors() == FALSE)
	{
		return 1;
	}
	start_color();
	init_pair(HIGHLIGHT_COLOR, COLOR_BLACK, COLOR_RED);
	return 0;
}

void
initialize_ncurses(void)
{
	initscr();
	raw();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	refresh(); // TODO: Check if this is needed
}

void
cleanup_ncurses(void)
{
	endwin();
}

int
run_interactive(void)
{
	initialize_ncurses();
	initialize_colors();

	struct menu_t main_menu;
	struct option_t options[] = 
	{
		{"Encrypt", "Encrypt text with a known key", NULL},
		{"Decrypt", "Decrypt text with a known key", NULL},
	};
	main_menu.options = options;
	main_menu.num_options = 2;

	int w;
	int h;
	getmaxyx(stdscr, h, w);

	struct window_t *main_window = create_window(0, 0, w, h);
	run_menu(main_window, &main_menu);

	delete_window(main_window);
	cleanup_ncurses();

	return 0;
}
