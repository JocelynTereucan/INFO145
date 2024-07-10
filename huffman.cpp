#include "huffman.h"
#include <queue>
#include <unordered_map>
#include <vector>
#include <chrono>



Nodo* construirArbolHuffman(const std::unordered_map<int, int>& frecuencias) {
    std::priority_queue<Nodo*, std::vector<Nodo*>, Comparar> minHeap; //crea cola de prioridad mínima de nodos huffman
    for (const auto& par : frecuencias) {
        minHeap.push(new Nodo(par.first, par.second)); //inserta cada frecuencia como un nodo en la cola
    }

    while (minHeap.size() != 1) {
        Nodo* izquierda = minHeap.top(); minHeap.pop(); //extrae el nodo con la menor frecuencia de la cola
        Nodo* derecha = minHeap.top(); minHeap.pop(); //Extrae el siguiente nodo con la menor frecuencia de la cola

        Nodo* suma = new Nodo(-1, izquierda->frecuencia + derecha->frecuencia); //crea un nodo suma con la suma de las frecuencias
        suma->izquierda = izquierda; //establece nodo izquierdo del nodo suma
        suma->derecha = derecha; //establece nodo derecho del nodo suma

        minHeap.push(suma); //inserta suma en la cola
    }

    return minHeap.top(); //retorna raiz
}

void generarCodigos(Nodo* raiz, std::string codigo, std::unordered_map<int, std::string>& huffmanCodes) {
    if (!raiz) return; //si la raiz es nula, retorna
    
    if (raiz->dato != -1) {
        huffmanCodes[raiz->dato] = codigo; //asigna el código huffman si es un nodo hoja
    }
    
    generarCodigos(raiz->izquierda, codigo + "0", huffmanCodes); //codigo para hijo izquierdo 
    generarCodigos(raiz->derecha, codigo + "1", huffmanCodes); //codigo para hijo derecho
}

std::unordered_map<int, int> calcularFrecuencia(const std::vector<int>& gapArray) {
    std::unordered_map<int, int> frecuencias; //crea mapa para almacenar frecuencias
    for (int gap : gapArray) {
        frecuencias[gap]++; //cuenta las frecuencias de cada valor en el vector
    }
    return frecuencias; //retorna el mapa
}

//medicion de tiempo
double measure_huffman_search_time(const std::vector<int>& gc, int target, const std::unordered_map<int, std::string>& huffmanCodes) {
    auto start = std::chrono::high_resolution_clock::now();
        // Decodificar utilizando los códigos Huffman
    std::unordered_map<std::string, int> reverseCodes;
    for (const auto& pair : huffmanCodes) {
        reverseCodes[pair.second] = pair.first;
    }

    std::string bitstream;
    for (int val : gc) {
        bitstream += huffmanCodes.at(val);
    }

    // Realizar la búsqueda del elemento objetivo en los datos decodificados
    int foundIndex = -1;
    int current_index = 0;
    while (current_index < bitstream.size() && foundIndex == -1) {
        for (auto it = reverseCodes.begin(); it != reverseCodes.end(); it++) {
            if (bitstream.substr(current_index, it->first.size()) == it->first) {
                if (it->second == target) {
                    foundIndex = current_index;
                }
                current_index += it->first.size();
                break;
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    return diff.count();
}

size_t measure_memory_huffman(const std::vector<int>& gc) {
    std::unordered_map<int, int> frecuencias = calcularFrecuencia(gc);
    Nodo* arbolHuffman = construirArbolHuffman(frecuencias);
    std::unordered_map<int, std::string> huffmanCodes;
    generarCodigos(arbolHuffman, "", huffmanCodes);
    size_t total_bits = 0;
    for (int val : gc) {
        total_bits += huffmanCodes[val].length();
    }
    return (total_bits + 7) / 8; // Redondea al byte más cercano
}