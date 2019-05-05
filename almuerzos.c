#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "menu.h"
#include "fecha.h"
#include "sectores.h"
#include "empleados.h"
#include "almuerzos.h"

#define MAXALM 21
#define MAXMENU 5
#define MAXEMP 101

int initLunch(eAlmuerzo list[], int len)
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

int findEmptyLunch(eAlmuerzo list[],int len)
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
int findLunch(eAlmuerzo list[],int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].codigoAlm == file && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};

void viewLunch(eAlmuerzo aAlmuerzo)
{

    printf(" \nCodigo:%d - Menu:%s -  legajo:%d-  Nombre:%s-  Apellido:%s- Dia:%d-  Mes:%d-  Anio:%d \n ", aAlmuerzo.codigoAlm, aAlmuerzo.menuAlm.descripcion, aAlmuerzo.legAlm.file,aAlmuerzo.legAlm.name,aAlmuerzo.legAlm.lastName+,aAlmuerzo.fechaAlm.dia,aAlmuerzo.fechaAlm.mes,aAlmuerzo.fechaAlm.anio);
};

void viewLunchs(eAlmuerzo list[], int len)
{

    system("cls");
    printf(" Codigo Menu Legajo Dia Mes Anio \n\n");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewLunch(list[i]);
        }
    }

};
int addLunch(eAlmuerzo list[],int len,eEmployee listEmp[],int lenEmp,eMenu listMenu[],int lenMenu)
{


    eAlmuerzo newAlmuerzo;



    harcodeoMenu(listMenu);

    int index;
    char auxMenu[51];
    char auxLegajo[51];
    char auxDia[11];
    char auxMes[11];
    char auxAnio[11];
    float ret;
    int fechaCorrecta=-1;
    int menu=0,legajo=0,fecha=0;


    if(list != NULL && MAXALM > 0 )
    {
        system("cls");
        fflush(stdin);
        index = findEmptyLunch(list,len);
        printf("*** ALTA ALMUERZO ***\n\n");
        if( index == -1)
        {

            printf("NO HAY ESPACIO EN EL SISTEMA\n\n");
            ret = -1;
            system("pause");
        }
        else
        {


            printf("Nuevo Almuerzo, su codigo es : %d \n",index);
            newAlmuerzo.codigoAlm = index ;




            if(menu == 0 )
            {

                viewMenus(listMenu,lenMenu);
                while(!funcion_getStringLetras("Ingrese Menu: ",auxMenu))
                {
                    printf("ERROR- EL MENU TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    menu=1;


                };
                 menu=1;

            }


            printf("\nMenu: %s \n",auxMenu);

            if(legajo==0)
            {
                viewEmployees(listEmp,lenEmp);
                while(!funcion_getStringNumeros("Ingrese legajo del empleado: ",auxLegajo))
                {
                    printf("ERROR- EL LEGAJO TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                    system("pause");
                    system("cls");
                    printf("\nMenu: %s \n",auxMenu);
                    legajo=1;

                };
                legajo=1;

            }
            printf("\nMenu: %s - Legajo: %s \n",auxMenu,auxLegajo);
            if(fecha == 0)
            {
                do
                {
                       system("cls");
                       printf("****** Fecha de Almuerzo ******\n\n");
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

                printf("\nMenu: %s - Legajo: %s\n\nFecha de Almuerzo\n\nDia %s - Mes %s - Anio %s \n\n",auxMenu,auxLegajo,auxDia,auxMes,auxAnio);
                system("pause");

            while((menu == 1) && (legajo == 1) &&(fecha == 1))
            {

                strcpy(newAlmuerzo.menuAlm.descripcion,auxMenu);
                newAlmuerzo.legAlm.file = atoi(auxLegajo);
                newAlmuerzo.fechaAlm.dia = atoi(auxDia);
                newAlmuerzo.fechaAlm.mes = atoi(auxMes);
                newAlmuerzo.fechaAlm.anio = atoi(auxAnio);


                newAlmuerzo.isEmpty = 0;
                list[index] = newAlmuerzo ;
                system("cls");
                printf("\n\n********ALMUERZO CARGADO CORRECTAMENTE*********\n\n");
                viewLunch(list[index]);
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

