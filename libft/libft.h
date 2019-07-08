/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:47:02 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 12:42:25 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define SIZEMAX 65535

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			*ft_strlower(char *str);
int				err_putchar(int c);
char			*ft_strshift(char *str, int shift);
char			*ft_strtrim_quote(char *s);
int				str_isalnum(char *str);
void			ft_put_dblstr(char **str);
int				ft_dbl_strlen(char **str);
void			ft_dbl_strdel(char **str);
char			*ft_strjoinfree(char *s1, char const *s2);
char			**dbl_strdup(char **env);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(long long int n);
char			**ft_strsplit(char const *s, char c);
char			*ft_strtrim(char const *s);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_strdupfree(char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, char *src);
char			*ft_strncat(char *dest, const char *src, size_t nb);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *dst, const char *src);
char			*ft_strnstr(const char *dst, const char *src, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
long	int		ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_lstlen(t_list *lst);
t_list			*ft_lstsearch(t_list *lst, const void *content);
t_list			*ft_lstcat(t_list *dest, t_list *src);
void			ft_lstrev(t_list *lst);
t_list			**ft_lstsplit(t_list *lst);
char			*ft_strupper(char *str);
char			*ft_strndup(const char *s, int n);
int				ft_power(int nbr, int power);
char			*ft_utoa(unsigned long int n);
char			*ft_strrev(char *str);
char			*convert_binary(int dec);
char			*ft_chrjoin(char *s, char c);
char			*ft_strrdel(char *s, int c);
char			*ft_itoa_base(unsigned long int value, int base);
char			*field_width(int count, char c);
int				ft_chrlen(const char *str, char c);
int				ft_strstrindex(const char *dst, const char *src);
int				ft_strchrindex(const char *s, int c);
char			**ft_strsplit_quote(char *str, char c);
void			*ft_remalloc(char *str, size_t size);
char			**ft_realloc_double(char **str, size_t size);
char			*ft_realloc(char *str, size_t size);
int				ft_strrchrindex(const char *s, int c);
int				ft_chrlen_quote(const char *str, int c);
char			*ft_strchr_quote(const char *str, int c);

#endif
