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
        ranuras_ocupadas += 1;
    }
    else{

        if (ranuras_ocupadas == ranuras){
            redimensionar(ranuras + 5);
        }
    
        Index -= 1;
        int contador = 0;
        while ( (actual != VACIO)){
            
            Index += 1;
            Index = p(tabla[Index].rol, Index);
            actual = tabla[Index].rol;
            
        }

        tabla[Index] = c;
        ranuras_ocupadas += 1;   
    }
}

cuenta registro_cuentas::obtener(string rol){
    int inicio;
    int pos = inicio = hash(rol);

    for (int i = 1; tabla[pos].rol != VACIO && tabla[pos].rol != rol; i++){
    pos = (inicio + p(rol, i)) % ranuras; // próxima ranura en la secuencia
    }
    if (tabla[pos].rol == rol){
    //cout <<"rol encontrado";
    tabla[pos].index = pos;
    return tabla[pos]; // registro encontrado, búsqueda exitosa
    }
    else{
        //cout <<"rol no encontrado";
        tabla[pos].index = pos;
        return tabla[pos];
    }
}

void registro_cuentas::eliminar(string rol){
    
    cuenta Borrar = obtener(rol);
    int index = Borrar.index;

    if (Borrar.rol != VACIO){
    tabla[index].rol = VACIO;
    tabla[index].nombre = "";
    tabla[index].descripcion = "";
    cout << "eliminado con exito el rol: " <<  rol << endl;
    }

    else{
        cout << "Rol no encontrado para eliminar" << endl;
    }
}

void registro_cuentas::modificar(string rol, string descripcion){
    
    cuenta Modificar = obtener(rol);
    int index = Modificar.index;

    if (Modificar.rol != VACIO){
        tabla[index].descripcion = descripcion;
        cout<< "se modifico la descripcion a: " << descripcion<<endl;
    }
}

void registro_cuentas::redimensionar(int n) {
        
        cuenta* nueva_tabla = new cuenta[n];

        for (int i = 0; i < n; ++i) {
            nueva_tabla[i].rol = VACIO; // Marcar todas las ranuras como vacías
        }

        for (int i = 0; i < ranuras; ++i) {
            nueva_tabla[i].rol = tabla[i].rol;
            nueva_tabla[i].nombre = tabla[i].rol;
            nueva_tabla[i].descripcion = tabla[i].rol;
        }

        delete[] tabla;
        tabla = nueva_tabla;
        ranuras = n;
        ranuras_ocupadas = 0;
    }

void registro_cuentas::estadisticas(){
    
}