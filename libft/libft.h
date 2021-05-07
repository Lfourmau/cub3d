/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:51:34 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/07 10:27:04 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define BUFFER_SIZE 5

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
** display
*/
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** bases conversions
*/
void			ft_putnbr_base(int nbr, char *base);
int				ft_atoi_base(char *str, char *base);

/*
** int to ascii (or reverse)
*/
int				ft_atoi(const char *str);
char			*ft_itoa(int nb);
char			*ft_itoa_base(long long int nb, char *base);

/*
** str funcs
*/
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *prefixe, char const *suffixe);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t size);
char			**ft_split(char const *str, char sep);
char			*ft_substr(char const *s, unsigned int start, size_t len);

/*
**  isthat funcs
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int nbr);
int				ft_isspace(char c);

/*
**  memory funcs
*/
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *memzone, int octet, size_t len);
void			ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t nbelements, size_t size);

/*
**  list manip
*/
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *str, char const *set);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));

/*
**  get_next_line
*/
int				get_next_line(int fd, char **line);
char			*gnl_loop(char *buffer, char *tmp, int *read_return, int fd);

#endif
