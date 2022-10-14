#include <iostream>
#include <array>

// Añadir std para fácil llamado de funciones
using namespace std;

//// Declaración de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void LlenarMatriz(matriz & miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz & miMatriz);

template <typename matriz>
void GaussJordan(matriz & miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz & miMatriz);


int main()
{
    // Definimos el número de variables de nuestro sistema
    const int variables = 3;
    // El número de columnas será el número de variables más su solición para cada ecuación
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Observamos si la matriz es la correcta
    //ImprimirMatriz(miMatriz);

    // Aplicamos el método de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);

    // Imprimimos la solución de la matriz
    ImprimirSolucion(miMatriz);

    return 0; // Indicamos que salimos del programa con éxito
}

/*
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ningún valor.
*/
template <typename matriz>
void LlenarMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            cin >> miMatriz[i][j];
        }
    }
}

/*
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        for (int j = 0; j < variables + 1; j++)
            cout << miMatriz[i][j] << '\t';
        cout << "]\n";
    }
}

/*
Imprime en pantalla la solución para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz & miMatriz)
{
    int n = miMatriz.size();
    for(int i=0;i<n;i++)
    {
        cout<<"\nx"<<i<<" = "<<miMatriz[i][n]<<endl;
    }
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/
template <typename matriz>
void GaussJordan(matriz & miMatriz) {
    //Se usa la función .size para obtener el tamaño de (n) de miMatriz
    int n = miMatriz.size();
    //Definimos una variable temporal para almacenar datos momentaneamente
    float temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            //Se divide el valor de mi matriz en j,i entre el valor en i,i y el resultado se almacena en la variable temporal.
            temp = miMatriz[j][i] / miMatriz[i][i];
            /*un tercer ciclo para eliminar el valor en jk (los valores de la parte de abajo respecto a la diagonal) 
            con ayuda del factor temporal que es el valor inverso a miMatriz[j][k] se eliminan los valores iguales miMatriz[j][k] es igual a mi Matriz[i][k]*temp 
            por lo tanto al restarlos nos da 0*/ 
            for (int k = i; k < n + 1; k++) {
                miMatriz[j][k] -= temp * miMatriz[i][k];
            }
        }
    }


    for (int i = n - 1; i >= 0; i--) {

        for (int j = i - 1; j >= 0; j--) {
            temp = miMatriz[j][i] / miMatriz[i][i];
            for (int k = n; k >= i; k--) {
                miMatriz[j][k] -= temp * miMatriz[i][k];
            }
        }

        float x[n];
        for (int i = 0; i < n; i++)
            x[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (x[i] == 0 && j != n)
                    x[i] = miMatriz[i][j];
                if (x[i] != 0)
                    miMatriz[i][j] /= x[i];
            }
        }
    }
}
