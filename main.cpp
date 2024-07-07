#include <iostream>
#include <vector>
#include "data_generation.h"
#include "binary_search.h"

int main() {
    size_t n = 1000000; // Considero una gran cantidad de datos como 10.000

    //Generación de datos con distribución lineal"
    std::vector<int> data_lineal = generate_data_lineal(n);
    std::cout << "Datos lineales generados.\n";
    //print_data(data_lineal);

    //Generacion de datos con distribución normal
    std::vector<int> data_normal = generate_data_normal(n);
    std::cout << "Datos normales generados.\n";
    //print_data(data_normal);


    //Búsqueda Binaria en Arreglo Explícito
    
    //datos lineales
    int target_lineal = data_lineal[n / 2]; // Elemento a buscar
    int index_lineal = binary_search(data_lineal, target_lineal); //Realiza busqueda binaria del elemento central del arreglo
    if (index_lineal != -1) {
        std::cout << "Elemento " << target_lineal << " encontrado en el índice " << index_lineal << std::endl;
    } else {
        std::cout << "Elemento " << target_lineal << " no encontrado en el arreglo." << std::endl;
    }
    double search_time_lineal = measure_search_time(data_lineal, target_lineal); //calcula el tiempo que demora en realizar la busqueda
    std::cout << "Tiempo de búsqueda en datos lineales: " << search_time_lineal << " segundos\n";
    size_t space_lineal = measure_memory(data_lineal); //calcula el espacio necesario
    std::cout << "Espacio requerido para datos lineales: " << space_lineal << " bytes" << std::endl;
    
    //datos normales
    int target_normal = data_normal[n / 2]; // Elemento a buscar
    int index_normal = binary_search(data_normal, target_normal); //Realiza busqueda binaria del elemento central del arreglo
    if (index_normal != -1) {
        std::cout << "Elemento " << target_normal << " encontrado en el índice " << index_normal << std::endl;
    } else {
        std::cout << "Elemento " << target_normal << " no encontrado en el arreglo." << std::endl;
    }
    double search_time_normal = measure_search_time(data_normal, target_normal); //tiempo necesario para encontrar el dato
    std::cout << "Tiempo de búsqueda en datos lineales: " << search_time_lineal << " segundos\n";
    size_t space_normal = measure_memory(data_normal); //calcula el espacio necesario
    std::cout << "Espacio requerido para datos normales: " << space_normal << " bytes" << std::endl;
    
    return 0;
}