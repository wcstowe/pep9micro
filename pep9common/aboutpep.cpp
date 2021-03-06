// File: aboutpep.cpp
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

#include "aboutpep.h"
#include "ui_aboutpep.h"
#include "pep.h"

AboutPep::AboutPep(QString aboutText, QPixmap pixmap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutPep), str(aboutText), icon(pixmap)
{
    ui->setupUi(this);
    ui->aboutLabel->setText(str);
    ui->label->setPixmap(pixmap);
    setMinimumHeight(460);
    //setMaximumHeight(450);
    this->resize(this->contentsRect().x(),450);
}

AboutPep::~AboutPep()
{
    delete ui;
}
