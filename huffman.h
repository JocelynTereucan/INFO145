#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <unordered_map>
#include <string>
#include <vector>

struct Nodo {
    int dato;
    int frecuencia;
    Nodo* izquierda;
    Nodo* derecha;
    
    Nodo(int dato, int frecuencia) : dato(dato), frecuencia(frecuencia), izquierda(nullptr), derecha(nullptr) {}
};

struct Comparar {
    bool operator()(Nodo* izquierda, Nodo* derecha) {
        return izquierda->frecuencia > derecha->frecuencia;
    }
};

Nodo* construirArbolHuffman(std::unordered_map<int, int>& frecuencias);
void generarCodigos(Nodo* raiz, std::string codigo, std::unordered_map<int, std::string>& huffmanCodes);

std::unordered_map<int, int> calcularFrecuencia(const std::vector<int>& gapArray);

#endif // HUFFMAN_H
