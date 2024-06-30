#include "Hashing.hpp"
#include <iostream>
#include <string>

/*****
* int auxilar_hash
******
* Resumen:
* Convierte una porción de un rol dado en un entero utilizando operaciones de cadena y conversión a entero.
******
* Input:
* string rol : El rol del cual se extraerá y convertirá una porción a entero.
******
* Returns:
* int : El entero resultante de la conversión de la porción del rol.
*****/

int auxilar_hash(string rol){
    string Volver_entero;
    Volver_entero = rol.substr(5,7);
    int retorno;
    retorno = stoi(Volver_entero);
    return retorno;
}// obtenemos los 3 numeros anteriores al - y lo volvemos entero

/*****
* float registro_cuentas::Factor_de_carga
******
* Resumen:
* Calcula y devuelve el factor de carga de la tabla de hash, que es la proporción entre el número de ranuras ocupadas y el número máximo de ranuras.
******
* Input:
* int r_ocupadas : Número de ranuras actualmente ocupadas en la tabla de hash.
* int r_max : Número máximo de ranuras en la tabla de hash.
******
* Returns:
* float : El factor de carga calculado como r_ocupadas / r_max.
*****/ 

float registro_cuentas::Factor_de_carga(int r_ocupadas, int r_max){
    float r_ocupadas_f = float(r_ocupadas);
    float r_max_f = float (r_max);
    float returnear = r_ocupadas_f / r_max_f;
    factor_de_carga = returnear;
    return returnear;
}