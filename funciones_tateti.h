#define NORMAL      "\033[0m"
#define CYAN_T      "\x1b[24m\033[0;36m"
#define ROJO_T      "\033[31m"
#define PURPURA_T   "\033[35m"
#define AMARILLO_T  "\033[1;33m"
#define VERDE_T     "\033[1;32m"
#define TITULO      "\x1b[33m\x1b[4m"

//Rellenar matriz
void rellenar(int M[3][3]){
    for(int i=0;i<3;i++){for(int j=0;j<3;j++){M[i][j]='.';}}
}

//Imprime parte de celda
void print_celda(int letra, int parte,int columna){

    char letraX[4][10]={" __  __  "," \\ \\/ /  ","  >  <   "," /_/\\_\\  "};
    char letraO[4][10]={"   ___   ","  / _ \\  "," | (_) | ","  \\___/  "};
    char vacio[10]="         ";
    
    if(columna==2){
        switch (letra){
            case 'X': printf("%s%s%s\n ",PURPURA_T,letraX[parte],CYAN_T);break;
            case 'O': printf("%s%s%s\n ",AMARILLO_T,letraO[parte],CYAN_T);break;
            case '.': printf("%s%s\n ",CYAN_T,vacio);break;
        }
    } else {
        switch (letra){
            case 'X': printf("%s%s%s| |",PURPURA_T,letraX[parte],CYAN_T);break;
            case 'O': printf("%s%s%s| |",AMARILLO_T,letraO[parte],CYAN_T);break;
            case '.': printf("%s%s| |",CYAN_T,vacio);break;
        }
    }
}

//Muestra de matriz
void graficar(int M[3][3]){
    system("cls");
    printf(" ");
    for(int i=0;i<3;i++){
        for(int k=0;k<4;k++){
            for(int j=0;j<3;j++){   
                print_celda(M[i][j],k,j);
            }
        }
        if(i!=2){
            for(int k=0;k<3;k++){print_celda('.',1,k);}
            for(int k=0;k<33;k++){printf("=");}
            printf("\n ");
        } else{for(int k=0;k<3;k++){print_celda('.',1,k);}}
    }
}

//Input jugador
void input_jugador(int matriz[3][3], int jugador){
    int pos, aux, cont, aux2=0;
    do{
        aux=0;
        do{ 
            system("cls");
            graficar(matriz);
            if(aux2==1){printf("%sPOSICION INVALIDA!!!%s",ROJO_T,CYAN_T);aux2=0;}
            printf("\n %c Introduce posicion '%c' (1-9): %s", 26, jugador, NORMAL); scanf("%i", &pos);
        } while (pos<1 || pos>9);

        cont=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){   
                cont++;
                if(cont==pos && matriz[i][j]=='.'){matriz[i][j]=jugador;aux=1;break;
                } else if(cont==pos && matriz[i][j]!='.'){aux2=1;}
            }
        }
        
    } while(aux==0);
}

//Control Filas o Columnas
int ctrl_f_c(int foc, int aux, int matriz[3][3]){
    int a, b, cont, aux2;

    for(a=0;a<3 && aux==0;a++){
        cont=aux2=0;
        if(matriz[a][0]!='.' && foc==1){aux2 = matriz[a][0];
        } else if(matriz[0][a]!='.' && foc==2){aux2 = matriz[0][a];}
        for(b=1;b<3;b++){
            if(aux2 == matriz[a][b] && foc==1){cont++;
            } else if(aux2 == matriz[b][a] && foc==2){cont++;}
        }
        if(cont==2){if(aux2=='O'){aux=2;break;} else {aux=1;break;}} 
    }
    return aux;
}

//Control diagonales
int ctrl_diagonales(int a, int b, int aux, int matriz[3][3]){
    if(matriz[0][a]==matriz[1][1] && matriz[0][a]==matriz[2][b] && aux==0){
        if(matriz[0][a]=='O'){aux=2;} else if(matriz[0][a]=='X'){aux=1;}
    }  
    return aux;
}

//Control tablero
int ctrl(int matriz[3][3]){
    int aux = 0;

    //Ctrl fila
    aux = ctrl_f_c(1,aux, matriz);
    //Ctrl columna
    aux = ctrl_f_c(2,aux, matriz);
    
    //Diagonal principal
    aux = ctrl_diagonales(0,2,aux, matriz);
    //Diagonal secundaria
    aux = ctrl_diagonales(2,0,aux, matriz);
     
    return aux;
}
