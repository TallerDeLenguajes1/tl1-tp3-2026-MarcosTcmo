#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarVector(char *vectorReceptor[], int cantidad);

int main(){
    char *nombres[5],nombre[50];
    int tamanioCadena = 0;
    for (int i = 0; i < 5; i++)
    {
        puts("Ingrese un Nombre");
        scanf("%s", &nombre);
        tamanioCadena = strlen(nombre);
        nombres[i] = (char *) malloc ((tamanioCadena + 1) * sizeof(char));
        strcpy(nombres[i],nombre);
        //printf("Nombre guardado %s\n",nombres[i]); 
        
    }
    mostrarVector(nombres,5);
    for (int i = 0; i < 5; i++)
    {
        free(nombres[i]);
    }
    
    

    getchar();
    return 0;
}

void mostrarVector(char *vectorReceptor[], int cantidad){
    printf("Nombres de los vectores almacenados: \n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Nombre %d: %s\n",i+1,vectorReceptor[i]);       
    }
    
}