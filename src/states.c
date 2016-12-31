// Copyright (c) 2016 Upamanyu Sharma

#include "interactive.h"
#include "window.h"
#include "menu.h"

const state_function_t state_table[] =
{
	do_state_initial, do_state_encrypt,
};

enum state_t
do_state_initial(void)
{
	struct window_t *window = create_full_window();
	struct option_t options[] =
	{
		{"Encrypt", "Encrypt text using a known key"},
		{"Decrypt", "Decrypt text using a known key"},
	};
	struct menu_t menu = {options, 2};

	int selected_option = run_menu(window, &menu);
	delete_window(window);

	enum state_t next_state = STATE_ENCRYPT;
	if (selected_option == 0)
	{
		next_state = STATE_ENCRYPT;
	}
	else if (selected_option == 1)
	{
		next_state = STATE_ENCRYPT;
	}
	return next_state;
}

enum state_t
do_state_encrypt(void)
{
	return STATE_EXIT;
}
