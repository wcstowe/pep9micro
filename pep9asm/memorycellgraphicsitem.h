// File: memorycellgraphicsitem.h
/*
    Pep9 is a virtual machine for writing machine language and assembly
    language programs.

    Copyright (C) 2009  J. Stanley Warford, Pepperdine University

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

#ifndef MEMORYCELLGRAPHICSITEM_H
#define MEMORYCELLGRAPHICSITEM_H

#include <QGraphicsItem>
#include "enu.h"
#include "colors.h"
class AMemoryDevice;

int cellSize(Enu::ESymbolFormat symbolFormat);
// This is used exclusively in the memoryTracePane/memoryCellGraphicsItem
class MemoryCellGraphicsItem : public QGraphicsItem
{
public:
    MemoryCellGraphicsItem(const AMemoryDevice *memDevice, int addr, QString sym, Enu::ESymbolFormat eSymFrmt, int xLoc, int yLoc);
    ~MemoryCellGraphicsItem() { }

    QRectF boundingRect() const;

    void updateContents(int newAddr, QString newSymbol, Enu::ESymbolFormat newFmt, int newY);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    // Cell changes background color if it has been modified.
    void setModified(bool value);
    void setColorTheme(const PepColors::Colors &newColors);
    static const int boxHeight;
    static const int boxWidth;
    static const int addressWidth;
    static const int symbolWidth;
    static const int bufferWidth;

    // QColor boxColor;
    QColor setBackgroundColor(QColor color);
    // QColor textColor;
    // QColor boxTextColor;
    void updateValue();
    quint16 getAddress() const;
    quint16 getNumBytes() const;
    quint16 getValue() const;

private:
    const AMemoryDevice *memDevice;
    int x, y;
    quint16 address, iValue;
    Enu::ESymbolFormat eSymbolFormat;
    QString symbol, value;
    QRectF box;
    const PepColors::Colors * colors;
    QColor backgroundColor;
    bool isModified;

};

#endif // MEMORYCELLGRAPHICSITEM_H
