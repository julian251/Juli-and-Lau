#ifndef DatabaseManager_H
#define DatabaseManager_H

#include <QString>
#include <QSqlDatabase>
#include <QVector>
#include "User.h"
#include "HealthRecord.h"

class DatabaseManager {
public:
    DatabaseManager(const QString& dbPath);
    ~DatabaseManager();

    bool connect();
    void disconnect();

    bool isConnected() const;

    bool validateLogin(const QString& username, const QString& password, QString& userIdOut);

    QVector<User> loadUsers();
    QVector<HealthRecord> loadHealthRecordsByUser(const QString& userId);

    bool insertUser(const User& user);
    bool insertHealthRecord(const HealthRecord& record);

private:
    QSqlDatabase m_db;
    QString m_dbPath;
};

#endif
