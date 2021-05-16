#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tp2.h"
#define TAM 0

int inicializarEmpleados(eEmploye lista[],int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].isEmpty = 1;

    }
    return 0;
}

int menu()
{
    int opcion = 0;
    system("cls");
    printf("********** ABM EMPLEADOS **********\n\n");
    printf("1. Alta empleado\n");
    printf("2. Modificacion empleado\n");
    printf("3. Baja empleado\n");
    printf("4. Mostrar empleado\n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d",&opcion);


    return opcion;
}


int altaEmpleado(eEmploye lista[],int tam,int* pLegajo)
{
    int todoOk = 0;// si retorna 0 no se pudo cargar datos
    eEmploye aux;
    int indice;
    system("cls");
    printf("         Alta empleados\n");
    if(lista != NULL && tam > 0 && pLegajo != NULL)
    {
        indice = buscarLibre(lista,tam);
        if(indice == -1)
        {
            printf("No ahi lugar en el sistema\n");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(aux.name);
            while(strlen(aux.name) > 50)
            {
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(aux.name);

            }

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(aux.lastName);
            while(strlen(aux.lastName) > 50)
            {
                printf("Ingrese apellido: ");
                fflush(stdin);
                gets(aux.lastName);

            }

            printf("Ingrese sueldo: ");
            scanf("%f",&aux.salary);

            printf("Ingrese Sector 1 o 2 o 3: ");
            scanf("%d",&aux.sector);
            while(aux.sector < 1 || aux.sector > 3)
            {
                printf("Reingrese Sector 1 o 2 o 3: ");
                scanf("%d",&aux.sector);

            }

            aux.isEmpty = 0;
            aux.id = *pLegajo;
            (*pLegajo)++;
            lista[indice] = aux;
            todoOk = 1;//si retorna uno se pudo cargar los datos
        }

    }
    return todoOk ;
}

int buscarLibre(eEmploye lista[],int tam)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int mostarEmpleados(eEmploye lista[],int tam)
{
    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && tam > 0)
    {
        printf("LEGAJO    NOMBRE      APELLIDO          SUELDO   SECTOR \n");
        printf("--------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarEmpleado(lista[i]);
                printf("\n\n");
                flag = 0;
            }
            todoOk = 1;
        }
        if(flag)
        {
            printf("************* No se encontraron empleados **************\n\n");
        }
    }
    return todoOk;
}


void mostrarEmpleado(eEmploye lista)
{
    printf(" %4d %10s   %10s      %10.2f   %4d    \n",lista.id,lista.name,lista.lastName,lista.salary,lista.sector);
}

int buscarEmpleado(eEmploye lista[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].id == legajo && lista[i].isEmpty == 0)//se revisa los legajos del vector ingresado hasta encontrar el que es igual al numero de legajo ingresado y que el indice este cargado"0"
        {
            indice = i;//Se le da el valor a indice donde esta cargado el numero de legajo que buscamos
            break;
        }
    }
    return indice;
}

int modificarEmpleados(eEmploye lista[], int tam)
{
    int error = 1;
    int indice;
    int legajo;
    int modificar;
    char confirmar;


    if(lista != NULL && tam >0)//validacion de datos de entrada
    {
        system("cls");//Se limpia la pantalla
        printf("Modificar persona\n\n");
        mostarEmpleados(lista, tam);//Funcion MostarEmpleados para ver los numeros de legajo
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        indice = buscarEmpleado(lista, tam, legajo);//la variable indice toma el valor retornado por la funcion buscarEmpleado

        if(indice == -1)//Si no hay nada cargado se le da el valor -1
        {
            printf("No se encontro el legajo\n\n");
        }
        else
        {
            system("cls");
            mostrarEmpleado(lista[indice]);
            printf("1.Nombre\n");
            printf("2.Apellido\n");
            printf("3.Salario\n");
            printf("4.Sector\n");
            printf("Que es lo que desea modificar: ");
            fflush(stdin);
            scanf("%d",&modificar);

            switch(modificar)
            {
            case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(lista[indice].name);
                while(strlen(lista[indice].name) > 50)
                {
                    printf("Error nombre demasiado largo: ");
                    fflush(stdin);
                    gets(lista[indice].name);

                }
                break;

            case 2:
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                gets(lista[indice].lastName);
                while(strlen(lista[indice].lastName) > 50)
                {
                    printf("Error apellido demasiado largo: ");
                    fflush(stdin);
                    gets(lista[indice].lastName);

                }
                break;
            case 3:
                printf("Ingrese sueldo: ");
                scanf("%f",&lista[indice].salary);
                break;

            case 4:
                printf("Ingrese Sector 1 o 2 o 3: ");
                scanf("%d",&lista[indice].sector);
                while(lista[indice].sector < 1 || lista[indice].sector > 3)
                {
                    printf("Reingrese Sector 1 o 2 o 3: ");
                    scanf("%d",&lista[indice].sector);

                }
                break;
            }
            printf("Desea confirmar el cambio?(s=Si o n=No): ");
            fflush(stdin);
            scanf("%c", &confirmar);
            if(confirmar=='s')
            {
                error=0;
            }
            else
            {
                error=1;
            }
        }
    }
    return error;
}


int bajaEmpleado(eEmploye lista[], int tam)
{
    int error = 1;
    int indice;
    int legajo;
    char confirma;

    if(lista != NULL && tam > 0)//validacion de datos de entrada
    {
        system("cls");//Se limpia la pantalla
        printf("Baja de Empleado\n\n");
        mostarEmpleados(lista,tam);//Funcion mostarEmpleados para ver los numeros de legajo
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        indice = buscarEmpleado(lista,tam,legajo);//la variable indice toma el valor retornado por la funcion buscarEmpleado

        if(indice == -1)//Si no hay nada cargado se le da el valor -1
        {
            printf("No hay ninguna Empleado con ese legajo\n\n");
        }
        else
        {
            mostrarEmpleado(lista[indice]);//Se muestra la persona guardada en el indice indicado
            printf("Confirma la eliminacion del empleado?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                lista[indice].isEmpty=1;//Se vacia isEmpty en el indice indicado dentro del vector
                error = 0;//0errores
            }
            else
            {
                error  =2;//si el usuario cancela la baja devuelve un 2
            }
        }
    }
    return error;
}

int ordenamiento(eEmploye lista[],int tam)
{
    int todoOk = -1;
    eEmploye aux;
    if(lista != NULL && tam > 0)
    {
        for(int i = - 1; i < tam; i ++)
        {
            for(int j = i + 1; i < tam; i ++)
            {
                if((lista[i].sector < lista[j].sector) &&
                    (lista[i].sector == lista[i].sector) &&
                     (lista[i].lastName < lista[j].lastName) )
                {
                 aux = lista[i];
                 lista[i] = lista[j];
                 lista[j] = aux;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}













