#include "HashTable.h"
#include <iostream>

using namespace std;

int main() {
    int tableSize = 10;
    int searchValue, removeValue;

    // Prueba con Chaining
    HashTable hashTable1(tableSize, Chaining);

    // Insertar algunos valores de ejemplo
    hashTable1.insert(5);
    hashTable1.insert(15);
    hashTable1.insert(25);
    hashTable1.insert(2);
    hashTable1.insert(10);
    hashTable1.insert(8);
    hashTable1.insert(1);
    hashTable1.insert(30);

    hashTable1.display();

    // Solicitar al usuario que ingrese el valor a buscar
    cout << "\nIngrese el valor que desea buscar en la tabla (Chaining): ";
    cin >> searchValue;
    cout << "Buscar " << searchValue << ": " 
              << (hashTable1.search(searchValue) ? "Encontrado" : "No encontrado") << "\n";

    // Solicitar al usuario que ingrese el valor a eliminar
    cout << "\nIngrese el valor que desea eliminar de la tabla (Chaining): ";
    cin >> removeValue;
    hashTable1.remove(removeValue);
    cout << "\nDespues de eliminar " << removeValue << ":\n";
    hashTable1.display();

    // Prueba con Linear Probing
    HashTable hashTable2(tableSize, LinearProbing);
    hashTable2.insert(5);
    hashTable2.insert(15);
    hashTable2.insert(25);
    hashTable2.insert(2);
    hashTable2.insert(10);
    hashTable2.insert(51);
    hashTable2.insert(11);
    hashTable2.insert(35);

    hashTable2.display();

    cout << "\nIngrese el valor que desea buscar en la tabla (Linear Probing): ";
    cin >> searchValue;
    cout << "Buscar " << searchValue << ": " 
              << (hashTable2.search(searchValue) ? "Encontrado" : "No encontrado") << "\n";

    cout << "\nIngrese el valor que desea eliminar de la tabla (Linear Probing): ";
    cin >> removeValue;
    hashTable2.remove(removeValue);
    cout << "\nDespues de eliminar " << removeValue << ":\n";
    hashTable2.display();

    // Prueba con Quadratic Probing
    HashTable hashTable3(tableSize, QuadraticProbing);
    hashTable3.insert(5);
    hashTable3.insert(15);
    hashTable3.insert(25);
    hashTable3.insert(2);
    hashTable3.insert(10);
    hashTable3.insert(42);
    hashTable3.insert(7);
    hashTable3.insert(4);
    hashTable3.insert(82);
    hashTable3.insert(17);
    hashTable3.insert(14);

    hashTable3.display();

    cout << "\nIngrese el valor que desea buscar en la tabla (Quadratic Probing): ";
    cin >> searchValue;
    cout << "Buscar " << searchValue << ": " 
              << (hashTable3.search(searchValue) ? "Encontrado" : "No encontrado") << "\n";

    cout << "\nIngrese el valor que desea eliminar de la tabla (Quadratic Probing): ";
    cin >> removeValue;
    hashTable3.remove(removeValue);
    cout << "\nDespues de eliminar " << removeValue << ":\n";
    hashTable3.display();

    return 0;
}
