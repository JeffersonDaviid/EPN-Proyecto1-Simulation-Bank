#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo
{
    // char dato;
    int priori; // prioridad del nodo
    struct nodo *sgte;
};

struct cola
{
    nodo *delante;
    nodo *atras;
};

struct nodo *crearNodo(int pr)
{
    struct nodo *nuevoNodo = new (struct nodo);
    // nuevoNodo->dato = x;
    nuevoNodo->priori = pr;
    return nuevoNodo;
};

void encolar(struct cola &q, int priori)
{

    struct nodo *aux = crearNodo(priori);
    aux->sgte = NULL;

    if (q.delante == NULL)
        q.delante = aux; // encola el primero elemento
    else
        (q.atras)->sgte = aux;

    q.atras = aux; // puntero que siempre apunta al ultimo elemento
}

void ordenarPrioridad(struct cola &P)
{
    struct nodo *aux1, *aux2;
    int p_aux;
    aux1 = P.delante;
    while (aux1->sgte != NULL)
    {
        aux2 = aux1->sgte;
        while (aux2 != NULL)
        {
            if (aux1->priori > aux2->priori)
            {
                p_aux = aux1->priori;

                aux1->priori = aux2->priori;

                aux2->priori = p_aux;
            }
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }
}

void muestraCola(struct cola N, struct cola P)
{

    struct nodo *aux;
    aux = N.delante;
    cout << "\nCOLA NORMAL" << endl;

    if (N.delante == NULL)
        cout << "\n\t\t< COLA NORMAL VACIA >";
    else
        do
        {
            cout << "[" << aux->priori << "]-->";
            aux = aux->sgte;
            if (aux == NULL)
                cout << "NULL";
        } while (aux != NULL);

    /* Ordenando por prioridad */
    cout << "\n\nCOLA DE PRIORIDAD" << endl;
    struct nodo *aux2;
    aux2 = P.delante;
    if (P.delante == NULL)
        cout << "\n\t\t< COLA DE PRIORIDAD VACIA >\n\n\t";
    else
        do
        {
            ordenarPrioridad(P);
            cout << "[" << aux2->priori << "]-->";
            aux2 = aux2->sgte;
            if (aux2 == NULL)
                cout << "NULL\n\n\t";
        } while (aux2 != NULL);
}

void insertar(struct cola &N, struct cola &P, int pr)
{
    encolar(N, pr);
    encolar(P, pr);
    muestraCola(N, P);
}

void eliminar(struct cola &N, struct cola &P)
{
    struct nodo *aux, *aux2;
    // COLA NORMAL
    aux = N.delante; // aux apunta al inicio de la cola
    N.delante = (N.delante)->sgte;
    delete (aux);

    // COLA DE PRIORIDAD
    aux2 = P.delante; // aux apunta al inicio de la cola
                      // if (P.delante == NULL)
    P.delante = (P.delante)->sgte;
    delete (aux2);

    muestraCola(N, P);
}

void menu()
{
    cout << "\n\t COLAS CON PRIORIDAD EN C++ \n\n";
    cout << " 1. ENCOLAR                           " << endl;
    cout << " 2. ELIMINAR                           " << endl;
    cout << " 3. SALIR                             " << endl;

    cout << "\n INGRESE OPCION: ";
}

int main()
{
    struct cola P;
    struct cola N;

    P.delante = NULL;
    P.atras = NULL;
    N.delante = NULL;
    N.atras = NULL;

    int pr;
    int op;

    do
    {
        system("cls");
        menu();
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "\n ----------------------------------------------------------------";
            cout << "\n Ingrese prioridad: ";
            cin >> pr;

            insertar(N, P, pr);

            cout << "\n\n\t\tCaracter '" << pr << "' encolado...\n\n";
            break;

        case 2:
            cout << "\n ----------------------------------------------------------------";
            cout << "\n ELIMINAR/DESENCOLAR\n\n";

            if (P.delante != NULL)
                eliminar(N, P);
            else
                cout << "\n\n\tCola vacia...!" << endl;
            break;
        default:
            break;
        }
        system("pause");
    } while (op != 3);

    return 0;
}