#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mostrarVector(char *vectorReceptor[], int cantidad);
void *BuscaNombrePorId(char *vectorReceptor[],int cantidad,int indiceBuscar);
char *BuscaNombrePorPalabra(char *vectorReceptor[], int cantidad, char *nombreABuscar);

int main(){
    char *nombres[5],nombre[50];
    int tamanioCadena = 0,indiceBuscar = 0;
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
    printf("Ingrese que indice quiere buscar en el vector: \n");
    scanf("%d", &indiceBuscar);
    BuscaNombrePorId(nombres,5,indiceBuscar);
    printf("Ingrese un nombre que quiera buscar: ");
    scanf("%s", &nombre);
    nombreABuscar = (char *) malloc ((strlen(nombre) + 1) * sizeof(char));
    strcpy(nombreABuscar,nombre);
    vectorDevuelto = BuscaNombrePorPalabra(nombres,5,nombreABuscar);
    puts(vectorDevuelto);
    for (int i = 0; i < 5; i++)
    {
        free(nombres[i]);
    }
    free(vectorDevuelto);
    
    

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
void *BuscaNombrePorId(char *vectorReceptor[],int cantidad,int indiceBuscar){
    int bandera = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (i == indiceBuscar)
        {
            bandera = 1;
        }
    }
    if (bandera)
    {
        printf("Este es el nombre encontrado en la posicion %d: %s\n",indiceBuscar,vectorReceptor[indiceBuscar - 1]);
    }else{
        puts("No se encontro el valor buscado");
    }   
}
char *BuscaNombrePorPalabra(char *vectorReceptor[], int cantidad, char *nombreABuscar){
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
