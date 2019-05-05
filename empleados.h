typedef struct
{
    int file;
    char name[51];
    char lastName[51];
    char gender[51];
    float salary;
    eFecha fechaEmpleado;
    eSectores sectorEmpleado;
    int isEmpty;
} eEmployee;

int initEmployees(eEmployee list[], int len);
int findEmpty(eEmployee list[],int len);
int findEmployee(eEmployee list[],int len, int file);
void viewEmployee(eEmployee aEmployee);
void viewEmployees(eEmployee list[], int len);
int addEmployee(eEmployee list[], int len);
int funcion_opciones();
int removeEmployee(eEmployee* list, int len);
void modifyEmployee(eEmployee list[], int len);
int sortemployees(eEmployee list[], int len);



