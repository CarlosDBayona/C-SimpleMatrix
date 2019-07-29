#include <stdio.h>
#include <stdlib.h>

void llenar(int size, float matriz[size][size]);
void imprimir(int size, float matriz[size][size]);
void transpose(int size, float matriz[size][size]);
void sum(int size, float matriz_1[size][size], float matriz_2[size][size], float result[size][size]);
void substraction(int size, float matriz_1[size][size],float matriz_2[size][size], float result[size][size]);

int main()
{
    printf("Hecho Por Carlos Daniel Bayona\n");
    printf("Digite el tamaño de la matriz \n");
    int size;
    scanf("%d", &size);
    char letra;
    do{
        printf("Menu De Opciones\n");
        printf("(+)Sumar Matrices\n");
        printf("(-)Restar Matrices\n");
        printf("(T)Trasponer Matriz\n");
        printf("(Q)Salir)\n");
        switch(letra){
            case '+':
            {
                printf("Matriz 1\n");
                float matriz_1[size][size];
                llenar(size, matriz_1);
                imprimir(size, matriz_1);
                printf("Matriz 2\n");
                float matriz_2[size][size];
                llenar(size,matriz_2);
                imprimir(size, matriz_2);
                float result[size][size];
                sum(size, matriz_1, matriz_2,result);
                printf("Resultado\n");
                imprimir(size, result);
                printf("Precione cualquier tecla para continuar\n");
                getchar();
                break;
            }
            case '-':
            {
                printf("Matriz 1\n");
                float matriz_1[size][size];
                llenar(size, matriz_1);
                imprimir(size, matriz_1);
                printf("Matriz 2\n");
                float matriz_2[size][size];
                llenar(size,matriz_2);
                imprimir(size, matriz_2);
                float result[size][size];
                substraction(size, matriz_1, matriz_2,result);
                printf("Resultado\n");
                imprimir(size, result);
                printf("Precione cualquier tecla para continuar\n");
                getchar();
                break;
            }
            case 'T':
            {
                printf("Matriz Generada\n");
                float matriz[size][size];
                llenar(size, matriz);
                imprimir(size, matriz);
                printf("Matriz Transpuesta\n");
                transpose(size, matriz);
                imprimir(size, matriz);
                printf("Precione cualquier tecla para continuar\n");
                getchar();
                break;
            }
        }
        letra = getchar();
        system("clear");
    }while(letra != 'q');
   
    return 0;
}

void llenar(int size, float matriz[size][size]) {
    for(int i=0; i<size; i++){
        for(int j=0; j<size;j++){
            matriz[i][j]=(float)rand()/(float)(RAND_MAX/9);
        }
    }  
}

void imprimir(int size, float matriz[size][size]){
    for(int i=0; i<size; i++){
        for(int j=0; j<size;j++){
            printf("%0.6f",matriz[i][j]);
            printf(" ");
        }
        printf("\n");
    }  
}

void transpose(int size, float matriz[size][size]){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size;j++){
            float temp  = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
    }  
}

void sum(int size, float matriz_1[size][size], float matriz_2[size][size], float result[size][size]){
    for(int i = 0; i < size; i++){
        for (int j=0; j<size; j++){
            result[i][j] = matriz_1[i][j] + matriz_2[i][j];
        }
    }
}
void substraction(int size, float matriz_1[size][size], float matriz_2[size][size], float result[size][size]){
    for(int i = 0; i < size; i++){
        for (int j=0; j<size; j++){
            result[i][j] = matriz_1[i][j] - matriz_2[i][j];
        }
    }
}