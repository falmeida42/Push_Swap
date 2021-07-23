#include "push_swap.h"

void	algo_3(t_list **stack_a)
{
	t_list	*ax;
	int		a;
	int		b;
	int		c;

	ax = *stack_a;
	a = ax->valor;
	b = ax->proximo->valor;
	c = ax->proximo->proximo->valor;
	if (a > b && b < c && c > a)
		swap_a(stack_a);
	else if (a > b && b > c && c < a)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (a > b && b < c && c < a)
		rotate_a(stack_a);
	else if (a < b && b > c && c > a)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else
		reverse_rotate_a(stack_a);
}

void	algo_5(t_list **stack_a, t_list **stack_b)
{
	while (lst_size(*stack_a) > 3)
	{
		while ((*stack_a)->valor != map_val(*stack_a))
		{
			if (map_min(*stack_a) < lst_size(*stack_a) / 2)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
	}
	if (sorted(*stack_a) == false)
		algo_3(stack_a);
	while ((*stack_b) != NULL)
		push_a(stack_a, stack_b);
}

void	select_algo(t_list **stack_a, t_list **stack_b)
{
	int	nbr;

	nbr = lst_size(*stack_a);
	if (nbr == 2)
		swap_a(stack_a);
	else if (nbr == 3)
		algo_3(stack_a);
	else if (nbr <= 99)
		algo_5(stack_a, stack_b);
	else
	{
		cont_index(stack_a);
		algo_100(stack_a, stack_b);
	}
}

t_list	*fill_stack(int argc, char **argv)
{
	t_list	*stack_a;
	int		nbr;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i++]);
		ft_lstadd_back(&stack_a, ft_lstnew(nbr));
	}
	if (check_dup(stack_a) == false)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (check_error(argc - 1, argv + 1) == true)
	{
		stack_a = fill_stack(argc, argv);
		if (!stack_a)
			return (1);
		if (sorted(stack_a) == false)
			select_algo(&stack_a, &stack_b);
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
