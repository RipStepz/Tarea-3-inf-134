#include "Hashing.hpp"
#include <iostream>
#include <string>
using namespace std;
const string registro_cuentas::VACIO = "-1";

registro_cuentas::registro_cuentas() {
    tabla = new cuenta[ranuras];
    for (int i = 0; i < ranuras; i++){
        tabla[i].rol = VACIO;
    }
}

registro_cuentas::~registro_cuentas() {
     delete[] tabla; // Borrado del arreglo dinamico
 }

int registro_cuentas::hash(string rol){
    int key = auxilar_hash(rol);
    return key % ranuras; //obtencion ranura para insertar en el hash
}

int registro_cuentas::p(string rol, int i){
    int c1 = 2, c2 = 1 , c3 = 0;
    if (i == ranuras){
    return 0;
    } 
    return (c1*i*i + c2*i + c3) % ranuras;
}

void registro_cuentas::agregar(cuenta c){

    int Index = hash(c.rol);
    string actual = tabla[Index].rol;

    if (actual == VACIO){
        
        tabla[Index] = c;
    }
    else{

        Index -= 1;
        int contador = 0;
        while ( (actual != VACIO) && (contador <= ranuras)){
            
            Index += 1;
            Index = p(tabla[Index].rol, Index);
            actual = tabla[Index].rol;
        }

        tabla[Index] = c;   
    }
}

cuenta registro_cuentas::obtener(string rol){
    int inicio;
    int pos = inicio = hash(rol);

    for (int i = 1; tabla[pos].rol != VACIO && tabla[pos].rol != rol; i++){
    pos = (inicio + p(rol, i)) % ranuras; // próxima ranura en la secuencia
    }
    if (tabla[pos].rol == rol){
    cout <<"rol encontrado";
    tabla[pos].index = pos;
    return tabla[pos]; // registro encontrado, búsqueda exitosa
    }
    else{
        cout <<"rol no encontrado";
        tabla[pos].index = pos;
        return tabla[pos];
    }
}

void registro_cuentas::eliminar(string rol){
    
    cuenta Borrar = obtener(rol);
    
    if (Borrar.rol != VACIO){

    int index = Borrar.index;
    tabla[index].rol = VACIO;
    tabla[index].nombre = "";
    tabla[index].descripcion = "";

    }
     
    else{
        cout << "Rol no encontrado para eliminar" << endl;
    }
}

