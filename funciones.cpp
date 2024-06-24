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
    return (c1*i*i + c2*i + c3); //p es un valor que se le suma al índice inicial. el %ranuras se hace al valor de p + inicio.
}

void registro_cuentas::agregar(cuenta c){
    int inicio; //indice de referencia, es el asignado a la cuenta c
    int pos = inicio = hash(c.rol); //pos es el índice que usaremos para movernos por la tabla.
    int contador = 0;

    while(tabla[pos].rol != VACIO && tabla[pos].rol != c.rol && contador < ranuras){ //se recorre la tabla hastan que se encuentre un espacio vacío, se encuentre que el rol  ya existe, o se recorra por completo la tabla.
        pos = (p(c.rol, contador) + inicio)%ranuras; // (indice inicial + el valor entregado por p)%ranuras asegura que pos siempre se mueva en el rango de la tabla.
        contador += 1;
    };

    if (tabla[pos].rol == c.rol){
        cout <<"Rol ya existente"<<endl;
    } 
    
    else if (tabla[pos].rol == VACIO) {
        c.index = pos;
        tabla[pos] = c;
        ranuras_ocupadas += 1;
        Factor_de_carga(ranuras_ocupadas, ranuras);
        //cout << "agregado "<<tabla[pos].rol<<" en la ranura: "<<pos<<endl;

    } else if (factor_de_carga >= 0.6){
        
        redimensionar(ranuras * 2);
        agregar(c);
        
    };
    
};

cuenta registro_cuentas::obtener(string rol){
    int inicio;
    int pos = inicio = hash(rol);

    for (int i = 1; tabla[pos].rol != VACIO && tabla[pos].rol != rol; i++){
    pos = (inicio + p(rol, i)) % ranuras; // próxima ranura en la secuencia
    }
    if (tabla[pos].rol == rol){
    //cout <<"rol encontrado";
    tabla[pos].index = pos;
    //cout << tabla[pos].nombre << " " << tabla[pos].descripcion <<endl;
    return tabla[pos]; // registro encontrado, búsqueda exitosa
    }
    else{
        cout <<"Rol no existente" << endl;
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
    ranuras_ocupadas -=1;
    Factor_de_carga(ranuras_ocupadas , ranuras);
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
    }
    else{
        cout<< "Rol no existente"<<endl;
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
    cout << "RANURAS OCUPADAS: " << ranuras_ocupadas <<endl;
    cout << "RANURAS TOTALES: " << ranuras <<endl;
    cout << "FACTOR DE CARGA: " << Factor_de_carga(ranuras_ocupadas, ranuras) <<endl;
}