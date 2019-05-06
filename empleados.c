#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "fecha.h"
#include "sectores.h"
#include "empleados.h"


#define MAX 1001
#define MAXF 1001
#define MAXS 5

int initEmployees(eEmployee list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        };
    }
    else
    {
        ret = -1;
    };

    return ret;
};
int findEmpty(eEmployee list[],int len)
{
    int index = -1;
    for(int i=0; i< len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        };
    };
    return index ;
};
int findEmployee(eEmployee list[],int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].file == file && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};

void viewEmployee(eEmployee aEmployee)
{

    printf(" \nLegajo:%d - Nombre:%s -  Apellido:%s- Genero:%s - Salario:%.2f-  Sector:%s-  Dia:%d-  Mes:%d-  Anio:%d \n ", aEmployee.file, aEmployee.name, aEmployee.lastName, aEmployee.gender, aEmployee.salary,aEmployee.sectorEmpleado.descripcion,aEmployee.fechaEmpleado.dia,aEmployee.fechaEmpleado.mes,aEmployee.fechaEmpleado.anio);
};

void viewEmployees(eEmployee list[], int len)
{

    system("cls");


    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewEmployee(list[i]);
        }
    }

};
int addEmployee(eEmployee list[], int len)
{
    eEmployee newEployee;
    eSectores sectorEmpleado[MAXS];

    harcodeoSector(sectorEmpleado);

    int index;
    char auxName[51];
    char auxLastName[51];
    char auxSalary[10];
    char auxGender[51];
    char auxSector[51];
    char auxDia[11];
    char auxMes[11];
    char auxAnio[11];
    float ret;
    int fechaCorrecta=-1;
    int nombre=0,apellido=0,salario=0,genero=0,fecha=0;
    int sector=0;

    if(list != NULL && MAX > 0 )
    {
        system("cls");
        fflush(stdin);
        index = findEmpty (list, len);
        printf("*** ALTA EMPLEADO ***\n\n");
        if( index == -1)
        {

            printf("NO HAY ESPACIO EN EL SISTEMA\n\n");
            ret = -1;
            system("pause");
        }
        else
        {


            printf("Empleado Nuevo, su legajo es : %d \n",index);
            newEployee.file = index ;




            if(nombre == 0 )
            {
                while(!funcion_getStringLetras("Ingrese Nombre: ",auxName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    nombre=1;


                };
                 nombre=1;

            }


            printf("\nNombre: %s \n",auxName);

            if(apellido==0)
            {
                while(!funcion_getStringLetras("Ingrese Apellido: ",auxLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s \n",auxName);
                    apellido=1;

                };
                apellido=1;

            }
            printf("\nNombre: %s - Apellido: %s \n",auxName,auxLastName);
            if(salario == 0)
            {
                while(!funcion_getStringNumerosFlotantes("Ingrese Salario: ",auxSalary))
                {
                    printf("ERROR- EL SALARIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s \n",auxName,auxLastName);
                    salario=1;
                };
                salario=1;

            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s \n",auxName,auxLastName,auxSalary);

            if(genero == 0)
            {
                while(!funcion_getStringLetras("Ingrese Genero: ",auxGender))
                {
                    printf("ERROR- EL GENERO TIENE QUE CONTENER SOLO NUMEROS ENTEROS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s - Salario: %s \n\n",auxName,auxLastName,auxSalary);
                    genero=1;
                };
                genero=1;

            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s - Genero %s \n",auxName,auxLastName,auxSalary,auxGender);

            if(sector == 0)
            {
                viewSectores(sectorEmpleado,MAXS);
                while(!funcion_getStringLetras("Ingrese sector: ",auxSector))
                {
                    printf("ERROR- EL SECTOR TIENE QUE CONTENER SOLO NUMEROS ENTEROS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s - Salario: %s- Genero: %s \n",auxName,auxLastName,auxSalary,auxGender);
                    sector=1;
                 };
                sector=1;

            }
           printf("\nNombre: %s - Apellido: %s - Salario: %s - Genero %s - Sector: %s \n",auxName,auxLastName,auxSalary,auxGender,auxSector);

            if(fecha == 0)
            {
                do
                {
                       system("cls");
                       printf("****** Fecha de Ingreso ******\n\n");
                       while(!funcion_getStringNumeros("Ingrese dia: ", auxDia))
                        {
                            printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");

                        };
                        while(!funcion_getStringNumeros("Ingrese mes: ", auxMes))
                        {
                            printf("ERROR- EL MES TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");

                        };
                        while(!funcion_getStringNumeros("Ingrese anio: ", auxAnio))
                        {
                            printf("ERROR- EL ANIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");
                        };

                        fechaCorrecta = funcion_ValidarFecha(auxDia,auxMes,auxAnio);

                    }
                    while(fechaCorrecta == 0);

                fecha=1;


            }

                printf("\nNombre: %s - Apellido: %s - Salario: %s - Genero %s- Sector: %s\n\nFecha de Ingreso\n\nDia %s - Mes %s - Anio %s \n\n",auxName,auxLastName,auxSalary,auxGender,auxSector,auxDia,auxMes,auxAnio);
                system("pause");

            while((nombre == 1) && (apellido == 1) && (salario == 1) && (genero == 1) && (fecha == 1) && (sector == 1))
            {
                strcpy(newEployee.name,auxName);
                strcpy(newEployee.lastName,auxLastName);
                strcpy(newEployee.gender,auxGender);
                newEployee.salary = atof(auxSalary);
                newEployee.fechaEmpleado.dia = atoi(auxDia);
                newEployee.fechaEmpleado.mes = atoi(auxMes);
                newEployee.fechaEmpleado.anio = atoi(auxAnio);
                strcpy(newEployee.sectorEmpleado.descripcion,auxSector);

                newEployee.isEmpty = 0;
                list[index] = newEployee ;
                system("cls");
                printf("\n\n********NUEVO EMPLEADO, BIENVENIDO*********\n\n");
                viewEmployee(list[index]);
                printf("\n\n\n");
                ret=0;
                break;

            }
        }
    }
    else
    {
        ret =-1;
    }
    return ret;

};
int funcion_opciones()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- ALTA \n");
    printf(" 2- MODIFICAR \n");
    printf(" 3- BAJA \n");
    printf(" 4- INFORMAR \n");
    printf(" 5- INGRESAR ALMUERZO \n");
    printf(" 6- SALIR \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-6 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 6\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};

int funcion_opcionesModificacion()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES *******");
    printf("\n Que desea modificar?\n");
    printf(" 1- NOMBRE \n");
    printf(" 2- APELLIDO \n");
    printf(" 3- SALARIO \n");
    printf(" 4- SECTOR \n");
    printf(" 5- GENERO \n");
    printf(" 6- NO MODIFICAR NADA \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-6 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 6\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};
int removeEmployee(eEmployee* list, int len)
{

    int index;
    char next[3];
    int id;
    char auxId[4];



    system("cls");
    printf("  *** BAJA EMPLEADO ***\n\n");

    while(!funcion_getStringNumeros("Ingrese Legajo: ", auxId))
    {
        printf("ERROR- EL LEGAJO TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index = findEmployee(list, len, id);

    while (index == 0)
    {
        printf("NO HAY NINGUN EMPLEADO CON ESE LEGAJO %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un legajo existente: ", auxId))
        {
            printf("ERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findEmployee(list, len, id);

    }



    while (index == 1)
    {
        viewEmployee(list[index]);

        while(!funcion_getStringLetras("\nQUIERE BORRAR USUARIO DEL SISTEMA? si/no: ",next))
        {
            printf("\n ERROR DEBE CONTENER SOLO LETRAS");
        }

        fflush(stdin);



        if(strcmp(next,"si") && strcmp(next,"SI"))
        {
            printf("NO SE REALIZO LA BAJA\n\n");
            break;


        }
        else if(strcmp(next,"no")&& strcmp(next,"NO"))
        {

            list[index].isEmpty = 1;
            printf("SE HIZO LA BAJA DEL EMPLEADO CORRECTAMENTE\n\n");
            break;


        }

    }
    return -1;
}

void modifyEmployee(eEmployee list[], int len)
{
    eSectores nSector[MAXS];
    harcodeoSector(nSector);
    int id;
    char auxId[5];
    int index;
    char newSalary[10];
    char newSector[51];
    char newName[51];
    char newLastName[51];
    char newGender[31];
    char seguir='s';
    int exit = 1;

    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    while(!funcion_getStringNumeros("Ingrese legajo: ", auxId))
    {
        printf("ERROR- EL LEGAJO TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index = findEmployee(list, len, id);

    while (index == -1)
    {
        printf("NO HAY NINGUN EMPLEADO CON ESE LEGAJO %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un legajo existente: ", auxId))
        {
            printf("ERROR- EL LEGAJO TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findEmployee(list, len, id);

    }


    while ((index >= 0) && (index <=1000))
    {
        viewEmployee(list[index]);

        do
        {
            switch (funcion_opcionesModificacion())
            {
            case 1:
                fflush(stdin);
                viewEmployee(list[index]);

                while(!funcion_getStringLetras("Ingrese nombre nuevo: ", newName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].name,newName);
                exit = 0;
                break;
            case 2:
                fflush(stdin);
                viewEmployee(list[index]);
                while(!funcion_getStringLetras("Ingrese apellido nuevo: ",newLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].lastName,newLastName);
                exit = 0;

                break;
            case 3:
                fflush(stdin);
                viewEmployee(list[index]);

                while(!funcion_getStringNumerosFlotantes("Ingrese Salario: ", newSalary))
                {
                    printf("ERROR- EL SALARIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                    system("pause");
                    system("cls");

                };

                list[index].salary = atof(newSalary);
                exit = 0;
                break;
            case 4:
                fflush(stdin);
                viewEmployee(list[index]);
                viewSectores(nSector,MAXS);

                while(!funcion_getStringLetras("Ingrese sector nuevo: ", newSector))
                {
                    printf("ERROR- EL SECTOR TIENE QUE CONTENER SOLO LETRAS \n\n");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].sectorEmpleado.descripcion,newSector);
                exit = 0;
                break;
                case 5:
                fflush(stdin);
                viewEmployee(list[index]);
                while(!funcion_getStringLetras("Ingrese genero nuevo: ", newGender))
                {
                    printf("ERROR- EL SECTOR TIENE QUE CONTENER SOLO LETRAS \n\n");
                    system("pause");
                    system("cls");
                };
                 strcpy(list[index].gender,newGender);
                exit = 0;
                break;
            case 6:
                printf("Volviendo a menu principal");
                exit = 1;

                break;
            default:
                printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 6\n\n");
                system("pause");
                break;


            }

            if(exit==0)

            {
                printf("\n     *** MODIFICACCION EXITOSA ***");
                printf("\nDesea continuar modificando? \n\n");
                scanf("%c",&seguir);

                fflush(stdin);
                system("cls");
                break;
            }

            else
            {
                printf("\n\nEsta por salir de modificacion esta seguro? s/n \n\n");
                scanf("%c",&seguir);

                fflush(stdin);
                system("cls");

            }
            return;
        }
        while (seguir == 's' || seguir == 'S');


    }
    };

int sortemployees(eEmployee list[], int len)
{
    eEmployee auxEmployee;

    int ret;


    if(list != NULL && len > 0)
    {

        for(int i = 0; i < len-1; i++)
        {
            for(int j = i+1; j < len; j++)
            {
               if(strcmp(list[j].lastName, list[i].lastName) > 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].name < list[i].name  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
        }
    }


    else
    {
        ret = -1;
    }


    return ret;

};

