#ifndef _MENU_H_
#define _MENU_H_
#include <stdlib.h>

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

void
run_option(const struct option_t *option);

void
draw_menu(struct menu_t *menu);

void
run_menu(struct menu_t *menu);

extern const int HIGHLIGHT_COLOR;

#endif // _MENU_H_
