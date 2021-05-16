#ifndef TP2_H_INCLUDED
#define TP2_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmploye;


#endif // TP2_H_INCLUDED


/** \brief inicializa la estructura
 *
 * \param recibe estructura
 * \param tamaño
 * \return retorna 0
 *
 */
int inicializarEmpleados(eEmploye lista[],int tam);

/** \brief muestra el menu de opciones
 * \return retorna la opcion selecciona
 *
 */

int menu();

/** \brief da de alta a un empleado
 *
 * \param recibe estructura
 * \param tamaño
 * \param puntero del legajo
 * \return todoOk que indica si fue todo cargada correctamente
 *
 */

int altaEmpleado(eEmploye lista[],int tam,int* pLegajo);

/** \brief busca espacio libre
 *
 * \param recibe estructura
 * \param tamaño de la estructura
 * \return devuelve el espacio libre
 *
 */
int buscarLibre(eEmploye lista[],int tam);

/** \brief muestra un empleado
 */
void mostrarEmpleado(eEmploye lista);

/** \brief mustra empledos
 *
 * \param recibe estructura
 * \param recibe tamaño
 * \return retorna si lo pudo hacer
 *
 */
int mostarEmpleados(eEmploye lista[],int tam);

 /** \brief modifica a un empleado
  *
  * \param recibe estructura
  * \param tamaño
  * \return si se pudo realizar el cambio
  *
  */
int modificarEmpleados(eEmploye lista[], int tam);

/** \brief se da de baja a un empleado
 *
 * \param recibe structura
 * \param tamaño
 * \return si se pudo realizar la baja
 *
 */
int bajaEmpleado(eEmploye lista[], int tam);

/** \brief ordena los empleados
 *
 * \param recibe estructura
 * \param tamaño
 * \return si se pudo realizar
 *
 */
int ordenamiento(eEmploye lista[],int tam);
