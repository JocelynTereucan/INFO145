#include <iostream>
#include "data_generation.h"

int main() {
    size_t n = 100; // Puedes ajustar el tamaño según tus necesidades

    std::cout << "Generando datos con distribución lineal" << std::endl;
    std::vector<int> data_lineal = generate_data_lineal(n);
    print_data(data_lineal);

    std::cout << "\nGenerando datos con distribución normal" << std::endl;
    std::vector<int> data_normal = generate_data_normal(n);
    print_data(data_normal);

    return 0;
}