
#define ARCH_EMP "data/empleados.dat"
#define ARCH_INDEX "data/index.dat"

#define MAX_BUFF 40
#define MAX_LINE 300
#define MAX_LEGAJO 10000
#define TRUE 0
#define FALSE 1

#define SUSCCESS 0
#define ERR 1

#define ACTIVO 1
#define BAJA 2




typedef  enum {
    operario,jefe
} t_tipoempleado;

typedef struct {
    char categoria[MAX_BUFF];
} t_empleado_nojerarquico;

typedef struct {
    char nombreOficina[MAX_BUFF];
    char cantEmpleados[MAX_BUFF];
} t_empleado_jerarquico;

typedef union {
        t_empleado_nojerarquico d1;
        t_empleado_jerarquico d2;
} templeado;

typedef struct {
    int legajo;
    char nombre[MAX_BUFF];
    int activo;
    t_tipoempleado cargo;
    templeado jerarquia;
}t_empleado;


/*****************
* MENU
*****************/
void printMenu ();
int menu (int, int);

/**************
* ABM
***************/
int create();
int read(int, fpos_t *);
int update();
int delete();


/**************
* EMPLEADO
**************/
int validateEmp(t_empleado *, int);
int empToStruct(t_empleado *, char[]);


int printEmpleado(t_empleado *);
void printJefe(t_empleado *);
void printOperario(t_empleado *);
void printTotal(t_empleado *);

/**************
* Lists
***************/
int list();
int listJefes();
int listOperarios();
int listTotal();

int menuList();
void printMenuLists();

/**************
* UTILS
***************/
int cleanString(char *, char *);
int clean (char *);
int confirma(char *);
int enteroEnRango(char *, int, int);

/**************
* CONEXION
***************/
FILE * connect(char *);
int closeConnect(FILE *fp);
