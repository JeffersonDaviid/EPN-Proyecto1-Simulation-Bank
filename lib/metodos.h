#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;
#include <string>

const string whiteSpaces(" \f\n\r\t\v"); // caracteres a eliminar

void trimRight(string &str)
{
    string::size_type pos = str.find_last_not_of(whiteSpaces);
    str.erase(pos + 1);
}

void trimLeft(string &str)
{
    string::size_type pos = str.find_first_not_of(whiteSpaces);
    str.erase(0, pos);
}

/*
recibe string que necesita aliminar espacios en blanco derecha/izquierda
*/
void trim(string &str)
{
    trimRight(str);
    trimLeft(str);
}