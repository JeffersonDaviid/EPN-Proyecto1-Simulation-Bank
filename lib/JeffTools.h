#include <stdio.h>
#include <unistd.h>
#include <time.h>

const int maxID = 999999;
const int minID = 100000;

/**********************************************************************************************************************
                                                    R O O T S
**********************************************************************************************************************/

typedef struct // con typedef declaramos las variables de estructuras más fácil (tiene más usos)
{
    int ID;
    char user[20];
    char password[20];
    char email[30];
    char county[20];
    char city[20];
    char phoneNumber[10];
    char identificationCard[12];
    float cash;
} usuario;

// USER POR DEFECTO
usuario usuarios[25] = // Usuarios por defecto
    {
        {121212, "FRANCIS", "Constrasenia1", "email1@try.com", "Ecuador", "Quito", "525568515", "1759354151", 200},
        {232323, "JOSE", "Constrasenia2", "email2@try.com", "Ecuador", "Quito", "984521385", "1865245515", 100.00},
        {454545, "EMELY", "Constrasenia3", "email3@try.com", "Colombia", "Bogota", "945824681", "7216545354", 50.00},
        {565656, "MICA", "Constrasenia4", "email4@try.com", "Ecuador", "Guayaquil", "952568515", "1759354151", 25.30},
        {131463, "Aldahir", "constraseña2", "amigos@gmai.com", "Ecuador", "Quito", "985628564", "1958425654", 0.00},
        {100282, "Camila", "contrasenia32", "camila32@gmail.com", "Venezuela", "Caracas", "351584596", "8952484651", 35.00},
        {100762, "Jefferson", "contrasenia2", "david32@pepe.com", "Japon", "Japon", "855482156", "5245625482", 150.00},
        {101615, "Martin", "martinelCrack", "martin@outlook.com", " Chile ", "Republica", "487432151", "5465151515", 30.00},
        {787878, "ALANIS", "Contrasenia5", "email5@try.com", "Estados Unidos", "New York", "984521385", "1651245515", 5000.00}};

/**********************************************************************************************************************
                                                M A R K E T I N G
**********************************************************************************************************************/
// COLORES Y ASPECTO VISUAL

void inicioAnimacion()
{
    char lineas[94] = "----------------------------------------------------------------------------------------------";
    char welcome[11] = "WELCOME TO:";
    char nameBank[61] = "S I M U L A T I O N  -  I N T E R N A T I O N A L  -  B A N K";
    char createUsssssssser[15] = "2. Crear Cuenta";
    char iniciarSesssssion[17] = "1. Iniciar Sesion";
    char salir[8] = "0. SALIR";

    char botonEntrar[24] = "Presione para continuar ";

    printf("\n\n\n\n\n\n\n\n\n\n\n");
    for (int i = 0; i < 94; i++)
    {
        printf("%c", lineas[i]);
        usleep(1000);
    }
    printf("\n\t");
    for (int i = 0; i < 11; i++)
    {
        printf("%c", welcome[i]);
        usleep(3000);
    }
    printf("\n\t\t");
    for (int i = 0; i < 61; i++)
    {
        printf("%c", nameBank[i]);
        usleep(3000);
    }
    printf("\n");
    for (int i = 0; i < 94; i++)
    {
        printf("%c", lineas[i]);
        usleep(1000);
    }
    printf("\n\n\n\n\n\t");
    for (int i = 0; i < 17; i++)
    {
        printf("%c", iniciarSesssssion[i]);
        usleep(1000);
    }
    printf("\n\t");
    for (int i = 0; i < 15; i++)
    {
        printf("%c", createUsssssssser[i]);
        usleep(1000);
    }
    printf("\n\n\t");
    for (int i = 0; i < 8; i++)
    {
        printf("%c", salir[i]);
        usleep(1000);
    }

    printf("\n\n\n\n\n\t\t\t\t");
    for (int i = 0; i < 24; i++)
    {
        printf("%c", botonEntrar[i]);
        usleep(1000);
    }
}

void inicio()
{
    char lineas[94] = "----------------------------------------------------------------------------------------------";
    char welcome[11] = "WELCOME TO:";
    char nameBank[61] = "S I M U L A T I O N  -  I N T E R N A T I O N A L  -  B A N K";
    char createUsssssssser[15] = "2. Crear Cuenta";
    char iniciarSesssssion[17] = "1. Iniciar Sesion";
    char salir[8] = "0. SALIR";
    char botonEntrar[24] = "Presione para continuar ";

    printf("\n\n\n\n\n\n\n\n\n\n\n");
    for (int i = 0; i < 94; i++)
        printf("%c", lineas[i]);

    printf("\n\t");
    for (int i = 0; i < 11; i++)
        printf("%c", welcome[i]);

    printf("\n\t\t");
    for (int i = 0; i < 61; i++)
        printf("%c", nameBank[i]);

    printf("\n");
    for (int i = 0; i < 94; i++)
        printf("%c", lineas[i]);

    printf("\n\n\n\n\n\t");
    for (int i = 0; i < 17; i++)
        printf("%c", iniciarSesssssion[i]);

    printf("\n\t");
    for (int i = 0; i < 15; i++)
        printf("%c", createUsssssssser[i]);
    printf("\n\n\t");
    for (int i = 0; i < 8; i++)
        printf("%c", salir[i]);

    printf("\n\n\n\n\n\t\t\t\t");
    for (int i = 0; i < 24; i++)
        printf("%c", botonEntrar[i]);
}

// ENCABEZADO del simulador
void HEADER()
{
    printf(" --------------------------------------------------------------------------------------------\n");
    printf("\t\tS I M U L A T I O N  -  I N T E R N A T I O N A L  -  B A N K \n");
    printf(" --------------------------------------------------------------------------------------------\n");
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
    {
        barr[i] = ' ';
    }

    for (int i = 0; i < LONGITUD_BARR; i++)
    {
        int porcentaje = (i * 100) / (LONGITUD_BARR - 1); // porcentaje/iteración
        for (int x = 0; x <= 4; x++)                      // iterar misma posicion  -  guardar útlimo
        {
            barr[i] = caracteres[(x % 5)];
            printf("\r\t\t\t[%s] Complete...", barr, porcentaje);
            usleep(450 * delay);
        }
    }
    fflush(stdout); // Limpia la memoria
    printf("\n");
}