

typedef struct list
{
	int     valeur;
	struct list *suivant;
	struct list *precedent;
} ListeD;


int est_vide(ListeD *lst)
{
	return (lst == NULL);
}

void    afficher(ListeD *list)
{
	while (list)
	{
		printf("%d", list->valeur);
		list = list->suivant;
	}
}

int     compter(ListeD *list)
{
	int i;

	while (list)
	{
		i++;
		list = list->suivant;
	}
	return (i);
}

void    ajoutF(Liste **list, Liste *element)
{
	if (!*list)
	{
		*list = element;
		element->precedent = NULL;
		element->suivant = NULL;
	}
	while (!(*list)->suivant)
	{
		list = list->suivant;
	}
	element->precedent = *list;
	(*list)->suivant = element;
}

void supprimerD(ListeD **list)
{
	ListeD *current = *list;

	if (!list || !*list)
		return ;

	while (current->suivant)
		current = current->suivant;
	if (current->precedent)
		current->precedent->suivant = NULL;
	else
		*list = NULL;
	free(current);
}

void	supprimerOcc(ListeD **list)
{
	ListeD *temp;
	ListeD *lst;
	ListeD *to_free;

	if (!list || !*list)
		return ;
	temp = *list;
	while (temp)
	{
		lst = temp->suivant;
		while (lst)
		{
			if (temp->valeur == lst->valeur)
			{
				to_free = lst;
				lst = lst->suivant;
				if (to_free->precedent)
					to_free->precedent->suivant = to_free->suivant;
				if (to_free->suivant)
					to_free->suivat->precedent = to_free->precedent;
				free(to_free);
			}
			else
				lst = lst->suivant;
		}
		temp = temp->suivant;
	}
}

