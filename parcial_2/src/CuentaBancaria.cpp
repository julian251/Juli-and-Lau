#include "CuentaBancaria.h"
#include <string>

// Constructor
CuentaBancaria::CuentaBancaria(std::string numeroCuenta, double saldo) {
        // Inicializa el número de cuenta y el saldo
        this->numeroCuenta = numeroCuenta;
        if (saldo >= 0) {
            this->saldo = saldo;
        } else {
            std::cout << "El saldo no puede ser negativo." << std::endl;
            this->saldo = 0; // Asignar un saldo inicial de 0 si se proporciona un saldo negativo
        }
}

// Getters
float CuentaBancaria::getSaldo() const {
    return saldo;
}
bool CuentaBancaria::isBloqueada() const {
    return bloqueada;
}
std::string CuentaBancaria::getNumeroCuenta() const{
    return numeroCuenta;
}
// Setters
void CuentaBancaria::setNumeroCuenta(std::string numeroCuenta) {
    this->numeroCuenta = numeroCuenta;
}
void CuentaBancaria::setSaldo(double saldo) {
    if (saldo >= 0) {
        this->saldo = saldo;
    } else {
        std::cout << "El saldo no puede ser negativo." << std::endl;
    }
}
void CuentaBancaria::setBloqueada(bool bloqueada) {
    this->bloqueada = bloqueada;
}
// Método para depositar dinero
void CuentaBancaria::depositar(double cantidad) {
    if (cantidad > 0) {
        saldo += cantidad;
    } else {
        std::cout << "La cantidad a depositar debe ser positiva." << std::endl;
    }
}
// Método para retirar dinero
void CuentaBancaria::retirar(double cantidad) {
    if (bloqueada) {
        std::cout << "La cuenta está bloqueada. No se pueden realizar retiros." << std::endl;
        return;
    }
    if (cantidad > 0 && cantidad <= saldo) {
        saldo -= cantidad;
    } else {
        std::cout << "La cantidad a retirar debe ser positiva y menor o igual al saldo disponible." << std::endl;
    }
}
// Métodos para bloquear y desbloquear los retiros de una cuenta
void CuentaBancaria::bloquearRetiros() {
    bloqueada = true;
}
void CuentaBancaria::desbloquearRetiros() {
    bloqueada = false;
}