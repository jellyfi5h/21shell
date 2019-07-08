/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 06:19:50 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/20 03:32:27 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"
#include "../../includes/termcap.h"

static	void	return_key_heredoc(struct s_termcap *info)
{
	return_line(info);
	info->content = ft_strjoinfree(info->content, "\n");
	ft_putstr("\n>> ");
	free(info->line);
	info->line = (char*)ft_memalloc(1);
}

static	void	handler_doc(int sig)
{
	if (sig == SIGINT)
	{
		exit(1);
	}
}

static	int		here_doc_file(char *content, int here_doc_pipe)
{
	int	fd;

	fd = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd(content, fd);
	close(fd);
	if (here_doc_pipe == 1)
		exit(0);
	fd = open(".here_doc", O_RDONLY, 0666);
	return (fd);
}

static	void	set_here_doc(struct s_termcap *doc)
{
	disable_term();
	doc->prompt = ft_strdup(">> ");
	ft_putstr(doc->prompt);
	doc->line = (char*)ft_memalloc(1);
	doc->content = (char*)ft_memalloc(1);
	doc->cursor = (struct s_cursor){3, 1, 3};
}

int				read_here_doc(char *keyword, int here_doc_pipe)
{
	char				buff[5];
	struct s_termcap	doc;

	set_here_doc(&doc);
	ft_bzero(buff, 5);
	signal(SIGINT, handler_doc);
	while (read(0, buff, 4) > 0)
	{
		if (buff[0] == '\n' && buff[1] == '\0')
		{
			if (ft_strequ(doc.line, keyword))
			{
				ft_putchar('\n');
				break ;
			}
			return_key_heredoc(&doc);
		}
		else if (*((int *)buff) == CTRL_D)
			end_of_life(&doc.line, doc.cursor, NULL);
		else
			read_input_keys(&doc, buff);
		tputs(tgoto(tgetstr("ch", NULL), 0, doc.cursor.co), 1, err_putchar);
		ft_bzero(buff, 5);
	}
	return (here_doc_file(doc.content, here_doc_pipe));
}
