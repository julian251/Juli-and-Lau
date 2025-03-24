#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            // Se hacen 9 iteraciones para validar las filas, columnas y cuadros
            for (int caso = 0; caso < 9; caso++){
                // Validación de filas y columnas
                for (int caso1 = 0; caso1 <9; caso1++){
                    // Validación de filas
                    for (int i = 0; i < 9; i++){
                        // Validar si no es el mismo cuadro y si hay un número en el cuadro, es decir si hay que validar el cuadro
                        if (i != caso1 && board[caso][i] != '.'){ 
                            // Se toma la variable caso como columna y las variables caso1 e i como filas
                            if (board[caso][caso1] == board[caso][i])
                                return false;
                        }
                    }
                    // Validación de columnas
                    for (int j = 0; j < 9; j++){
                        // Se valida si no es el mismo cuadro y si hay un numero en el cuadro, es decir si hay que validar
                        if (j != caso1 && board[j][caso] != '.'){ 
                            // Se toma la variable caso como fila y las variables caso1 y j como columnas
                            if (board[caso1][caso] == board[j][caso])
                                return false;
                        }                        
                    }
                }
            // Validación de cuadros
            /* 
            Se toma el modulo de caso para obtener la fila y el cociente de caso para obtener la columna inical de cada cuadro
            Se hace un ciclo anidado para recorrer cada cuadro y se valida si hay un numero en el cuadro, si lo hay se valida si es igual a otro numero en el cuadro
            */
            for (int fil1 = (caso%3)*3; fil1 < (caso%3)*3 + 3 ; fil1++){
                for (int col1 = (caso/3)*3; col1 < (caso/3)*3 + 3; col1++){
                    // Se valida si hay un número en el cuadro
                    if (board[col1][fil1] != '.'){
                        // Si hay un número en el cuadro se valida si coincide con otro número en el cuadro
                        for (int k = (caso%3)*3; k < (caso%3)*3 + 3; k++){
                            for (int l = (caso/3)*3; l < (caso/3)*3 + 3; l++){
                                if ((k != fil1) && (l != col1)){
                                    if (board[col1][fil1] == board[l][k])
                                        return false;
            /*
            Para inicializar las variables fil1 y col1 se toma el modulo de caso para obtener la fila y el cociente de caso 
            para obtener la columna inicial de cada cuadro, esto con el fin de validar la fila n, columna n y cuadro n cada interación.
            Se multiplican por tres para empezar en la fila y columna inicial de cada cuadro correspondiente a cada iteración, y para
            el límite se añade 3 al valor inicial, ya que solo se quiere verificar el cuadro.
            Por ejemplo para caso = 0, se obtiene fil1 = 0 y col1 = 0, para caso = 1, se obtiene fil1 = 3 y col1 = 0, 
            para caso = 2, se obtiene fil1 = 6 y col1 = 0 y así sucesivamente.
            */
                                }
                            }
                        }
                    }
                }
            }
            }
        return true; 
        }      
    };
int main(){
    Solution sol;
    vector <vector<char>> board = {
        {'5', '3', '.', '1', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '.', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '1', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    bool result = sol.isValidSudoku(board);
    cout << "[" << result <<"]"<< endl;
    return 0;
    }