#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector <int> twoSum(vector <int>& nums, int target){
            // Se determina el tamaño del vector
            int size = nums.size();
            // Se inicializan los indices
            int index1 = 0; 
            int index2 = 0;
            // Se recorre el vector y se hace la suma de los elementos
            for (int i = 0; i < size-1; i++){
                index1 = i;
                for (int j = i+1; j < size; j++){
                    // Se valida que la suma de los elementos sea igual al objetivo
                    if (nums[i]+nums[j] == target){
                        index2 = j;
                        // Se retorna el indice de los elementos que cumplen con la condición
                        return {index1, index2};
                    }
            }
            return {index1, index2};
        }
    }
};
int main(){
    // prueba de la función
    Solution sol;
    vector <int> nums = {2, 7, 11, 15};
    int target = 9;
    vector <int> result = sol.twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] <<"]"<< endl;
    return 0;
}