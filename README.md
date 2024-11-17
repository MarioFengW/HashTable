# HashTable in C++

This project implements a `HashTable` class in C++ that allows storing, searching, and removing keys using two collision resolution strategies: **Linear Probing** and **Quadratic Probing**.

## Project Description

The `HashTable` class is designed to simulate a hash table with essential functionalities, such as inserting, searching, and removing elements while handling collisions using specific strategies. It also manages the load factor and performs **rehashing** when necessary.

## Features

- **Simple Hashing**: Uses a hash function that calculates `hash = key % size`.
- **Collision Resolution**: Supports two methods:
  - **Linear Probing**: Finds the next available index using `index = (hash + i) % size`.
  - **Quadratic Probing**: Finds the next available index using `index = (hash + i * i) % size`.
- **Rehashing**: Automatically resizes the table when the load factor exceeds 70%.
- **Main Operations**:
  - `insert`: Inserts a key into the table.
  - `search`: Returns `true` if a key is present, `false` otherwise.
  - `remove`: Deletes a key if it is present.
- **Visualization**: Displays the table's state after each operation.

## Class Structure

### Properties

- `size`: Size of the hash table.
- `table`: A vector of integers or key-value pairs to simulate the hash table.
- `numElements`: Number of elements currently in the table, used to monitor the load factor.
- `collisionResolutionMethod`: An enum or flag to select the collision resolution method (Linear or Quadratic).

### Constructor and Main Methods

- **Constructor**: Initializes the table size and collision resolution method.
- **Hash Function**: A simple hashing function that maps keys to an index in the table.
- **insert**: Adds a key to the table using the chosen collision resolution method.
- **search**: Checks if a key is present in the table.
- **remove**: Removes a key from the table if it exists.

## Collision Resolution Methods

### Linear Probing
- If a collision occurs, uses `index = (hash + i) % size`, where `i` is an incremental counter, to find the next available slot.

### Quadratic Probing
- If a collision occurs, uses `index = (hash + i * i) % size` to find the next available slot.

## Load Factor and Rehashing

- The load factor is monitored to ensure the table's efficiency.
- When the table becomes 70% full, it resizes and reinserts all elements to a larger table.
