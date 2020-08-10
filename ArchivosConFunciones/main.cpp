#include <iostream>
#include <fstream>
using namespace std;
void Ingresar ();
void Leer ();

int main()
{

    Ingresar();
    Leer();

    return 0;
}

void Ingresar()
{

    string nombre, apellido, carrera;
    int e;
    char r;
    ofstream archivoPrueba;
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo: ";
    getline (cin, nombreArchivo);
    archivoPrueba.open(nombreArchivo.c_str (), ios::app);
    do
    {
        cout << "\tIngrese el nombre: ";
        getline (cin, nombre, '\n');
        cout << "\tIngrese el apellido: ";
        getline (cin, apellido, '\n');
        cout << "\tIngrese la carrera: ";
        getline (cin, carrera, '\n');
        cout << "\tIngrese la edad: ";
        cin >> e;

        archivoPrueba << nombre << " " << apellido << " " << carrera << " " << e << "\n";
        cout << "Desea agregar otros contactos (s/n): ";
        cin >> r;
        cin.ignore ();
    }
    while (r == 's');
    archivoPrueba.close ();
}

void Leer()
{

    string nombre, apellido, carrera;
    int e, op;
    ifstream archivoLectura ("contactos.txt");
    string text;

    cout << "Opciones" << endl;
    cout << "1. Mostrar datos"<< endl;
    cout << "2. Salir" << endl;
    cout << "Ingrese el numero de su opcion: ";
    cin >> op;
    switch (op)
    {
    case 1:
    {
        while (!archivoLectura.eof ())
        {
            archivoLectura >> nombre >> apellido >> carrera >>e;
            if (!archivoLectura.eof ())
            {
                getline (archivoLectura, text);
                cout << "*****************************" << "\n";
                cout << "Nombre: " << nombre << "\n";
                cout << "Apellido: " << apellido << "\n";
                cout << "Carrera: " << carrera << "\n";
                cout << "Edad: " << e << "\n";
            }
        }

    }
    break;
    case 2:
    {
        cout << "Gracias" << endl;
    }
    break;
    default:
    {
        cout << "Opcion ingresada invalida" << endl;
    }
    }

    archivoLectura.close ();

}
