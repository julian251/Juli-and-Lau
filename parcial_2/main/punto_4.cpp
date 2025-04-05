#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "CuentaBancaria.h"


int main() {
    // Crear un vector de cuentas bancarias
    std::vector<CuentaBancaria> cuentas;
    // Agregar cuentas al vector
    cuentas.push_back(CuentaBancaria("123456789", 1000));
    cuentas.push_back(CuentaBancaria("987654321", 2000));
    cuentas.push_back(CuentaBancaria("456789123", 3000));

    // Simulación de operaciones
    cuentas[0].depositar(500);
    cuentas[1].retirar(1000);
    cuentas[2].setBloqueada(true);
    cuentas[1].depositar(200);
    cuentas[2].retirar(500); // Intento de retiro en cuenta bloqueada
    std::cout << "Saldo cuenta 1: " << cuentas[0].getSaldo() << std::endl;
    std::cout << "Saldo cuenta 2: " << cuentas[1].getSaldo() << std::endl;
    std::cout << "Saldo cuenta 3: " << cuentas[2].getSaldo() << std::endl;

    // Reporte de el sado de las cuentas
    std::ofstream reporte("reporte.txt");
    if (reporte.is_open()) {
        for (const auto& cuenta : cuentas) {
            reporte << "Número de cuenta: " << cuenta.getNumeroCuenta() << std::endl;
            reporte << "Saldo: " << cuenta.getSaldo() << std::endl;
            reporte << "Estado de la cuenta: " << (cuenta.isBloqueada() ? "Bloqueada" : "Activa") << std::endl;
            reporte << "-------------------------" << std::endl;
        }
        reporte.close();
    } else {
        std::cout << "No se pudo abrir el archivo de reporte." << std::endl;
    }
    return 0;
}