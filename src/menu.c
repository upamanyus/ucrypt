#include "menu.h"

#include <string.h>
#include <ncurses.h>

const int HIGHLIGHT_COLOR = 1;

void
draw_menu(struct window_t *window, const struct menu_t *menu)
{
	for (int j = 0; j < menu->num_options; j++)
	{
		int y = window->h/2 - (menu->num_options)/2 + j;
		print_centered(window, menu->options[j].text, y);
	}
}

void
draw_menu_with_focus(struct window_t *window, const struct menu_t *menu, int focused_option)
{
	for (int j = 0; j < menu->num_options; j++)
	{
		int y = window->h/2 - (menu->num_options)/2 + j;
		if (j == focused_option)
		{
			print_centered_highlighted(window, menu->options[j].text, y);
		}
		else
		{
			print_centered(window, menu->options[j].text, y);
		}
	}
}

void
run_menu(struct window_t *window, const struct menu_t *menu)
{
	int focused_option = 0;
	bool quit = false;
	while (quit == false)
	{
		draw_menu_with_focus(window, menu, focused_option);
		wrefresh(window->win);
		int ch;
		ch = getch();
		if (ch == KEY_DOWN)
		{
			focused_option++;
			if (focused_option >= menu->num_options - 1)
			{
				focused_option = menu->num_options - 1;
			}
		}
		else if (ch == KEY_UP)
		{
			focused_option--;
			if (focused_option <= 0)
			{
				focused_option = 0;
			}
		}
		else if (ch == KEY_ENTER || ch == 10 || ch == 13)
		{
			menu->options[focused_option].action();
		}
		else if(ch == 'q' || ch == 'Q')
		{
			quit = true;
		}
	}
}
