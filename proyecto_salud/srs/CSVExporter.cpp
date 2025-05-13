#include "CSVExporter.h"
#include <QFile>
#include <QTextStream>

bool CSVExporter::exportToCSV(const QString& filePath, const QVector<HealthRecord>& records) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;  // Error al abrir archivo
    }

    QTextStream out(&file);

    // Encabezados del CSV
    out << "RecordID,UserID,Date,Weight,BloodPressureSystolic,BloodPressureDiastolic,GlucoseLevel\n";

    // Escribir cada registro
    for (const auto& record : records) {
        out << record.getRecordId() << ","
            << record.getUserId() << ","
            << record.getDate().toString(Qt::ISODate) << ","
            << record.getWeight() << ","
            << record.getSystolicBP() << ","
            << record.getDiastolicBP() << ","
            << record.getGlucose() << "\n";
    }

    file.close();
    return true;
}
