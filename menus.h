#include <stdio.h>
#include <stdlib.h>
#include "funciones_tateti.h"

//Resultado final
void res_final(int resultado, int M[3][3]){
    system("cls");
    graficar(M);
    if(resultado!=0){
        printf("\n%s--  El jugador Num. %d ha ganado  --\n%s",VERDE_T, resultado, NORMAL);
    } else {
        printf("\n%s--     No hay ningun ganador     --\n%s",ROJO_T,NORMAL);
    }
    system("pause");
}

//Tablero
void tablero(int M[3][3]){
    int jugador, resultado = 0;

    for(int i=0;i<9 && resultado==0;i++){  
        
        if(i%2==0){jugador='X';} else {jugador='O';}
        system("cls");
        input_jugador(M,jugador);
        
        resultado = ctrl(M);   
    }

    res_final(resultado,M);
}

//Menu 0
void inicio(){
    int M[3][3], aux;
    system("title TaTeTi v2.1a");
    system("mode con: cols=35 lines=20");
    do{
        system("cls");
        rellenar(M);
        printf("\n\t%s================\n",CYAN_T);
        printf("\n\t===%c %sTaTeTi%s %c===\n",16,TITULO,CYAN_T,17);
        printf("\n\t================\n\n\n");
        printf("\n\t %s(1) %s  JUGAR\n",NORMAL,CYAN_T);
        printf("\n\t %s(0) %s  SALIR",NORMAL,CYAN_T);
        printf("\n\n\n\n\nIngrese una opcion:%s ", NORMAL); scanf("%i", &aux);
        printf("%s",CYAN_T);
        
        if(aux==1){tablero(M);}

    } while(aux!=0);

}