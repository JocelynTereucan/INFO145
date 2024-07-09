#include "data_generation.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

// Función para generar datos con distribución lineal
std::vector<int> generate_data_lineal(size_t n) {
    std::vector<int> data(n);
    //srand(time(nullptr));
    static std::default_random_engine generator(static_cast<long unsigned int>(time(0)));
    std::uniform_int_distribution<int> distribution(1, 10); //Distribución uniforme de 1 a 10

    data[0] = rand() % 100; //Inicializar el primer valor
    
    for (size_t i = 1; i < n; ++i) {
        data[i] = data[i - 1] + rand() % 10; //Incremento aleatorio pequeño
    }
    std::sort(data.begin(), data.end());
    return data;
}

// Función para generar datos con distribución normal
std::vector<int> generate_data_normal(size_t n) {
    std::vector<int> data(n);
    //srand(time(nullptr));
    //std::default_random_engine generator;
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::normal_distribution<double> dist(50.0, 10.0); // media 50, desviación estándar 10
    for (size_t i = 0; i < n; ++i) {
        data[i] = static_cast<int>(dist(generator));
    }
    std::sort(data.begin(), data.end());
    return data;
}

// Función para imprimir datos (para verificar datos)
void print_data(const std::vector<int>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}