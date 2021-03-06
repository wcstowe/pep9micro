/*
    Pep9CPU is a CPU simulator for executing microcode sequences to
    implement instructions in the instruction set of the Pep/9 computer.

    Copyright (C) 2018  Matthew McRaven, Pepperdine University

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef ACPUMODEL_H
#define ACPUMODEL_H

#include <QObject>
#include "enu.h"
class AMemoryDevice;
/*
 * Class representing commonalities between all Pep/9 implementations.
 * Provides a unified way to access registers, status bits, and memory.
 * Also provides debugging facilities via hitBreakpoint(type).
 *
 * By deriving from this class instead of a concrete base class, UI elements can be
 * reused between all three projects.
 *
 * To use, inherit first from ACPUModel, then InterfaceISACPU and/or InterfaceMCCPU. ACPUModel describes the
 * data in a CPU, while the interfaces describe properties of the
 *  CPU at varying levels of abstraction.
 */
class ACPUModel: public QObject
{
    Q_OBJECT
public:
    ACPUModel(QSharedPointer<AMemoryDevice> memoryDev, QObject* parent = nullptr) noexcept;
    virtual ~ACPUModel();

    // Returns a #non-owning# pointer to the memory device being used by the CPU
    AMemoryDevice* getMemoryDevice() noexcept;
    const AMemoryDevice* getMemoryDevice() const noexcept;
    void setMemoryDevice(QSharedPointer<AMemoryDevice> newDevice);
    bool getExecutionFinished() const noexcept;
    bool getInSimulation() const noexcept;
    bool getInDebug() const noexcept;

    // Return the depth of the call stack (#calls+#traps-#ret-#rettr)
    int getCallDepth() const noexcept;

    // Prepare the CPU for starting simulations / debugging.
    virtual void initCPU() = 0;
    // Fetch values of the status bit reigsters(NZVCS bits).
    virtual bool getStatusBitCurrent(Enu::EStatusBit) const = 0;
    virtual bool getStatusBitStart(Enu::EStatusBit) const = 0;
    /*
     * Return the current value of the named register. On implementations with non-atomic instructions
     * (e.g. micrcoded CPU's) the value of a register might vary over the course of executing an instruction.
     */
    virtual quint8 getCPURegByteCurrent(Enu::CPURegisters reg) const = 0;
    virtual quint16 getCPURegWordCurrent(Enu::CPURegisters reg) const = 0;
    // Return the value of a register at the start of an instruction
    virtual quint8 getCPURegByteStart(Enu::CPURegisters reg) const = 0;
    virtual quint16 getCPURegWordStart(Enu::CPURegisters reg) const = 0;
    // CPU can be debugged with multiple levels of diagnostic information
    virtual Enu::DebugLevels getDebugLevel() const noexcept = 0;
    virtual void setDebugLevel(Enu::DebugLevels level) = 0;
    // Did any part of the CPU simulation cause an error?
    virtual QString getErrorMessage() const noexcept = 0;
    virtual bool hadErrorOnStep() const noexcept = 0;

    virtual bool stoppedForBreakpoint() const noexcept = 0;

public slots:
    // Prepare CPU for a normal (non-debugging) simulation.
    virtual void onSimulationStarted() = 0;
    // Clean up CPU after simulation.
    virtual void onSimulationFinished() = 0;
    // Prepare CPU for being stepped through.
    virtual void onDebuggingStarted() = 0;
    // Clean up CPU after debugging.
    virtual void onDebuggingFinished() = 0;
    // Cancel execution (and clean up) without raising any warnings.
    virtual void onCancelExecution() = 0;

    // Execute until completion, cancelation, or errors occur.
    virtual bool onRun() = 0;
    // Wipe all registers & memory, but KEEP loaded microprograms & breakpoints.
    virtual void onResetCPU() = 0;
    virtual void onClearMemory();

signals:
    void simulationFinished();
    void hitBreakpoint(Enu::BreakpointTypes type);
    // If a simulator does not support assembler (Pep9CPU), then this will not be emitted.
    void asmInstructionFinished();

protected:
    QSharedPointer<AMemoryDevice> memory;
    int callDepth;
    bool inDebug, inSimulation, executionFinished;
    mutable bool controlError;
    mutable QString errorMessage;
};

#endif // ACPUMODEL_H
