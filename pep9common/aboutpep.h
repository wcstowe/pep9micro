// File: aboutpep.h
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

#ifndef ABOUTPEP_H
#define ABOUTPEP_H

#include <QDialog>

namespace Ui {
    class AboutPep;
}

class AboutPep : public QDialog {
    Q_OBJECT
public:
    // Icons will be scaled to 150x150 px.
    AboutPep(QString aboutText, QPixmap icon, QWidget *parent = nullptr);
    ~AboutPep();

private:
    Ui::AboutPep *ui;
    QString str;
    QPixmap icon;
};

#endif // ABOUTPEP_H
