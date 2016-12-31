// Copyright (c) 2016 Upamanyu Sharma

#ifndef _INTERACTIVE_H_
#define _INTERACTIVE_H_

enum state_t {STATE_INITIAL, STATE_ENCRYPT, STATE_EXIT};

typedef enum state_t (*state_function_t)(void);

enum state_t
do_state_initial(void);

enum state_t
do_state_encrypt(void);

extern const state_function_t state_table[];

// Initializes ncurses for use by ucrypt.
void
initialize_ncurses(void);

// Cleans up ncurses stuff
void
cleanup_ncurses(void);

// Runs the interactive mode of ucrypt
// < (return): Returns the exit status; 0 if everything went fine, nonzero
// otherwise.
int
run_interactive(void);

#endif // _INTERACTIVE_H_
