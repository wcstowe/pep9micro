// File: byteconverterdec.h
/*
    Pep9CPU is a CPU simulator for executing microcode sequences to
    implement instructions in the instruction set of the Pep/9 computer.

    Copyright (C) 2010  J. Stanley Warford, Pepperdine University

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

#ifndef BYTECONVERTERDEC_H
#define BYTECONVERTERDEC_H

#include <QWidget>
#include <QRegExpValidator>

namespace Ui {
    class ByteConverterDec;
}

class ByteConverterDec : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(ByteConverterDec)
public:
    explicit ByteConverterDec(QWidget *parent = 0);
    virtual ~ByteConverterDec();
    void setValue(int);

private:
    Ui::ByteConverterDec *m_ui;
    QRegExpValidator* decValidator;

signals:
    void textEdited(const QString &);
};

#endif // BYTECONVERTERDEC_H