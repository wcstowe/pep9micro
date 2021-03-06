#ifndef FULLMICROCODEMEMOIZER_H
#define FULLMICROCODEMEMOIZER_H

#include <QString>
#include "enu.h"
class CPUControlSection;
struct callStack
{
    quint16 greatest_SP = 0, least_SP = 0;
};

class PartialMicrocodedCPU;
class PartialMicrocodedMemoizer
{
public:
    explicit PartialMicrocodedMemoizer(PartialMicrocodedCPU& item);
    Enu::DebugLevels getDebugLevel() const;

    void clear();
    void storeStateInstrEnd();
    void storeStateInstrStart();
    QString memoize();
    QString finalStatistics();
    void setDebugLevel(Enu::DebugLevels level);

private:
    PartialMicrocodedCPU& cpu;
    Enu::DebugLevels level;
    QString formatNum(quint16 number);
    QString formatNum(quint8 number);
    QString formatAddress(quint16 address);
};

#endif // FULLMICROCODEMEMOIZER_H
