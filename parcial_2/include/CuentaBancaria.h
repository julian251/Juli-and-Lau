#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <iostream>
#include <string>

class CuentaBancaria {
    private:
    //Atributos privados que representan el saldo y el estado de la cuenta
        float saldo = 0;
        bool bloqueada = false;
    // Estos atributos se inicalizan con valores por defecto de una cuenta bancaria
        // la cuenta tiene un saldo de 0 y no está bloqueada
    protected:
    // Atributo protegido para el número de cuenta
        std::string numeroCuenta;
    public:
        // Constructor
        CuentaBancaria(std::string numeroCuenta, double saldo);
        
        // Getters
        std::string getNumeroCuenta() const;
        float getSaldo() const;
        bool isBloqueada() const;

        // Setters
        void setNumeroCuenta(std::string numeroCuenta);
        void setSaldo(double saldo);
        void setBloqueada(bool bloqueada);

        // Método para depositar dinero
        void depositar(double cantidad);

        // Método para retirar dinero
        void retirar(double cantidad);

        // Método para bloquear los retiros de una cuenta
        void bloquearRetiros();
        void desbloquearRetiros();
};

#endif // CUENTABANCARIA_H