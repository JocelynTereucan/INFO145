#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
#include "gap_coding.h"

// Función para búsqueda binaria
int binary_search(const std::vector<int>& arr, int x);

double measure_search_time(const std::vector<int>& arr, int x); 
// Función para medir el tiempo de búsqueda
//double measure_binary_search_time(const std::vector<int>& arr, int x);
//double measure_gap_search_time(const std::vector<int>& arr, const Sample& sample, int x);
// Función para medir el espacio en memoria (aproximadamente)
size_t measure_memory(const std::vector<int>& arr);

#endif // BINARY_SEARCH_H