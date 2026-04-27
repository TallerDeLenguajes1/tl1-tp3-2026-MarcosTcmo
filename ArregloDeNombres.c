#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarVector(char *vectorReceptor[], int cantidad);
void BuscarNombre(char *vectorReceptor[], int cantidad, char *nombreABuscar);

int main(){
    char *nombres[5],nombre[50],*nombreABuscar;
    int tamanioCadena = 0;
    for (int i = 0; i < 5; i++)
    {
        puts("Ingrese un Nombre");
        gets(nombre);
        tamanioCadena = strlen(nombre);
        nombres[i] = (char *) malloc ((tamanioCadena + 1) * sizeof(char));
        strcpy(nombres[i],nombre);
        //printf("Nombre guardado %s\n",nombres[i]); 
        
    }
    mostrarVector(nombres,5);
    printf("Ingrese un nombre que quiera buscar: ");
    scanf("%s", &nombre);
    nombreABuscar = (char *) malloc ((strlen(nombre) + 1) * sizeof(char));
    strcpy(nombreABuscar,nombre);
    BuscarNombre(nombres,5,nombreABuscar);
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

void BuscarNombre(char *vectorReceptor[], int cantidad, char *nombreABuscar){
    char *resultado;
    resultado = strstr(vectorReceptor,nombreABuscar);
    printf("%s", *resultado);
    
}
