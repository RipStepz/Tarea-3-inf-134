#include <iostream>
#include <string>
#include <fstream>
#include "Hashing.hpp"

using namespace std;

int main(){

    
    ifstream fich("prueba.txt");
    

    // if(!fich.is_open()) { 
    // cout << "No se pudo abrir el archivo." << endl;
    // }
    // else{
    // cout << "se abrio el archivo"<< endl;
    // }
    // string palabra, rol, nombre, descripcion;
    
    // while (fich >> palabra) {
    //     if (palabra == "AGREGAR") {
            
    //         fich >> rol;
    //         fich >> nombre;
    //         fich >> descripcion;

    //         nueva_cuenta.rol = rol;
    //         nueva_cuenta.nombre = nombre;
    //         nueva_cuenta.descripcion = descripcion;
                
    //         registro.agregar(nueva_cuenta); 
    //     }

    //     else if (palabra == "OBTENER"){
            
    //         fich >> rol;
    //         registro.obtener(rol);

    //     }
    //     else if (palabra == "QUITAR"){
            
    //         fich >> rol;
    //         registro.eliminar(rol);
    //     }
        
    //     else if(palabra == "MODIFICAR"){
    //         fich >> rol;
    //         fich >> descripcion;

    //         registro.modificar(rol, descripcion); 
    //        }

    //     else if(palabra == "ESTADISTICAS"){
    //         registro.estadisticas();
    //     }
    //     else {
    //         cerr << "Comando no reconocido: " << palabra << endl;
    //     }
        
    // }
    
    registro_cuentas registro;
    cuenta nueva_cuenta, obtenida;

    nueva_cuenta.rol = "99999999-9";
    nueva_cuenta.nombre = "Pablo";
    nueva_cuenta.descripcion = "Un_estudiante_de_historia";

    registro.agregar(nueva_cuenta); // 1

    nueva_cuenta.rol = "00000000-0";
    nueva_cuenta.nombre = "Laura";
    nueva_cuenta.descripcion = "Una_estudiante_de_arte";

    registro.agregar(nueva_cuenta); // 2

    nueva_cuenta.rol = "99999999-9";
    nueva_cuenta.nombre = " Roberto";
    nueva_cuenta.descripcion = "Un_estudiante_de_diseño";

    registro.agregar(nueva_cuenta); // 3

    obtenida = registro.obtener("99999999-9"); // 4

    nueva_cuenta.rol = "12341234-2";
    nueva_cuenta.nombre = "Ana";
    nueva_cuenta.descripcion = "Un_estudiante_de_matematicas";

    registro.agregar(nueva_cuenta); // 5

    nueva_cuenta.rol = "12341234-2";
    nueva_cuenta.nombre = "Lucia";
    nueva_cuenta.descripcion = "Una_estudiante_de_biologia";

    registro.agregar(nueva_cuenta); // 6

    return 0;
}
