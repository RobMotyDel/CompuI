/*
Author: Roberto Montoya
Email: rob.monty.del@gmail.com
*/


#include <iostream>

using namespace std;

int main() {
    //variables
    float num1 = 0, num2 = 0, resultado;
    int mod, a, b;
    char oper{1};

    //Inicio de Programa

    cout << "Este programa hace operaciones basicas entre dos numeros." << endl;
    cout << "Primer numero:";
    cin >> num1;
    cout<< "Operacion:";
    cin >> oper;
    cout << "Segundo numero:";
    cin >> num2;

    //Definicion de resultados dependiendo del operador
    if (oper == '+') {
        resultado = num1 + num2;
        cout << "\nResultado: " << num1 << " + " << num2 << " = " << resultado << endl;
    }
    //Analiza la operacion de - (resta)
    if (oper == '-') {
        resultado = num1 - num2;
        cout << "\nResultado: " << num1 << " - " << num2 << " = " << resultado << endl;
    }
    //Analiza la operacion de / (division) y evita que se divida entre 0
    if (oper == '/') {
        if (num2 == 0){
            cout << "\nEsta operacion no se puede llevar a cabo, intenta no dividir entre 0" << endl;
            return 0;
        }
        else {
            resultado = num1 / num2;
            cout << "\nResultado: " << num1 << " / " << num2 << " = " << resultado << endl;
        }
    }
    //Analiza la operacion de * (multiplicación)
    if (oper == '*') {
        resultado = num1 * num2;
        cout << "\nResultado: " << num1 << " * " << num2 << " = " << resultado << endl;
    }
    //Analiza la operacion de % (modulo) y convierte números flotantes en enteros
    if (oper == '%') {
        int a = static_cast<int>(num1);//Forma de convertir un flotante en un entero, se redondea para abajo
        int b = static_cast<int>(num2);
        mod = a % b;
        cout << "\nResultado: " << a << " % " << b << " = " << mod << endl;
    }
    return 0;
}