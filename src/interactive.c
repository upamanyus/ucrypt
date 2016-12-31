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

	enum state_t current_state = STATE_INITIAL;
	while (current_state != STATE_EXIT)
	{
		current_state = state_table[current_state]();
	}

	cleanup_ncurses();

	return 0;
}
