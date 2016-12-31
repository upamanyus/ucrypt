#ifndef _INTERACTIVE_H_
#define _INTERACTIVE_H_

// Initializes ncurses for use by ucrypt.
void
initialize_ncurses();

// Cleans up ncurses stuff
void
cleanup_ncurses();

// Runs the interactive mode of ucrypt
// < (return): Returns the exit status; 0 if everything went fine, nonzero
// otherwise.
int
run_interactive();

#endif // _INTERACTIVE_H_
