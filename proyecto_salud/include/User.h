#ifndef User_H
#define User_H

#include <QString>

/**
 * @class User
 * @brief Representa un usuario con credenciales de acceso.
 */
class User {
public:
    /**
     * @brief Constructor por defecto de la clase User.
     */
    User();

    /**
     * @brief Constructor con parámetros para inicializar un usuario.
     * @param id Identificador único del usuario.
     * @param username Nombre de usuario.
     * @param password Contraseña del usuario.
     */
    User(const QString& id, const QString& username, const QString& password);

    /**
     * @brief Obtiene el identificador del usuario.
     * @return QString con el identificador del usuario.
     */
    QString getId() const;

    /**
     * @brief Establece el identificador del usuario.
     * @param id Identificador único del usuario.
     */
    void setId(const QString& id);

    /**
     * @brief Obtiene el nombre de usuario.
     * @return QString con el nombre de usuario.
     */
    QString getUsername() const;

    /**
     * @brief Establece el nombre de usuario.
     * @param username Nombre de usuario.
     */
    void setUsername(const QString& username);

    /**
     * @brief Obtiene la contraseña del usuario.
     * @return QString con la contraseña del usuario.
     */
    QString getPassword() const;

    /**
     * @brief Establece la contraseña del usuario.
     * @param password Contraseña del usuario.
     */
    void setPassword(const QString& password);

    /**
     * @brief Verifica si las credenciales proporcionadas coinciden con las del usuario.
     * @param inputUsername Nombre de usuario ingresado.
     * @param inputPassword Contraseña ingresada.
     * @return true si las credenciales coinciden, false en caso contrario.
     */
    bool checkCredentials(const QString& inputUsername, const QString& inputPassword) const;

private:
    QString m_id;         /**< Identificador único del usuario. */
    QString m_username;   /**< Nombre de usuario. */
    QString m_password;   /**< Contraseña del usuario. */
};

#endif