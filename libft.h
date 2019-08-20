/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:52:20 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:31:10 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

# define BUFF_SIZE 100

char				*ft_strtrim_all(char const *s);
t_coord				*ft_create_coords(int x, int y);
void				ft_get_coords(t_coord *dst, int x, int y);
size_t				ft_strchrpos(char const *s, char c);
size_t				ft_sqrt(size_t nb, int opt);
size_t				ft_countchars(char const *s, char c);
int					get_next_line(const int fd, char **line);
long				ft_strcpy_whilech(char **dst, char *src, char c);
char				*ft_itoa_base(long n, int osn, int opt);
size_t				ft_countwords(char const *s);
size_t				ft_numlen(size_t num);
t_list				*ft_lstsplit(char const *s, char c);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memrevcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
void				ft_strchr_replace(char **s, int old, int new);
void				ft_strchr_swap(char **s, int a, int b);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack,
		const char *needle);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
int					ft_atoi(const char *str);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strrejoin(char *s1, char *s2);

/*
**		ft_printf
*/

#include <stdarg.h>
#include <stdint.h>

typedef struct		s_options
{
	int     left_side;
	int     sign;
	int     space;
	int     alt_out;
	int     zeros;
	int     width;
	int     prec;
	char    *len_mod;
	char    type;
}					t_options;

int					ft_printf(const char *format, ...);
int					prepare_opt(char *format, size_t *begin, va_list *args);
int					print_type(t_options *opt, va_list *args);

/*
**      func for 's' conv
*/

void				define_width(char *format, int *width, size_t *i);
void				define_prec(char *format, int *prec, size_t *i);
int					flags(t_options *opt, char c);
int					parse_type(t_options *opt, char c);
void				parse_len_mod(t_options *opt, char *format);

/*
**      func for 'd' conv
*/

int					count_and_free(char *buff);
int					length(size_t n, size_t base);
char				*ft_itoa_sizet(size_t nb, size_t base, int uppercase);
void				set_sign(char *s, int *signfp, int *i, int side);
void				apply_len_mod(intmax_t *n, char *len_mod);
void				create_signfp(int *signfp, t_options *opt, intmax_t n);
char				*create_buff(t_options *opt, int lennum, int signfp);
void				left_side_output(char *buff, int signfp,
		t_options *opt, char *num);
void				right_side_output(char *buff, int signfp,
		t_options *opt, char *num);
char				*create_dig_output(char *num, t_options *opt, int signfp);

/*
**      func for 'uoxX' conv
*/

void				create_signfp_u(int *signfp, t_options *opt, uintmax_t n);
void				apply_len_mod_u(uintmax_t *n, char *len_mod);
char				set_sign_u(int signfp);
void				set_len_from_signfp(int *len, int signfp);

/*
**      func for 'fF' conv
*/

char				*mant_double(char *mant, char *num, int denorm, int dcase);
char				*rounding(char *num, t_options *opt, int i, int j);
char				*create_fnum(char *mant, int exp, int denorm, int dcase);
char				*bits_div(char *bits, t_options *opt, int dcase);
char				*ft_itoa_double(double *n, t_options *opt, int *signfp);
void				overf(char *buf, int i);
void				summ(char *t, char **buf, int i);
void				divis(char **buf, int i);
char				*ft_itoa_longdouble(long double *n,
		t_options *opt, int *signfp);
void				set_fsignfp(char *num, int *signfp, int i);
void				create_fsignfp(int *signfp, t_options *opt, char *bits);
char				*create_float_output(char *num, t_options *opt, int signfp);
char				*is_inf(char *bits, t_options *opt);

/*
**      types
*/

int					print_f(double n, t_options *opt);
int					print_lf(long double n, t_options *opt);
int					print_p(void *p, t_options *opt);
int					print_s(char *s, t_options *opt);
int					print_c(char c, t_options *opt);
int					print_d(intmax_t n, t_options *opt);
int					print_u(uintmax_t u, t_options *opt);
int					print_o(uintmax_t o, t_options *opt);
int					print_x(uintmax_t u, t_options *opt);

/*
**      libft func
*/

char				*ft_optstrrejoin(char *s1, char *s2, int opt);
int					ft_atoi_binary(char *s);
void				make_str_upper(char *s);


#endif
