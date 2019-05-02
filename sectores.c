#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "sectores.h"

void harcodeoSector(eSectores* list)
{

    eSectores x[]=
    {
        {001,"Recursos Humanos",0},
        {002,"IT",0},
        {003,"Finanzas",0},
        {004,"Auditoria",0},
        {005,"Facility",0},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = x[i];
    }
};

void viewSector(eSectores aSectores)
{
    printf(" \nID:%d - Descripcion:%s\n ",aSectores.id,aSectores.descripcion);
};

void viewSectores(eSectores list[], int len)
{

    system("cls");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewSector(list[i]);
        }
    }

};

