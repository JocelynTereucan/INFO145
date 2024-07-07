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

## Compilación y Ejecución

- Ejecutar en el terminal del directorio del proyecto
    'g++ -o main main.cpp data_generation.cpp'
- Para ejecutar el programa compilado, escibe en la terminal
    ´./main'


