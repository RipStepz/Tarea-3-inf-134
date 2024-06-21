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