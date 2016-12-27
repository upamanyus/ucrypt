#include "menu.h"

#include <string.h>
#include <ncurses.h>

const int HIGHLIGHT_COLOR = 1;

void
print_centered(const char *str, int width, int y)
{
	int offset = width/2 - (strlen(str))/2;
	if (offset < 0)
	{
		offset = 0;
	}
	mvprintw(y, offset, "%s", str);
}

void
print_centered_highlighted(const char *str, int width, int y)
{
	int offset = width/2 - (strlen(str))/2;
	if (offset < 0)
	{
		offset = 0;
	}
	attron(COLOR_PAIR(HIGHLIGHT_COLOR));
	mvprintw(y, offset, "%s", str);
	attroff(COLOR_PAIR(HIGHLIGHT_COLOR));
}

void
draw_menu(struct menu_t *menu)
{
	int height = 0;
	int width = 0;
	getmaxyx(stdscr, height, width);
	for (int j = 0; j < menu->num_options; j++)
	{
		int y = height/2 - (menu->num_options)/2 + j;
		print_centered(menu->options[j].text, width, y);
	}
}

void
draw_menu_with_focus(struct menu_t *menu, int focused_option)
{
	int height = 0;
	int width = 0;
	getmaxyx(stdscr, height, width);
	for (int j = 0; j < menu->num_options; j++)
	{
		int y = height/2 - (menu->num_options)/2 + j;
		if (j == focused_option)
		{
			print_centered_highlighted(menu->options[j].text, width, y);
		}
		else
		{
			print_centered(menu->options[j].text, width, y);
		}
	}
}

void
run_menu(struct menu_t *menu)
{
	int focused_option = 0;
	bool quit = false;
	while (quit == false)
	{
		draw_menu_with_focus(menu, focused_option);
		int ch;
		ch = getch();
		if (ch == KEY_DOWN)
		{
			focused_option++;
		}
		else if (ch == KEY_UP)
		{
			focused_option--;
		}
		else if(ch == 'q' || ch == 'Q')
		{
			quit = true;
		}
	}
}
