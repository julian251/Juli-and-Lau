#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <iostream>
#include <string>

/**
 * @class CuentaBancaria
 * @brief Representa una cuenta bancaria con saldo, estado de bloqueo y número de cuenta.
 */
class CuentaBancaria {
    private:
    //Atributos privados que representan el saldo y el estado de la cuenta

        float saldo = 0;///< Saldo actual de la cuenta bancaria.
        bool bloqueada = false;///< Indica si la cuenta está bloqueada.

    // Estos atributos se inicalizan con valores por defecto de una cuenta bancaria, la cuenta tiene un saldo de 0 y no está bloqueada
    protected:
    // Atributo protegido para el número de cuenta
        std::string numeroCuenta;///< Número de cuenta bancaria.
    public:
       /**
         * @brief Constructor de la clase CuentaBancaria.
         * @param numeroCuenta Número de cuenta bancaria.
         * @param saldo Saldo inicial de la cuenta. Si es negativo, se inicializa en 0.
         */

        // Constructor
        CuentaBancaria(std::string numeroCuenta, double saldo);

        // Getters

       /**
         * @brief Obtiene el número de cuenta bancaria.
         * @return El número de cuenta bancaria.
         */
        std::string getNumeroCuenta() const;

       /**
         * @brief Obtiene el saldo actual de la cuenta bancaria.
         * @return El saldo actual.
         */
        float getSaldo() const;

       /**
         * @brief Verifica si la cuenta está bloqueada.
         * @return `true` si la cuenta está bloqueada, `false` en caso contrario.
         */
        bool isBloqueada() const;

        // Setters

       /**
         * @brief Establece el número de cuenta bancaria.
         * @param numeroCuenta Nuevo número de cuenta bancaria.
         */
        void setNumeroCuenta(std::string numeroCuenta);

       /**
         * @brief Establece el saldo de la cuenta bancaria.
         * @param saldo Nuevo saldo de la cuenta. Si es negativo, no se actualiza.
         */
        void setSaldo(double saldo);

       /**
         * @brief Establece el estado de bloqueo de la cuenta.
         * @param bloqueada `true` para bloquear la cuenta, `false` para desbloquearla.
         */
        void setBloqueada(bool bloqueada);

        // Método para depositar dinero
       /**
         * @brief Deposita una cantidad de dinero en la cuenta.
         * @param cantidad Cantidad a depositar. Debe ser positiva.
         */
        void depositar(double cantidad);

        // Método para retirar dinero
         /**
            * @brief Retira una cantidad de dinero de la cuenta.
            * @param cantidad Cantidad a retirar. Debe ser positiva y menor o igual al saldo disponible.
            * @note Si la cuenta está bloqueada, no se permite el retiro.
            */
        void retirar(double cantidad);

        // Método para bloquear los retiros de una cuenta

         /**
            * @brief Bloquea los retiros de la cuenta.
            */
        void bloquearRetiros();

        // Método para desbloquear los retiros de una cuenta

         /**
            * @brief Desbloquea los retiros de la cuenta.
            */
        void desbloquearRetiros();
};

#endif // CUENTABANCARIA_H