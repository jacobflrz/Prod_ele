
#include <iostream>
#include <vector>
#include <conio.h> // Biblioteca para el uso de nudos
using namespace std;



struct nodo
{
    int dato; //Se muestra el tipo de dato a almacenar
     
    nodo *siguiente; //* FUNCIONA COMO APUNTADOR, DIRECCION DE MEMORIA
    
} *primero, *ultimo; //Variables con apuntador para recorrer el nodo

nodo *lista = NULL;

void insertarLista()
{
     nodo *nuevo_nodo = new nodo ();
     
     cout << "Ingrese las notas:";
     cin >> nuevo_nodo -> dato; 
     
     
     if (primero == NULL)
     {
         
         primero = nuevo_nodo;
         primero -> siguiente = NULL;
         ultimo = nuevo_nodo;
     }
     
    else 
    
    {
        
        ultimo -> siguiente = nuevo_nodo;
        nuevo_nodo-> siguiente = NULL;
        ultimo = nuevo_nodo;
    }
}

void mostrarLista ()
{
    nodo *actual = new nodo();
    actual = primero;
    if (primero != NULL)
    {
        while (actual != NULL)
        {
            cout << actual-> dato << "-> ";
            actual = actual -> siguiente;
        }
    }
    

}

int Suma ()
{
    int suma = 0;
    nodo *actual = primero;
    
    while (actual != NULL)
    {
        suma += actual->dato;
        actual = actual->siguiente;
    }
    cout << "La suma  es de: " << suma << endl;
    return suma;
}

void Multiplicacion()
{
    int mult = 1;
    nodo *actual = primero;
    
    while (actual != NULL)
    {
        mult *= actual->dato;
        actual = actual->siguiente;
    }
    cout << "El producto es de: " << mult << endl;
}


int contar()
{
    int contador = 0;
    nodo *actual = primero;
    while (actual != NULL)
    {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void promedio ()
{
   
    
    double suma = 0.0;
    int i = 0; 
    nodo *actual = primero;

    while (actual != NULL)
    {
        suma += actual->dato;
        i++;
        actual = actual->siguiente;
    }

    double prom = suma / i;
    cout << "El promedio es de: " << prom << endl;
}



void menu();

int main()

{
    
    int opcion, dato;
    
    do //LISTA DE OPCIONES
    {
        
        cout << "------------- MENU ------------- "<< endl;
        cout << "1. Insertar notas "<< endl;
        cout << "2. Mostrar notas"<< endl;
        cout << "3. Sumar"<< endl;
        cout << "4. Multiplicacion"<< endl;
        cout << "5. Promedio"<< endl;
        cout << "-------------------------------" << endl;
        cout << endl;
        cout << "Ingrese una opcion"<< endl << endl<<"-------------------------------" << endl;
        cin >> opcion;
     
        system("cls");
        
        switch (opcion)
        {
            
            case 1:
                insertarLista();
                cout<< "\n";
                system ("pause");
                break;
            
            case 2:
                mostrarLista();
                cout<< "\n";
                system ("pause");
                break;
                
            case 3:
                Suma();
                cout<< "\n";
                system ("pause");
                break;
            case 4:
                Multiplicacion();
                cout<< "\n";
                system ("pause");
                break;

            case 5: // <-- Nuevo caso para promedio
                promedio();
                cout<< "\n";
                system ("pause");
                break;
        }
        system("cls");
    }while (opcion != 3);
  
    return 0;
}