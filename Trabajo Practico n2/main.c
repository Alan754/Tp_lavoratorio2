#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 1000
#include "tp2.h"
//Profe soy alan fernando peralta soy el que no puede instalar eclipse en su pc ya avise en administracion desde el tp1
int main()
{
    int nexLegajo = 2000;
    int respuesta;
    char salida = 'n';
    eEmploye Empleados[TAM];
    int flag = 0;
    inicializarEmpleados(Empleados,TAM);
    do
    {
        switch(menu())
        {
        case 1:
            if(altaEmpleado(Empleados,TAM,&nexLegajo))
            {
                printf("Los datos fueron cargados sin problema\n");
            }
            else
            {
                printf("No se pudieron cargar los datos del emplado ya que el sistema esta lleno \n");
            }
            flag = 1;
            break;
        case 2:
            if(flag == 1)
            {
                respuesta = modificarEmpleados(Empleados,TAM);
                if(respuesta == 0)
                {
                    printf("Se realizo la modificacion con exito!!!\n");
                }
                else if(respuesta == 1)
                {
                    printf("Problemas al intentar modificar la persona\n");
                }
                else
                {
                    printf("Modificacion cancelada por el usuario");
                }
                flag = 2;
            }
            else
            {
                printf("Primero debe cargar los empleados\n");
                system("pause");
            }
            break;
        case 3:
            if(flag == 2)
            {
                respuesta = bajaEmpleado(Empleados,TAM);
                if(respuesta == 0)
                {
                    printf("Se realizo la baja con exito!!!");
                }
                else if(respuesta == 1)
                {
                    printf("Problemas al intentar realizar la baja");
                }
                else
                {
                    printf("Baja cancelada por el usuario");
                }
            }
            else if(flag == 1 || flag == 0)
            {
                printf("Primero debe cargar los empledos para poder utilizar esta funcion");
                system("pause");
            }
            break;
        case 4:
            if(flag == 1)
            {
                system("cls");
                mostarEmpleados(Empleados,TAM);
                respuesta = ordenamiento(Empleados,TAM);
                if(respuesta == 1)
                {
                    mostarEmpleados(Empleados,TAM);
                }
                else
                {
                    printf("Hubo un error en el ordenamiento de caracteres\n");
                }
            }
            else
            {
                printf("Primero debe cargar los empledos para poder utilizar esta funcion");
                system("pause");
            }

            break;
        case 5:
            flag = 0;
            printf("\nSeguro que desea salir? s(si)/n(no): ");
            fflush(stdin);
            scanf("%c",&salida);
            salida = tolower(salida);
            while(salida != 's' && salida != 'n')
            {
                printf("Error ingrese s o n para salir: ");
                fflush(stdin);
                scanf("%c",&salida);
                salida = tolower(salida);
            }
            break;
        }
        system("pause");
    }
    while(salida == 'n');

    return 0;
}
