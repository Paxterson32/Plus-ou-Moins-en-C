#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

/****************************************Definition des prototypes****************************************/
void difficulte(int *diffi,int *maxi, int *nbre);
void Jeu();

/*************************************************************************************************************/
void Jeu()
{
	int max,min = 1,dif,N,nV,n_A,n_E = 0,nbre_Joueurs;
	
	printf("Le but de ce jeu est assez simple : vous serez amene a deviner un mot genere par l'ordinateur\nen un nombre minimal de coups'");
	printf("\nChoississez votre niveau de difficulte!  \n\n");
	printf("1.Facile\n2.Normale\n3.Difficile\n4.Tres dur\n");
	scanf("%d",&dif);

	difficulte(&dif,&max,&nV);//Aller a la fonction difficulte pour definir le max, le min, ...

	printf("\nLe nombre est compris entre %d et %d",min,max);
	//do
	//{
	printf("\n\nCombien de Joueurs ?\n");
	printf("1.Joueur 1 Vs Ordinateur\n2.Joueur 1 Vs Joueur 2\n");
	scanf("%d",&nbre_Joueurs);
	
	switch(nbre_Joueurs)
	{
		case 1:
			n_A = (rand() % (max - min + 1)) + min;//Genertion automatique du nombre par l'ordinateur
			break;
		case 2:
			n_A = 0;
			while (n_A <min || n_A>max)
			{
				printf("Joueur 1 veuillez saisir un nombre compris entre %d et %d\n",min,max);
				scanf("%d",&n_A);
			}
			break;
		default :
			printf("Saisie incorrecte. Recommencez : ");
		 	break;

	}
	//}while(nbre_Joueurs != 1 || nbre_Joueurs != 2);


	system("cls");//Effacer l'ecran
	printf("\n\nLet's go !!!!\n\n");
	
	do
	{
		scanf("%d",&N);
		n_E++;
		
		if(N == n_A )
		printf("Biiiiiiigo!!!! La reponse est correcte.\nVous l'avez eu en %d coups",n_E);
		else
		{
			if(min<=N && N<=max)
			{
				if(N<n_A)
				printf("Plus grand! \n");
				if(N>n_A)
				printf("Plus petit! \n");
			}
			else
			printf("Le nombre est compris entre %d et %d\n",min,max);
		}
		

	}while(N != n_A && n_E != nV);
	
	if(n_E == nV && N != n_A){
	printf("\nESSAYEZ DE FAIRE MIEUX LA PROCHAINE FOIS\nIl fallait trouver %d \n\n\n",n_A);
	printf("G.A.M.E   O.V.E.R !!!!");}

}
/*******************************************************************************************************************/
//definir le max, le min et le nombre maximal d'essais en fonction de la difficulte choisie.

void difficulte(int *diffi,int *maxi, int *nbre)
{
	switch (*diffi)
	{
	case 1:
		*maxi = 10; *nbre = 3;
	
		break;
	case 2:
		*maxi = 50; *nbre = 6;
		break;
	case 3:
		*maxi = 100; *nbre = 10;
		break;
	case 4:
		*maxi = 200;  *nbre = 3;
		break;
	default:
		printf("Saisie invalide : Le nombre doit etre compris entre 1 et 4");
		break;
	}
}
/****************************************************************************************************************************/
int main()
{
	
	srand(time(NULL));
	char choix;
	do
	{
	
	system("cls");

	Jeu();//Aller vers la fonction jeu pour la partie
	printf("\n\nVoulez-vous reesayer ? (O ou N) : ");
	choix = getchar();
	printf("\n\n");

	}while(choix !='n' || choix !='N');

	return 0;
	
}
