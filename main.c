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


#define MAX 1001
#define MAXMENU 5
#define MAXSEC 5
#define MAXALM 21
#define MAXF 1001
int funcion_opciones();

int main()
{
    eMenu menus[MAXMENU];
    eSectores sectores[MAXSEC];
    eAlmuerzo almuerzo[MAXALM];

    harcodeoMenu(menus);
    harcodeoSector(sectores);


    {
        char seguir='s';
        eEmployee employee[MAX];
        initEmployees(employee,MAX);
        initLunch(almuerzo,MAXALM);
        int flagSinAlta=0;



        do
        {

            switch (funcion_opciones())
            {
            case 1:
                addEmployee(employee, MAX);
                flagSinAlta++;
                break;
            case 2:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN EMPLEADOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    modifyEmployee(employee, MAX);
                };
                break;
            case 3:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN EMPLEADOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    removeEmployee(employee, MAX);
                };
                break;
            case 4:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN EMPLEADOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    sortemployees(employee,MAX);
                    viewEmployees(employee, MAX);
                };

                break;
            case 5:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN EMPLEADOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    addLunch(almuerzo,MAXALM,employee,MAX,menus,MAXMENU);

                    //viewLunchs(almuerzo,MAXALM,employee,employee[index].file);
                };

                break;
            case 6:
                printf("Saliendo...");
                exit(-1);
                break;
            default:
                printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
                system("pause");
                break;

            }
            printf("\n Desea continuar? si/no \n\n");
            scanf("%c",&seguir);

            fflush(stdin);
            system("cls");


        }
        while (seguir == 's' || seguir == 'S');

        printf("\n\n Saliendo...\n\n");

    }
    return 0;
}
