#include <vector>
#include <chrono>
#include <iostream>
#include "binary_search.h"

//Función para calcular Gap-Coding
std::vector<int> gap_coding(const std::vector<int>& arr) {
    std::vector<int> gc;
    if (arr.empty()) {
        return gc;  
    }
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
    int low = 0;
    int high = m - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (sample.values[mid] == x) {
            return mid * b; // Elemento encontrado en el sample
        } else if (sample.values[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Decodificar los valores en el intervalo y buscar el elemento
    int start = (low - 1) * b;
    int end = low * b;

    int current_value = sample.values[low - 1];
    for (int i = start; i < end && i < n; ++i) {
        current_value += gc[i];
        if (current_value == x) {
            return i;
        }
    }
    return -1; //si nunca lo encontró retorna el -1
}
