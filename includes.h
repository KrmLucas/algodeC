
#define ARCH_EMP "data/empleados.dat"
#define ARCH_INDEX "data/index.dat"

#define MAX_BUFF 40
#define MAX_LINE 300
#define MAX_LEGAJO 10000

#define TRUE 1
#define FALSE 0

#define FAILED 1
#define SUCCESS 0

#define ACTIVO 1
#define BAJA 0

#define B 1
#define M 2

#define JERARQUICO 1
#define NO_JERARQUICO 0

#define LIST_ALL 1
#define LIST_JERARQUICOS 2
#define LIST_NO_JERARQUICOS 3

typedef  enum {
    operario,jefe
} t_tipoempleado;

typedef struct {
    char categoria[MAX_BUFF];
} t_empleado_nojerarquico;

typedef struct {
    char nombreOficina[MAX_BUFF];
    int cantEmpleados;
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
//int read(int, fpos_t *);
int update();
int delete();


/**************
* EMPLEADO
**************/
int validateEmp(t_empleado *, int);
int printEmpleado(t_empleado *);

/**************
* Lists
***************/
int list();
int menuList();
void printMenuLists();

void enc_jefes();
void enc_operarios();
void enc_total();


/**************
* UTILS
***************/
int cleanString(char *, char *);
int clean (char *);
int confirma(char *);
int enteroEnRango(char *, int, int);
void flush_buff(char *);

/**************
* CONEXION
***************/
FILE * connect(char *);
int closeConnect(FILE *fp);
int insert(t_empleado *, int);
int findById(t_empleado *, int);
int findAll(int);
