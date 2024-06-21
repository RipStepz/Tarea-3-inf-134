#include "Hashing.hpp"
#include <iostream>
#include <string>

int auxilar_hash(string rol){
    string Volver_entero;
    Volver_entero = rol.substr(5,7);
    int retorno;
    retorno = stoi(Volver_entero);
    return retorno;
}// obtenemos los 3 numeros anteriores al - y lo volvemos entero

// void registro_cuentas::auxiliar_agregar(cuenta *x, string rol_, string nombre_ , string info){
//     x->rol = rol_;
//     x->nombre = nombre_;
//     x->descripcion = info;
// }// crea la cuenta, para ser agrega al hashing

// string registro_cuentas::auxiliar_agregar2(int i, cuenta* x){
//     if (i == 1){
//         return x->rol;
//     }
//     if(i==2){
//         return x->nombre;
//     }
//     if (i==3){
//         return x->descripcion;
//     }
// }