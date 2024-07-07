#include <vector>
#include <chrono>
#include <iostream>
#include "binary_search.h"

//Función para calcular Gap-Coding
std::vector<int> gap_coding(const std::vector<int>& arr) {
    std::vector<int> gc;
    gc.push_back(arr[0]); // El primer elemento es igual al original
    for (size_t i = 1; i < arr.size(); ++i) {
        gc.push_back(arr[i] - arr[i - 1]); // Calcula la diferencia con el elemento anterior
    }
    return gc;
}

//Definición de la estructura sample
struct Sample {
    std::vector<int> values;
    int gap;
};

//Función para realizar la búsqueda binaria en el arreglo Gap-Coded utilizando el sample
int binary_search_gap_coded(const std::vector<int>& gc, const Sample& sample, int x) {
    int n = gc.size();
    int m = sample.values.size();
    int b = sample.gap;
    
    //Recuperar el elemento inicial del sample y su índice correspondiente en gc
    int initial_value = sample.values[0];
    int index = binary_search(gc, initial_value);
    
    //Si el elemento está en el arreglo Gap-Coded, calcular la posición en el arreglo original
    if (index != -1) {
        int position = index * b; //Calcular la posición inicial en el arreglo original
        int current_value = initial_value; //Valor actual para reconstruir el arreglo original
        
        //Iterar sobre los elementos del sample y ajustar la posición
        for (int i = 1; i < m; ++i) {
            current_value += sample.values[i]; //Avanzar al siguiente valor del sample
            position += sample.gap; //Ajustar la posición en el arreglo original
        }
    }
    
    return -1; //si nunca lo encontró retorna el -1
}
