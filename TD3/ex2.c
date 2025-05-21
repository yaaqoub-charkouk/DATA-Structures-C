#include <stdlib.h>

typedef struct arbre
{
	int             valeur;
	struct arbre    *gauche;
	struct arbre    *droite;
}   ArbreB;

ArbreB  *creer_arbre(int valeur, ArbreB *G, ArbreB *D)
{
	ArbreB  *node;

	node = malloc(sizeof(ArbreB));
	node->valeur = valeur;
	node->gauche = G;
	node->droite = D;
	return (node);
}

void    afficher_prefixe(ArbreB *arbre) // Algorithm prefixe
{
	if (!arbre)
		printf(" . ") ;
	else
	{
		printf(" %d ", arbre->valeur);
		afficherA(arbre->gauche);
		afficherA(arbre->droite);
	}
}

void	afficher_postfixe(ArbreB *arbre)
{
	if (!arbre)
		printf(" . ") ;
	else
	{
		afficherA(arbre->gauche);
		afficherA(arbre->droite);
		printf(" %d ", arbre->valeur);
	}
}

void	afficher_infixe(ArbreB *arbre)
{
	if (!arbre)
		printf(" . ") ;
	else
	{
		afficherA(arbre->gauche);
		printf(" %d ", arbre->valeur);
		afficherA(arbre->droite);
	}
}

int	nbr_noeuds(ArbreB *arbre)
{
	if (!arbre)
		return (0);
	return (1 + nbr_noeuds(arbre->gauche) + nbr_noeuds(arbre->droite));
}

int	max(int	x, int	y)
{
	if (x > y) return (x);
	else	return (y);
}

int	hauteur(ArbreB *arbre)
{
	if (!arbre)
		return (0);
	return (1 + max(hauteur(arbre->gauche), hauteur(arbre->droite)));
}

int	recherche(ArbreB *arbre, int e)
{
	if (!arbre)
		return (0);
	if (e == arbre->valeur)
		return (1);
	else
		return (recherche(arbre->gauche, e) + recherche(arbre->droite, e));
}

void	free_tree(ArbreB *a)
{
	if (!a)
		return ;
	else
	{
		free_tree(a->gauche);
		free_tree(a->droite);
		free(a);
		a = NULL;
		return ;
	}
}