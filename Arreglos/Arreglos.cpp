#include <iostream>
#include <array>

#define LEN 3 //Número de elementos en los arreglos

// Añadir std para fácil llamado de funciones
using namespace std;

// Declaración de funciones
//La primera parte define lo que te va a regresar
//regresa <> Nombre (parametros)
void ImprimirArreglo(array<float, LEN> arreglo); //Void es una función que no regresa nada.
array<float, LEN> LlenarArreglo(void);
array<float, LEN> MultiplicarArreglo(array<float, LEN> arreglo, float multiplo);
array<float, LEN> SumarArreglos(array<float, LEN> arr1, array<float, LEN> arr2);


int main()
{
    char decision;
    array<float, LEN> arr = { 0 }; // Inicializamos el arreglo con ceros como buena práctica
    arr = LlenarArreglo(); // Solicitamos al usuario que llene un arreglo y lo asignamos a nuestro arreglo principal
    cout << "Operacion, poner * si es multipliacion y poner + en caso de suma: ";
    cin >> decision;
    // Si la operación no es '+' de suma, o '*' de multiplicación, seguimos preguntando al usuario.
    while (decision != '+' && decision != '*')
    {
        cout << "Operacion: ";
        cin >> decision;
    }
    // Si se ingresa la multiplicación
    if (decision == '*') {
        float factor;
        cout << "Factor: ";
        cin >> factor;  // Pedimos el factor a multiplicar
        arr = MultiplicarArreglo(arr, factor); // Multiplicamos nuestro arreglo principal por el factor y el resultado lo asignamos a nuestro arreglo principal.
    }
        // Si se ingresa la suma
    else if (decision == '+') {
        array<float, LEN> arr2 = {0}; // Creamos el segundo arreglo y lo inicializamos en ceros
        arr2 = LlenarArreglo(); // Pedimos al usuario que llene otro arreglo y lo asignamos a nuetsro nuevo arreglo
        arr = SumarArreglos(arr, arr2); // Sumamos ambos arreglos elemento a elemento, y reasignamos el resutlado a nuestro arreglo principal
    }
    cout << "Resultado: ";
    ImprimirArreglo(arr); // Imprimimos el resultado de la operación sobre el arreglo principal
    return 0; // Indicamos que salimos del programa con éxito
}

// Imprime los elementos del arreglo 'arreglo' separando cada elemento con un espacio en blanco
void ImprimirArreglo(array<float, LEN> arreglo)
{
    for (int i = 0; i < LEN; i++)
        cout << arreglo[i] << ' ';
    cout << endl;
}

// Llena un arreglo de tamaño LEN y lo "regresa" como resultado
array<float, LEN> LlenarArreglo() {
    //Se hace la funcón para llenar un arreglo de tamaño LEN
    //inicializamos el arreglo en 0, y con un ciclo for nos movemos en todos los espacios del arreglo hasta LEN
    array<float, LEN> arreglo = {0};
    for (int i = 0; i < LEN ; i++) {
        //Se pide que se ingrese el primer valor del arreglo
        cout<< "Valor elemento [" << i << "]: ";
        //se actualiza el valor ingresado de areglo[i] = a la entrada del usuario
        cin>> arreglo[i];
    }
    return arreglo;
}

// Multiplica cada elemento del arreglo 'arreglo' por el factor 'mult'
array<float, LEN> MultiplicarArreglo(array<float, LEN> arreglo, float multiplo){
    //Con un ciclo for nos movemos en todos los espacios del arreglo hasta LEN
    for (int i = 0; i < LEN; ++i) {
        //Se ingresa una variable múltiplo y se multiplica al valor de arreglo[i], a su vez se actualiza en la posición
        arreglo[i] *= multiplo;
    }
    //se hace el return del arreglo que se ingresa con los cambios del multiplo
    return arreglo;
}

// Suma elemento a elemento los arreglos 'arr1' y 'arr2' y regresa el arreglo resultante
array<float, LEN> SumarArreglos(array<float, LEN> arr1, array<float, LEN> arr2){
    //con un ciclo for nos movemos en todos los espacios del arreglo hasta LEN
    for (int i = 0; i < LEN; ++i) {
        //Se hace la suma entre ambos arreglos en la misma posición y se guarda en arr1
        arr1[i] += arr2[i];
    }
    //como las variables estan guardadas en arr1 se hace el return del mismo
    return arr1;
}