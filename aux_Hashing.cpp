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

float registro_cuentas::Factor_de_carga(int r_ocupadas, int r_max){

float r_ocupadas_f = float(r_ocupadas);
float r_max_f = float (r_max);
float returnear = r_ocupadas_f / r_max_f;
factor_de_carga = returnear;
return returnear;

}