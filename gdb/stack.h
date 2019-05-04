/* Stack manipulation commands, for GDB the GNU Debugger.

   Copyright (C) 2003-2019 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef STACK_H
#define STACK_H

/* Access method used by the MI -stack-select-frame command to switch to
   frame FI.  This differs from SELECT_FRAME in that the observers for a
   user selected context change will be triggered.  */

void select_frame_for_mi (struct frame_info *fi);

gdb::unique_xmalloc_ptr<char> find_frame_funname (struct frame_info *frame,
						  enum language *funlang,
						  struct symbol **funcp);

typedef void (*iterate_over_block_arg_local_vars_cb) (const char *print_name,
						      struct symbol *sym,
						      void *cb_data);

void iterate_over_block_arg_vars (const struct block *block,
				  iterate_over_block_arg_local_vars_cb cb,
				  void *cb_data);

void iterate_over_block_local_vars (const struct block *block,
				    iterate_over_block_arg_local_vars_cb cb,
				    void *cb_data);

/* Initialize *WHAT to be a copy of the user desired print what frame info.
   If !WHAT.has_value (), the printing function chooses a default set of
   information to print, otherwise the printing function should print
   the relevant information.  */

void get_user_print_what_frame_info (gdb::optional<enum print_what> *what);

/* Return 1 if we should display the address in addition to the location,
   because we are in the middle of a statement.  */

int frame_show_address (struct frame_info *frame, struct symtab_and_line sal);

/* Get or set the last displayed symtab and line, which is, e.g. where we set a
 * breakpoint when `break' is supplied with no arguments.  */
void clear_last_displayed_sal (void);
int last_displayed_sal_is_valid (void);
struct program_space* get_last_displayed_pspace (void);
CORE_ADDR get_last_displayed_addr (void);
struct symtab* get_last_displayed_symtab (void);
int get_last_displayed_line (void);
symtab_and_line get_last_displayed_sal ();

/* Completer for the "frame apply all" command.  */
void frame_apply_all_cmd_completer (struct cmd_list_element *ignore,
				    completion_tracker &tracker,
				    const char *text, const char */*word*/);

#endif /* #ifndef STACK_H */
