
typedef struct
{
    int codigo;
    char descripcion[51];
    float importe;
    int isEmpty;
} eMenu;

void harcodeoMenu(eMenu* list);
void viewMenu(eMenu aMenus);
void viewMenus(eMenu list[], int len);
