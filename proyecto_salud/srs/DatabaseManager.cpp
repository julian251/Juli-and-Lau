#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

DatabaseManager::DatabaseManager(const QString& dbPath)
    : m_dbPath(dbPath) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(m_dbPath);
}

DatabaseManager::~DatabaseManager() {
    disconnect();
}

bool DatabaseManager::connect() {
    if (!m_db.open()) {
        qDebug() << "Failed to connect to database:" << m_db.lastError().text();
        return false;
    }
    return true;
}

void DatabaseManager::disconnect() {
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DatabaseManager::isConnected() const {
    return m_db.isOpen();
}

bool DatabaseManager::validateLogin(const QString& username, const QString& password, QString& userIdOut) {
    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        userIdOut = query.value(0).toString();
        return true;
    }
    return false;
}

QVector<User> DatabaseManager::loadUsers() {
    QVector<User> users;
    QSqlQuery query("SELECT id, username, password FROM users");
    while (query.next()) {
        users.append(User(query.value(0).toString(), query.value(1).toString(), query.value(2).toString()));
    }
    return users;
}

QVector<HealthRecord> DatabaseManager::loadHealthRecordsByUser(const QString& userId) {
    QVector<HealthRecord> records;
    QSqlQuery query;
    query.prepare("SELECT id, user_id, date, weight, systolic, diastolic, glucose "
                  "FROM health_records WHERE user_id = :userId");
    query.bindValue(":userId", userId);

    if (query.exec()) {
        while (query.next()) {
            records.append(HealthRecord(
                query.value(0).toString(),     // recordId
                query.value(1).toString(),     // userId
                QDate::fromString(query.value(2).toString(), "yyyy-MM-dd"), // date
                query.value(3).toFloat(),      // weight
                query.value(4).toInt(),        // systolic
                query.value(5).toInt(),        // diastolic
                query.value(6).toFloat()       // glucose
            ));
        }
    }
    return records;
}

bool DatabaseManager::insertUser(const User& user) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (id, username, password) VALUES (:id, :username, :password)");
    query.bindValue(":id", user.getId());
    query.bindValue(":username", user.getUsername());
    query.bindValue(":password", user.getPassword());
    return query.exec();
}

bool DatabaseManager::insertHealthRecord(const HealthRecord& record) {
    QSqlQuery query;
    query.prepare("INSERT INTO health_records (id, user_id, date, weight, systolic, diastolic, glucose) "
                  "VALUES (:id, :user_id, :date, :weight, :systolic, :diastolic, :glucose)");
    query.bindValue(":id", record.getRecordId());
    query.bindValue(":user_id", record.getUserId());
    query.bindValue(":date", record.getDate().toString("yyyy-MM-dd"));
    query.bindValue(":weight", record.getWeight());
    query.bindValue(":systolic", record.getSystolicBP());
    query.bindValue(":diastolic", record.getDiastolicBP());
    query.bindValue(":glucose", record.getGlucose());
    return query.exec();
}
