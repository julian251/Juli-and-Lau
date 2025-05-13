#ifndef CSVExporter_H
#define CSVExporter_H

#include "HealthRecord.h"
#include <QString>
#include <QVector>

class CSVExporter {
public:
    static bool exportToCSV(const QString& filePath, const QVector<HealthRecord>& records);
};

#endif
