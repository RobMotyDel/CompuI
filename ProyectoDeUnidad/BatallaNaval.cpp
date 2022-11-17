 #include <iostream>
using namespace std;

void MatrizCeros(int mat[10][10]);
//void BarcoUnaPieza(int mat[10][10]);
void BarcoDosPiezas(int mat[10][10]);
void BarcoTresPiezas(int mat[10][10]);
void BarcoCuatroPiezas(int mat[10][10]);
void BarcoCincoPiezas(int mat[10][10]);

int main(){
    int A[10][10];

    MatrizCeros(A);
    //BarcoUnaPieza(A);
    BarcoDosPiezas(A);
    BarcoTresPiezas(A);
    BarcoCuatroPiezas(A);
    BarcoCincoPiezas(A);

    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}

void MatrizCeros(int mat [10][10]) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            mat[i][j] = 0;
}

/*void BarcoUnaPieza(int mat[10][10]){
    int fil, col;
    cout << "Ingresa tu barco de una pieza" << endl;
    cout << "Ingrese una fila del 1 al 10" << endl;
    cin >> fil;
    cout << "Ingrese una columna del 1 al 10" << endl;
    cin >> col;
    mat[fil-1][col-1] = 1;
}*/
void BarcoDosPiezas(int mat[10][10]){
    char dir{0};
    int fil, col;
    cout << "Ahora ingresa tu barco de 2 piezas " << endl;
    //Ciclo for donde i < 2 para que se repita dos veces
    cout << "Ingresa una fila del 1 al 10" << endl;
    cin >> fil;
    cout << "Ingresa una columna del 1 al 10" << endl;
    cin >> col;
    cout << "Ahora ingresa una direccion L para izquierda, R para derecha, D para abajo y U para arriba" << endl;
    cin >> dir;
    if(dir == 'L'){
        mat[fil-1][col-2] = 2;
    }
    if(dir == 'R'){
        mat[fil-1][col] = 2;
    }
    if(dir == 'U'){
        mat[fil-2][col-1] = 2;
    }
    if(dir == 'D'){
        mat[fil][col-1] = 2;
    }
    mat[fil-1][col-1] = 2;
}

void BarcoTresPiezas(int mat[10][10]){
    int fil, col;
    char dir;
    cout << "Ingresa tu barco de 3 partes" << endl;
    cout << "Ingresa una fila del 1 al 10" << endl;
    cin >> fil;
    cout << "Ingresa una columna del 1 al 10" << endl;
    cin >> col;
    cout << "Ahora ingresa una direccion L para izquierda, R para derecha, D para abajo y U para arriba" << endl;
    cin >> dir;
    if(dir == 'L'){
        mat[fil-1][col-2] = 3;
        mat[fil-1][col-3] = 3;
    }
    if(dir == 'R'){
        mat[fil-1][col] = 3;
        mat[fil-1][col+1] = 3;
    }
    if(dir == 'U'){
        mat[fil-2][col-1] = 3;
        mat[fil-3][col-1] = 3;
    }
    if(dir == 'D'){
        mat[fil][col-1] = 3;
        mat[fil+1][col-1] = 3;
    }
    mat[fil-1][col-1] = 3;
}

void BarcoCuatroPiezas(int mat[10][10]){
    int fil, col;
    char dir;
    cout << "Ingresa tu barco de 4 partes" << endl;
    cout << "Ingresa una fila del 1 al 10" << endl;
    cin >> fil;
    cout << "Ingresa una columna del 1 al 10" << endl;
    cin >> col;
    cout << "Ahora ingresa una direccion L para izquierda, R para derecha, D para abajo y U para arriba" << endl;
    cin >> dir;
    if(dir == 'L'){
        mat[fil-1][col-2] = 4;
        mat[fil-1][col-3] = 4;
        mat[fil-1][col-4] = 4;
    }
    if(dir == 'R'){
        mat[fil-1][col] = 4;
        mat[fil-1][col+1] = 4;
        mat[fil-1][col+2] = 4;
    }
    if(dir == 'U'){
        mat[fil-2][col-1] = 4;
        mat[fil-3][col-1] = 4;
        mat[fil-4][col-1] = 4;
    }
    if(dir == 'D'){
        mat[fil][col-1] = 4;
        mat[fil+1][col-1] = 4;
        mat[fil+2][col-1] = 4;
    }
    mat[fil-1][col-1] = 4;
}

void BarcoCincoPiezas(int mat[10][10]){
     int fil, col;
     char dir;
     cout << "Ingresa tu barco de 5 partes" << endl;
     cout << "Ingresa una fila del 1 al 10" << endl;
     cin >> fil;
     cout << "Ingresa una columna del 1 al 10" << endl;
     cin >> col;
     cout << "Ahora ingresa una direccion L para izquierda, R para derecha, D para abajo y U para arriba" << endl;
     cin >> dir;
     if(dir == 'L'){
         mat[fil-1][col-2] = 5;
         mat[fil-1][col-3] = 5;
         mat[fil-1][col-4] = 5;
         mat[fil-1][col-5] = 5;
     }
     if(dir == 'R'){
         mat[fil-1][col] = 5;
         mat[fil-1][col+1] = 5;
         mat[fil-1][col+2] = 5;
         mat[fil-1][col+3] = 5;
     }
     if(dir == 'U'){
         mat[fil-2][col-1] = 5;
         mat[fil-3][col-1] = 5;
         mat[fil-4][col-1] = 5;
         mat[fil-5][col-1] = 5;
     }
     if(dir == 'D'){
         mat[fil][col-1] = 5;
         mat[fil+1][col-1] = 5;
         mat[fil+2][col-1] = 5;
         mat[fil+3][col-1] = 5;
     }
     mat[fil-1][col-1] = 5;
}