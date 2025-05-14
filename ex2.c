#include <stdio.h>
#include <math.h>


typedef struct point
{
	int x;
	int y;
}  t_point ;

typedef struct vecteur
{
	t_point o;
	t_point d;
}   t_vect;



t_point creerpoint(void)
{
	t_point ret;

	printf("saisir x \t : ");
	scanf("%d", &ret.x);
	printf("saisir y \t : ");
	scanf("%d", &ret.y);
	return (ret);
}

t_vect  creervecteur(t_point    a, t_point  b)
{
	t_vect ab;

	ab.o = a;
	ab.d = b;
	return (ab);
}

float	norme(t_vect v)
{
	return (sqrt(pow(v.d.x - v.o.x, 2) + pow(v.d.y - v.o.y, 2)));
}

int	main(void)
{
	t_point	a;
	t_point	b;
	t_vect	ab;

	a = creerpoint();
	b = creerpoint();
	ab = creervecteur(a, b);
	printf("ab (%d, %d)\n", b.x - a.x, b.y - a.y);
	printf("la norme ||ab|| est %f ", norme(ab));
	return (0);
}