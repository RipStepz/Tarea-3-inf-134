#include <iostream>
#include <string>
#include "Hashing.hpp"
using namespace std;

int main()
{
    registro_cuentas registro;

    cuenta nueva_cuenta;
    nueva_cuenta.rol = "113131313-3";
    nueva_cuenta.nombre = "Carla";
    nueva_cuenta.descripcion = "Una_estudiante_de_literatura";

    registro.agregar(nueva_cuenta);

    cuenta obtenida = registro.obtener("113131313-3");
    cout << "Rol: " << obtenida.rol << endl;
    cout << "Nombre: " << obtenida.nombre << endl;
    cout << "Descripcion: " << obtenida.descripcion << endl;

    cuenta nueva_cuenta2;
    nueva_cuenta2.rol = "14141414-4";
    nueva_cuenta2.nombre = "Diego";
    nueva_cuenta2.descripcion = "Un_estudiante_de_filosofia";

    registro.agregar(nueva_cuenta2);

    obtenida = registro.obtener("14141414-4");
    cout << "Rol: " << obtenida.rol << endl;
    cout << "Nombre: " << obtenida.nombre << endl;
    cout << "Descripcion: " << obtenida.descripcion << endl;

    return 0;
}
