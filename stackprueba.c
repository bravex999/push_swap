#include <stdlib.h>
#include <stdio.h>

typedef	struct	s_node
{
	int value;
	struct s_node *next;
}t_node;

typedef	struct s_stack
{
	t_node	*top;
}t_stack;

t_stack	*init_stack()
{
	t_stack	*stack = malloc(sizeof(t_stack));
	if(!stack)
		return (NULL);
	stack->top = NULL;
	return(stack);
}

void	add_node(t_stack *stack, int value)
{
	t_node *new_node = malloc(sizeof(t_node));
	if(!new_node)
		return;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;
	while(stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}

	free(stack);
 }

int main ()
{
	t_stack *stack_a = init_stack();
	if(!stack_a)
		return(1);

	add_node(stack_a, 10);
	add_node(stack_a, 20);
	add_node(stack_a, 30);

	t_node	*current;
	current = stack_a->top;
	while(current)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}

	printf("NULL");

	free_stack(stack_a);
	return (0);
}
































