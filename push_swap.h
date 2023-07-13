/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:47:44 by tpenalba          #+#    #+#             */
/*   Updated: 2023/07/13 17:33:10 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct data
{
	int				len;
	int				*tab;
	int				*index;
	struct t_data	*pile_a;
	struct t_data	*pile_b;
	int				len_a;
	int				len_b;
	char			**output;
	int				nbr;
}	t_data;

typedef struct s_pile
{
	long int			value;
	struct s_pile		*next;
}	t_pile;

//utils
// static size_t		count_words(char const *str, char c);
// static char			*ft_copystring(char const *s, char c, int i);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);
// static	int			ft_is_numeric(int c);
size_t				ft_strlen(const char *str);
//int					get_len(int *tab);

//chekinput

int					ft_checkargs(int argc, char **argv, t_data *data);
void				error404(void);
void				ft_checkoccurence(int *tab, t_data *data);
void				onearg(int argc, char **argv, t_data *data);
int					convert(int argc, char **argv, t_data *data);
void				ft_indexation(t_data *data);
char				**ft_alloc_output(char **argv, t_data *data, int argc);

//pile utils
void				add_data_to_list(t_pile **list_data, int nb);
int					ft_fill(t_data *data, t_pile **pile_a);
void				print_list(t_pile *pile_a);

//swap
void				swap(t_pile **pile);
void				swap_a(t_pile **pile_a);
void				swap_b(t_pile **pile_b);

//push
void				push(t_pile **src, t_pile **dst);
void				push_pa(t_pile **pile_b, t_pile **pile_a);
void				push_pb(t_pile **pile_a, t_pile **pile_b);

//rotate
void				rotate(t_pile **pile);
void				rotate_a(t_pile **pile_a);
void				rotate_b(t_pile **pile_b);
void				rotate_both(t_pile **pile_a, t_pile **pile_b);

void				reverse_rotate(t_pile **pile);
void				reverse_rotate_a(t_pile **pile_a);
void				reverse_rotate_b(t_pile **pile_b);
void				reverse_rotate_both(t_pile **pile_a, t_pile **pile_b);

//algo
int					is_sort(t_pile **data);
void				radix(t_pile **pile_a, t_pile **pile_b, long int size);
void				sort_three(t_pile **pile_a);
void				sort_five(t_pile **pile_a, t_pile **pile_b);
//free
//void				ft_free(t_data *data);

#endif
