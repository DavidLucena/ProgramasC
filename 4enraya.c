#include <stdio.h>
#include <string.h>

#define ROW 7
#define COL 7
#define MAX 20

int jugada (char matriz[][COL], int col, int jugador );
int enralla(char matriz[][COL],int fila,int col);

int check=0,fila,acabado=1;

int main (void){

	char matriz [ROW][COL],nombre1[MAX+1],nombre2[MAX+1];
	int col,jugador=0,i,j,aux=7;

	for(i=0;i<ROW;i++)
        for(j=0;j<COL;j++)
            matriz[i][j]='_';

    printf("\n\t--- 4 EN RALLA INTERACTIVO ---\n\n");

	do{
        printf("\tJugador 1, dime cual es tu nombre: "); gets(nombre2);
        if (strlen(nombre2)>MAX || strlen(nombre2)<1)
            printf("El nombre no puede tener más de 20 caracteres.\n");
	}while(strlen(nombre2)>MAX || strlen(nombre2)<1);

	do{
        printf("\n\tJugador 2, dime cual es tu nombre: "); gets(nombre1);
        if (strlen(nombre1)>MAX || strlen(nombre2)<1)
            printf("El nombre no puede tener más de 20 caracteres.\n");
	}while(strlen(nombre1)>MAX || strlen(nombre1)<1);

	printf("\n\t\tTABLERO ACTUAL\n");

	for(i=0;i<ROW;i++){
        printf("\t\t%d ",aux--);
        for(j=0;j<COL;j++)
            printf("%c ",matriz[i][j]);
        printf("\n");
	}

	aux=0;
    printf("\t\t");

	for(i=0;i<=ROW;i++)
        printf("%d ",aux++);

	aux=7;
	printf("\n");

    do{

        if (jugador%2==1)
            printf("\n\t- TURNO DE %s -\n",nombre1);
        else
            printf("\n\t- TURNO DE %s -\n",nombre2);

        do{
            printf("\tDime la columna donde quieres poner la ficha: "); scanf("%d",&col);
            if (col<1 || col>7)
                printf("\tLa columna debe estar entre 1 y 7, ambos incluidos\n\n");
        }while (col<1 || col>7);

        fila=jugada(matriz,col,jugador);

        printf("\n\t\tTABLERO ACTUAL\n");

        for(i=0;i<ROW;i++){
            printf("\t\t%d ",aux--);
            for(j=0;j<COL;j++)
                printf("%c ",matriz[i][j]);
            printf("\n");
        }

        aux=0;
        printf("\t\t");

        for(i=0;i<=ROW;i++){
            printf("%d ",aux++);
        }

        aux=7;
        printf("\n");

        if (check==1)
            printf("\n\tLa columna dada ya esta llena\n");

        else jugador++;

        if (check==1 && jugador>=(ROW*COL))
            acabado=0;

        enralla(matriz,fila,col-1);

    }while(acabado!=0);

	if (jugador%2==1)
		printf("\n\tEsta partida la ha ganado %s\n",nombre2);
	else if (jugador>=(ROW*COL))
		printf("\n\tSe han acabado los turnos. Ha habido un empate\n");
	else
		printf("\n\tEsta partida la ha ganado %s\n",nombre1);

return 0;
}


int jugada (char matriz[][COL], int col, int jugador){

    int i;

    if(jugador%2==1){

        for(i=ROW-1;i>=0;i--){
            if (matriz[i][col-1]=='_'){
                matriz[i][col-1]='X';
				check=0;
				return i;
			}
			else {
                if (i==0){
                    check=1;
					return -1;
				}
            }
        }
    }



    else{

        for(i=ROW-1;i>=0;i--){
            if (matriz[i][col-1]=='_'){
                matriz[i][col-1]='O';
				check=0;
				return i;
			}
			else {
                if (i==0){
                    check=1;
					return -1;
				}
			 }
        }
    }
}


int enralla(char matriz[][COL],int fila,int col){

    int i,contv=0,conth=0;

	if (matriz[fila][col]=='X'){
        for(i=0;i<ROW;i++){
            if (matriz[i][col]=='X'){
                contv++;
				if (contv==4)
                    return acabado=0;

            }
			else
				contv=0;
        }

		for(i=0;i<COL;i++){
            if (matriz[fila][i]=='X'){
                conth++;
                if (conth==4)
                    return acabado=0;
			}
			else
				conth=0;
		}
	}

	else{

		for(i=0;i<ROW;i++){
			if (matriz[i][col]=='O'){
				contv++;
				if (contv==4)
					return acabado=0;
			}
			else
                contv=0;
		}

		for(i=0;i<COL;i++){
			if (matriz[fila][i]=='O'){
				conth++;
				if (conth==4)
					return acabado=0;
			}
			else
				conth=0;
		}
	}
}

q
