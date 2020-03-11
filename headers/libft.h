/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 20:18:02 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/10 21:52:13 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

typedef char *						t_chrp;
typedef short int *					t_sintp;
typedef int *						t_intp;
typedef long int *					t_lintp;
typedef long long int *				t_llintp;
typedef unsigned char *				t_uchrp;
typedef unsigned short int *		t_ushintp;
typedef unsigned int *				t_uintp;
typedef unsigned long int *			t_ulintp;
typedef unsigned long long int *	t_ullintp;
typedef char						t_chr;
typedef short int					t_shint;
typedef int							t_int;
typedef long int					t_lint;
typedef long long int				t_llint;
typedef unsigned char				t_uchr;
typedef unsigned short int			t_ushint;
typedef unsigned int				t_uint;
typedef unsigned long int			t_ulint;
typedef unsigned long long int		t_ullint;
typedef double						t_dbl;
typedef long double					t_ldbl;

/*
** Type defs
*/
typedef	unsigned char			t_byte;
typedef unsigned char			t_bool;

union			u_binary64 {
	double						doubling;
	uint64_t					integer;
};

typedef struct	s_binary64
{
	unsigned char				sign;
	uint16_t					exponent;
	uint64_t					mantisa;
	double						actual;
	t_ullint					fullpart;
}				t_binary64;

union			u_binary128 {
	long double					doubling;
	__uint128_t					integer;
};

typedef struct	s_binary128
{
	unsigned char				sign;
	uint16_t					exponent;
	__uint128_t					mantisa;
	long double					actual;
	t_ullint					fullpart;
}				t_binary128;

typedef struct	s_double_s
{
	char						intreps[30];
	char						floatreps[100];
	int64_t						intrep;
	double						afterdot;
}				t_double_s;

typedef struct	s_list
{
	void						*content;
	size_t						content_size;
	struct s_list				*next;
}				t_list;
/*
** Pre-Def values
** Macroses Part 0
*/
# define INT_MIN_S 		"-2147483648"
# define INT_MAX_S 		"2147483647"
# define INT_S_L		10
# define LLINT_MIN_S 	"-9223372036854775808"
# define LLINT_MAX_S 	"9223372036854775807"
# define LLINT_S_L		19
# define ULLINT_MAX_S	"18446744073709551615"
# define ULLINT_S_L		20
# define TRUE 1
# define FALSE 0

/*
** Sizes
** Macroses Part 2
*/

/*
**	Strings
*/
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			**ft_split(char const *s, char c);
int				ft_strwordsdelim(const char *str, char delim);
int				ft_strlendelim(const char *str, char delim);
char			*ft_strdupdelim(const char *s1, char delim);
char			*ft_strtrimdelim(char const *s, char delim);
int				ft_strnumlen(char *str);
int				ft_strnumlen_inplace(const char **str);
int				ft_strdelim(char **dest, const char *s1, char delim);

/*
** Convertions
*/
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_strlower(char *str);
void			ft_strupper(char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
unsigned int	ft_itoa_base(
						char *str, void *number, int base, t_bool is_signed);

/*
**	System Writes
*/
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
void			ft_print_byte(t_byte byte);
void			ft_object_bit_print(size_t const size, void const *const ptr);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
/*
**	Memmory
*/
void			*ft_memalloc(size_t size);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memrealloc(
							void *content, size_t cur_size, size_t des_size);
void			*ft_memjoin(void *sh, const void *sn, size_t shl, size_t snh);
void			*ft_memdup(const void *cont, size_t size);
void			*ft_memshrink(void *area, void *start, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			ft_memdel(void **ap);

/*
**	C Type Checks
*/
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isnonprint(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isspace(int c, t_bool is_short);

/*
**	Math
*/
int				ft_floorsqrt(int toroot);
int64_t			ft_pow(int64_t num1, int power);
double			ft_dpow(double num1, int power);
long double		ft_ldpow(long double num1, int power);
unsigned int	ft_numlen(void *number, t_bool is_signed);
int				ft_abs(int x);
t_lint			ft_labs(t_lint x);
t_llint			ft_llabs(t_llint x);
t_llint			ft_max(t_llint chalenger, t_llint champion);
t_ullint		ft_umax(t_ullint chalenger, t_ullint champion);

/*
** Lists
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstnewp(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new_lst);
void			ft_lstaddend(t_list **alst, t_list *new_lst);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstpush(t_list **alst, t_list *new_lst);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstfrem(t_list **head);
t_list			*ft_lstlrem(t_list *head);
t_list			*ft_lstanydel(t_list *head, t_list *nd);

/*
** Real numbers
*/
void			ft_binary64(double value, t_binary64 *fmt);
void			ft_binary128(long double value, t_binary128 *fmt);
size_t			ft_dtos(
					double number, size_t ndigit, t_bool is_dot, char *buff);
size_t			ft_ldtos(
				long double number, size_t ndigit, t_bool is_dot, char *buff);

/*
**	Array
*/
t_bool			ft_in_array(const void *needle, const void *array,
												size_t blk_size, size_t size);

/*
**	Sorting
*/
void			ft_list_bubble_sort(t_list **list,
												t_bool (comp)(void *, void *));
void			ft_string_bubble_sort(char **strings, size_t count,
												t_bool (comp)(void *, void *));
#endif
