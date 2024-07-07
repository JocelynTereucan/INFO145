#include <vector>
#include <chrono>
#include <iostream>

// Función para búsqueda binaria
int binary_search(const std::vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1; //indice izquiero y derecho del arreglo
    while (left <= right) { //mientras no se llega al final del arreglo
        int mid = left + (right - left) / 2; //calcula el indice medio del segmento actual
        if (arr[mid] == x) { //revisa si es el elemento buscado y lo retorna
            return mid;
        } else if (arr[mid] < x) { //si el elemento es menor al buscado, el siguiente segmento es el del lado izquiero despues del elemento central
            left = mid + 1;
        } else { //sino, el elemento es mayor al buscado, ahora el nuevo segmento es el derecho antes del indice del medio
            right = mid - 1;
        }
    }
    return -1; //si nunca lo encontró retorna el -1
}

//medicion de tiempo
double measure_search_time(const std::vector<int>& arr, int x) {
    auto start = std::chrono::high_resolution_clock::now(); //inicia el tiempo
    binary_search(arr, x); //busca
    auto end = std::chrono::high_resolution_clock::now(); //tiempo final
    std::chrono::duration<double> diff = end - start; //calcula la duracion
    return diff.count();
}

// Medir espacio en bytes (solo aproximado)
size_t measure_memory(const std::vector<int>& arr) {
    return arr.size() * sizeof(int);
}
