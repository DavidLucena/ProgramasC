#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define COL 7
#define FIL 7

int i,j,acabado=0,turno=1,aux=0;
int contporta1=0,contsub1=0,contlan1=0,conttot1=0; //contadores jugador 1
int contporta2=0,contsub2=0,contlan2=0,conttot2=0;//contadores jugador 2


void iniciartablero (char matriz1[][COL], char matriz2[][COL],char matriz3[][COL],char matriz4[][COL]);
void rellenartablero1 (char matriz1[][COL]);
void rellenartablero2 (char matriz2[][COL]);
void tirajugador1 (char matriz2[][COL],char matriz3[][COL]);
void tirajugador2 (char matriz1[][COL],char matriz4[][COL]);
void clrscr();


int main (void){
	char matriz1[FIL][COL],matriz2[FIL][COL],matriz3[FIL][COL],matriz4[FIL][COL];
	iniciartablero(matriz1,matriz2,matriz3,matriz4);
	rellenartablero1(matriz1);
	clrscr();
	rellenartablero2(matriz2);
	clrscr();
	do{
        if (turno%2==1)
            tirajugador1(matriz2,matriz3);
        else tirajugador2(matriz1,matriz4);
        turno++;
        //clrscr();
    }while(acabado==0);

    if ((turno-1)%2==1)
        printf("Ha ganado el jugador 1!");
    else printf("Ha ganado el jugador 2!");
	return 0;
}

void iniciartablero (char matriz1[][COL], char matriz2[][COL],char matriz3[][COL],char matriz4[][COL]){


	for(i=0;i<FIL;i++)
		for(j=0;j<COL;j++)
			matriz1[i][j]='~';

	for(i=0;i<FIL;i++)
		for(j=0;j<COL;j++)
			matriz2[i][j]='~';

    for(i=0;i<FIL;i++)
		for(j=0;j<COL;j++)
			matriz3[i][j]='~';

    for(i=0;i<FIL;i++)
		for(j=0;j<COL;j++)
			matriz4[i][j]='~';

    printf("\n\t\t\t---NORMAS---\n\n");
    printf("1) Los barcos se posicionan de derecha a izquierda y de arriba a abajo partiendo de la casilla dada\n");
    printf("2) En caso de repetir casilla a la hora de atacar se pasa el turno al rival\n");
    printf("3) El tablero de juego es de 7x7 casillas para ambos jugadores\n");
    printf("4) Los turnos son pasados de 1 en 1 y siempre empieza el jugador numero 1\n");
    printf("5) En caso de que la fila o columna este llena se preguntara de nuevo\n\n\n");


}

void rellenartablero1 (char matriz1[][COL]){

	int fila,columna,direccion,cont=0,contola=1,lanchavale=0;

	printf("Jugador 1, dispones de los siguientes barcos: \n\n");
	printf("\tPortaviones 	---> 4 casillas\n");
	printf("\tSubmarino 	---> 3 casillas\n");
	printf("\tLancha    	---> 2 casillas\n\n\n");

    printf("\t\t");

	for(i=0;i<=FIL;i++)
        printf("%d ",aux++);

	aux=COL;
	printf("\n");

	aux=1;

	for(i=0;i<FIL;i++){
        printf("\t\t%d ",aux++);
        for(j=0;j<COL;j++)
            printf("%c ",matriz1[i][j]);
        printf("\n");
	}

	aux=0;

	printf("\n\n");



	do{
		printf("En que direccion quieres poner el portaviones?\n\nVertical, pulsa 1\t Horizontal, pulsa 0: ");	scanf("%d",&direccion);
		if (direccion<0 || direccion>1)
			printf("Opcion no valida\n");
	}while (direccion<0 || direccion>1);

	if(direccion==1){

		do{
			printf("En que columna quieres poner el portaviones? ");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y 7\n");
		}while (columna <1 || columna>COL);

		do{
			printf("En que fila quieres poner el portaviones? ");	scanf("%d",&fila);
			if (fila <1 || fila>FIL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
			if((FIL-fila+1)<4)
				printf("El portaviones no cabe ahi\n");
		}while ((fila <1 || fila>FIL) || ((FIL-fila+1)<4));

		i=fila-1;
	do{
		matriz1[i][columna-1]='P';
		i++;
		cont++;
	}while(cont<4);

	cont=0;
	}


	if(direccion==0){
		do{
			printf("En que columna quieres poner el portaviones? ");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y %d\n",COL);
			if((COL-columna+1)<4)
				printf("El portaviones no cabe ahi\n");
		}while ((columna <1 || columna>COL) || ((COL-columna+1)<4));

		do{
			printf("En que fila quieres poner el portaviones? ");	scanf("%d",&fila);
			if (fila <1 || fila>COL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
		}while (fila <1 || fila>COL);

	i=columna-1;
	do{
		matriz1[fila-1][i]='P';
		i++;
		cont++;
	}while(cont<4);

	cont=0;
	}


	clrscr();

	//--SUBMARINO--

    printf("\n\t\t---ESTADO TABLERO---\n\n");

	printf("\t\t");

	for(i=0;i<=FIL;i++)
        printf("%d ",aux++);

	aux=COL;
	printf("\n");

	aux=1;

	for(i=0;i<FIL;i++){
        printf("\t\t%d ",aux++);
        for(j=0;j<COL;j++)
            printf("%c ",matriz1[i][j]);
        printf("\n");
	}

	aux=0;

	printf("\n\n");

	do{
		printf("En que direccion quieres poner el submarino?\nVertical, pulsa 1\t Horizontal, pulsa 0: ");	scanf("%d",&direccion);
		if (direccion<0 || direccion>1)
			printf("Opcion no valida\n");
	}while (direccion<0 || direccion>1);

	if(direccion==1){

		do{
			printf("En que columna quieres poner el submarino? ");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y 7\n");
		}while (columna <1 || columna>COL);

		do{
			contola=0;
			printf("En que fila quieres poner el submarino? ");	scanf("%d",&fila);
			if (fila <1 || fila>FIL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
			else if ((FIL-fila+1)<3)
				printf("El submarino no cabe ahi\n");

			else{

				for(i=fila-1;i<(i+2)&&contola<3;i++){
					if ((matriz1[i][columna-1])=='~')
						contola++;
					else{
						contola=0;
						printf("Puedes escribir en esa columna, pero no en la fila dada\n");
					}
					if(contola==0)
					break;
				}


			}
		}while ((fila <1 || fila>FIL) || (FIL-fila+1)<3 || contola<3);


		i=fila-1;
	do{
		matriz1[i][columna-1]='S';
		i++;
		cont++;
	}while(cont<3);

	cont=0;
	}



	if(direccion==0){
		do{
			printf("En que columna quieres poner el submarino? ");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y %d\n",COL);
			if((COL-columna+1)<3)
				printf("El submarino no cabe ahi\n");
		}while ((columna <1 || columna>COL) || ((COL-columna+1)<3));



		do{
			contola=0;
			printf("En que fila quieres poner el submarino? ");	scanf("%d",&fila);
			if (fila <1 || fila>FIL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
			else if ((COL-columna+1)<3)
				printf("El submarino no cabe ahi\n");

			else{

				for(i=columna-1;i<(i+2)&&contola<3;i++){
					if ((matriz1[fila-1][i])=='~')
						contola++;
					else{
						contola=0;
						printf("Puedes escribir en esa columna, pero no en la fila dada\n");
					}
					if(contola==0)
					break;
				}


			}

		}while ((fila <1 || fila>FIL) || (COL-columna+1)<3 || contola<3);

	i=columna-1;

	do{
		matriz1[fila-1][i]='S';
		i++;
		cont++;
	}while(cont<3);

	cont=0;
	}

    clrscr();

	//--LANCHA

	printf("\n\t\t---ESTADO TABLERO---\n\n");
	printf("\t\t");

	for(i=0;i<=FIL;i++)
        printf("%d ",aux++);

	aux=COL;
	printf("\n");

	aux=1;

	for(i=0;i<FIL;i++){
        printf("\t\t%d ",aux++);
        for(j=0;j<COL;j++)
            printf("%c ",matriz1[i][j]);
        printf("\n");
	}

	aux=0;

	printf("\n\n");

	do{
		printf("En que direccion quieres poner la lancha?\nVertical, pulsa 1\t Horizontal, pulsa 0: ");	scanf("%d",&direccion);
		if (direccion<0 || direccion>1)
			printf("Opcion no valida\n");
	}while (direccion<0 || direccion>1);

	if(direccion==1){

		do{
			printf("En que columna quieres poner la lancha? ");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y 7\n");
		}while (columna <1 || columna>COL);

		do{
			contola=0;
			printf("En que fila quieres poner la lancha? ");	scanf("%d",&fila);
			if (fila <1 || fila>FIL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
			if ((FIL-fila+1)<2)
				printf("La lancha no cabe ahi\n");

            for(i=0;i<COL;i++){
                if (matriz1[fila-1][i]=='~')
                    lanchavale=1;
            }

            if(lanchavale==0)
                printf("Debes elegir otra fila porque la escogida está llena\n");

			else{

				for(i=fila-1;i<(i+1)&&contola<2;i++){
					if ((matriz1[i][columna-1])=='~')
						contola++;
					else{
						contola=0;
						printf("Puedes escribir en esa columna, pero no en la fila dada\n");
					}
					if(contola==0)
					break;
				}


			}

		}while ((fila <1 || fila>FIL) || (FIL-fila+1)<2 || contola<2 || lanchavale==0);


		i=fila-1;
	do{
		matriz1[i][columna-1]='L';
		i++;
		cont++;
	}while(cont<2);

	cont=0;
	}



	if(direccion==0){
		do{
			printf("En que columna quieres poner la lancha?");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y %d\n",COL);
			if((COL-columna+1)<2)
				printf("La lancha no cabe ahi\n");
            for(i=0;i<COL;i++){
                if (matriz1[i][columna-1]=='~')
                    lanchavale=1;
            }

            if(lanchavale==0)
                printf("Debes elegir otra columna porque la escogida esta llena\n");
		}while ((columna <1 || columna>COL) || ((COL-columna+1)<2) || lanchavale==0);



		do{
			contola=0;
			printf("En que fila quieres poner la lancha?");	scanf("%d",&fila);
			if (fila <1 || fila>FIL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
			else if ((COL-columna+1)<2)
				printf("La lancha no cabe ahi\n");

			else{

				for(i=columna-1;i<(i+1)&&contola<2;i++){
					if ((matriz1[fila-1][i])=='~')
						contola++;
					else{
						contola=0;
						printf("Puedes escribir en esa columna, pero no en la fila dada\n");
					}
					if(contola==0)
					break;
				}


			}

		}while ((fila <1 || fila>FIL) || (COL-columna+1)<2 || contola<2);

	i=columna-1;

	do{
		matriz1[fila-1][i]='L';
		i++;
		cont++;
	}while(cont<2);

	cont=0;
	}

}

void rellenartablero2 (char matriz2[][COL]){

	int fila,columna,direccion,cont=0,contola=1,lanchavale=0;

	printf("Jugador 2, dispones de los siguientes barcos: \n\n");
	printf("\tPortaviones 	---> 4 casillas\n");
	printf("\tSubmarino 	---> 3 casillas\n");
	printf("\tLancha    	---> 2 casillas\n\n\n");

    printf("\t\t");

	for(i=0;i<=FIL;i++)
        printf("%d ",aux++);

	aux=COL;
	printf("\n");

	aux=1;

	for(i=0;i<FIL;i++){
        printf("\t\t%d ",aux++);
        for(j=0;j<COL;j++)
            printf("%c ",matriz2[i][j]);
        printf("\n");
	}

	aux=0;

	printf("\n\n");

	do{
		printf("En que direccion quieres poner el portaviones?\nVertical, pulsa 1\tHorizontal, pulsa 0: ");	scanf("%d",&direccion);
		if (direccion<0 || direccion>1)
			printf("Opcion no valida\n");
	}while (direccion<0 || direccion>1);

	if(direccion==1){

		do{
			printf("En que columna quieres poner el portaviones? ");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y 7\n");
		}while (columna <1 || columna>COL);

		do{
			printf("En que fila quieres poner el portaviones? ");	scanf("%d",&fila);
			if (fila <1 || fila>FIL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
			if((FIL-fila+1)<4)
				printf("El portaviones no cabe ahi\n");
		}while ((fila <1 || fila>FIL) || ((FIL-fila+1)<4));

		i=fila-1;
	do{
		matriz2[i][columna-1]='P';
		i++;
		cont++;
	}while(cont<4);

	cont=0;
	}


	if(direccion==0){
		do{
			printf("En que columna quieres poner el portaviones? ");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y %d\n",COL);
			if((COL-columna+1)<4)
				printf("El portaviones no cabe ahi\n");
		}while ((columna <1 || columna>COL) || ((COL-columna+1)<4));

		do{
			printf("En que fila quieres poner el portaviones? ");	scanf("%d",&fila);
			if (fila <1 || fila>COL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
		}while (fila <1 || fila>COL);

	i=columna-1;
	do{
		matriz2[fila-1][i]='P';
		i++;
		cont++;
	}while(cont<4);

	cont=0;
	}

    clrscr();

	//--SUBMARINO--

	printf("\n\t\t---ESTADO TABLERO---\n\n");
	printf("\t\t");

	for(i=0;i<=FIL;i++)
        printf("%d ",aux++);

	aux=COL;
	printf("\n");

	aux=1;

	for(i=0;i<FIL;i++){
        printf("\t\t%d ",aux++);
        for(j=0;j<COL;j++)
            printf("%c ",matriz2[i][j]);
        printf("\n");
	}

	aux=0;

	printf("\n\n");


	do{
		printf("En que direccion quieres poner el submarino?\nVertical, pulsa 1\tHorizontal,pulsa 0: ");	scanf("%d",&direccion);
		if (direccion<0 || direccion>1)
			printf("Opcion no valida\n");
	}while (direccion<0 || direccion>1);

	if(direccion==1){

		do{
			printf("En que columna quieres poner el submarino? ");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y 7\n");
		}while (columna <1 || columna>COL);

		do{
			contola=0;
			printf("En que fila quieres poner el submarino? ");	scanf("%d",&fila);
			if (fila <1 || fila>FIL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
			else if ((FIL-fila+1)<3)
				printf("El submarino no cabe ahi\n");

			else{

				for(i=fila-1;i<(i+2)&&contola<3;i++){
					if ((matriz2[i][columna-1])=='~')
						contola++;
					else{
						contola=0;
						printf("Puedes escribir en esa columna, pero no en la fila dada\n");
					}
					if(contola==0)
					break;
				}


			}
		}while ((fila <1 || fila>FIL) || (FIL-fila+1)<3 || contola<3);


		i=fila-1;
	do{
		matriz2[i][columna-1]='S';
		i++;
		cont++;
	}while(cont<3);

	cont=0;
	}



	if(direccion==0){
		do{
			printf("En que columna quieres poner el submarino? ");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y %d\n",COL);
			if((COL-columna+1)<3)
				printf("El submarino no cabe ahi\n");
		}while ((columna <1 || columna>COL) || ((COL-columna+1)<3));



		do{
			contola=0;
			printf("En que fila quieres poner el submarino? ");	scanf("%d",&fila);
			if (fila <1 || fila>FIL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
			else if ((COL-columna+1)<3)
				printf("El submarino no cabe ahi\n");

			else{

				for(i=columna-1;i<(i+2)&&contola<3;i++){
					if ((matriz2[fila-1][i])=='~')
						contola++;
					else{
						contola=0;
						printf("Puedes escribir en esa columna, pero no en la fila dada\n");
					}
					if(contola==0)
					break;
				}


			}

		}while ((fila <1 || fila>FIL) || (COL-columna+1)<3 || contola<3);

	i=columna-1;

	do{
		matriz2[fila-1][i]='S';
		i++;
		cont++;
	}while(cont<3);

	cont=0;
	}

    clrscr();

	//--LANCHA

	printf("\n\t\t---ESTADO TABLERO---\n\n");
	printf("\t\t");

	for(i=0;i<=FIL;i++)
        printf("%d ",aux++);

	aux=COL;
	printf("\n");

	aux=1;

	for(i=0;i<FIL;i++){
        printf("\t\t%d ",aux++);
        for(j=0;j<COL;j++)
            printf("%c ",matriz2[i][j]);
        printf("\n");
	}

	aux=0;

	printf("\n\n");

	do{
		printf("En que direccion quieres poner la lancha?\nVertical, pulsa 1\tHorizontal,pulsa 0: ");	scanf("%d",&direccion);
		if (direccion<0 || direccion>1)
			printf("Opcion no valida\n");
	}while (direccion<0 || direccion>1);

	if(direccion==1){

		do{
			printf("En que columna quieres poner la lancha? ");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y 7\n");
		}while (columna <1 || columna>COL);

		do{
			contola=0;
			printf("En que fila quieres poner la lancha? ");	scanf("%d",&fila);
			if (fila <1 || fila>FIL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
			if ((FIL-fila+1)<2)
				printf("La lancha no cabe ahi\n");

            for(i=0;i<COL;i++){
                if (matriz2[fila-1][i]=='~')
                    lanchavale=1;
            }

            if(lanchavale==0)
                printf("Debes elegir otra fila porque la escogida está llena\n");

			else{

				for(i=fila-1;i<(i+1)&&contola<2;i++){
					if ((matriz2[i][columna-1])=='~')
						contola++;
					else{
						contola=0;
						printf("Puedes escribir en esa columna, pero no en la fila dada\n");
					}
					if(contola==0)
					break;
				}


			}

		}while ((fila <1 || fila>FIL) || (FIL-fila+1)<2 || contola<2 || lanchavale==0);


		i=fila-1;
	do{
		matriz2[i][columna-1]='L';
		i++;
		cont++;
	}while(cont<2);

	cont=0;
	}



	if(direccion==0){
		do{
			printf("En que columna quieres poner la lancha?");	scanf("%d",&columna);
			if (columna <1 || columna>COL)
				printf("La columna debe estar comprendida entre 1 y %d\n",COL);
			if((COL-columna+1)<2)
				printf("La lancha no cabe ahi\n");
            for(i=0;i<COL;i++){
                if (matriz2[i][columna-1]=='~')
                    lanchavale=1;
            }

            if(lanchavale==0)
                printf("Debes elegir otra columna porque la escogida está llena\n");
		}while ((columna <1 || columna>COL) || ((COL-columna+1)<2) || lanchavale==0);



		do{
			contola=0;
			printf("En que fila quieres poner la lancha?");	scanf("%d",&fila);
			if (fila <1 || fila>FIL)
				printf("La fila debe estar comprendida entre 1 y 7\n");
			else if ((COL-columna+1)<2)
				printf("La lancha no cabe ahi\n");

			else{

				for(i=columna-1;i<(i+1)&&contola<2;i++){
					if ((matriz2[fila-1][i])=='~')
						contola++;
					else{
						contola=0;
						printf("Puedes escribir en esa columna, pero no en la fila dada\n");
					}
					if(contola==0)
					break;
				}


			}

		}while ((fila <1 || fila>FIL) || (COL-columna+1)<2 || contola<2);

	i=columna-1;

	do{
		matriz2[fila-1][i]='L';
		i++;
		cont++;
	}while(cont<2);

	cont=0;
	}

	for(i=0;i<FIL;i++){
		for(j=0;j<COL;j++)
			printf("%c ",matriz2[i][j]);
		printf("\n");

    }

    clrscr();
}

void tirajugador1 (char matriz2[][COL],char matriz3[][COL]){

    int fila,columna;

   printf("\n\t\t---ESTADO TABLERO JUGADOR 1---\n\n");

	printf("\t\t");

	for(i=0;i<=FIL;i++)
        printf("%d ",aux++);

	aux=COL;
	printf("\n");

	aux=1;

	for(i=0;i<FIL;i++){
        printf("\t\t%d ",aux++);
        for(j=0;j<COL;j++)
            printf("%c ",matriz3[i][j]);
        printf("\n");
	}

	aux=0;

	printf("\n\n");

    printf("Hora de disparar jugador1\n");
    do{
        printf("Columna: "); scanf("%d",&columna);
        printf("Fila: "); scanf("%d",&fila);

        if (fila>FIL || fila<1 || columna>COL || columna<1)
            printf("Los numeros dados deben estar entre 1 y 7\n");
    }while(fila>FIL || fila<1 || columna>COL || columna<1);

    if (matriz3[fila-1][columna-1]=='X' || matriz3[fila-1][columna-1]=='O'){
        printf("Esta casilla ya ha sido seleccionada previamente, se pasa el turno al adversario\n");
    }

    else if(matriz2[fila-1][columna-1]=='P' && contporta1<4){
        contporta1++;
        conttot1++;
        matriz3[fila-1][columna-1]='O';
        if (contporta1==4)
            printf("El portaviones está tocado y hundido\n");
        else printf("Tocado\n");
    }
    else if(matriz2[fila-1][columna-1]=='S' && contsub1<3){
        contsub1++;
        conttot1++;
        matriz3[fila-1][columna-1]='O';
        if (contsub1==3)
            printf("El submarino está tocado y hundido\n");
        else printf("Tocado\n");
    }
    else if(matriz2[fila-1][columna-1]=='L' && contlan1<2){
        contlan1++;
        conttot1++;
        matriz3[fila-1][columna-1]='O';
        if (contlan1==2)
            printf("La lancha está tocada y hundida\n");
        else printf("Tocado\n");
    }

    else{
        printf("Agua\n");
        matriz3[fila-1][columna-1]='X';
    }


    printf("\n\t\t---ESTADO TABLERO JUGADOR 2---\n\n");
	printf("\t\t");

	for(i=0;i<=FIL;i++)
        printf("%d ",aux++);

	aux=COL;
	printf("\n");

	aux=1;

	for(i=0;i<FIL;i++){
        printf("\t\t%d ",aux++);
        for(j=0;j<COL;j++)
            printf("%c ",matriz3[i][j]);
        printf("\n");
	}

	aux=0;

	printf("\n\n");

    if (conttot1==9)
        acabado=1;

}

void tirajugador2 (char matriz1[][COL],char matriz4[][COL]){

    int fila,columna;

    printf("\n\t\t---ESTADO TABLERO---\n\n");

	printf("\t\t");

	for(i=0;i<=FIL;i++)
        printf("%d ",aux++);

	aux=COL;
	printf("\n");

	aux=1;

	for(i=0;i<FIL;i++){
        printf("\t\t%d ",aux++);
        for(j=0;j<COL;j++)
            printf("%c ",matriz4[i][j]);
        printf("\n");
	}

	aux=0;

	printf("\n\n");

    printf("Hora de disparar jugador2\n");
    do{
        printf("Columna: "); scanf("%d",&columna);
        printf("Fila: "); scanf("%d",&fila);

        if (fila>FIL || fila<1 || columna>COL || columna<1)
            printf("Los numeros dados deben estar entre 1 y 7\n");
    }while(fila>FIL || fila<1 || columna>COL || columna<1);

    if (matriz4[fila-1][columna-1]=='X' || matriz4[fila-1][columna-1]=='O'){
        printf("Esta casilla ya ha sido seleccionada previamente, se pasa el turno al adversario\n");
    }

    else if(matriz1[fila-1][columna-1]=='P' && contporta2<4){
        contporta2++;
        conttot2++;
        matriz4[fila-1][columna-1]='O';
        if (contporta2==4)
            printf("El portaviones está tocado y hundido\n");
        else printf("Tocado\n");
    }
    else if(matriz1[fila-1][columna-1]=='S' && contsub2<3){
        contsub2++;
        conttot2++;
        matriz4[fila-1][columna-1]='O';
        if (contsub2==3)
            printf("El submarino está tocado y hundido\n");
        else printf("Tocado\n");
    }
    else if(matriz1[fila-1][columna-1]=='L' && contlan2<2){
        contlan2++;
        conttot2++;
        matriz4[fila-1][columna-1]='O';
        if (contlan2==2)
            printf("La lancha está tocada y hundida\n");
        else printf("Tocado\n");
    }

    else{
        printf("Agua\n");
        matriz4[fila-1][columna-1]='X';
    }


    printf("\n\t\t---ESTADO TABLERO---\n\n");
	printf("\t\t");

	for(i=0;i<=FIL;i++)
        printf("%d ",aux++);

	aux=COL;
	printf("\n");

	aux=1;

	for(i=0;i<FIL;i++){
        printf("\t\t%d ",aux++);
        for(j=0;j<COL;j++)
            printf("%c ",matriz4[i][j]);
        printf("\n");
	}

	aux=0;

	printf("\n\n");

    if (conttot2==9)
        acabado=1;
}
void clrscr(){
    system("@cls||clear");
}
