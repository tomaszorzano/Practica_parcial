#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "Funciones.h"

void harcodeoMenu(eMenu* list)
{

    eMenu x[]={
    {001,"Menu Vegetariano",150.00,0},
    {002,"Menu Argentino",130.00,0},
    {003,"Menu Venezolano",200.00,0},
    {004,"Menu Carnivoro",223.00,0},
    {005,"Menu del dia",100.00,0},
    };
    for(int i = 0; i< 5;i++)
    {
        list[i] = x[i];
    }
};

void viewMenu(eMenu aMenus)
{
    printf(" \nCodigo:%d- Descripcion:%s- Importe:%0.2f\n ",aMenus.codigo,aMenus.descripcion,aMenus.importe);
};

void viewMenus(eMenu list[], int len)
{

    system("cls");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewMenu(list[i]);
        }
    }

};

