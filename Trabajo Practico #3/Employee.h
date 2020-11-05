#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define NOMBRE_LEN 128
#define CANTIDAD_REINTENTOS 3
#define MIN_ID 0
#define MAX_ID 9999
#define MIN_SUELDO 0
#define MAX_SUELDO 100000
typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,float sueldo);
Employee* employee_newParametrosTxt(char* id,char* nombre,char* horasTrabajadas, char* sueldo);
void employee_delete(Employee*);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setIdTxt(Employee* this, char* id);
int employee_getIdTxt(Employee* this, char* id);

int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);
int employee_getHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);

int employee_setSueldo(Employee* this, float sueldo);
int employee_getSueldo(Employee* this, float* sueldo);
int employee_setSueldoTxt(Employee* this, char* sueldo);
int employee_getSueldoTxt(Employee* this, char* sueldo);

int employee_compareByName(void* thisA, void* thisB);

#endif // employee_H_INCLUDED
