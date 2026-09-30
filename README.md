# Práctica 4: Calculadora básica

> **Las secciones 1 a 6 ya están resueltas por el profesor.** Léelas con atención, pero no las modifiques. Tu trabajo empieza en la sección 7.

## 1. Descripción del problema (Fase 1, resuelta)

El programa muestra un menú con cuatro operaciones (suma, resta, multiplicación y división). El usuario elige una, escribe dos números y el programa muestra el resultado de la operación. Es la base de cualquier calculadora y del tipo de menú que se usa, por ejemplo, en el panel de control de una máquina.

## 2. Entradas y salidas (Fase 1, resuelta)

**Entradas:**
1. `opcion` (`int`): la operación elegida, de 1 a 4. Se lee con `leerEntero`.
2. `a` (`double`): el primer número. Se lee con `leerDecimal`.
3. `b` (`double`): el segundo número. Se lee con `leerDecimal`.

**Salidas:**
1. `resultado` (`double`): el resultado de la operación.
2. Se muestra en la forma `a símbolo b = resultado`, por ejemplo `7 / 2 = 3.5`. El símbolo se guarda en `simbolo` (`char`).

**Operaciones:** 1) `a + b`   2) `a - b`   3) `a * b`   4) `a / b`

## 3. Restricciones e invariante (Fases 1 y 2, resuelta)

**Restricciones:**
- La opción debe estar entre 1 y 4. Si no, el programa la vuelve a pedir.
- Si la operación es división, `b` no puede ser 0. Si lo es, el programa vuelve a pedir solo `b`.
- En la resta y en la división el orden importa: siempre se calcula `a` op `b`.

**¿Quién detecta cada error?**
- `leerEntero` y `leerDecimal` detectan el **formato**: texto (`abc`) o, en el caso de `leerEntero`, decimales (`2.5`).
- El programa detecta el **rango**: una opción fuera de 1 a 4 y un divisor igual a 0.

**Invariante:** al llegar al Paso 7 (el cálculo), `opcion` está entre 1 y 4 y, si la opción es 4 (división), `b` es distinto de 0. Por eso el cálculo siempre es válido.

## 4. Casos resueltos a mano (Fase 1, resuelta)

| Caso | Opción | a | b | Resultado |
|---|---|---|---|---|
| 1 | 1 (suma) | 8 | 5 | 8 + 5 = 13 |
| 2 | 2 (resta) | 3 | 5 | 3 - 5 = -2 |
| 3 | 3 (multiplicación) | 2.5 | 4 | 2.5 * 4 = 10 |
| 4 | 4 (división) | 7 | 2 | 7 / 2 = 3.5 |
| 5 | 4 (división) | 5 | 0, luego 2 | vuelve a pedir `b`; 5 / 2 = 2.5 |

## 5. Receta en pseudocódigo (Fase 2, resuelta)

La receta completa está en el archivo `RECETA.md`. No la modifiques: si encuentras algo que no contempla, anótalo en la sección 11.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o calculadora
./calculadora
```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con una división donde primero escribes 0 como segundo número. -->

```
___Calculadora b├ísica
Ingresa la operacion (1-suma, 2-resta, 3-division, 4-multiplicacion): 3
Ingresa numero A: 8
Ingresa numero B: 5
 A/B 1.6__
```

## 8. De la receta al código (Fase 3)
<!-- Para cada paso de la receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1 y 2. Título y menú | __  std::cout << "Calculadora básica\n";
        Operacion = leerDecimal("Ingresa la operacion (1-suma, 2-resta, 3-division, 4-multiplicacion): ");___ |
| 3. Leer y validar la opción | __if (Operacion < 1 || Operacion > 4) {
            std::cout << "Ingrese un valor entre 1 y 4 validos.\n";
        }
     while (Operacion < 1 || Operacion > 4);___ |
| 4 y 5. Leer `a` y `b` | __ A = leerDecimal("Ingresa numero A: ");
    B = leerDecimal("Ingresa numero B: ");___ |
| 6. Validar el divisor | _if (Operacion == 3 && B != 0){
    DIV= A / B ;
     std::cout << " A/B " << DIV << "\n";
} else if (Operacion == 3) {
    std::cout << "No se puede dividir entre cero.\n";
}____ |
| 7. Decisión múltiple (un `case`) | __no use ___ |
| 8. Mostrar el resultado | ____ std::cout << " A*B " << MUL << "\n";_ |

**¿Hubo algún paso de la receta que te costó traducir a C++? ¿Cuál y por qué?**
___nop__

## 9. Experimentos (Fase 3)

**Experimento A: sin el `break` del `case 1`, ¿qué mostró el programa con 8 + 5? ¿Qué te dijo el compilador? ¿Por qué pasó?**
__no use___

**Experimento B: sin la validación del Paso 6, ¿qué mostró el programa con 5 / 0? ¿Tiene sentido?**
_____

**Experimento C (opcional): con `a` y `b` de tipo `int`, ¿qué resultado dio 7 / 2? ¿Te avisó el compilador?**
_____

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas (opción, a, b) | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Suma | 1, 8, 5 | 8 + 5 = 13 | __si___ | ___si__ |
| Resta negativa | 2, 3, 5 | 3 - 5 = -2 | __no___ | ___8__ |
| Multiplicación con decimales | 3, 2.5, 4 | 2.5 * 4 = 10 | __si___ | ___si__ |
| Multiplicación con negativo | 3, -3, 4 | -3 * 4 = -12 | ___si__ | _____ |
| División | 4, 7, 2 | 7 / 2 = 3.5 | si | ___si__ |
| Dividendo cero | 4, 0, 5 | 0 / 5 = 0 | ___no__ | ___muestra error__ |
| Divisor cero | 4, 5, 0 (luego 2) | vuelve a pedir `b`; 5 / 2 = 2.5 | __si___ | _____ |
| Suma con cero | 1, 5, 0 | 5 + 0 = 5 (**no** vuelve a pedir `b`) | _si pasa la prueba____ | _____ |
| Opción fuera de rango | 5 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | ___pide otro numero__ | _____ |
| Opción cero | 0 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | _____pide otro numero | _____ |
| Opción decimal | 2.5 (luego 2), 3, 5 | `leerEntero` vuelve a pedir; 3 - 5 = -2 | __entrada no validas___ | _____ |
| Opción con texto | `suma` (luego 1), 8, 5 | `leerEntero` vuelve a pedir; 8 + 5 = 13 | _entrada no valida____ | _____ |
| Número con texto | 1, `abc` (luego 8), 5 | `leerDecimal` vuelve a pedir; 8 + 5 = 13 | __entrada no vaida___ | _____ |
| Caso propio 1 | ____suma_ | ___3.5+63__ | __66.5___ | _____ |
| Caso propio 2 | _____ | _____ | _____ | _____ |

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | ____lo de los decimales_ | ___la condicion de entrada__ | ___si__ |


**¿Encontré algo que la receta no contemplaba? ¿Qué?**
__los switch___

**Reto elegido (opcional):** __na___

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| ___na__ | ___na__ |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
____a hacerlo bien_

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
__ nada ka neta___

**¿Qué fue lo más difícil y cómo lo resolví?**
__correcto uso de la declaracion___

**¿Qué pregunta me quedó sin responder?**
____ninguna_

**¿Fue más fácil programar a partir de una receta ajena que de la mía? ¿Por qué?**
___mas dificil porque cuando la hago yo , lo puedo ejecutar en base a lo que yo requiera__

**Si yo hubiera diseñado la receta, ¿qué le cambiaría?**
__lo de los switch___

## 14. Lista de verificación antes de entregar (Fase 5)

- [ t] Llené las secciones 7 a 13 (no quedan `_____`)
- [ t] No modifiqué las secciones 1 a 6 ni la receta de `RECETA.md`
- [ t] Cada bloque de `main.cpp` tiene su comentario `// Paso N`
- [ t] Mi programa compila sin advertencias
- [ t] Probé todos los casos de la tabla
- [ t] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ t] No modifiqué `utilerias.h`
- [ t] Hice al menos 4 commits con mensajes claros
- [ t] Hice `git push` y verifiqué mi fork en GitHub
- [ t] Entregué el enlace de mi fork en Classroom