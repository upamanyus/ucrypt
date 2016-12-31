#include "window.h"
#include <string.h>
#include <stdlib.h>

struct window_t*
create_window(int x, int y, int w, int h)
{
	struct window_t* window = (struct window_t*)malloc(sizeof(struct window_t));
	window->x = x;
	window->y = y;
	window->w = w;
	window->h = h;
	window->win = newwin(h, w, y, x);

	return window;
}

struct window_t*
create_full_window()
{
	int w;
	int h;
	getmaxyx(stdscr, h, w);
	return create_window(0, 0, w, h);
}

void
delete_window(struct window_t *window)
{
	delwin(window->win);
	free(window);
}

void
update_window(struct window_t *window)
{
	wrefresh(window->win);
}

void
print_centered(struct window_t *window, const char *str, int y)
{
	int offset = window->w/2 - (strlen(str))/2;
	if (offset < 0)
	{
		offset = 0;
	}
	mvwprintw(window->win, y, offset, "%s", str);
}

void
print_centered_highlighted(struct window_t *window, const char *str, int y)
{
	int offset = window->w/2 - (strlen(str))/2;
	if (offset < 0)
	{
		offset = 0;
	}
	wattron(window->win, A_STANDOUT);
	mvwprintw(window->win, y, offset, "%s", str);
	wattroff(window->win, A_STANDOUT);
}
