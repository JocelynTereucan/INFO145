#ifndef DATA_GENERATION_H
#define DATA_GENERATION_H

#include <vector>
#include <string>

// Funciones para generar datos
std::vector<int> generate_data_lineal(size_t n);
std::vector<int> generate_data_normal(size_t n);

void print_data(const std::vector<int>& data);

#endif // DATA_GENERATION_H