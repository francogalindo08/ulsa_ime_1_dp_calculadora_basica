// Práctica 4: Calculadora básica
// Traduce la receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque de código.

// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Qué funciones trae ahora utilerias.h? ¿Qué devuelve cada una?
#include "utilerias.h"

int main() {
    
    // Variables (siempre inicializadas)
    // TODO: opcion, a, b, resultado y simbolo.
    //       ¿De qué tipo es cada una? Revisa la sección 2 de tu README.
    //       ¿Con qué valor empieza un char?
   
int SUMA =1 ,RESTA=2 , DIV=3 ,MUL=4;
double A =0.0;
double B= 0.0;
int Operacion;


    // Pasos 1 y 2: título y menú
    // TODO
    std::cout << "Calculadora básica\n";

    // Paso 3: leer la opción con leerEntero y repetir si no está entre 1 y 4
    do {
        Operacion = leerDecimal("Ingresa la operacion (1-suma, 2-resta, 3-division, 4-multiplicacion): ");
        if (Operacion < 1 || Operacion > 4) {
            std::cout << "Ingrese un valor entre 1 y 4 validos.\n";
        }
    } while (Operacion < 1 || Operacion > 4);
    // TODO: ¿qué ciclo usaste en la Práctica 3 para volver a pedir un dato?

    // Pasos 4 y 5: leer los dos números con leerDecimal
    A = leerDecimal("Ingresa numero A: ");
    B = leerDecimal("Ingresa numero B: ");

    // Paso 6: SOLO si la opción es división, ¿qué haces si b es 0?
    // TODO
if (Operacion == 1){
    SUMA = A + B ;
    std::cout << " A+B " << SUMA << "\n";
}
if (Operacion == 2){
    RESTA = A - B;
    std::cout << " A-B " << RESTA << "\n";
}
if (Operacion == 3 && B != 0){
    DIV= A / B ;
     std::cout << " A/B " << DIV << "\n";
} else if (Operacion == 3) {
    std::cout << "No se puede dividir entre cero.\n";
}
if (Operacion == 4){
    MUL= A * B ;
     std::cout << " A*B " << MUL << "\n";
}
    // Paso 7: decisión múltiple
    // TODO: switch (opcion) { case 1: ... break; ... default: ... }
    //       ¿Qué pasa si olvidas un break? (Experimento A)

    // Paso 8: salida -> a simbolo b = resultado
    // TODO

    // ¿Qué significa return 0;?
    return 0;
}