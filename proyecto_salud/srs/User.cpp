#include "User.h"

User::User() : m_id(""), m_username(""), m_password("") {}

User::User(const QString& id, const QString& username, const QString& password)
    : m_id(id), m_username(username), m_password(password) {}

QString User::getId() const {
    return m_id;
}

void User::setId(const QString& id) {
    m_id = id;
}

QString User::getUsername() const {
    return m_username;
}

void User::setUsername(const QString& username) {
    m_username = username;
}

QString User::getPassword() const {
    return m_password;
}

void User::setPassword(const QString& password) {
    m_password = password;
}

bool User::checkCredentials(const QString& inputUsername, const QString& inputPassword) const {
    return (m_username == inputUsername && m_password == inputPassword);
}
