Para compilar debe usar el siguiente texto 
g++ -c main.cpp -o main.o
g++ -c funciones.cpp -o funciones-o
g++ -c aux_Hashing.cpp -o aux_Hashing-o
g++ main.o funciones-o aux_Hashing-o -o  mi_programa

y para correr el programa debe usar este: ./mi_programa