#include "huffman.h"
#include <queue>
#include <unordered_map>
#include <vector>

Nodo* construirArbolHuffman(std::unordered_map<int, int>& frecuencias) {
    std::priority_queue<Nodo*, std::vector<Nodo*>, Comparar> minHeap;
    for (const auto& par : frecuencias) {
        minHeap.push(new Nodo(par.first, par.second));
    }

    while (minHeap.size() != 1) {
        Nodo* izquierda = minHeap.top(); minHeap.pop();
        Nodo* derecha = minHeap.top(); minHeap.pop();

        Nodo* suma = new Nodo(-1, izquierda->frecuencia + derecha->frecuencia);
        suma->izquierda = izquierda;
        suma->derecha = derecha;

        minHeap.push(suma);
    }

    return minHeap.top();
}

void generarCodigos(Nodo* raiz, std::string codigo, std::unordered_map<int, std::string>& huffmanCodes) {
    if (!raiz) return;
    
    if (raiz->dato != -1) {
        huffmanCodes[raiz->dato] = codigo;
    }
    
    generarCodigos(raiz->izquierda, codigo + "0", huffmanCodes);
    generarCodigos(raiz->derecha, codigo + "1", huffmanCodes);
}

std::unordered_map<int, int> calcularFrecuencia(const std::vector<int>& gapArray) {
    std::unordered_map<int, int> frecuencias;
    for (int gap : gapArray) {
        frecuencias[gap]++;
    }
    return frecuencias;
}