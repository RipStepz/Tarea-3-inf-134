#include "Hashing.hpp"
#include <iostream>
#include <string>
using namespace std;
const string registro_cuentas::VACIO = "-1";

registro_cuentas::registro_cuentas() {
    tabla = new cuenta[ranuras]; // Inicialización del arreglo dinámico
    for (int i = 0; i < ranuras; i++)
    {
        tabla[i].rol = VACIO;
    }   
}

registro_cuentas::~registro_cuentas() {
    delete tabla; // Borrado del arreglo dinamico
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
        while (actual != VACIO){
            
            Index = p(tabla[Index].rol, Index);
            actual = tabla[Index].rol;
            Index += 1;
        }

        tabla[Index] = c;   
    }
    
}