#include <stdio.h>

typedef struct list
{
	float		coeff;
	int			exp;
	struct list *suivant;
} ListePoly;

ListePoly	*lecture(void)
{
	ListePoly	*lst;
	ListePoly	**head;
	char	on;
	head = &lst;

	lst = malloc(sizeof(ListePoly));
	on = 'a';
	while (on != 'o')
	{
		printf("saisir le coeff \t: ");
		scanf("%f", &lst->coeff);
		printf("saisir l exp \t: ");
		scanf("%d", &lst->exp);
		printf("saisir le on");
		scanf("%c", &on);
	}
	return (*head);
}

int	valeur(ListePoly *p, int x)
{
	int	v;

	v = 0;
	while(p)
	{
		v += p->coeff * pow(x, p->exp);
		p = p->suivant;
	}
	return (v);
}

int	degre(ListePoly *p)
{
	int	deg;
	
	deg = 0;
	while (p)
	{
		if (p->exp > deg)
			deg = p->exp;
		p = p->suivant;
	}
	return (deg);
}

ListePoly *somme(ListePoly *p1, ListePoly *p2)
{
	ListePoly	*s = NULL;
	ListePoly	*node;
	ListePoly	*temp;
	int			exp;

	while (p1)
	{
		node = malloc(sizeof(ListePoly));
		node->coeff = p1->coeff;
		node->exp = p1->exp;
		node->suivant = s;
		s = node;
		p1 = p1->suivant;
	}

	while (p2)
	{
		exp = p2->exp;

		node = malloc(sizeof(ListePoly));
		node->coeff = p2->coeff;
		node->exp = p2->exp;
		node->suivant = NULL;

		temp = s;
		while (temp)
		{
			if (temp->exp == exp)
			{
				temp->coeff += p2->coeff;
				break;
			}
			temp = temp->suivant;
		}
		if (!temp)
		{
			node->suivant = s;
			s = node;
		}

		p2 = p2->suivant;
	}
	return s;
}

void	derivee(ListePoly *p)
{
	while (p)
	{
		p->coeff = p->coeff * p->exp;
		p->exp--;
		p = p->suivant;
	}
}