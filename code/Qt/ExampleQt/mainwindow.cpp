#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->filename->setText("Peter");
    ui->directory->setText("was here!");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_locate_button_clicked()
{
    qDebug() << "locate_button clicked";

    QString fn = ui->filename->text();
    QString dir = ui->directory->text();

    QString contents = dir + "/" + fn;

    ui->textBrowser->setText(contents);
    this->repaint();
}
