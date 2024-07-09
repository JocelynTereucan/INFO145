#include <iostream>
#include <vector>
#include <unordered_map>
#include "data_generation.h"
#include "binary_search.h"
#include "gap_coding.h"
#include "huffman.h"

int main() {
    size_t n = 100; //Cantidad de datos (debe ser enorme)

    //Generación de datos con distribución lineal"
    std::vector<int> data_lineal = generate_data_lineal(n);
    std::cout << "Datos lineales generados.\n";
    print_data(data_lineal);

    //Generacion de datos con distribución normal
    std::vector<int> data_normal = generate_data_normal(n);
    std::cout << "Datos normales generados.\n";
    print_data(data_normal);


    //Búsqueda Binaria en Arreglo Explícito
    
    //datos lineales
    int target_lineal = data_lineal[n / 2]; //Elemento que se busca, central (n/2)
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
    int target_normal = data_normal[n / 2]; //Elemento que se busca, central (n/2)
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
    

    //Arreglo representado con Gap-Coding
    std::vector<int> gc_lineal = gap_coding(data_lineal);
    std::vector<int> gc_normal = gap_coding(data_normal);

    Sample sample_lineal{ {data_lineal[0], data_lineal[static_cast<int>(n/4)], data_lineal[static_cast<int>(n/2)]}, static_cast<int>(n/4) }; //Ejemplo de sample
    Sample sample_normal{ {data_normal[0], data_normal[static_cast<int>(n/4)], data_normal[static_cast<int>(n/2)]}, static_cast<int>(n/4) }; //Ejemplo de sample
    //imprimo los sample, para saber que estan correctos
    //datos lineales
    std::cout << "Sample para datos lineales:\n";

    for (size_t i = 0; i < sample_lineal.values.size(); ++i) {
        std::cout << sample_lineal.values[i] << " ";
    }
    std::cout << "\nGap entre elementos del Sample: " << sample_lineal.gap << "\n\n";
    //datos normales
    std::cout << "Sample para datos normales:\n";
    for (size_t i = 0; i < sample_normal.values.size(); ++i) {
        std::cout << sample_normal.values[i] << " ";
    }
    std::cout << "\nGap entre elementos del Sample: " << sample_normal.gap << "\n\n";


    //Búsqueda Binaria en Arreglo Gap-Coded para datos lineales
    int target_lineal_gc = data_lineal[n / 2];
    int index_lineal_gc = binary_search_gap_coded(gc_lineal, sample_lineal, target_lineal_gc);
    if (index_lineal_gc != -1) {
        std::cout << "Elemento " << target_lineal_gc << " encontrado en el índice " << index_lineal_gc << " del arreglo original (Gap-Coded)." << std::endl;
    } else {
        std::cout << "Elemento " << target_lineal_gc << " no encontrado en el arreglo Gap-Coded." << std::endl;
    }

    //Búsqueda Binaria en Arreglo Gap-Coded para datos normales
    int target_normal_gc = data_normal[n / 2];
    int index_normal_gc = binary_search_gap_coded(gc_normal, sample_normal, target_normal_gc);
    if (index_normal_gc != -1) {
        std::cout << "Elemento " << target_normal_gc << " encontrado en el índice " << index_normal_gc << " del arreglo original (Gap-Coded)." << std::endl;
    } else {
        std::cout << "Elemento " << target_normal_gc << " no encontrado en el arreglo Gap-Coded." << std::endl;
    }


    //Huffman
    //lineal
    //std::vector<int> gc_lineal = gap_coding(data_lineal);
    std::unordered_map<int, int> frecuencias_lineal = calcularFrecuencia(gc_lineal);
    Nodo* arbolHuffman_lineal = construirArbolHuffman(frecuencias_lineal);
    std::unordered_map<int, std::string> huffmanCodes_lineal;
    generarCodigos(arbolHuffman_lineal, "", huffmanCodes_lineal);
    std::cout << "Códigos de Huffman para datos lineales:\n";
    for (const auto& par : huffmanCodes_lineal) {
        std::cout << par.first << ": " << par.second << "\n";
    }


    //normal
    //std::vector<int> gc_normal = gap_coding(data_normal);
    std::unordered_map<int, int> frecuencias_normal = calcularFrecuencia(gc_normal);
    Nodo* arbolHuffman_normal = construirArbolHuffman(frecuencias_normal);
    std::unordered_map<int, std::string> huffmanCodes_normal;
    generarCodigos(arbolHuffman_normal, "", huffmanCodes_normal);
    std::cout << "Códigos de Huffman para datos normales:\n";
    for (const auto& par : huffmanCodes_normal) {
        std::cout << par.first << ": " << par.second << "\n";
    }


    return 0;
}