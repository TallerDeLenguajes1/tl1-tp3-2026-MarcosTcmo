#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
char *TiposProductos[5] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
typedef struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos          // El tamaño de este arreglo depende de la variable
                                 //  “CantidadProductosAPedir”
} Cliente;
float costoTotal(Producto productoRecibido);
void mostrarPorPantalla(Cliente mostrar, float precioTotal);

int main()
{
    srand(time(NULL));
    char nombreClienteTemporal[50];
    int cantidadClientes = 0, idProductoRandom = 0;
    float costoTotalProductos, costoTotalTodosProductos = 0;
    puts("Buenos Dias\nCuantos Clientes quiere ingresar el dia de hoy?");
    scanf("%d", &cantidadClientes);
    limpiarBuffer();
    Cliente *clientesCargados;
    clientesCargados = (Cliente *)malloc(cantidadClientes * sizeof(Cliente));
    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("Cargue el nombre del cliente: %d\n", i + 1);
        scanf("%s", &nombreClienteTemporal);
        limpiarBuffer();
        clientesCargados[i].NombreCliente = (char *)malloc((strlen(nombreClienteTemporal) + 1) * (sizeof(char)));
        strcpy(clientesCargados[i].NombreCliente, nombreClienteTemporal);
        clientesCargados[i].ClienteID = i;
        clientesCargados[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientesCargados[i].Productos = (Producto *)malloc(clientesCargados[i].CantidadProductosAPedir * sizeof(Producto));
        printf("Cantidad de productos que cargara: %d\n", clientesCargados[i].CantidadProductosAPedir);
        costoTotalTodosProductos = 0;
        for (int j = 0; j < clientesCargados[i].CantidadProductosAPedir; j++)
        {
            clientesCargados[i].Productos[j].ProductoID = j;
            clientesCargados[i].Productos[j].Cantidad = rand() % 10 + 1;
            idProductoRandom = rand() % 5;
            clientesCargados[i].Productos[j].TipoProducto = TiposProductos[idProductoRandom];
            clientesCargados[i].Productos[j].PrecioUnitario = (rand() % (100 - 10 + 1)) + 10;
            costoTotalProductos = costoTotal(clientesCargados[i].Productos[j]);
            costoTotalTodosProductos += costoTotalProductos;
        }
        mostrarPorPantalla(clientesCargados[i], costoTotalTodosProductos);
    }
    for (int i = 0; i < cantidadClientes; i++)
    {
        free(clientesCargados[i].NombreCliente);
        free(clientesCargados[i].Productos);
    }
    free(clientesCargados);
    getchar();
    return 0;
}
float costoTotal(Producto productoRecibido)
{
    return productoRecibido.Cantidad * productoRecibido.PrecioUnitario;
}
void mostrarPorPantalla(Cliente mostrar, float precioTotal)
{
    printf("Cliente numero :%d\nNombre : %s\nCantidad productos a pedir: %d\n", mostrar.ClienteID + 1, mostrar.NombreCliente, mostrar.CantidadProductosAPedir);
    for (int i = 0; i < mostrar.CantidadProductosAPedir; i++)
    {
        printf("---------------\nProducto Id: %d\nCantidad Productos: %d\nProducto pedido: %s\nPrecio Unitario: %.2f\n---------------", mostrar.Productos[i].ProductoID + 1, mostrar.Productos[i].Cantidad, mostrar.Productos[i].TipoProducto, mostrar.Productos[i].PrecioUnitario);
    }
    printf("\nCosto total de los pedidos: %.2f\n", precioTotal);
}