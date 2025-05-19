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

void    afficherA(ArbreB *arbre)
{
	if (!arbre)
		return ;
	afficherA(arbre->gauche);
	afficherA(arbre->droite);
	printf("%d", arbre->valeur);
}