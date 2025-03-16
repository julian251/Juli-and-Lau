#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string addStrings(string num1, string num2) {
            //Declaración de variables
            int size1 = num1.size();
            int size2 = num2.size();
            int carry = 0;
            string result = "";
            int size;
            //Se determina el tamaño de los números y se iguala su tamaño concatenando ceros a la izquierda
            if (size1 > size2){
                size = size1;
                for(int i = 0; i < size1-size2; i++){
                    num2 = "0" + num2;
                }
            } else if (size2 > size1){
                size = size2;
                for(int i = 0; i < size2-size1; i++){
                    num1 = "0" + num1;
                }
            } else {
                size = size1;
            }
            //Se recorren ambos números de derecha a izquierda y se realiza la suma
            for (int i= size-1; i>=0; i--){
                //Se concatena el resultado de la suma con el resultado anterior
                result = to_string((num1[i]-'0' + num2[i]-'0' + carry)%10) + result; // Se resta '0' para convertir de ascii a int
                /*Se determina el resultado antes del carry, para que el resultado corresponda con el carry anterior 
                y carry sea el próximo carry*/
                carry = (num1[i]-'0' + num2[i]-'0' + carry)/10;
                //Se concatena el carry final al resultado en el ultimo ciclo
                if (i == 0 && carry != 0){
                    result = to_string(carry) + result;
                }
            }
            return result;
        }
    };

int main(){
    Solution sol;
    string result = sol.addStrings("2345", "8903");
    cout << result << endl;
    return 0;
}