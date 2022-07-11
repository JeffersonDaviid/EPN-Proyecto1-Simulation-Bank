#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

/**************************************************************
Date         : 17.jun.2022
Developer's  : Chileno Jefferson - Narváez Jhoel - Palma Darío
Subject      : Simulation Bank
**************************************************************/

const int DELAY = 1000; // Tiempo de espera
char EnterOrExit;
int positionUserFree; // indica la posicion de usuario

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

// BUSCA POSITION LIBRE PARA CREAR NUEVO USUARIO
void searchPositionFree()
{
    for (int i = 0; i < 100; i++)
        if (usuarios[i].user[0] == '\0') // si la propiedad esta vacia
        {
            positionUserFree = i;
            break;
        }
}

// CREAR NUEVO USUARIO
void createNewUser()
{
    searchPositionFree(); // ESPACIO PARA NUEVO USUARIO
    // printf("\n soy la posicion %d y estoy vacia", positionUserFree); // revisar la posición vacia

    // GUARDAMOS EL NOMBRE
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a nombre, salta a contrasenia
    printf("\n COMPLETE LOS SIGUIENTES CAMPOS - COMPLETE THE FOLLOWING FIELDS\n");
    printf("\n Nombre - Name:\t\t\t");
    scanf("%s", &usuarios[positionUserFree].user);
    // GUARDAMOS LA CONSTRASEÑA
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a contraseña, salta a email
    printf(" Contrasena - Password:\t\t");
    scanf("%s", &usuarios[positionUserFree].password);
    // GUARDAMOS EMAIL
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a email, salta a country
    printf(" Correo - Email:\t\t");
    scanf("%s", &usuarios[positionUserFree].email);
    // GUARDAMOS PAIS
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a country, salta a city
    printf(" Pais - Country:\t\t");
    scanf("%s", &usuarios[positionUserFree].county);
    // GUARDAMOS CIUDAD
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a city, salta a phoneNumber
    printf(" Ciudad - City:\t\t\t");
    scanf("%s", &usuarios[positionUserFree].city);
    // GUARDAMOS TELEFONO
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a phoneNumber, salta a IdentificationCard
    printf(" Telefono - Phone number:\t0");
    scanf("%s", &usuarios[positionUserFree].phoneNumber);
    // GUARDAMOS IDENTIFICACION
    fflush(stdin); // LIMPIA EL BUFFER - RAM
    printf(" Pasaporte - Passport:\t\t");
    scanf("%s", &usuarios[positionUserFree].identificationCard);
    // ASIGNAR UN ID UNICO
    int ID_Unico = rand() % (maxID - minID + 1) + minID; // ID de 6 cifras
    for (int i = 0; i < positionUserFree; i++)           // BUSCAR TODOS LOS ID - aseguramos todos los anteriores ID son !=
    {
        if (ID_Unico == usuarios[i].ID) // ¿Hay usuario con mismo ID?
        {
            while (ID_Unico == usuarios[i].ID)                   // Cambia numero hasta que sea diferente
                ID_Unico = rand() % (maxID - minID + 1) + minID; // ID NO SE REPITE

            i = -1; // SUPER IMPORTANTE, volvemos a pregunta desde el principio ¿Hay usuario con mismo ID?
        }
    }
    usuarios[positionUserFree].ID = ID_Unico;
    /*TENER ID UNICO*/
    // d  (a   a)  a→ c  →→→  d (a != c) → unico
    // d  (a   a)  a→ d  →→→  d (a != d) → unico  PERO  d == d
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Rutina Principal
void main()
{
    srand(time(NULL)); // Semilla numero aleatorio
    getch();
    inicioAnimacion();
    do
    {
        system("cls");
        inicio();
        scanf("%c", &EnterOrExit);

        if (EnterOrExit == '1') // INCIAR SESION
        {
        volverIniciar:
            system("cls");

            int buscarID;
            char buscarpass[20];
            int result;
            int userPosition; // Posicion usuario
            bool flagSessionSucces = false;
            flagSessionSucces = false; // reiniciar para buscar en cada iteracion

            system("cls");
            HEADER();
            printf(" Inicio / Iniciar Sesion\n");
            printf("\n\n\n\n\n\n\n\t\t\t\t USERNAME:     ");
            scanf("%i", &buscarID);
            printf("\n\n\t\t\t\t PASSWORD:     ");
            fflush(stdin);
            scanf("%s", &buscarpass);

            for (int i = 0; i < 25; i++)
                if (buscarID == usuarios[i].ID)
                {
                    userPosition = i;
                    result = strcmp(usuarios[i].password, buscarpass);
                    // printf("\n \t\t\t Sale 0 contrasenia correcta = %d", result);
                    if (result == 0)
                        flagSessionSucces = true;
                    break;
                }

            if (flagSessionSucces == false)
            {
                printf("\n\n\n\n\n\t\t\t Usuario o Contrasenia incorrecta ");
                getch();
            }

            if (flagSessionSucces == true) // SI ES QUE INICIA SESSION MOSTRAR OPERACIONES
            {
                system("cls");
                HEADER();
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Iniciando Sesion...\n\n");
                showBarrRotateCenter(5);
                system("cls");
                do
                {
                    system("cls");
                    HEADER();
                    printf(" Inicio / Operaciones\n");
                    printf("\n\t\t\t\tW E L C O M E   B A C K, %s\n", usuarios[userPosition].user);
                    printf("\n Lista de opciones\n"
                           "\n 1. Realizar Desposito"
                           "\n 2. Realizar Trasaccion"
                           "\n 3. Ralizar Retiro"
                           "\n\n 0. Salir");

                    printf("\n\n Ingrese una opcion: ");
                    scanf("%s", &EnterOrExit);
                    int Option = EnterOrExit - '0'; // CHAR TO INT
                    float deposito;
                    // int Option = atoi(EnterOrExit); // CHAR TO INT - DON'T WORK
                    switch (Option)
                    {
                    case 1:
                        system("cls");
                        HEADER();
                        printf(" Usuario / Inicio / Deposito\n");

                        printf("\n Dinero a depositar:\t$ ");
                        scanf("%f", &deposito);
                        system("cls");
                        HEADER();
                        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Terminamos en un momento...\n\n");
                        showBarrRotateCenter(5);
                        system("cls");
                        HEADER();
                        printf(" Usuario / Inicio / Deposito\n");
                        printf("\n\n Saldo anterior:\t$ %.2f", usuarios[userPosition].cash);
                        usuarios[userPosition].cash += deposito;
                        printf("\n Saldo actual:\t\t$ %-.2f", usuarios[userPosition].cash);
                        printf("\n\n\n\n\n\t\t\t El deposito se realizo correctamente.\n");
                        getch();
                        break;
                    case 2:

                        break;
                    default:
                        printf("\n\n La operacion indicada, no existe.\n");
                        break;
                    }
                } while (EnterOrExit != '0');
                EnterOrExit = 'a'; // SALIR AL MENU PRINCIPAL
            }
            else
                goto volverIniciar; // Volver a iniciar sesion
        }
        if (EnterOrExit == '2') // CREAR CUENTA
        {
            system("cls");
            HEADER();
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t CARGANDO REGISTRO... \n\n");
            showBarrRotateCenter(3);
            system("cls");
            HEADER();
            printf(" Inicio / Crear usuario\n");
            createNewUser();
            printf("\n\n CONFIRMACION DE REGISTRO DE CUENTA \n\n"
                   " 0. confirmar \n"
                   " 1. Salir\n\n\n\n\n\n"
                   "\t\t\t\tIngrese una opcion: ");
            fflush(stdin);
            scanf("%s", &EnterOrExit);

            if (EnterOrExit == '0') // GUARDAR USUARIO
            {
                system("cls");
                HEADER();
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t VALIDANDO DATOS...\n\n");
                showBarrRotateCenter(30);

                system("cls");
                HEADER();
                // printf("\n soy la posicion %d y estoy llena", positionUserFree); // revisar la posición vacia
                printf(" Inicio / Crear Usuario / Resumen\n");
                printf("\n REGISTRO COMPLETO\n");
                printf("\n Resumen breve\n");
                printf("\n Codigo Unico:\t\t%-d", usuarios[positionUserFree].ID);
                printf("\n Nombre:\t\t%-s", usuarios[positionUserFree].user);
                printf("\n Correo:\t\t%-s", usuarios[positionUserFree].email);

                printf("\n\n Nota: Guardar su user ID (codigo unico).\n Porque todas las transacciones se realizaran con este codigo\n\n\n\n\n\n\n\n\n\n\n\n\n"
                       "\t\t\t\tPresione 0 para continuar ");
                // GUARDAR EN FICHEROS
                FILE *fichero = fopen("usuarios.txt", "a"); // busca/crear archivo +baseDeDatos.txt+
                if ((fichero) == NULL)
                    perror("No se ha posido establecer conexion con el archivo"); // informa si hay errores con PERROR y MUESTRA CUAL ES EL PROBLE EN ESPECIFICO

                fprintf(fichero, "\n\n {%d,"
                                 "%s"
                                 ",%s"
                                 ",%s"
                                 ",%s"
                                 ",%s"
                                 ",%s"
                                 ",%s"
                                 ",%.2f}",
                        usuarios[positionUserFree].ID, usuarios[positionUserFree].user, usuarios[positionUserFree].password, usuarios[positionUserFree].email, usuarios[positionUserFree].county, usuarios[positionUserFree].city, usuarios[positionUserFree].phoneNumber, usuarios[positionUserFree].identificationCard, usuarios[positionUserFree].cash);

                fflush(fichero); // LIMPIAR FICHERO Y RAM
                fclose(fichero); // CERRAR EL FICHERO
                getch();

                EnterOrExit = 'a'; // SALIR AL MENU PRINCIPAL
            }
            else                   // NO HACE NADA POR EL MOMENTO
                EnterOrExit = 'a'; // NO GUARDAR USUARIO y SALIR MENU AL PRINCIPAL
        }

    } while (EnterOrExit != '0');
}
