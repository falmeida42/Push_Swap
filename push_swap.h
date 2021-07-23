/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:37:56 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/23 17:30:49 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct t_list
{
	int				valor;
	int				index;
	struct t_list	*proximo;
}t_list;

/* Moviments*/
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	swap(t_list **stack);
void	push(t_list **stack_src, t_list **stack_dst);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
/* Moviments */

/* Moviments1 */
void	swap_a(t_list **primeirono);
void	swap_b(t_list **primeirono);
void	swap_a_b(t_list **primeirono, t_list **primeironob);
void	push_a(t_list **primeirono, t_list **primeironob);
void	push_b(t_list **primeirono, t_list **primeironob);
/* Moviments1 */

/* Moviments2 */
void	rotate_a(t_list **primeirono);
void	rotate_b(t_list **primeirono);
void	rotate_ab(t_list **primeirono, t_list **primeironob);
void	reverse_rotate_a(t_list **primeirono);
void	reverse_rotate_b(t_list **primeirono);
/* Moviments2 */

/* Moviments3 */
void	reverse_rotate_ab(t_list **primeirono, t_list **primeironob);
/* Moviments3 */

/* Check error */
bool	check_dup(t_list *stack_a);
bool	check_char(char *argv);
bool	check_error(int argc, char **argv);
/* Check error */

/* Utils */
int		map_val(t_list *stack);
int		map_min(t_list *stack);
int		ft_atoi(const char *str);
bool	sorted(t_list *primeirono);
bool	max_list(t_list *stack);
long	ft_atol(char *str);
int		map_max(t_list *stack);
/* Utils */

/* Utils list */
void	ft_lstadd_back(t_list **lst, t_list *newno);
void	no_esquerda(t_list **primeirono, int valor);
void	delet_esquerda(t_list **primeirono);
void	no_direita(t_list *primeirono, int valor, int index);
void	delet_direita(t_list *primeirono);
/* Utils list */

/* Utils list 2 */
int		lst_size(t_list *stack);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
/* Utils list 2 */

/* Algo 100 */
void	cont_index(t_list **stack_a);
void	decide_b(t_list **stack_a, t_list **stack_b, int chunk, int size);
void	print_index(t_list *stack_a);
void	algo_100(t_list **stack_a, t_list **stack_b);
void	algo_5(t_list **stack_a, t_list **stack_b);
int		find_val(t_list *stack_a, int valor);
/* Algo 100 */

/* Decisions */
void	decisions(t_list **stack_a, t_list **stack_b, int chunk, int size);
/* Decisions */

#endif
