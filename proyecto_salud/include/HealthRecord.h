#ifndef HealthRecord_H
#define HealthRecord_H

#include <QString>
#include <QDate>

class HealthRecord {
public:
    HealthRecord();
    HealthRecord(const QString& recordId,
                 const QString& userId,
                 const QDate& date,
                 float weight,
                 int systolicBP,
                 int diastolicBP,
                 float glucose);

    QString getRecordId() const;
    void setRecordId(const QString& recordId);

    QString getUserId() const;
    void setUserId(const QString& userId);

    QDate getDate() const;
    void setDate(const QDate& date);

    float getWeight() const;
    void setWeight(float weight);

    int getSystolicBP() const;
    void setSystolicBP(int systolic);

    int getDiastolicBP() const;
    void setDiastolicBP(int diastolic);

    float getGlucose() const;
    void setGlucose(float glucose);

    void printRecord() const;

private:
    QString m_recordId;
    QString m_userId;
    QDate m_date;
    float m_weight;
    int m_systolicBP;
    int m_diastolicBP;
    float m_glucose;
};

#endif
