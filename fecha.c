#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "fecha.h"


void addDia(eFecha list[], int len,char imput[])

{
    char auxDia[6];
    int entro=0;
    int dia=0;

    if(entro == 0)
    {
        do
        {
            while(!funcion_getStringNumeros("Ingrese dia: ", auxDia))
            {
                printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                system("pause");
                system("cls");
                printf("\nDia: %s \n",auxDia);
            }
        }
        while ((dia < 0)&&(dia > 31));

        strcpy(imput,auxDia);
        entro=1;



    }


};

void addMes(eFecha list[], int len,char imput[])

{
    char auxMes[6];
    int entro=0;
    int mes=0;

    if(entro == 0)
    {
        do
        {
            while(!funcion_getStringNumeros("Ingrese mes: ", auxMes))
            {
                printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                system("pause");
                system("cls");
                printf("\nDia: %s \n",auxMes);




            }
        }
        while((mes < 0 )&& (mes >13));
        strcpy(imput,auxMes);
        entro=1;


    }


};

void addAnio(eFecha list[], int len,char imput[])

{
    char auxAnio[6];
    int entro=0;
    int anio=0;

    if(entro == 0)
    {


        do
        {
            while(!funcion_getStringNumeros("Ingrese anio: ", auxAnio))
            {
                printf("ERROR- EL ANIO TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                system("pause");
                system("cls");
                printf("\nAnio: %s \n",auxAnio);


            }


        }
        while((anio< 1900) && (anio >2100));

            strcpy(imput,auxAnio);
            entro=1;



    }
};





