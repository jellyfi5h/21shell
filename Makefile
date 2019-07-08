# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 01:57:49 by mfetoui           #+#    #+#              #
#    Updated: 2019/07/08 16:04:38 by aboukhri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/expansions.c src/helpful_func.c src/interpreter.c src/lexical_errors.c src/path_lexer.c src/signals.c src/termios.c src/vsh.c src/termcap/auto_complete/auto_completion.c src/termcap/auto_complete/display_files.c src/termcap/auto_complete/get_similar_files.c src/termcap/auto_complete/line_handle.c src/termcap/auto_complete/list_files.c src/termcap/auto_complete/manage_file.c src/termcap/auto_complete/reset_autocomplete.c src/termcap/auto_complete/str_handle.c src/termcap/edit_line/copy_cut.c src/termcap/edit_line/delete.c src/termcap/edit_line/edit_line.c src/termcap/edit_line/return_key.c src/termcap/navigate_cursor/cursor.c src/termcap/navigate_cursor/navigate_cursor.c src/termcap/navigate_cursor/navigate_lines.c src/termcap/navigate_cursor/navigate_word.c src/termcap/quotes/quotes.c src/termcap/select_line/select_line.c src/termcap/select_line/select_navigate.c src/termcap/select_list/display_select.c src/termcap/select_list/navigate_select.c src/termcap/select_list/select_keys.c src/termcap/history.c src/termcap/read_input.c src/termcap/termcap.c src/redirections/here_doc.c src/redirections/is_redirection.c src/redirections/redirection_handler.c src/redirections/redirection_lexer.c src/redirections/redirection_parser.c src/redirections/redirection_tools.c src/pipe/pipe.c src/pipe/pipe_utils.c src/builtins/builtins.c src/builtins/chdir.c src/builtins/echo.c src/builtins/env.c src/builtins/setenv.c src/builtins/unsetenv.c src/environ/list_env.c src/environ/manage_env.c 
NAME = 21sh
LIB = ./libft/libft.a

BOLDRED = \033[1;31m
ED =  \033[0m
all: $(NAME)
$(NAME):
	@echo "$(BOLDRED)Building 21sh ...$(ED)"				
	@echo "$(BOLDRED)██████╗  ██╗███████╗██╗  ██╗$(ED)"
	@sleep 0.3
	@echo "╚════██╗███║██╔════╝██║  ██║"
	@sleep 0.3
	@echo "$(BOLDRED) █████╔╝╚██║███████╗███████║$(ED)"
	@make -C libft
	@echo "██╔═══╝  ██║╚════██║██╔══██║"
	@sleep 0.3
	@echo "$(BOLDRED)███████╗ ██║███████║██║  ██║$(ED)"
	@gcc -Wall -Wextra -Werror $(LIB) $(SRC) -o $(NAME) -ltermcap
	@echo "╚══════╝ ╚═╝╚══════╝╚═╝  ╚═╝"

clean:
	@make clean -C libft
	@rm -f *.o

fclean: clean
	@echo "\033[1;34mcleaning 21sh ...$(ED)"
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
