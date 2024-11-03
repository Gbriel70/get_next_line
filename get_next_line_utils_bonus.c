
#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*list;
	size_t	calloc_size;
	unsigned char *zero_list;
	size_t i;
	
	if (num != 0 && size > SIZE_MAX / num)
		return NULL;
	calloc_size = num * size;
	list = malloc(calloc_size);
	if (!list)
		return (NULL);
	i = 0;
	zero_list = list;
	while (i < calloc_size)
	{
		zero_list[i] = '\0';
		i++;
	}
	return(zero_list);
}

t_line	*ft_lstnew(char *content)
{
	t_line *new;

	new = malloc(sizeof(*new));
	if(!new)
		return NULL;
	new->content = content;
	new->lenght = 0;
	new->next = NULL;
	return (new);
}

t_line	*ft_lstlast(t_line *lst)
{
	if(!lst)
		return NULL;
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_line **lst, t_line *new)
{
	t_line *aux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = *lst;
	aux = ft_lstlast(*lst);
	aux->next = new;
}

void	ft_lstclear(t_line **lst, void (*del)(void *))
{
	t_line *temp_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp_lst = *lst;
		*lst = (*lst)->next;
		free(temp_lst->content);
		free(temp_lst);
	}
	*lst = NULL;
}