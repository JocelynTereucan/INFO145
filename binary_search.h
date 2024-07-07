#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

// Función para búsqueda binaria
int binary_search(const std::vector<int>& arr, int x);

// Función para medir el tiempo de búsqueda
double measure_search_time(const std::vector<int>& arr, int x);

// Función para medir el espacio en memoria (aproximadamente)
size_t measure_memory(const std::vector<int>& arr);

#endif // BINARY_SEARCH_H