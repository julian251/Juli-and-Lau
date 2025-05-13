#ifndef HealthAnalyzer_H
#define HealthAnalyzer_H

#include "HealthRecord.h"
#include <QVector>

class HealthAnalyzer {
public:
    explicit HealthAnalyzer(const QVector<HealthRecord>& records);

    float averageWeight() const;
    float averageGlucose() const;
    float averageSystolicBP() const;
    float averageDiastolicBP() const;

    float weightTrend() const;    // + positivo si aumenta, - si baja
    float glucoseTrend() const;   // mismo concepto

private:
    QVector<HealthRecord> m_records;

    float calculateTrend(const QVector<float>& values) const;
};

#endif // HEALTHANALYZER_H
