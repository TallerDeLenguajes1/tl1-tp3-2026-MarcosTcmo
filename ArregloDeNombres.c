#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
void *mostrarVector(char **vectorReceptor, int cantidad);
void *BuscaNombrePorId(char **vectorReceptor, int cantidad, int indiceBuscar);
char *BuscaNombrePorPalabra(char **vectorReceptor, int cantidad, char *nombreABuscar);

int main()
{
    int tamanioCadena = 0, indiceBuscar = 0, eleccionUsuario, cantidadNombres = 0;
    char **nombres, nombre[50], *nombreABuscar = NULL, *vectorDevuelto = NULL;
    printf("Ingrese la cantidad de nombres que desea ingresar: \n");
    scanf("%d", &cantidadNombres);
    limpiarBuffer();
    nombres = (char **)malloc(cantidadNombres * sizeof(char *));
    for (int i = 0; i < cantidadNombres; i++)
    {
        puts("Ingrese un Nombre");
        fgets(nombre, 50, stdin);
        nombre[strcspn(nombre, "\n")] = 0;
        tamanioCadena = strlen(nombre);
        nombres[i] = (char *)malloc((tamanioCadena + 1) * sizeof(char));
        strcpy(nombres[i], nombre);
        // printf("Nombre guardado %s\n",nombres[i]);
    }
    mostrarVector(nombres, cantidadNombres);
    puts("----------------------\n¿Porque metodo quiere buscar el nombre?\n1. Mediante Id\n2. Mediante palabra clave\n----------------------");
    scanf("%d", &eleccionUsuario);
    switch (eleccionUsuario)
    {
    case 1:
        printf("Ingrese que indice quiere buscar en el vector: \n");
        scanf("%d", &indiceBuscar);
        BuscaNombrePorId(nombres, cantidadNombres, indiceBuscar);
        break;
    case 2:
        printf("Ingrese un nombre que quiera buscar: ");
        scanf("%s", &nombre);
        limpiarBuffer();
        nombreABuscar = (char *)malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(nombreABuscar, nombre);
        
        vectorDevuelto = BuscaNombrePorPalabra(nombres, cantidadNombres, nombreABuscar);
        puts(vectorDevuelto);
        break;
    }
    free(vectorDevuelto);
    free(nombreABuscar);
    
    for (int i = 0; i < cantidadNombres; i++)
    {
        free(nombres[i]);
    }
    free(nombres);

    getchar();
    return 0;
}

void *mostrarVector(char **vectorReceptor, int cantidad)
{
    printf("Nombres de los vectores almacenados: \n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Nombre %d: %s\n", i + 1, vectorReceptor[i]);
    }
}
void *BuscaNombrePorId(char **vectorReceptor, int cantidad, int indiceBuscar)
{
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
        printf("Este es el nombre encontrado en la posicion %d: %s\n", indiceBuscar, vectorReceptor[indiceBuscar - 1]);
    }
    else
    {
        puts("No se encontro el valor buscado");
    }
}
char *BuscaNombrePorPalabra(char **vectorReceptor, int cantidad, char *nombreABuscar)
{
    char *resultado, *vectorDevuelto;
    for (int i = 0; i < cantidad; i++)
    {
        resultado = strstr(vectorReceptor[i], nombreABuscar);
        if (resultado != NULL)
        {
            vectorDevuelto = (char *)malloc((strlen(vectorReceptor[i]) + 1) * sizeof(char));
            strcpy(vectorDevuelto, vectorReceptor[i]);
            return vectorDevuelto;
        }
    }
    vectorDevuelto = (char *)malloc(3 * sizeof(char));
    strcpy(vectorDevuelto, "-1");
    return vectorDevuelto;
}
