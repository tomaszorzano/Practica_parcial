typedef struct
{
    int id;
    char  descripcion[51];
    int isEmpty;


} eSectores;

void harcodeoSector(eSectores* list);
void viewSector(eSectores aSectores);
void viewSectores(eSectores list[], int len);
