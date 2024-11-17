#include "HashTable.h"

using namespace std;

// Constructor
HashTable::HashTable(int size, CollisionResolutionMethod method, double loadFactorThreshold)
    : tableSize(size), numElements(0), method(method), loadFactorThreshold(loadFactorThreshold) {
    chainTable.resize(tableSize);
    probingTable.resize(tableSize, -1);  // -1 indicates empty slot
    isOccupied.resize(tableSize, false);
}

// Función de hash
int HashTable::hashFunction(int key) const {
    return key % tableSize;
}

// Factor de carga
double HashTable::getLoadFactor() const {
    return static_cast<double>(numElements) / tableSize;
}

// Redimensionamiento de la tabla
void HashTable::resizeTable() {
    int oldSize = tableSize;
    tableSize *= 2;  // Doblar el tamaño de la tabla
    numElements = 0; // Reiniciar el número de elementos

    // Redimensionar las estructuras de datos
    vector<list<int>> oldChainTable = chainTable;
    vector<int> oldProbingTable = probingTable;
    vector<bool> oldIsOccupied = isOccupied;

    chainTable.clear();
    chainTable.resize(tableSize);
    probingTable.clear();
    probingTable.resize(tableSize, -1);
    isOccupied.clear();
    isOccupied.resize(tableSize, false);

    // Reinsertar los elementos antiguos
    for (int i = 0; i < oldSize; ++i) {
        if (method == Chaining) {
            for (int key : oldChainTable[i]) {
                insert(key);
            }
        } else if (oldIsOccupied[i] && oldProbingTable[i] != -1) {
            insert(oldProbingTable[i]);
        }
    }
}

// Métodos de inserción
void HashTable::insert(int key) {
    if (getLoadFactor() > loadFactorThreshold) {
        resizeTable();
    }
    switch (method) {
        case Chaining:
            chainTable[hashFunction(key)].push_back(key);
            break;
        case LinearProbing:
            linearProbingInsert(key);
            break;
        case QuadraticProbing:
            quadraticProbingInsert(key);
            break;
    }
    numElements++;
}

void HashTable::linearProbingInsert(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (isOccupied[(index + i) % tableSize] && probingTable[(index + i) % tableSize] != -1) {
        i++;
    }
    probingTable[(index + i) % tableSize] = key;
    isOccupied[(index + i) % tableSize] = true;
}

void HashTable::quadraticProbingInsert(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (isOccupied[(index + i * i) % tableSize] && probingTable[(index + i * i) % tableSize] != -1) {
        i++;
    }
    probingTable[(index + i * i) % tableSize] = key;
    isOccupied[(index + i * i) % tableSize] = true;
}

// Métodos de búsqueda
bool HashTable::search(int key) const {
    switch (method) {
        case Chaining:
            for (int element : chainTable[hashFunction(key)]) {
                if (element == key) return true;
            }
            return false;
        case LinearProbing:
            return linearProbingSearch(key);
        case QuadraticProbing:
            return quadraticProbingSearch(key);
    }
    return false;
}

bool HashTable::linearProbingSearch(int key) const {
    int index = hashFunction(key);
    int i = 0;
    while (isOccupied[(index + i) % tableSize]) {
        if (probingTable[(index + i) % tableSize] == key) return true;
        i++;
    }
    return false;
}

bool HashTable::quadraticProbingSearch(int key) const {
    int index = hashFunction(key);
    int i = 0;
    while (isOccupied[(index + i * i) % tableSize]) {
        if (probingTable[(index + i * i) % tableSize] == key) return true;
        i++;
    }
    return false;
}

// Métodos de eliminación
void HashTable::remove(int key) {
    switch (method) {
        case Chaining:
            chainTable[hashFunction(key)].remove(key);
            break;
        case LinearProbing:
            linearProbingRemove(key);
            break;
        case QuadraticProbing:
            quadraticProbingRemove(key);
            break;
    }
    numElements--;
}

void HashTable::linearProbingRemove(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (isOccupied[(index + i) % tableSize]) {
        if (probingTable[(index + i) % tableSize] == key) {
            probingTable[(index + i) % tableSize] = -1;
            isOccupied[(index + i) % tableSize] = false;
            break;
        }
        i++;
    }
}

void HashTable::quadraticProbingRemove(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (isOccupied[(index + i * i) % tableSize]) {
        if (probingTable[(index + i * i) % tableSize] == key) {
            probingTable[(index + i * i) % tableSize] = -1;
            isOccupied[(index + i * i) % tableSize] = false;
            break;
        }
        i++;
    }
}

// Método para mostrar la tabla hash
void HashTable::display() const {
    if (method == Chaining) {
        cout << "Tabla Hash (Chaining):\n";
        for (int i = 0; i < tableSize; ++i) {
            cout << "Índice " << i << ": ";
            for (int key : chainTable[i]) {
                cout << key << " -> ";
            }
            cout << "nullptr\n";
        }
    } else {
        cout << "\nTabla Hash (" << (method == LinearProbing ? "Linear Probing" : "Quadratic Probing") << "):\n";
        for (int i = 0; i < tableSize; ++i) {
            cout << "Índice " << i << ": ";
            if (probingTable[i] == -1) {
                cout << "nullptr\n";
            } else {
                cout << probingTable[i] << "\n";
            }
        }
    }
}
