#include <iostream>
#include "data_generation.h"

int main() {
    size_t n = 10000; // Considero una gran cantidad de datos como 10.000

    //Generación de datos con distribución lineal"
    std::vector<int> data_lineal = generate_data_lineal(n);
    std::cout << "Datos lineales generados.\n";
    print_data(data_lineal);

    //Generacion de datos con distribución normal
    std::vector<int> data_normal = generate_data_normal(n);
    std::cout << "Datos normales generados.\n";
    print_data(data_normal);

    return 0;
}