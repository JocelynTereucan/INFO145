#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <unordered_map>
#include <string>
#include <vector>
#include <chrono>


struct Nodo{
    int dato;
    int frecuencia;
    Nodo* izquierda;
    Nodo* derecha;
    
    Nodo(int dato, int frecuencia) : dato(dato), frecuencia(frecuencia), izquierda(nullptr), derecha(nullptr) {}
};

struct Comparar{
    bool operator()(Nodo* izquierda, Nodo* derecha) {
        return izquierda->frecuencia > derecha->frecuencia;
    }
};


Nodo* construirArbolHuffman(const std::unordered_map<int, int>& frecuencias);
void generarCodigos(Nodo* raiz, std::string str, std::unordered_map<int, std::string>& huffmanCodes);
std::unordered_map<int, int> calcularFrecuencia(const std::vector<int>& datos);
std::vector<int> decodificarHuffman(const std::unordered_map<int, std::string>& huffmanCodes, const std::vector<int>& gc);
int binary_search_huffman(const std::vector<int>& gc, const std::unordered_map<int, std::string>& huffmanCodes, int target);
double measure_huffman_search_time(const std::vector<int>& gc, int target, const std::unordered_map<int, std::string>& huffmanCodes);
size_t measure_memory_huffman(const std::vector<int>& gc);

#endif // HUFFMAN_H
