#include <iostream>
#include <string.h>
using namespace std;

struct historial
{
    int ID = 0;
    int typeTrasaction = 0;
    float cash_depo_reti_transfer = 0;
    float cashNow = 0;
    int day = 0;
    int mon = 0;
    int year = 0;
    int hour = 0;
    int minut = 0;
    int seconds = 0;
};

struct usuario
{
    int ID;
    char userName[50] = "";
    char userLastName[50] = "";
    char password[50] = "";
    char email[50] = "";
    char county[25] = "";
    char city[25] = "";
    char phoneNumber[20] = "";
    char identificationCard[20] = "";
    float cashTotal = 0;
    struct historial historialUsuario[50];
};
