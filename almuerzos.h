typedef struct
{
    int codigoAlm;
    eMenu menuAlm;
    eEmployee legAlm;
    eFecha fechaAlm;
    int isEmpty;

} eAlmuerzo;

int initLunch(eAlmuerzo list[], int len);

void viewLunch(eAlmuerzo aAlmuerzo);
void viewLunchs(eAlmuerzo list[], int len);
int findEmptyLunch(eAlmuerzo list[],int len);
int findLunch(eAlmuerzo list[],int len, int file);
int addLunch(eAlmuerzo list[],int len,eEmployee listEmp[],int lenEmp,eMenu listMenu[],int lenMenu);


