/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 23:44:37 by aboukhri          #+#    #+#             */
/*   Updated: 2019/07/08 15:43:35 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAP_H
# define TERMCAP_H
# include "../libft/libft.h"
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <fcntl.h>

# define K_UP 0x415b1b
# define K_RIGHT 0x435b1b
# define K_DOWN 0x425b1b
# define K_LEFT 0x445b1b
# define K_ESC 0x1b
# define K_DELETE 0x7e335b1b
# define K_RETURN 0xa
# define K_BACKSPACE 0x7f
# define K_HOME 0x485b1b
# define K_END 0x465b1b
# define ALT_LEFT 0x445b1b1b
# define ALT_RIGHT 0x435b1b1b
# define ALT_UP 0x415b1b1b
# define ALT_DOWN 0x425b1b1b
# define CTRL_D 0x4
# define CTRL_P 0x10
# define CTRL_T 0x14
# define CTRL_L 0xc

struct			s_cursor
{
	int		co;
	int		li;
	int		prompt;
};

typedef	struct	s_file
{
	int				index;
	char			*name;
	char			type;
	int				nav:1;
	struct s_file	*next;
}				t_file;

struct			s_history
{
	char			**list;
	int				index;
};

struct			s_autocomplete
{
	t_file		*files;
	char		*path;
	char		*filename;
	int			len_files;
	int			check_first:1;
	int			stop;
};

struct			s_termcap
{
	char					*content;
	char					*line;
	struct s_cursor			cursor;
	struct s_autocomplete	complete;
	struct s_history		history;
	char					*select;
	int						sig;
	char					*prompt;
};

/*
**	autocomplete
*/

int				get_word_index(char *line, int pos);
char			*str_word_index(char *line, int pos);
void			auto_complete(struct s_termcap *info, char buff[4]);
void			set_autocomplete(struct s_termcap *info);
void			free_autocomplete(struct s_autocomplete *complete);
char			*str_word_index(char *line, int pos);
int				nbr_line(t_file *file, int cl);
int				column_size(t_file *file);
char			*str_space(int size);
int				start_pos(char *line, struct s_cursor cursor);
t_file			*insert_files(char *line, int pos,
				struct s_autocomplete complete);
void			remove_lines(char *str);

/*
**	list_files
*/

t_file			*new_file(char *name, char type, int index, int nav);
t_file			*file_join(t_file *begin, t_file *end);
int				display_files(struct s_autocomplete complete);
int				file_len(t_file *file);
void			free_file(t_file *file);
void			sort_files(t_file **file);
int				file_exists(t_file *file, char *name);
void			put_files(t_file *files);

/*
**	edit line
*/

void			copy_line(char **copy, char *select);
void			cut_line(char **line, struct s_cursor *cursor, int pos);
void			print_line(char **line, char *copy, struct s_cursor *cursor);
void			write_line(char *line, struct s_cursor cursor);
void			delete_key(char **line, struct s_cursor *cursor, int size);
char			*delete_char(char *str, int pos);
void			paste_line(char **line, struct s_cursor *cursor, char *buff);
int				return_key(struct s_termcap *info);
void			clear_all_lines(struct s_cursor cursor);
void			reset_screen(struct s_termcap info);
void			edit_keys(int key, struct s_termcap *info);

/*
**	navigate cursor
*/

void			navigate_next_word(char *line, struct s_cursor *cursor);
void			navigate_previous_word(char *line, struct s_cursor *cursor);
void			navigate_keys(int key, struct s_termcap *info);
void			cursor_navigate_left(char *line, struct s_cursor *cursor);
void			cursor_navigate_right(char *line, struct s_cursor *cursor);
void			return_line(struct s_termcap *info);
void			navigate_lines(int key, struct s_termcap *info);
void			cursor_reset(char *line, struct s_cursor cursor);
void			cursor_end_line(struct s_termcap info);
void			home_end_keys(int key, struct s_termcap *info);

/*
**	quotes
*/

int				read_quote(char *line);

/*
**	select line
*/

void			select_text(struct s_termcap *info);
int				select_left(char *line, char **select,
				struct s_cursor *cursor, int pos);
int				select_right(char *line, char **select,
				struct s_cursor *cursor, int pos);

/*
**	select list files
*/

void			list_choices(t_file *files);
void			exit_select();
void			read_rightleft(int key, struct s_autocomplete complete,
				t_file **pos);
void			read_updown(int key, struct s_autocomplete complete,
				t_file **pos);
int				is_column(int co, int li, int cl, int len);
void			read_select_keys(int k, struct s_autocomplete complete,
				t_file **pos);

/*
**	history
*/

void			history_keys(struct s_termcap *info, int key);

/*
**	get info of line and cursor
*/

struct s_cursor	last_cursor(char *line, int prompt);
struct s_cursor	cursor_index(char *line, int pos, int prompt);
int				line_index(char *line, struct s_cursor cursor);

/*
**	readline
*/

void			read_input_keys(struct s_termcap *info, char *buff);
void			set_readline(struct s_termcap *info);

/*
**	helpful_func
*/

int				sum_key(char *buff);
int				key_is_str(char *buff);
void			edit_str(char **line, char *copy, int pos);
char			*transform_filename(char *file);

/*
**	termios
*/

void			enable_term();
void			disable_term();

#endif
