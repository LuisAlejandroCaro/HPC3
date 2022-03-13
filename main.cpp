/*
 * Autor: Luis Alejandro Caro Díaz
 * Fecha: 1 de marzo de 2022
 * Materia: HPC-3
 * Objetivo: Se requiere crear una aplicación
 * para el calculo de la regresión lineal.
 * 1. Debe haber una clase para el tratamiento,
 * manipulación normalización de los datos, dado
 * por un fichero CSV (valres separados por comas)
 * 2. Crear/Implementar una clase que haga los
 * calculos sobre el modelo de regresión
 * lineal, usando el gradiente descendiente
 *
*/

#include "EXTRACT/extracciondata.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <boost/algorithm/string.hpp>

int main(int argc, char* argv[]){

    /* Se crea el objeto del tipo "extracciondata"
     * y se incluyen los 3 argumentos que hemos de
     * pasar al objeto (dato por el constructor de la clase) */
    ExtractionData extraer(argv[1], argv[2], argv[3]);

    /* Se leen los datos del fichero, a través
     * de la función ReadCSV() */
    std::vector<std::vector<std::string>> dataSet = extraer.Readcsv();

    /* Para probar la lectura del fichero,
     * se obtienen la cantidad de filas y columnas */
    int rows = dataSet.size() + 1;
    int cols = dataSet[0].size();

    /* Se crea una matriz dinámica double
     * de dimensión rows*cols */
    Eigen::MatrixXd df = extraer.CSVtoEigen(dataSet, rows, cols);

    std::cout << df << std::endl;

    return 0;
}
