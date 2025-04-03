#include <iostream>

class solution {
    public:
    class ParkingSystem {
        private:
            int bigSpaces;
            int mediumSpaces;
            int smallSpaces;
        public:
            // Constructor
            ParkingSystem(int big, int medium, int small) {
                bigSpaces = big;
                mediumSpaces = medium;
                smallSpaces = small;
            }
            // Getters
            int getBigSpaces() {
                return bigSpaces;
            }
            int getMediumSpaces() {
                return mediumSpaces;
            }
            int getSmallSpaces() {
                return smallSpaces;
            }
            // Setters
            void setBigSpaces(int big) {
                bigSpaces = big;
            }
            void setMediumSpaces(int medium) {
                mediumSpaces = medium;
            }
            void setSmallSpaces(int small) {
                smallSpaces = small;
            }
            // Método para añadir carros
            bool addCar(int carType) {
                if (carType == 1) { // Carro grande
                    if (bigSpaces > 0) {
                        bigSpaces--;
                        return true;
                    }
                } else if (carType == 2) { // Carro mediano
                    if (mediumSpaces > 0) {
                        mediumSpaces--;
                        return true;
                    }
                } else if (carType == 3) { // Carro pequeño
                    if (smallSpaces > 0) {
                        smallSpaces--;
                        return true;
                    }
                }
                return false;
            }
    };
};

int main(){
    // Crear un objeto ParkingSystem
    solution::ParkingSystem parkingSystem(0, 1, 1);
    // Añadir carros
    std::cout << parkingSystem.addCar(1) << std::endl; // true
    std::cout << parkingSystem.addCar(2) << std::endl; // true
    std::cout << parkingSystem.addCar(3) << std::endl; // false
    std::cout << parkingSystem.addCar(1) << std::endl; // false
    return 0;
}