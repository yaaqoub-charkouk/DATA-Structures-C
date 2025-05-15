#include <stdlib.h>
#include <stdio.h>

typedef struct lst
{
	int			contenu;
	struct lst	*suivant;
}	t_list;

int	is_empty(t_list *lst)
{
	if (!lst)
		return (1);
	return (0);
}

void	ajoutD(t_list **lst, t_list *node)
{
	if (!lst || !*lst || !node)
		return ;
	node->suivant = *lst;
	*lst = node;
}

// void	ajoutFin(t_list *lst, t_list *node)
// {
// 	if (!lst)
// 		lst = node;
// 	while(lst)
// 		lst = lst->suivant;
// 	lst->suivant = node;
// }

void	affiche(t_list	*lst)
{
	while (lst)
	{
		printf("contenu %d", lst->contenu);
		lst = lst->suivant;
	}
}

int	compterlist(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->suivant;
	}
	return (i);
}

int	position(t_list	*lst, t_list *list)
{
	int	i;

	i = 1;
	while (lst)
	{
		if (lst->contenu == list->contenu)
			return (i);
		i++;
	}
	return (-1);
}
t_list *AjoutF(int x,t_list *L)
{
	t_list	*Elm,*Dernier;

	Elm = (t_list*)malloc(sizeof(t_list));
	Elm->contenu = x;
	if (L == NULL)
	{
		Elm->suivant = NULL;
		L = Elm;
		return L;
	}
	else
	{
		Dernier = L;
		while(Dernier->suivant != NULL)
		{
			Dernier = Dernier->suivant;
		}
	Elm->suivant = NULL;
	Dernier->suivant = Elm;
	return (L);
	}
}

int	main(void)
{
	t_list	*lst;
	
	lst = malloc(1 * sizeof(t_list));
	lst->contenu = 1;
	lst->suivant = NULL;
	lst = AjoutF(4, lst);
	affiche(lst);
	return (0);
}