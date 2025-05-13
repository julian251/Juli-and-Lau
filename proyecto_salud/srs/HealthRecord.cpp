#include "HealthRecord.h"
#include <QDebug>

HealthRecord::HealthRecord()
    : m_recordId(""), m_userId(""), m_date(QDate::currentDate()),
      m_weight(0.0f), m_systolicBP(0), m_diastolicBP(0), m_glucose(0.0f) {}

HealthRecord::HealthRecord(const QString& recordId,
                           const QString& userId,
                           const QDate& date,
                           float weight,
                           int systolicBP,
                           int diastolicBP,
                           float glucose)
    : m_recordId(recordId), m_userId(userId), m_date(date),
      m_weight(weight), m_systolicBP(systolicBP), m_diastolicBP(diastolicBP), m_glucose(glucose) {}

QString HealthRecord::getRecordId() const {
    return m_recordId;
}

void HealthRecord::setRecordId(const QString& recordId) {
    m_recordId = recordId;
}

QString HealthRecord::getUserId() const {
    return m_userId;
}

void HealthRecord::setUserId(const QString& userId) {
    m_userId = userId;
}

QDate HealthRecord::getDate() const {
    return m_date;
}

void HealthRecord::setDate(const QDate& date) {
    m_date = date;
}

float HealthRecord::getWeight() const {
    return m_weight;
}

void HealthRecord::setWeight(float weight) {
    m_weight = weight;
}

int HealthRecord::getSystolicBP() const {
    return m_systolicBP;
}

void HealthRecord::setSystolicBP(int systolic) {
    m_systolicBP = systolic;
}

int HealthRecord::getDiastolicBP() const {
    return m_diastolicBP;
}

void HealthRecord::setDiastolicBP(int diastolic) {
    m_diastolicBP = diastolic;
}

float HealthRecord::getGlucose() const {
    return m_glucose;
}

void HealthRecord::setGlucose(float glucose) {
    m_glucose = glucose;
}

void HealthRecord::printRecord() const {
    qDebug() << "Record ID:" << m_recordId;
    qDebug() << "User ID:" << m_userId;
    qDebug() << "Date:" << m_date.toString();
    qDebug() << "Weight:" << m_weight << "kg";
    qDebug() << "Blood Pressure:" << m_systolicBP << "/" << m_diastolicBP << "mmHg";
    qDebug() << "Glucose:" << m_glucose << "mg/dL";
}
