#include "HealthAnalyzer.h"

HealthAnalyzer::HealthAnalyzer(const QVector<HealthRecord>& records)
    : m_records(records) {}

float HealthAnalyzer::averageWeight() const {
    if (m_records.isEmpty()) return 0;
    float total = 0;
    for (const auto& r : m_records)
        total += r.getWeight();
    return total / m_records.size();
}

float HealthAnalyzer::averageGlucose() const {
    if (m_records.isEmpty()) return 0;
    float total = 0;
    for (const auto& r : m_records)
        total += r.getGlucose();
    return total / m_records.size();
}

float HealthAnalyzer::averageSystolicBP() const {
    if (m_records.isEmpty()) return 0;
    float total = 0;
    for (const auto& r : m_records)
        total += r.getSystolicBP();
    return total / m_records.size();
}

float HealthAnalyzer::averageDiastolicBP() const {
    if (m_records.isEmpty()) return 0;
    float total = 0;
    for (const auto& r : m_records)
        total += r.getDiastolicBP();
    return total / m_records.size();
}

// Cálculo muy básico de tendencia: diferencia entre último y primero
float HealthAnalyzer::calculateTrend(const QVector<float>& values) const {
    if (values.size() < 2) return 0;
    return values.last() - values.first();
}

float HealthAnalyzer::weightTrend() const {
    QVector<float> weights;
    for (const auto& r : m_records)
        weights.append(r.getWeight());
    return calculateTrend(weights);
}

float HealthAnalyzer::glucoseTrend() const {
    QVector<float> glucose;
    for (const auto& r : m_records)
        glucose.append(r.getGlucose());
    return calculateTrend(glucose);
}
