#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarVector(char *vectorReceptor[], int cantidad);
char *BuscarNombre(char *vectorReceptor[], int cantidad, char *nombreABuscar);

int main(){
    char *nombres[5],nombre[50],*nombreABuscar,*vectorDevuelto;
    int tamanioCadena = 0;
    for (int i = 0; i < 5; i++)
    {
        puts("Ingrese un Nombre");
        fgets(nombre, 50, stdin);
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
    vectorDevuelto = BuscarNombre(nombres,5,nombreABuscar);
    puts(vectorDevuelto);
    for (int i = 0; i < 5; i++)
    {
        free(nombres[i]);
    }
    free(vectorDevuelto);
    
    

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

char *BuscarNombre(char *vectorReceptor[], int cantidad, char *nombreABuscar){
    char *resultado,*vectorDevuelto;
    for (int i = 0; i < cantidad; i++)
    {
        resultado = strstr(vectorReceptor[i],nombreABuscar);
        if (resultado != NULL)
        {
            vectorDevuelto = (char *) malloc ((strlen(vectorReceptor[i]) + 1) * sizeof(char));
            strcpy(vectorDevuelto,vectorReceptor[i]);
            return vectorDevuelto;
        }
    }
    vectorDevuelto = (char *) malloc (3 * sizeof(char));
    strcpy(vectorDevuelto,"-1");
    return vectorDevuelto;
    
}
