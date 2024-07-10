# INFO145 - Proyecto de Representación y Compresión de Arreglos Ordenados
Repositorio creado para almacenar trabajo realizado en el ramo INFO145 - primer semestre 2024. Profesor Hector Ferrada.


## Descripción del Proyecto

Este proyecto implementa diferentes técnicas de representación y compresión de arreglos ordenados en C++. Se realizan búsquedas binarias sobre arreglos representados de las siguientes maneras:
- Arreglo explícito sin comprimir.
- Arreglo representado con Gap-Coding.
- Arreglo representado por gaps comprimidos con Shannon-Fano o Huffman.

El objetivo es medir el espacio requerido por cada técnica y estimar el tiempo de búsqueda binaria.

## Requisitos Previos

- `g++` (compilador de C++)

## Estructura del Código

- 'main.cpp' :  Archivo que contiene funciones principales.
- 'data_generation.cpp' : Archivo que contiene las funciones para generar datos.
- 'data_generation.cpp' : Archivo de cabecera con las declaraciones de las funciones de generación de datos.
- 'Huffman.cpp : Este archivo contiene las implementaciones de las funciones relacionadas con la codificación de Huffman, incluyendo la construcción del árbol Huffman, la generación de códigos Huffman y la medición del rendimiento en términos de tiempo y espacio para la codificación Huffman.
- 'huffman.h' : Este archivo de cabecera contiene las declaraciones de las funciones y estructuras utilizadas en la codificación de Huffman, incluyendo prototipos de funciones para construir el árbol Huffman, generar códigos Huffman y medir el espacio en memoria utilizado por la codificación Huffman.
- 'binary_search.cpp' : Este archivo implementa el algoritmo de búsqueda binaria, utilizado para buscar elementos en arreglos ordenados. Incluye la función de búsqueda binaria y funciones auxiliares para medir el rendimiento en términos de tiempo de ejecución y espacio en memoria.
- 'binary_search.h' : Este archivo de cabecera contiene las declaraciones de las funciones utilizadas para realizar búsquedas binarias en arreglos ordenados, así como las definiciones de las estructuras de datos necesarias para la implementación de la búsqueda binaria.
- 'gap_coding.cpp' : En este archivo se encuentra la implementación de la codificación por gaps, un método utilizado para comprimir datos ordenados. Incluye funciones para realizar la codificación y decodificación de datos utilizando el método de codificación por gaps.
- 'gap_coding.h' : Este archivo de cabecera contiene las declaraciones de las funciones y estructuras utilizadas en la codificación por gaps, incluyendo prototipos de funciones para la codificación por gaps y funciones para medir el espacio en memoria utilizado por los datos codificados.




## Compilación y Ejecución

- Ejecutar en el terminal del directorio del proyecto
    'g++ -o main main.cpp data_generation.cpp binary_search.cpp gap_coding.cpp huffman.cpp'
- Para ejecutar el programa compilado, escibe en la terminal
    ´./main'


