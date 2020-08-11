#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream piramideNiveles;

  string nombre;
  int n;
  cout << "Ingrese el nombre del archivo: ";
  getline(cin, nombre);
  piramideNiveles.open(nombre.c_str(), ios::app);
  cout << "Ingrese el numero de niveles: ";
  cin >> n;

  piramideNiveles << "\n";
  while (n > 0){
    int i = 1;
    while (i <= n){
      cout << " * ";
      piramideNiveles << " * ";
      i++;
    }
    cout << endl;
    piramideNiveles << endl;
    n--;
  }

  piramideNiveles << "----------------------------------------------";
  piramideNiveles << "\n";

}
