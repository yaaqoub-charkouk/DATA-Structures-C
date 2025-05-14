struct filiere
{
	char	nom[5];
	int		num;
};

struct etudiant
{
	char			nom[30];
	int				note;
	struct filiere	f;
};

void	saisie(struct etudiant *a)
{
	printf("entrer le nom \t: ");
	scanf("%s", a->nom);
	printf("entrer la note \t: ");
	scanf("%d", a->note);
	printf("entrer la filiere \t: ");
	scanf("%s", a->f.nom);
	printf("entrer la semestre \t: ");
	scanf("%d", &a->f.num);
}

void	affichage(struct etudiant a)
{
	printf("nom %s\nnote %d\nfiliere %s\nnum %d\n",a.nom, a.note, a.f.nom, a.f.num);
}

struct etudiant e[330];

void	recherche(struct etudiant *t, int nb, char *nom)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (strcmp(t[i].nom, nom) == 0)
			return (affichage(t[i]));
	}
	printf("n'existe pas");
}