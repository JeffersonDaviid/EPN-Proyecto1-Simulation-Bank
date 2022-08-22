#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctime>
#include <fstream>
#include <string.h>
#include <vector>
#include <cstdio>
#include <iomanip>
#include "../lib/features.h"
#include "../lib/estructura.h"
#include "../lib/metodos.h"
#include <cwchar>
#include <windows.h>
using namespace std;

/**************************************************************
Date         : 17.jun.2022
Developer's  : Chileno Jefferson - Narváez Jhoel - Palma Darío
Subject      : Simulation Bank
**************************************************************/

const int DELAY = 1000; // Tiempo de espera
int opcion;
int positionUserFree; // indica la posicion de usuario
// char Pathdata[50] = "../output/registros.txt";
char Pathdata[50] = "registros.txt";
char PathdataNEW[50] = "registrosNew.txt";
string PathdataBinary = "registros.dat";
vector<usuario> lstUsuario;
vector<string> dia_semana;
vector<string> mes;

int userRepeat(string dataUser);

void loadUserBinary()
{
    ifstream rf(PathdataBinary, ios::in | ios::binary);
    // cout << "Abrir archivo:" << PathdataBinary << endl;
    if (!rf)
        cout << " << error >>" << endl;
    usuario user;
    while (rf.read((char *)&user, sizeof(usuario)))
        lstUsuario.push_back(user);
    rf.close();
}

void writeUserBinary()
{
    ofstream f(PathdataBinary, ios::out | ios_base::binary);
    if (f.good())
    {
        setColor(0, 2);
        // cout << endl
        //  << " GUARDADO EXITOSO: " << PathdataBinary << endl;
        for (auto &&prov : lstUsuario) // { [*],[*],[*]...}
            f.write((char *)&prov, sizeof(usuario));
        // f.write((char*)&lstProvincia[0], lstProvincia.size() * sizeof(provincia));
    }
    f.close();
    setColor(0, 8);
}

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
        struct usuario user;
        data >> user.ID;
        data >> user.userName;
        data >> user.password;
        data >> user.email;
        data >> user.county;
        data >> user.city;
        data >> user.phoneNumber;
        data >> user.identificationCard;
        data >> user.cashTotal;
        lstUsuario.push_back(user);
    }
    data.close();
    lstUsuario.pop_back();
}

// BUSCA POSITION LIBRE PARA CREAR NUEVO USUARIO
void searchPositionFree()
{
    for (int i = 0; i < 100; i++)
        if (lstUsuario[i].userName[0] == '\0') // si la propiedad esta vacia
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

crearUsuarioGoto:
    system("cls");
    HEADER();
    cout << " Inicio / Crear usuario\n";
    // GUARDAMOS EL NOMBRE
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a nombre, salta a contrasenia
    cout << "\n COMPLETE LOS SIGUIENTES CAMPOS - COMPLETE THE FOLLOWING FIELDS\n";
    cout << "\n Nombre - Name:\t\t\t";
    getline(cin, userName_temporal);
    trim(userName_temporal);
    // if (userName_temporal.length() == 0)
    // GUARDAMOS LA CONSTRASEÑA
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a contraseña, salta a email
    cout << " Contrasena - Password:\t\t";
    getline(cin, password_temporal);
    trim(password_temporal);
    // GUARDAMOS EMAIL
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a email, salta a country
    cout << " Correo - Email:\t\t";
    getline(cin, email_temporal);
    trim(email_temporal);
    // GUARDAMOS PAIS
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a country, salta a city
    cout << " Pais - Country:\t\t";
    getline(cin, country_temporal);
    trim(country_temporal);
    // GUARDAMOS CIUDAD
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a city, salta a phoneNumber
    cout << " Ciudad - City:\t\t\t";
    getline(cin, city_temporal);
    trim(city_temporal);
    // GUARDAMOS TELEFONO
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a phoneNumber, salta a IdentificationCard
    cout << " Telefono - Phone number:\t";
    getline(cin, phoneNumber_temporal);
    trim(phoneNumber_temporal);
    // GUARDAMOS IDENTIFICACION
    fflush(stdin); // LIMPIA EL BUFFER - RAM
    cout << " Pasaporte - Passport:\t\t";
    getline(cin, identificationCard_temporal);
    trim(identificationCard_temporal);
    fflush(stdin); // LIMPIA EL BUFFER - RAM

    if (userRepeat(identificationCard_temporal) == 0)
        goto crearUsuarioGoto; // Volver a iniciar sesion

    // ASIGNAR UN ID UNICO
    int ID_Unico = rand() % (maxID - minID + 1) + minID; // ID de 6 cifras
    for (int i = 0; i < lstUsuario.size(); i++)          // BUSCAR TODOS LOS ID - aseguramos todos los anteriores ID son !=
        if (ID_Unico == lstUsuario[i].ID)
        {
            while (ID_Unico == lstUsuario[i].ID)                 // Cambia numero hasta que sea diferente
                ID_Unico = rand() % (maxID - minID + 1) + minID; // ID NO SE REPITE

            i = -1; // SUPER IMPORTANTE, volvemos a pregunta desde el principio ¿Hay usuario con mismo ID?
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
        for (int i = 0; i < userName_temporal.length(); i++)
            user.userName[i] += userName_temporal[i];
        for (int i = 0; i < password_temporal.length(); i++)
            user.password[i] += password_temporal[i];
        for (int i = 0; i < email_temporal.length(); i++)
            user.email[i] += email_temporal[i];
        for (int i = 0; i < country_temporal.length(); i++)
            user.county[i] += country_temporal[i];
        for (int i = 0; i < city_temporal.length(); i++)
            user.city[i] += city_temporal[i];
        for (int i = 0; i < 10; i++)
            user.phoneNumber[i] = phoneNumber_temporal[i];
        for (int i = 0; i < 10; i++)
            user.identificationCard[i] = identificationCard_temporal[i];
        lstUsuario.push_back(user); // Guadar en el vector

        system("cls");
        HEADER();
        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t VALIDANDO DATOS...\n\n";
        // showBarrRotateCenter(30);

        system("cls");
        HEADER();
        // cout<<"\n soy la posicion %d y estoy llena", positionUserFree); // revisar la posición vacia
        cout << " Inicio / Crear Usuario / Resumen\n";
        cout << "\n REGISTRO COMPLETO\n";
        cout << "\n Resumen breve\n";
        cout << "\n Codigo Unico:\t\t" << lstUsuario[lstUsuario.size() - 1].ID;
        cout << "\n Nombre:\t\t" << lstUsuario[lstUsuario.size() - 1].userName;
        cout << "\n Correo:\t\t" << lstUsuario[lstUsuario.size() - 1].email;

        cout << "\n\n Nota: Guardar su user ID (codigo unico).\n Porque todas las transacciones se realizaran con este codigo\n\n\n\n\n\n\n\n\n\n\n\n\n"
                "\t\t\t\t";

        writeUserBinary();
        system("pause");
        // // GUARDAR EN FICHEROS
        // ofstream dataNew;
        // dataNew.open(PathdataNEW, ios::out); // abrir fichero modo escritura

        // if (dataNew.fail())
        // {
        //     cout << "No se pudo abrir el archivo\n";
        //     system("PAUSE");
        //     exit(1);
        // }
        // for (auto &&user : lstUsuario)
        // {
        //     dataNew << user.ID << endl;
        //     dataNew << user.userName << endl;
        //     dataNew << user.password << endl;
        //     dataNew << user.email << endl;
        //     dataNew << user.county << endl;
        //     dataNew << user.city << endl;
        //     dataNew << user.phoneNumber << endl;
        //     dataNew << user.identificationCard << endl;
        //     dataNew << user.cash << endl;
        // }
        // dataNew.close(); // CERRAR EL FICHERO
        // remove(Pathdata);
        // cout << "\nEl nuevo tamano del vector es: " << lstUsuario.size();
        opcion = 20; // SALIR AL MENU PRINCIPAL
        // rename(PathdataNEW, Pathdata);
    }
}

void showUser()
{
    for (auto &&user : lstUsuario)
    {
        cout << "ID: \t\t\t" << user.ID << endl
             << "Usuario: \t\t" << user.userName << endl
             << "contrasena : \t\t" << user.password << endl
             << "email : \t\t" << user.email << endl
             << "Pais : \t\t\t" << user.county << endl
             << "Ciudad : \t\t" << user.city << endl
             << "Numero de telefono : \t" << user.phoneNumber << endl
             << "Cedula : \t\t" << user.identificationCard << endl
             << "Dinero Total: \t\t$ " << fixed << setprecision(2) << user.cashTotal << endl;

        for (auto &&historial : user.historialUsuario)
            if (historial.cashNow != 0 && historial.year != 0)
            {
                fflush(stdin);
                cout << "Dinero : \t\t$ " << fixed << setprecision(2) << historial.cashNow
                     << "\t\t" << historial.day << " / " << mes[historial.mon] << " / " << historial.year << "\t" << historial.hour << ":" << historial.minut << ":" << historial.seconds << endl;
            }
            else
                break;

        cout << endl;
    }
}

void putHistory(int userPosition, float cash_depo_reti_transfer, int typeTransaction)
{
    /* fecha/hora actual basado en el sistema actual */
    time_t now = time(0);
    /* Objeto de una estructura tm con fecha/hora local */
    tm *time = localtime(&now); // La estructura <tm> es provista por la libreria <ctime> del lenguaje

    int year = 1900 + time->tm_year;

    // cout << time->tm_mday << " / " << mes[time->tm_mon] << " / " << year << endl;
    switch (typeTransaction)
    {
    case DEPOSITO:
        for (int i = 1; i < 100; i++)
            if (lstUsuario[userPosition].historialUsuario[i].cashNow == 0 && lstUsuario[userPosition].historialUsuario[i].year == 0)
            {
                lstUsuario[userPosition].historialUsuario[i].typeTrasaction = DEPOSITO;
                int ID_Unico_historial = rand() % (maxID - minID + 1) + minID; // ID de 6 cifras
                // for (int i = 0; i < 50; i++)                                   // BUSCAR TODOS LOS ID - aseguramos todos los anteriores ID son !=
                // {
                //     while (ID_Unico_historial == lstUsuario[userPosition].historialUsuario[i].ID) // Cambia numero hasta que sea diferente
                //         ID_Unico_historial = rand() % (maxID - minID + 1) + minID;                // ID NO SE REPITE
                //     i = -1; // SUPER IMPORTANTE, volvemos a pregunta desde el principio ¿Hay usuario con mismo ID?
                // }
                lstUsuario[userPosition].historialUsuario[i].ID = ID_Unico_historial;
                lstUsuario[userPosition].historialUsuario[i].cash_depo_reti_transfer = cash_depo_reti_transfer;
                lstUsuario[userPosition].historialUsuario[i].cashNow = lstUsuario[userPosition].cashTotal + cash_depo_reti_transfer;
                lstUsuario[userPosition].historialUsuario[i].day = time->tm_mday;
                lstUsuario[userPosition].historialUsuario[i].mon = time->tm_mon;
                lstUsuario[userPosition].historialUsuario[i].year = year;
                lstUsuario[userPosition].historialUsuario[i].hour = time->tm_hour;
                lstUsuario[userPosition].historialUsuario[i].minut = time->tm_min;
                lstUsuario[userPosition].historialUsuario[i].seconds = time->tm_sec;
                break;
            }
        break;
    case RETIRO:
        for (int i = 1; i < 100; i++)
            if (lstUsuario[userPosition].historialUsuario[i].cashNow == 0 && lstUsuario[userPosition].historialUsuario[i].year == 0)
            {
                lstUsuario[userPosition].historialUsuario[i].typeTrasaction = RETIRO;
                int ID_Unico_historial = rand() % (maxID - minID + 1) + minID; // ID de 6 cifras
                // for (int i = 0; i < 50; i++)                                   // BUSCAR TODOS LOS ID - aseguramos todos los anteriores ID son !=
                // {
                //     while (ID_Unico_historial == lstUsuario[userPosition].historialUsuario[i].ID) // Cambia numero hasta que sea diferente
                //         ID_Unico_historial = rand() % (maxID - minID + 1) + minID;                // ID NO SE REPITE
                //     i = -1; // SUPER IMPORTANTE, volvemos a pregunta desde el principio ¿Hay usuario con mismo ID?
                // }
                lstUsuario[userPosition].historialUsuario[i].ID = ID_Unico_historial;
                lstUsuario[userPosition].historialUsuario[i].cash_depo_reti_transfer = cash_depo_reti_transfer;
                lstUsuario[userPosition].historialUsuario[i].cashNow = lstUsuario[userPosition].cashTotal - cash_depo_reti_transfer;
                lstUsuario[userPosition].historialUsuario[i].day = time->tm_mday;
                lstUsuario[userPosition].historialUsuario[i].mon = time->tm_mon;
                lstUsuario[userPosition].historialUsuario[i].year = year;
                lstUsuario[userPosition].historialUsuario[i].hour = time->tm_hour;
                lstUsuario[userPosition].historialUsuario[i].minut = time->tm_min;
                lstUsuario[userPosition].historialUsuario[i].seconds = time->tm_sec;
                break;
            }
        break;
    case TRANSFERENCIA:
        for (int i = 1; i < 100; i++)
            if (lstUsuario[userPosition].historialUsuario[i].cashNow == 0 && lstUsuario[userPosition].historialUsuario[i].year == 0)
            {
                lstUsuario[userPosition].historialUsuario[i].typeTrasaction = TRANSFERENCIA;
                int ID_Unico_historial = rand() % (maxID - minID + 1) + minID; // ID de 6 cifras
                // for (int i = 0; i < 50; i++)                                   // BUSCAR TODOS LOS ID - aseguramos todos los anteriores ID son !=
                // {
                //     while (ID_Unico_historial == lstUsuario[userPosition].historialUsuario[i].ID) // Cambia numero hasta que sea diferente
                //         ID_Unico_historial = rand() % (maxID - minID + 1) + minID;                // ID NO SE REPITE
                //     i = -1; // SUPER IMPORTANTE, volvemos a pregunta desde el principio ¿Hay usuario con mismo ID?
                // }
                lstUsuario[userPosition].historialUsuario[i].ID = ID_Unico_historial;
                lstUsuario[userPosition].historialUsuario[i].cash_depo_reti_transfer = cash_depo_reti_transfer;
                lstUsuario[userPosition].historialUsuario[i].cashNow = lstUsuario[userPosition].cashTotal - cash_depo_reti_transfer;
                lstUsuario[userPosition].historialUsuario[i].day = time->tm_mday;
                lstUsuario[userPosition].historialUsuario[i].mon = time->tm_mon;
                lstUsuario[userPosition].historialUsuario[i].year = year;
                lstUsuario[userPosition].historialUsuario[i].hour = time->tm_hour;
                lstUsuario[userPosition].historialUsuario[i].minut = time->tm_min;
                lstUsuario[userPosition].historialUsuario[i].seconds = time->tm_sec;
                break;
            }
        break;
    default:
        cout << "\t\t\tWARNING! Tenemos problemas con el guardado del historial de transacciones\n\t\t\t\t\t\t";
        system("PAUSE");
        break;
    }
}

int subMenu(int &opcion, int userPosition)
{
    system("cls");
    HEADER();
    showUser();
    cout << " Inicio / Operaciones\n";
    cout << "\n\t\t\t\tW E L C O M E   B A C K, " << lstUsuario[userPosition].userName << "\n ";
    cout
        << "\n Lista de opciones\n\n";
    cout << "\t " << DEPOSITO << ". Depositar\n";
    cout << "\t " << RETIRO << ". Retirar\n";
    cout << "\t " << TRANSFERENCIA << ". Transferir\n";
    cout << "\t " << SALIR << ". Salir";

    cout << "\n\n\t Ingrese una opcion: ";
    // scanf("%s", &opcion);
    cin >> opcion;
    // int Option = opcion - '0'; // CHAR TO INT
    // int Option = atoi(opcion); // CHAR TO INT - DON'T WORK

    return opcion;
}

void showHistory(int userPosition, int typeTransaction)
{
    switch (typeTransaction)
    {
    case DEPOSITO:
        system("cls");
        HEADER();
        cout << " Usuario / Inicio / Historial / Deposito\n\n";
        cout << " Dinero Total: \t\t$ " << fixed << setprecision(2) << lstUsuario[userPosition].cashTotal << endl
             << endl;
        cout << "\t\tFecha\t\t   Referencia\t\tValor\t\t\tSaldo\t\t    Moneda\n";
        for (auto &&historial : lstUsuario[userPosition].historialUsuario)
            if (historial.year != 0 && historial.typeTrasaction == DEPOSITO)
            {
                cout << " |\t" << historial.day << "/" << mes[historial.mon] << "/" << historial.year;
                cout << "  " << historial.hour << ":" << historial.minut << ":" << historial.seconds << "\t|";
                cout << "\t" << historial.ID << "\t|";
                cout << "\t+ $" << historial.cash_depo_reti_transfer << "\t|";
                cout << "\t$" << historial.cashNow << "\t|";
                cout << "\tUSD"
                     << "\t|\n";
            }
        cout << "\n\n\t\t\t\t";
        system("pause");
        break;
    case RETIRO:
        system("cls");
        HEADER();
        cout << " Usuario / Inicio / Historial / Retiro\n\n";
        cout << " Dinero Total: \t\t$ " << fixed << setprecision(2) << lstUsuario[userPosition].cashTotal << endl
             << endl;
        cout << "\t\tFecha\t\t   Referencia\t\tValor\t\t\tSaldo\t\t    Moneda\n";
        for (auto &&historial : lstUsuario[userPosition].historialUsuario)
            if (historial.year != 0 && historial.typeTrasaction == RETIRO)
            {
                cout << " |\t" << historial.day << "/" << mes[historial.mon] << "/" << historial.year;
                cout << "  " << historial.hour << ":" << historial.minut << ":" << historial.seconds << "\t|";
                cout << "\t" << historial.ID << "\t|";
                cout << "\t- $" << historial.cash_depo_reti_transfer << "\t|";
                cout << "\t$" << historial.cashNow << "\t|";
                cout << "\tUSD"
                     << "\t|\n";
            }
        cout << "\n\n\t\t\t\t";
        system("pause");
        break;
    case TRANSFERENCIA:
        cout << " Usuario / Inicio / Historial / Transferencia\n\n";
        cout << " Dinero Total: \t\t$ " << fixed << setprecision(2) << lstUsuario[userPosition].cashTotal << endl
             << endl;
        cout << "\t\tFecha\t\t   Referencia\t\tValor\t\t\tSaldo\t\t    Moneda\n";
        for (auto &&historial : lstUsuario[userPosition].historialUsuario)
            if (historial.year != 0 && historial.typeTrasaction == TRANSFERENCIA)
            {
                cout << " |\t" << historial.day << "/" << mes[historial.mon] << "/" << historial.year;
                cout << "  " << historial.hour << ":" << historial.minut << ":" << historial.seconds << "\t|";
                cout << "\t" << historial.ID << "\t|";
                cout << "\t- $" << historial.cash_depo_reti_transfer << "\t|";
                cout << "\t$" << historial.cashNow << "\t|";
                cout << "\tUSD"
                     << "\t|\n";
            }
        cout << "\n\n\t\t\t\t";
        system("pause");
        break;
    case 10:
        system("cls");
        HEADER();
        cout << " Usuario / Inicio / Historial / General\n\n";
        cout << " Dinero Total: \t\t$ " << fixed << setprecision(2) << lstUsuario[userPosition].cashTotal << endl
             << endl;
        cout << "\t\tFecha\t\t   Referencia\t\tValor\t\t\tSaldo\t\t    Moneda\n";
        for (auto &&historial : lstUsuario[userPosition].historialUsuario)
        {
            if (historial.year != 0 && historial.typeTrasaction == DEPOSITO)
            {
                cout << " |\t" << historial.day << "/" << mes[historial.mon] << "/" << historial.year;
                cout << "  " << historial.hour << ":" << historial.minut << ":" << historial.seconds << "\t|";
                cout << "\t" << historial.ID << "\t|";
                cout << "\t+ $" << historial.cash_depo_reti_transfer << "\t|";
                cout << "\t$" << historial.cashNow << "\t|";
                cout << "\tUSD"
                     << "\t|\n";
            }
            if (historial.year != 0 && (historial.typeTrasaction == RETIRO || historial.typeTrasaction == TRANSFERENCIA))
            {
                cout << " |\t" << historial.day << "/" << mes[historial.mon] << "/" << historial.year;
                cout << "  " << historial.hour << ":" << historial.minut << ":" << historial.seconds << "\t|";
                cout << "\t" << historial.ID << "\t|";
                cout << "\t- $" << historial.cash_depo_reti_transfer << "\t|";
                cout << "\t$" << historial.cashNow << "\t|";
                cout << "\tUSD"
                     << "\t|\n";
            }
        }
        cout << "\n\n\t\t\t\t";
        system("pause");
        break;
    default:
        cout << "\t\t\tWARNING! Tenemos problemas para mostrar el historial de transacciones\n\t\t\t\t\t\t";
        system("PAUSE");
        break;
    }
}
string tolowerStr(string str)
{
    for (int x = 0; x < str.length(); x++)
        str[x] = tolower(str[x]);
    return str;
}
int userRepeat(string dataUser)
{
    for (auto &&user : lstUsuario)
    {
        string data(user.identificationCard); // convertimos CHAR TO STRING
        if (tolowerStr(data) == tolowerStr(dataUser))
        {
            setColor(0, 12);
            cout << "WARNING! Usuario '" << user.identificationCard << "' ya se encuentra registrado" << endl;
            setColor(0, 15);
            return 0;
        }
    }
    return -1;
}

int BuscarID(int ID)
{
    for (int i = 0; i < lstUsuario.size(); i++)
        if (ID == lstUsuario[i].ID)
            return i;
    return -1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Rutina Principal
int main()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;  // Width of each character in the font
    cfi.dwFontSize.Y = 20; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_MEDIUM;
    wcscpy(cfi.FaceName, L"Newton Howard Font"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    // loadUser();
    loadUserBinary();
    srand(time(NULL)); // Semilla numero aleatorio

    dia_semana.push_back("Domingo");
    dia_semana.push_back("Lunes");
    dia_semana.push_back("Martes");
    dia_semana.push_back("Miercoles");
    dia_semana.push_back("Jueves");
    dia_semana.push_back("Viernes");
    dia_semana.push_back("Sabado");

    mes.push_back("01");
    mes.push_back("02");
    mes.push_back("03");
    mes.push_back("04");
    mes.push_back("05");
    mes.push_back("06");
    mes.push_back("07");
    mes.push_back("08");
    mes.push_back("09");
    mes.push_back("10");
    mes.push_back("11");
    mes.push_back("12");

    // setColor(3, 4);
    // system("color 10");
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
            char buscarpass[50];
            int result;
            int userPosition; // Posicion usuario
            bool flagSessionSucces = false;
            flagSessionSucces = false; // reiniciar para buscar en cada iteracion

            system("cls");
            HEADER();
            cout << " Inicio / Iniciar Sesion\n";
            cout << "\n\n\n\n\n\n\n\t\t\t\t\t USERNAME:     ";
            cin >> buscarID;
            // scanf("%i", &buscarID);
            cout << "\n\n\t\t\t\t\t PASSWORD:     ";
            fflush(stdin);
            cin >> buscarpass;
            // scanf("%s", &buscarpass);
            if (buscarID != 0)
                for (int i = 0; i < lstUsuario.size(); i++)
                    if (buscarID == lstUsuario[i].ID)
                    {
                        userPosition = i;
                        // STRCMP Compara textos
                        // si son iguales devuelve 0
                        // si no son iguales no devuelve 0

                        // result = strcmp(lstUsuario[i].password, buscarpass);

                        // cout << "....'" << lstUsuario[i].password << "'....'" << buscarpass << "'" << endl;
                        // if (lstUsuario[i].password == buscarpass) // no funciona
                        if (strcmp(lstUsuario[i].password, buscarpass) == 0)
                            flagSessionSucces = true;
                        break;
                    }

            if (flagSessionSucces == false)
            {
                cout << "\n\n\n\n\n\t\t\t\t\t Usuario o Contrasenia incorrecta ";
                cout << "\n\t\t\t\t\t Presione 0 para salir al menu principal ";
                cin >> opcion;
                if (opcion == 0)
                    opcion = 20;
                else
                    goto volverIniciar; // Volver a iniciar sesion
            }

            if (flagSessionSucces == true) // SI ES QUE INICIA SESSION MOSTRAR OPERACIONES
            {
                system("cls");
                HEADER();
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Iniciando Sesion...\n\n";
                showBarrRotateCenter(5);
                system("cls");
                do
                {
                    float deposito_retiro_transferencia;
                    int destinatarioID;
                    switch (subMenu(opcion, userPosition))
                    {
                    case DEPOSITO:
                        do
                        {
                            system("cls");
                            HEADER();
                            cout << " Usuario / Inicio / Deposito\n";
                            cout << "\n Dinero a depositar:\t$ ";
                            cin >> deposito_retiro_transferencia;
                            if (deposito_retiro_transferencia == 0)
                            {
                                cout << "\n Presione 0 para salir";
                                cin >> opcion;
                                if (opcion == 0)
                                {
                                    opcion = 20; // Salir al menu
                                    break;
                                }
                            }
                        } while (deposito_retiro_transferencia < 0);

                        // scanf("%f", &deposito);
                        system("cls");
                        HEADER();
                        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Terminamos en un momento...\n\n";
                        showBarrRotateCenter(5);
                        system("cls");
                        HEADER();
                        cout << " Usuario / Inicio / Deposito\n";
                        cout << "\n\n Saldo anterior:\t$ " << fixed << setprecision(2) << lstUsuario[userPosition].cashTotal;
                        putHistory(userPosition, deposito_retiro_transferencia, DEPOSITO);
                        lstUsuario[userPosition].cashTotal = lstUsuario[userPosition].cashTotal + deposito_retiro_transferencia;
                        cout << "\n Saldo actual:\t\t$ " << fixed << setprecision(2) << lstUsuario[userPosition].cashTotal;

                        cout << "\n\n\n\n\n\t\t\t El deposito se realizo correctamente.\n";
                        // showUser();
                        showHistory(userPosition, DEPOSITO);
                        writeUserBinary();

                        // cout << "\nEl nuevo tamano del vector es: " << lstUsuario.size();
                        opcion = 20; // SALIR AL MENU PRINCIPAL
                        break;
                    case TRANSFERENCIA:
                        system("cls");
                        HEADER();
                        cout << " Usuario / Inicio / Transferencias\n\n";
                        cout << " Monto a transferir: \t\t$ ";
                        cin >> deposito_retiro_transferencia;
                        cout << " Cuenta del destinatario: \t";
                        cin >> destinatarioID;
                        if (BuscarID(destinatarioID) == -1)
                        {
                            cout << "\n\t\t\t\tEL USUARIO NO EXISTE\n\t\t\t\tIntente nuevamente\n\t\t\t";
                            system("pause");
                        }
                        else
                        {
                            if (lstUsuario[userPosition].cashTotal < deposito_retiro_transferencia)
                            {
                                cout << "\n\n\t\t\tNo se ha podido realizar la transferencia, fondos insuficientes\n\t\t\t\t ";
                                system("pause");
                            }
                            else
                            {
                                cout << "\n\n Esta a punto de transferir $" << deposito_retiro_transferencia << ", a este numero de cuenta " << destinatarioID << endl
                                     << endl;

                                cout << " Confirmar la transferencia\n\n 1: Si \n 2: No" << endl
                                     << endl;
                                cout << " Opcion: ";
                                cin >> opcion;
                                if (opcion == 1)
                                {
                                    cout << "\n\n\t\t\t\t\t\t Terminamos en un momento...\n\n";
                                    showBarrRotateCenter(5);

                                    putHistory(userPosition, deposito_retiro_transferencia, TRANSFERENCIA);
                                    putHistory(BuscarID(destinatarioID), deposito_retiro_transferencia, DEPOSITO);
                                    lstUsuario[userPosition].cashTotal = lstUsuario[userPosition].cashTotal - deposito_retiro_transferencia;
                                    lstUsuario[BuscarID(destinatarioID)].cashTotal = lstUsuario[BuscarID(destinatarioID)].cashTotal + deposito_retiro_transferencia;
                                    system("cls");
                                    HEADER();

                                    cout << "\n TRANFERENCIA EXITOSA!\n\n"
                                         << endl;
                                    cout << " Se ha transferido el monto de:\t\t$" << deposito_retiro_transferencia << endl;
                                    cout << " Su saldo es de:\t\t\t$" << lstUsuario[userPosition].cashTotal << endl
                                         << endl;

                                    showHistory(userPosition, TRANSFERENCIA);
                                    writeUserBinary();
                                }
                                else
                                {
                                    cout << "\t\t\tDe acuerdo, usted sera redireccionado al menu principal\n\t\t\t\t";
                                    system("pause");
                                    opcion = 20; // salir menu principal
                                }
                            }
                        }
                        break;
                    case RETIRO:
                        do
                        {
                            system("cls");
                            HEADER();
                            cout << " Usuario / Inicio / Retirar\n";
                            cout << "\n Dinero a retirar:\t$ ";
                            cin >> deposito_retiro_transferencia;
                            if (deposito_retiro_transferencia == 0)
                            {
                                cout << "\n Presione 0 para salir";
                                cin >> opcion;
                                if (opcion == 0)
                                {
                                    opcion = 20; // Salir al menu
                                    break;
                                }
                            }
                            if (lstUsuario[userPosition].cashTotal < deposito_retiro_transferencia)
                            {
                                cout << "\n\n\t\t\t\t\tFondos insuficientes\n\t\t\t\t";
                                system("pause");
                            }

                        } while (deposito_retiro_transferencia < 0 || lstUsuario[userPosition].cashTotal < deposito_retiro_transferencia);

                        // scanf("%f", &retiro);
                        system("cls");
                        HEADER();
                        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Terminamos en un momento...\n\n";
                        showBarrRotateCenter(5);
                        system("cls");
                        HEADER();
                        cout << " Usuario / Inicio / Retiro\n";
                        cout << "\n\n Saldo anterior:\t$ " << fixed << setprecision(2) << lstUsuario[userPosition].cashTotal;
                        putHistory(userPosition, deposito_retiro_transferencia, RETIRO);
                        lstUsuario[userPosition].cashTotal -= deposito_retiro_transferencia;
                        cout << "\n Saldo actual:\t\t$ " << fixed << setprecision(2) << lstUsuario[userPosition].cashTotal;

                        cout << "\n\n\n\n\n\t\t\t El deposito se realizo correctamente.\n";
                        // showUser();
                        showHistory(userPosition, RETIRO);
                        writeUserBinary();

                        // cout << "\nEl nuevo tamano del vector es: " << lstUsuario.size();
                        opcion = 20; // SALIR AL MENU PRINCIPAL
                        break;
                    case ESTADO_CUENTA:
                        // do
                        // {
                        // system("cls");
                        //     HEADER();
                        //     cout << " Usuario / Inicio / Estado de cuenta\n";
                        //     cout << " 1. Editar Usuario";
                        //     cout << " 2. ";

                        // } while (opcion != 0 || opcion < 0);
                        showHistory(userPosition, 10);
                        cout << "\n\n\n\t\t\t\t";
                        break;
                    case 5:
                        for (auto &&user : lstUsuario[userPosition].historialUsuario)
                            if (lstUsuario[userPosition].cashTotal == 0 && user.year != 0 && user.typeTrasaction != 0)
                            {
                                user.typeTrasaction = 0;
                                user.ID = 0;
                                user.cash_depo_reti_transfer = 0;
                                user.cashNow = 0;
                                user.day = 0;
                                user.mon = 0;
                                user.year = 0;
                                user.hour = 0;
                                user.minut = 0;
                                user.seconds = 0;
                            }

                        showHistory(userPosition, 10);
                        cout << "\n\n\n\t\t\t\t";
                        break;
                    default:
                        cout << "\n\n La operacion indicada, no existe.\n";
                        break;
                    }
                } while (opcion != SALIR);
                opcion = 20; // SALIR AL MENU PRINCIPAL
            }
        }
        if (opcion == CREAR_CUENTA) // CREAR CUENTA
        {
            system("cls");
            HEADER();
            cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t CARGANDO REGISTRO... \n\n";
            showBarrRotateCenter(3);
            createNewUser();
            setColor(0, 15);
        }
    } while (opcion != SALIR);

    writeUserBinary();

    return 1;
}