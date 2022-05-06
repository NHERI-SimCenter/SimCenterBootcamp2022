#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_folderButton_clicked()
{
    // the button was clicked

    qDebug() << "button was clicked";

    // now find a folder

    QFileDialog *dlg = new QFileDialog();
    QString filename = dlg->getOpenFileName(this,  "select a file in a folder", ".");
    delete dlg;

    qDebug() << filename;

    if (!filename.isEmpty())
    {
        QFileInfo fileInfo(filename);

        ui->filename->setText(fileInfo.fileName());
        ui->folderName->setText(fileInfo.absolutePath());
    }

    this->showFileContents(filename);
}


bool MainWindow::showFileContents(QString &filename)
{
    // load file
    QFile f(filename);

    if (f.open(QIODevice::ReadOnly)) {
        QTextStream *stream = new QTextStream(&f);
        QString theContents = stream->readAll();

        // display in textBrowser
        ui->textBrowser->setText(theContents);

        // let the user know that we did it
        return true;
    }
    else
    {
        // let the user know that we did fail
        ui->textBrowser->setText("CANNOT DISPLAY THIS FILE'S CONTENTS");
        return false;
    }
}

