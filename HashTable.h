#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

enum CollisionResolutionMethod { Chaining, LinearProbing, QuadraticProbing };

class HashTable {
private:
    // Chaining
    vector<list<int>> chainTable;
    // Linear and Quadratic Probing
    vector<int> probingTable;
    vector<bool> isOccupied;
    
    int tableSize;
    int numElements;
    CollisionResolutionMethod method;

    // Factor de carga y umbral
    double loadFactorThreshold;
    double getLoadFactor() const;
    void resizeTable();

    // Función de hash simple
    int hashFunction(int key) const;

    // Métodos para colisiones
    void linearProbingInsert(int key);
    void quadraticProbingInsert(int key);
    bool linearProbingSearch(int key) const;
    bool quadraticProbingSearch(int key) const;
    void linearProbingRemove(int key);
    void quadraticProbingRemove(int key);

public:
    // Constructor
    HashTable(int size, CollisionResolutionMethod method, double loadFactorThreshold = 0.7);

    // Métodos generales
    void insert(int key);
    bool search(int key) const;
    void remove(int key);
    void display() const;
};

#endif // HASHTABLE_H
