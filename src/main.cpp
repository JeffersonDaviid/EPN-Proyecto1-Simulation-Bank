#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <string.h>
#include <vector>
#include <cstdio>
#include "../lib/features.h"
#include "../lib/estructura.h"

using namespace std;

/**************************************************************
Date         : 17.jun.2022
Developer's  : Chileno Jefferson - Narváez Jhoel - Palma Darío
Subject      : Simulation Bank
**************************************************************/

const int DELAY = 1000; // Tiempo de espera
int opcion;
int positionUserFree; // indica la posicion de usuario
char Pathdata[250] = "registros.txt";
char PathdataNEW[250] = "registrosNew.txt";
vector<usuario> USERSSSS;

void loadUser()
{
    ifstream data;
    data.open(Pathdata, ios::in);

    if (data.fail())
    {
        cout << "No se pudo abrir el archivo para guardar los datos\n";
        cout << "No se pude ejecutar abrir el archivo desde fichero.exe\n";
        system("PAUSE");
        exit(1);
    }

    while (!data.eof())
    {
        for (int i = 0; i < 9; i++)
        {
            struct usuario user;
            data >> user.ID;
            i++;
            data >> user.userName;
            i++;
            data >> user.password;
            i++;
            data >> user.email;
            i++;
            data >> user.county;
            i++;
            data >> user.city;
            i++;
            data >> user.phoneNumber;
            i++;
            data >> user.identificationCard;
            i++;
            data >> user.cash;
            i == 0;
            // if (user.ID == USERSSSS[USERSSSS.size() - 1].ID)
            //     break;
            USERSSSS.push_back(user);
        }
    }
    data.close();
    USERSSSS.pop_back();
}

// BUSCA POSITION LIBRE PARA CREAR NUEVO USUARIO
void searchPositionFree()
{
    for (int i = 0; i < 100; i++)
        if (USERSSSS[i].userName[0] == '\0') // si la propiedad esta vacia
        {
            positionUserFree = i;
            break;
        }
}

// CREAR NUEVO USUARIO
void createNewUser()
{
    int opcion;
    int ID_temportal;
    string userName_temporal;
    string password_temporal;
    string email_temporal;
    string country_temporal;
    string city_temporal;
    string phoneNumber_temporal;
    string identificationCard_temporal;
    float cash_temporal;

    // GUARDAMOS EL NOMBRE
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a nombre, salta a contrasenia
    cout << "\n COMPLETE LOS SIGUIENTES CAMPOS - COMPLETE THE FOLLOWING FIELDS\n";
    cout << "\n Nombre - Name:\t\t\t";
    cin >> userName_temporal;
    // GUARDAMOS LA CONSTRASEÑA
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a contraseña, salta a email
    cout << " Contrasena - Password:\t\t";
    cin >> password_temporal;
    // GUARDAMOS EMAIL
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a email, salta a country
    cout << " Correo - Email:\t\t";
    cin >> email_temporal;
    // GUARDAMOS PAIS
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a country, salta a city
    cout << " Pais - Country:\t\t";
    cin >> country_temporal;
    // GUARDAMOS CIUDAD
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a city, salta a phoneNumber
    cout << " Ciudad - City:\t\t\t";
    cin >> city_temporal;
    // GUARDAMOS TELEFONO
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a phoneNumber, salta a IdentificationCard
    cout << " Telefono - Phone number:\t";
    cin >> phoneNumber_temporal;
    // GUARDAMOS IDENTIFICACION
    fflush(stdin); // LIMPIA EL BUFFER - RAM
    cout << " Pasaporte - Passport:\t\t";
    cin >> identificationCard_temporal;

    // ASIGNAR UN ID UNICO
    int ID_Unico = rand() % (maxID - minID + 1) + minID; // ID de 6 cifras
    for (int i = 0; i < USERSSSS.size(); i++)            // BUSCAR TODOS LOS ID - aseguramos todos los anteriores ID son !=
    {
        if (ID_Unico == USERSSSS[i].ID) // ¿Hay usuario con mismo ID?
        {
            while (ID_Unico == USERSSSS[i].ID)                   // Cambia numero hasta que sea diferente
                ID_Unico = rand() % (maxID - minID + 1) + minID; // ID NO SE REPITE

            i = -1; // SUPER IMPORTANTE, volvemos a pregunta desde el principio ¿Hay usuario con mismo ID?
        }
    }
    ID_temportal = ID_Unico;
    /*TENER ID UNICO*/
    // d  (a   a)  a→ c  →→→  d (a != c) → unico
    // d  (a   a)  a→ d  →→→  d (a != d) → unico  PERO  d == d

    cout << "\n\n CONFIRMACION DE REGISTRO DE CUENTA \n\n"
            " 1. Confirmar \n"
            " 0. Salir\n\n\n\n\n\n"
            "\t\t\t\tIngrese una opcion: ";
    fflush(stdin);
    cin >> opcion;

    if (opcion == ACEPTAR) // GUARDAR USUARIO
    {
        struct usuario user; // Guardar en la estructura
        user.ID = ID_temportal;
        user.userName = userName_temporal;
        user.password = password_temporal;
        user.email = email_temporal;
        user.county = country_temporal;
        user.city = city_temporal;
        user.phoneNumber = phoneNumber_temporal;
        user.identificationCard = identificationCard_temporal;
        USERSSSS.push_back(user); // Guadar en el vector

        system("cls");
        HEADER();
        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t VALIDANDO DATOS...\n\n";
        showBarrRotateCenter(30);

        system("cls");
        HEADER();
        // cout<<"\n soy la posicion %d y estoy llena", positionUserFree); // revisar la posición vacia
        cout << " Inicio / Crear Usuario / Resumen\n";
        cout << "\n REGISTRO COMPLETO\n";
        cout << "\n Resumen breve\n";
        cout << "\n Codigo Unico:\t\t" << USERSSSS[USERSSSS.size() - 1].ID;
        cout << "\n Nombre:\t\t" << USERSSSS[USERSSSS.size() - 1].userName;
        cout << "\n Correo:\t\t" << USERSSSS[USERSSSS.size() - 1].email;

        cout << "\n\n Nota: Guardar su user ID (codigo unico).\n Porque todas las transacciones se realizaran con este codigo\n\n\n\n\n\n\n\n\n\n\n\n\n"
                "\t\t\t\tPresione 0 para continuar ";

        // GUARDAR EN FICHEROS
        ofstream dataNew;
        dataNew.open(PathdataNEW, ios::out); // abrir fichero modo escritura

        if (dataNew.fail())
        {
            cout << "No se pudo abrir el archivo\n";
            system("PAUSE");
            exit(1);
        }

        for (auto &&user : USERSSSS)
        {
            dataNew << user.ID << endl;
            dataNew << user.userName << endl;
            dataNew << user.password << endl;
            dataNew << user.email << endl;
            dataNew << user.county << endl;
            dataNew << user.city << endl;
            dataNew << user.phoneNumber << endl;
            dataNew << user.identificationCard << endl;
            dataNew << user.cash << endl;
        }
        dataNew.close(); // CERRAR EL FICHERO

        // remove(Pathdata);
        // cout << "\nEl nuevo tamano del vector es: " << USERSSSS.size();
        opcion = 20; // SALIR AL MENU PRINCIPAL
        // rename(PathdataNEW, Pathdata);
        getch();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Rutina Principal
int main()
{
    loadUser();
    srand(time(NULL)); // Semilla numero aleatorio
    inicioAnimacion();
    do
    {
        system("cls");
        inicio();
        cin >> opcion;
        // scanf("%c", &opcion);

        if (opcion == INICIAR_SESION) // INCIAR SESION
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
            cout << " Inicio / Iniciar Sesion\n";
            cout << "\n\n\n\n\n\n\n\t\t\t\t USERNAME:     ";
            cin >> buscarID;
            // scanf("%i", &buscarID);
            cout << "\n\n\t\t\t\t PASSWORD:     ";
            fflush(stdin);
            cin >> buscarpass;
            // scanf("%s", &buscarpass);

            for (int i = 0; i < USERSSSS.size(); i++)
                if (buscarID == USERSSSS[i].ID)
                {
                    userPosition = i;
                    // STRCMP Compara textos
                    // si son iguales devuelve 0
                    // si no son iguales no devuelve 0

                    // result = strcmp(USERSSSS[i].password, buscarpass);

                    if ((USERSSSS[i].password.compare(buscarpass)) == 0)
                        flagSessionSucces = true;
                    break;
                }

            if (flagSessionSucces == false)
            {
                cout << "\n\n\n\n\n\t\t\t Usuario o Contrasenia incorrecta ";
                getch();
            }

            if (flagSessionSucces == true) // SI ES QUE INICIA SESSION MOSTRAR OPERACIONES
            {
                system("cls");
                HEADER();
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t Iniciando Sesion...\n\n";
                showBarrRotateCenter(5);
                system("cls");
                do
                {
                    float deposito;
                    float retiro;
                    float transferencia;

                    system("cls");
                    HEADER();
                    cout << " Inicio / Operaciones\n";
                    cout << "\n\t\t\t\tW E L C O M E   B A C K, " << USERSSSS[userPosition].userName << "\n ";
                    cout
                        << "\n Lista de opciones\n"
                           "\n 1. Realizar Desposito"
                           "\n 2. Realizar Trasaccion"
                           "\n 3. Ralizar Retiro"
                           "\n\n 0. Salir";

                    cout << "\n\n Ingrese una opcion: ";
                    // scanf("%s", &opcion);
                    cin >> opcion;
                    // int Option = opcion - '0'; // CHAR TO INT
                    // int Option = atoi(opcion); // CHAR TO INT - DON'T WORK
                    switch (opcion)
                    {
                    case DEPOSITAR:
                        do
                        {
                            system("cls");
                            HEADER();
                            cout << " Usuario / Inicio / Deposito\n";
                            cout << "\n Dinero a depositar:\t$ ";
                            cin >> deposito;

                        } while (deposito < 0);

                        // scanf("%f", &deposito);
                        system("cls");
                        HEADER();
                        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t Terminamos en un momento...\n\n";
                        showBarrRotateCenter(5);
                        system("cls");
                        HEADER();
                        cout << " Usuario / Inicio / Deposito\n";
                        cout << "\n\n Saldo anterior:\t$ " << USERSSSS[userPosition].cash;
                        USERSSSS[userPosition].cash += deposito;
                        cout << "\n Saldo actual:\t\t$ " << USERSSSS[userPosition].cash;
                        cout << "\n\n\n\n\n\t\t\t El deposito se realizo correctamente.\n";

                        // cout << "\nEl nuevo tamano del vector es: " << USERSSSS.size();
                        opcion = 20; // SALIR AL MENU PRINCIPAL
                        getch();
                        break;

                    case TRANSACCION:

                        break;
                    case RETIRAR:

                        break;
                    default:
                        cout << "\n\n La operacion indicada, no existe.\n";
                        break;
                    }
                } while (opcion != SALIR);
                opcion = 1; // SALIR AL MENU PRINCIPAL
            }
            else
                goto volverIniciar; // Volver a iniciar sesion
        }
        if (opcion == CREAR_CUENTA) // CREAR CUENTA
        {
            system("cls");
            HEADER();
            cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t CARGANDO REGISTRO... \n\n";
            showBarrRotateCenter(3);
            system("cls");
            HEADER();
            cout << " Inicio / Crear usuario\n";
            createNewUser();
        }

    } while (opcion != SALIR);

    // GUARDAR EN FICHEROS
    ofstream dataNew;
    dataNew.open(PathdataNEW, ios::out); // abrir fichero modo escritura

    if (dataNew.fail())
    {
        cout << "No se pudo abrir el archivo\n";
        system("PAUSE");
        exit(1);
    }

    for (auto &&user : USERSSSS)
    {
        dataNew << user.ID << endl;
        dataNew << user.userName << endl;
        dataNew << user.password << endl;
        dataNew << user.email << endl;
        dataNew << user.county << endl;
        dataNew << user.city << endl;
        dataNew << user.phoneNumber << endl;
        dataNew << user.identificationCard << endl;
        dataNew << user.cash << endl;
    }
    dataNew.close(); // CERRAR EL FICHERO

    remove(Pathdata);

    system("cls");
    cout << "---------------------------------------------------------------------------------------------\n\n";
    for (auto &&user : USERSSSS)
        cout << "ID: \t\t\t" << user.ID << endl
             << "Usuario: \t\t" << user.userName << endl
             << "contrasena : \t\t" << user.password << endl
             << "email : \t\t" << user.email << endl
             << "Pais : \t\t\t" << user.county << endl
             << "Ciudad : \t\t" << user.city << endl
             << "Numero de telefono : \t" << user.phoneNumber << endl
             << "Cedula : \t\t" << user.identificationCard << endl
             << "Dinero : \t\t" << user.cash << endl
             << endl;

    rename(PathdataNEW, Pathdata);
    return 1;
}
