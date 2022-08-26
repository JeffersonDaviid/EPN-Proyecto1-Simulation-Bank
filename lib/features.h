#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <vector>

const int maxID = 999999;
const int minID = 100000;
#define TAB '\t'
#define ENTER '\n'

/**********************************************************************************************************************
                                                    R O O T S
**********************************************************************************************************************/

enum ACCESIBILIDAD
{
    SALIR = 0,
    INICIAR_SESION,
    CREAR_CUENTA
};

enum FUNCIONALIDADES
{
    DEPOSITO = 1,
    RETIRO,
    TRANSFERENCIA,
    HISTORIAL,
    CUENTA
};

enum ACCESORES
{
    DENEGAR = 0,
    ACEPTAR
};

/**********************************************************************************************************************
                                                M A R K E T I N G
**********************************************************************************************************************/
// COLORES Y ASPECTO VISUAL

char lineas[135] = "--------------------------------------------------------------------------------------------------------------------------------------";
char welcome[12] = "WELCOME TO:";
char nameBank[62] = "S I M U L A T I O N  -  I N T E R N A T I O N A L  -  B A N K";
char createUsssssssser[16] = "2. Crear Cuenta";
char iniciarSesssssion[18] = "1. Iniciar Sesion";
char salir[9] = "0. SALIR";
char botonEntrar[25] = "Presione para continuar ";

void inicioAnimacion()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    for (int i = 0; i < 135; i++)
    {
        printf("%c", lineas[i]);
        usleep(1000);
    }
    printf("\n\t\t");
    for (int i = 0; i < 12; i++)
    {
        printf("%c", welcome[i]);
        usleep(3000);
    }
    printf("\n\t\t\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", nameBank[i]);
        usleep(3000);
    }
    printf("\n");
    for (int i = 0; i < 135; i++)
    {
        printf("%c", lineas[i]);
        usleep(1000);
    }
    printf("\n\n\n\n\n\t\t");
    for (int i = 0; i < 18; i++)
    {
        printf("%c", iniciarSesssssion[i]);
        usleep(1000);
    }
    printf("\n\t\t");
    for (int i = 0; i < 16; i++)
    {
        printf("%c", createUsssssssser[i]);
        usleep(1000);
    }
    printf("\n\n\t\t");
    for (int i = 0; i < 8; i++)
    {
        printf("%c", salir[i]);
        usleep(1000);
    }

    printf("\n\n\n\n\n\t\t\t\t\t");
    for (int i = 0; i < 25; i++)
    {
        printf("%c", botonEntrar[i]);
        usleep(1000);
    }
}

void inicio()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    for (int i = 0; i < 135; i++)
        printf("%c", lineas[i]);

    printf("\n\n\t\t");
    for (int i = 0; i < 12; i++)
        printf("%c", welcome[i]);

    printf("\n\t\t\t\t");
    for (int i = 0; i < 62; i++)
        printf("%c", nameBank[i]);

    printf("\n");
    for (int i = 0; i < 135; i++)
        printf("%c", lineas[i]);

    printf("\n\n\n\n\n\n\t\t");
    for (int i = 0; i < 18; i++)
        printf("%c", iniciarSesssssion[i]);

    printf("\n\t\t");
    for (int i = 0; i < 16; i++)
        printf("%c", createUsssssssser[i]);
    printf("\n\n\t\t");
    for (int i = 0; i < 8; i++)
        printf("%c", salir[i]);

    printf("\n\n\n\n\n\t\t\t\t\t");
    for (int i = 0; i < 25; i++)
        printf("%c", botonEntrar[i]);
}
// procedimiento para cambiar el color del fondo y/o pantalla
void setColor(int Background, int Text)
{
    int colorTexto = Text + (Background * 16);         // los colores van del 0 al 255 por eso se multiplica por 16
    HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE); // referenciamos a la consola.
    SetConsoleTextAttribute(terminal, colorTexto);
}

// ENCABEZADO del simulador
void HEADER()
{
    system("cls");
    setColor(14, 0);
    printf(" ------------------------------------------------------------------------------------------------------------------------------------\n");
    setColor(1, 15);
    printf("\t\t\t\tS I M U L A T I O N  -  I N T E R N A T I O N A L  -  B A N K \n");
    setColor(4, 0);
    printf(" ------------------------------------------------------------------------------------------------------------------------------------\n");
    setColor(0, 15);
}

const int LONGITUD_BARR = 30;
// PROGRESS BAR ROTATE
// Iterera caracteres y se queda con el último caracter, es ADAPTABLE a cualquier medida
// BARRA CENTRADA EN PANTALLA
void showBarrRotateCenter(int delay)
{
    char caracteres[] = "|/-\\I";           // valores iterar
    char barr[LONGITUD_BARR];               // barra estatica
    for (int i = 0; i < LONGITUD_BARR; i++) // Coloca espacios vacios para ser iterable
        barr[i] = ' ';

    for (int i = 0; i < LONGITUD_BARR; i++)
    {
        int porcentaje = (i * 100) / (LONGITUD_BARR - 1); // porcentaje/iteración
        for (int x = 0; x <= 4; x++)                      // iterar misma posicion  -  guardar útlimo
        {
            barr[i] = caracteres[(x % 5)];
            printf("\r\t\t\t\t\t[%s] Complete...", barr, porcentaje);
            usleep(450 * delay);
        }
    }
    fflush(stdout); // Limpia la memoria
    printf("\n");
    system("cls");
}

enum Colors
{ // Listado de colores (La letra "L" al inicio, indica que es un color mas claro que su antecesor).
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LGREY = 7,
    DGREY = 8,
    LBLUE = 9,
    LGREEN = 10,
    LCYAN = 11,
    LRED = 12,
    LMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};
