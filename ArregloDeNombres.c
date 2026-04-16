#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mostrarVector(char *vectorReceptor[], int cantidad);
void *buscarNombre(char *vectorReceptor[],int cantidad,int indiceBuscar);
int main(){
    char *nombres[5],nombre[50];
    int tamanioCadena = 0,indiceBuscar = 0;
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
    printf("Ingrese que indice quiere buscar en el vector: \n");
    scanf("%d", &indiceBuscar);
    buscarNombre(nombres,5,indiceBuscar);
    for (int i = 0; i < 5; i++)
    {
        free(nombres[i]);
    }
    getchar();
    return 0;
}

void *mostrarVector(char *vectorReceptor[], int cantidad){
    printf("Nombres de los vectores almacenados: \n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Nombre %d: %s\n",i+1,vectorReceptor[i]);       
    }   
}
void *buscarNombre(char *vectorReceptor[],int cantidad,int indiceBuscar){
    if (indiceBuscar < 6 && indiceBuscar > 0)
        {
            printf("Este es el nombre con el indice %d: %s\n",indiceBuscar,vectorReceptor[indiceBuscar - 1]);
        }else{
            printf("No se encontro el valor buscado\n");
        }
    
}